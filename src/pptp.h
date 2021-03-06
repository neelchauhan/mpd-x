
/*
 * pptp.h
 *
 * Written by Archie Cobbs <archie@freebsd.org>
 * Copyright (c) 1998-1999 Whistle Communications, Inc. All rights reserved.
 * See ``COPYRIGHT.whistle''
 */

#ifndef _PPTP_H_
#define	_PPTP_H_

#include "command.h"
#include "phys.h"
#include "ip.h"

/*
 * VARIABLES
 */

  extern const struct cmdtab	PptpSetCmds[];
  extern const struct phystype	gPptpPhysType;

  extern int		PptpsStat(Context ctx, int ac, const char *const av[], const void *arg);

#endif

