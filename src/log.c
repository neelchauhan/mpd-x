
/*
 * log.c
 *
 * Written by Toshiharu OHNO <tony-o@iij.ad.jp>
 * Copyright (c) 1993, Internet Initiative Japan, Inc. All rights reserved.
 * See ``COPYRIGHT.iij''
 * 
 * Rewritten by Archie Cobbs <archie@freebsd.org>
 * Copyright (c) 1995-1999 Whistle Communications, Inc. All rights reserved.
 * See ``COPYRIGHT.whistle''
 */

#include "ppp.h"
#ifdef SYSLOG_FACILITY
#include <syslog.h>
#endif

#include <pdel/sys/alog.h>

/*
 * DEFINITIONS
 */

  #define DUMP_BYTES_PER_LINE	16
  #define ROUNDUP(x,r)		(((x)%(r))?((x)+((r)-((x)%(r)))):(x))
  #define MAX_LOG_LINE		500

/* Log option descriptor */

  struct logopt
  {
    int		mask;
    const char	*name;
    const char	*desc;
  };

/*
 * GLOBAL VARIABLES
 */

  struct alog_config	gLogConf;

  int	gLogOptions = LG_DEFAULT_OPT | LG_ALWAYS;
#ifdef SYSLOG_FACILITY
  char	gSysLogIdent[32];
#endif

/*
 * INTERNAL VARIABLES
 */

#ifndef SYSLOG_FACILITY
  static FILE		*logfp = stderr;
#endif

  #define ADD_OPT(x,d)	{ LG_ ##x, #x, d },

  static struct logopt	LogOptionList[] =
  {
#ifdef LG_BUND
    ADD_OPT(BUND,	"Bundle events")
#endif
#ifdef LG_LINK
    ADD_OPT(LINK,	"Link events")
#endif
#ifdef LG_LCP
    ADD_OPT(LCP,	"LCP negotiation")
#endif
#ifdef LG_LCP2
    ADD_OPT(LCP2,	"LCP events and debugging")
#endif
#ifdef LG_AUTH
    ADD_OPT(AUTH,	"Link authentication events")
#endif
#ifdef LG_IPCP
    ADD_OPT(IPCP,	"IPCP negotiation")
#endif
#ifdef LG_IPCP2
    ADD_OPT(IPCP2,	"IPCP events and debugging")
#endif
#ifdef LG_IPV6CP
    ADD_OPT(IPV6CP,	"IPV6CP negotiation")
#endif
#ifdef LG_IPV6CP2
    ADD_OPT(IPV6CP2,	"IPV6CP events and debugging")
#endif
#ifdef LG_CCP
    ADD_OPT(CCP,	"CCP negotiation")
#endif
#ifdef LG_CCP2
    ADD_OPT(CCP2,	"CCP events and debugging")
#endif
#ifdef LG_CCP3
    ADD_OPT(CCP3,	"CCP complete packet dumps")
#endif
#ifdef LG_ECP
    ADD_OPT(ECP,	"ECP negotiation")
#endif
#ifdef LG_ECP2
    ADD_OPT(ECP2,	"ECP events and debugging")
#endif
#ifdef LG_FSM
    ADD_OPT(FSM,	"All FSM events (except echo & reset)")
#endif
#ifdef LG_ECHO
    ADD_OPT(ECHO,	"Echo/reply events for all automata")
#endif
#ifdef LG_PHYS
    ADD_OPT(PHYS,	"Physical layer events")
#endif
#ifdef LG_PHYS2
    ADD_OPT(PHYS2,	"Physical layer debug")
#endif
#ifdef LG_CHAT
    ADD_OPT(CHAT,	"Modem chat script")
#endif
#ifdef LG_CHAT2
    ADD_OPT(CHAT2,	"Chat script extra debugging output")
#endif
#ifdef LG_IFACE
    ADD_OPT(IFACE,	"IP interface and route management")
#endif
#ifdef LG_IFACE2
    ADD_OPT(IFACE2,	"IP interface and route management debug")
#endif
#ifdef LG_FRAME
    ADD_OPT(FRAME,	"Dump all incoming & outgoing frames")
#endif
#ifdef LG_PPTP
    ADD_OPT(PPTP,	"PPTP high level events")
#endif
#ifdef LG_PPTP2
    ADD_OPT(PPTP2,	"PPTP more detailed events")
#endif
#ifdef LG_PPTP3
    ADD_OPT(PPTP3,	"PPTP packet dumps")
#endif
#ifdef LG_RADIUS
    ADD_OPT(RADIUS,	"Radius authentication events")
#endif
#ifdef LG_RADIUS2
    ADD_OPT(RADIUS2,	"Radius authentication debug")
#endif
#ifdef LG_CONSOLE
    ADD_OPT(CONSOLE,	"Console events")
#endif
  };

  #define NUM_LOG_LEVELS (sizeof(LogOptionList) / sizeof(*LogOptionList))

/*
 * INTERNAL FUNCTIONS
 */

#ifndef SYSLOG_FACILITY
  static void	LogTimeStamp(int (*func)(const char *fmt, ...));
#else
  #define LogTimeStamp(c)	do{}while(0)
#endif

/*
 * LogOpen()
 */

int
LogOpen(void)
{
  memset(&gLogConf, 0, sizeof(gLogConf));
  if (!*gSysLogIdent)
    strcpy(gSysLogIdent, "mpd");
#ifdef SYSLOG_FACILITY
  gLogConf.name = gSysLogIdent;
  gLogConf.facility = alog_facility_name(SYSLOG_FACILITY);
  gLogConf.min_severity = LOG_INFO;
#else
  gLogConf.path = LG_FILE;
#endif

  if (alog_configure(0, &gLogConf) == -1) {
    warn("mpd: alog_configure failed");
    return(-1);
  }
  alog_set_channel(0);
  return(0);
}

/*
 * LogClose()
 */

void
LogClose(void)
{
  alog_shutdown(0);
}

/*
 * LogCommand()
 */

int
LogCommand(int ac, char *av[], void *arg)
{
  int	k, bits, add;

  if (ac == 0)
  {
    #define LG_FMT	"    %-12s  %-10s  %s\r\n"

    Printf(LG_FMT, "Log Option", "Enabled", "Description\r\n");
    Printf(LG_FMT, "----------", "-------", "-----------\r\n");
    for (k = 0; k < NUM_LOG_LEVELS; k++)
    {
      int	j;
      char	buf[100];

      snprintf(buf, sizeof(buf), "%s", LogOptionList[k].desc);
      for (j = 0; buf[j]; j++)
	buf[j] = tolower(buf[j]);
      Printf("  " LG_FMT, LogOptionList[k].name,
	(gLogOptions & LogOptionList[k].mask) ? "Yes" : "No", buf);
    }
    return(0);
  }

  while (ac--)
  {
    switch (**av)
    {
      case '+':
	(*av)++;
      default:
	add = TRUE;
	break;
      case '-':
	add = FALSE;
	(*av)++;
	break;
    }
    for (k = 0;
      k < NUM_LOG_LEVELS && strcasecmp(*av, LogOptionList[k].name);
      k++);
    if (k < NUM_LOG_LEVELS)
      bits = LogOptionList[k].mask;
    else
    {
      if (!strcasecmp(*av, "all"))
      {
	for (bits = k = 0; k < NUM_LOG_LEVELS; k++)
	  bits |= LogOptionList[k].mask;
      }
      else
      {
	Printf("\"%s\" is unknown. Enter \"log\" for list.\r\n", *av);
	bits = 0;
      }
    }
    if (add)
      gLogOptions |= bits;
    else
      gLogOptions &= ~bits;
    av++;
  }
  return(0);
}

/*
 * LogPrintf()
 *
 * The way to print something to the log
 */

void
LogPrintf(const char *fmt, ...)
{
  va_list       args;

  va_start(args, fmt);
  vLogPrintf(fmt, args);
  va_end(args);
}

void
vLogPrintf(const char *fmt, va_list args)
{
  char		buf[MAX_CONSOLE_BUF_LEN];
  va_list       args2;

  LogTimeStamp(logprintf);
#if (__FreeBSD_version >= 500000)
  va_copy(args2,args);
  valog(LOG_INFO, fmt, args);
  vsnprintf(buf, sizeof(buf), fmt, args2);
  va_end(args2);
#else
  valog(LOG_INFO, fmt, args);
  vsnprintf(buf, sizeof(buf), fmt, args);
#endif

  if (!gBackground)
  {
    fputs(buf, stdout);
    fputc('\n', stdout);
    fflush(stdout);
  } 

  // Console is not thread safe! 
  // Do not call it in a different thread!
  if (EventIsCtxThread()) 
  {
    if (gConsoleSession) {
	gConsoleSession->write(gConsoleSession, "%s\r\n", buf);
    
    } else {
	struct ghash_walk	walk;
	ConsoleSession	s;

	ghash_walk_init(gConsole.sessions, &walk);
	while ((s = ghash_walk_next(gConsole.sessions, &walk)) !=  NULL)
          if (Enabled(&s->options, CONSOLE_LOGGING))
	    s->write(s, "%s\r\n", buf);
    }
  }
}

/*
 * LogStdout()
 *
 * Print something to the console.
 */

void
LogStdout(const char *fmt, ...)
{
  va_list	args;

  va_start(args, fmt);
  vfprintf(stdout, fmt, args);
  putc('\n', stdout);
  fflush(stdout);
  va_end(args);
}

/*
 * LogDumpBp()
 *
 * Dump the contents of an Mbuf to the log
 */

void
LogDumpBp(int level, Mbuf bp, const char *fmt, ...)
{
  int		k, total;
  u_char	bytes[DUMP_BYTES_PER_LINE];
  char		line[256];
  int		linelen;
  va_list	ap;

  if (level & gLogOptions) {
/* Do header */

    va_start(ap, fmt);
    vLogPrintf(fmt, ap);
    va_end(ap);

/* Do data */

    line[0]=' ';
    line[1]=' ';
    line[2]=' ';
    line[3]=0;
    linelen=3;
  
    for (total = 0; bp; bp = bp->next)
    {
      int	start, stop, last = 0;

      stop = bp->next ? total + bp->cnt :
		ROUNDUP(total + bp->cnt, DUMP_BYTES_PER_LINE);
      for (start = total; total < stop; )
      {
        u_int	const byte = (MBDATA(bp))[total - start];

        if (total < start + bp->cnt)
        {
	  sprintf(line+linelen, " %02x", byte);
	  last = total % DUMP_BYTES_PER_LINE;
        }
        else
	  sprintf(line+linelen, "   ");
        linelen+=3;
      
        bytes[total % DUMP_BYTES_PER_LINE] = byte;
        total++;
      
        if (total % DUMP_BYTES_PER_LINE == 0)
        {
	  snprintf(line+linelen, sizeof(line), "  ");
          linelen+=2;
	  for (k = 0; k <= last; k++) {
	    line[linelen++] = isgraph(bytes[k]) ? bytes[k] : '.';
	    line[linelen] = 0;
	  }
	  LogPrintf("%s",line);
	  line[0]=' ';
	  line[1]=' ';
	  line[2]=' ';
	  line[3]=0;
	  linelen=3;
        }
      }
    }
  }
}

/*
 * LogDumpBuf()
 *
 * Dump the contents of a buffer to the log
 */

void
LogDumpBuf(int level, const u_char *buf, int count, const char *fmt, ...)
{
  int		k, stop, total;
  char		line[256];
  int		linelen;
  va_list	ap;

  if (level & gLogOptions) {
/* Do header */

    va_start(ap, fmt);
    vLogPrintf(fmt, ap);
    va_end(ap);

/* Do data */

    line[0]=' ';
    line[1]=' ';
    line[2]=' ';
    line[3]=0;
    linelen=3;

    stop = ROUNDUP(count, DUMP_BYTES_PER_LINE);
    for (total = 0; total < stop; )
    {
	if (total < count)
	    sprintf(line+linelen, " %02x", buf[total]);
	else
	    sprintf(line+linelen, "   ");
        linelen+=3;
	total++;
	if (total % DUMP_BYTES_PER_LINE == 0)
	{
	    snprintf(line+linelen, sizeof(line), "  ");
    	    linelen+=2;
    	    for (k = total - DUMP_BYTES_PER_LINE; k < total && k < count; k++) {
		line[linelen++] = isgraph(buf[k]) ? buf[k] : '.';
		line[linelen] = 0;
	    }
	    LogPrintf("%s",line);
	    line[0]=' ';
	    line[1]=' ';
	    line[2]=' ';
	    line[3]=0;
	    linelen=3;
	}
    }
  }
}

#ifndef SYSLOG_FACILITY

/*
 * LogTimeStamp()
 *
 * Print a timestamp
 */

static void
LogTimeStamp(int (*func)(const char *fmt, ...))
{
  struct tm	*ptm;
  time_t	now;

  now = time(NULL);
  ptm = localtime(&now);
  (*func)("%02d-%02d %02d:%02d:%02d ",
    ptm->tm_mon + 1, ptm->tm_mday,
    ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
}

#endif

/*
 * Perror()
 */

void
Perror(const char *fmt, ...)
{
  va_list	args;
  char		buf[200];

  snprintf(buf, sizeof(buf), "mpd: ");
  va_start(args, fmt);
  vsnprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), fmt, args);
  va_end(args);
  snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf),
    ": %s", strerror(errno));
  Log(LG_ERR, ("%s", buf));
}
