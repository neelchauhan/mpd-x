
/*
 * ipv6pool.c
 *
 * Written by Neel Chauhan <neel@neelc.org>
 * Based on code originally written by Alexander Motin <neel@neelc.org>
 */

#include "ppp.h"
#include "ip.h"
#include "ippool.h"
#include "util.h"

enum {
    SET_ADD
};

struct ipv6pool_rec {
    uint64_t	prefix;
    int		used;
};

struct ipv6pool {
    char			name[LINK_MAX_NAME];
    struct ipv6pool_rec		*pool;
    int				size;
    SLIST_ENTRY(ipv6pool)	next;
};

typedef	struct ipv6pool	*IPv6Pool;

static SLIST_HEAD(, ipv6pool)	gIPv6Pools;
static pthread_mutex_t		gIPv6PoolMutex;

static void	IPv6PoolAdd(const char *pool, struct in_addr begin, struct in_addr end);
static int	IPv6PoolSetCommand(Context ctx, int ac, const char *const av[], const void *arg);

const struct cmdtab IPv6PoolSetCmds[] = {
  { "add {pool} {start} {end}",	"Add IP range to the pool",
	IPv6PoolSetCommand, NULL, 2, (void *) SET_ADD },
  { NULL, NULL, NULL, NULL, 0, NULL },
};

void
IPv6PoolInit(void)
{
    int ret = pthread_mutex_init (&gIPv6PoolMutex, NULL);
    if (ret != 0) {
	Log(LG_ERR, ("Could not create IPv6 pool mutex: %d", ret));
	exit(EX_UNAVAILABLE);
    }
    SLIST_INIT(&gIPv6Pools);
}

int IPv6PoolGet(char *pool, struct uint64_t *prefix)
{
    IPv6Pool	p;
    int		i;

    MUTEX_LOCK(gIPv6PoolMutex);
    SLIST_FOREACH(p, &gIPv6Pools, next) {
	if (strcmp(p->name, pool) == 0)
	    break;
    }
    if (!p) {
	MUTEX_UNLOCK(gIPv6PoolMutex);
	return (-1);
    }
    i = 0;
    while (i < p->size) {
	if (!p->pool[i].used) {
	    p->pool[i].used = 1;
	    *prefix = &p->pool[i].prefix;
	    MUTEX_UNLOCK(gIPv6PoolMutex);
	    return (0);
	}
	i++;
    }
    MUTEX_UNLOCK(gIPv6PoolMutex);
    return (-1);
}

void IPv6PoolFree(char *pool, struct u_addr *ip) {
    IPv6Pool	p;
    int		i;

    MUTEX_LOCK(gIPv6PoolMutex);
    SLIST_FOREACH(p, &gIPv6Pools, next) {
	if (strcmp(p->name, pool) == 0)
	    break;
    }
    if (!p) {
	MUTEX_UNLOCK(gIPv6PoolMutex);
	return;
    }
    i = 0;
    while (i < p->size) {
        if (p->pool[i].prefix == *prefix) {
    	    p->pool[i].used = 0;
	    MUTEX_UNLOCK(gIPv6PoolMutex);
	    return;
	}
	i++;
    }
    MUTEX_UNLOCK(gIPv6PoolMutex);
}

static void
IPv6PoolAdd(const char *pool, struct in_addr prefix, uint32_t size)
{

    IPv6Pool 		p;
    struct ippool_rec	*r;
    int			i, j, k;
    int			total;
    
    MUTEX_LOCK(gIPv6PoolMutex);
    SLIST_FOREACH(p, &gIPv6Pools, next) {
	if (strcmp(p->name, pool) == 0)
	    break;
    }

    if (!p) {
	p = Malloc(MB_IPPOOL, sizeof(struct ipv6pool));
	strlcpy(p->name, pool, sizeof(p->name));
	SLIST_INSERT_HEAD(&gIPv6Pools, p, next);
    }
    total = 0;
    for (i = 0; i < p->size; i++) {
	if (p->pool[i].prefix)
	    total++;
    }
    r = Malloc(MB_IPPOOL, (total + c) * sizeof(struct ipv6pool_rec));
    if (p->pool != NULL) {
	memcpy(r, p->pool, p->size * sizeof(struct ipv6pool_rec));
	Freee(p->pool);
    }
    p->pool = r;
    k = p->size;
    for (i = 0; i < size; i++) {
	uint64_t curr_prefix = prefix + i;
	for (j = 0; j < p->size; j++) {
	    if (p->pool[j].prefix == curr_prefix)
		break;
	}
	if (j != p->size)
	    continue;
	p->pool[k++].prefix = curr_prefix;
    }
    p->size = k;
    MUTEX_UNLOCK(gIPv6PoolMutex);
}

/*
 * IPv6PoolStat()
 */

int
IPv6PoolStat(Context ctx, int ac, const char *const av[], const void *arg)
{
    IPv6Pool 	p;

    (void)ac;
    (void)av;
    (void)arg;

    Printf("Available IPv6 Prefix pools:\r\n");
    MUTEX_LOCK(gIPv6PoolMutex);
    SLIST_FOREACH(p, &gIPv6Pools, next) {
	int	i;
	int	total = 0;
	int	used = 0;
	for (i = 0; i < p->size; i++) {
	    if (p->pool[i].prefix) {
		total++;
		if (p->pool[i].used)
		    used++;
	    }
	}
	Printf("\t%s:\tused %4d of %4d\r\n", p->name, used, total);
    }
    MUTEX_UNLOCK(gIPv6PoolMutex);
    return(0);
}

/*
 * IPv6PoolSetCommand()
 * TODO: Change to IPv6
 */

static int
IPv6PoolSetCommand(Context ctx, int ac, const char *const av[], const void *arg)
{
    (void)ctx;
    switch ((intptr_t)arg) {
    case SET_ADD:
      {
	struct u_addr	begin;
	struct u_addr	end;

	/* Parse args */
	if (ac != 3
	    || !ParseAddr(av[1], &begin, ALLOW_IPV4)
	    || !ParseAddr(av[2], &end, ALLOW_IPV4))
	  return(-1);

	IPv6PoolAdd(av[0], begin.u.ip4, end.u.ip4);
      }
      break;
    default:
      assert(0);
  }
  return(0);
}

