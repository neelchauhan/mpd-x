[*Mpd 5.9 User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *L2TP device type commands*\
**Previous:** [*PPTP device type commands*](mpd47.md)\
**Next:** [*PPPoE device type commands*](mpd49.md)

------------------------------------------------------------------------

## []{#48}5.6. L2TP device type commands[]{#l2tp}

This chapter describes commands that are specific to L2TP type links.
These commands apply to the currently active link, and are only valid if
the currently active link has type **l2tp**.

The L2TP protocol utilizes UDP datagrams on port 1701 (and this is the
default for `port` in the commands below) to create and maintain virtual
tunnel between IP peers. One or more independent PPP connections
(sessions) can be carried inside this tunnel.

Complete L2TP network topology looks like:

    client <- some link type -> LAC <- L2TP tunnel -> LNS

LAC is physical level repeater, which receives PPP connection of some
type and forwards it to LNS using L2TP protocol. LNS is a PPP endpoint,
which receives PPP frames via L2TP tunnel and processes them.

In simple case, when physical conversion is not required, topology can
be simplified to:

    client (LAC emulator) <- L2TP tunnel -> LNS

Mpd is able to operate in both LAC and LNS modes. As LAC mpd supports
both simple case LAC emulator and complete LAC topologies. Complete LAC
can be configured by joining two physical devices using mpd\'s repeater
functionality.

Windows L2TP client uses IPSec encryption for the additional tunnel
security. So, to let it connect you must configure IPSec on your MPD
router or disable IPSec on Windows by setting registry DWORD value
ProhibitIpSec at the key
HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\RasMan\\Parameters\\
into \"1\".

**`set l2tp self ipaddr [ port ]`**

:   Sets the local IP address and port for the L2TP connection. There is
    known implementation bug if this option is not set while accepting
    incoming connections on the router with multiple IPs and clients are
    connecting not to the nearest address of this router.

**`set l2tp peer ipaddr [ port ]`**

:   Sets the peer IP address and port for the L2TP connection. This
    command applies to both incoming and outgoing connections. For
    outgoing connections, this command is required in order to specify
    where to connect to. For incoming connections, this command is
    optional; if not given, mpd accepts incoming connections from any
    host. Otherwise, only connections from the stated IP address (and,
    optionally, port) are allowed.

**`set l2tp hostname name`**

:   Sets the L2TP tunnel local hostname. For server side, only one
    unique hostname supported for every pair of listening IP (set l2tp
    self \...) and peer ip (set l2tp peer \...). If several hostnames
    defined, only the first matching will be used for all incoming
    connections.

**`set l2tp pmask mask`**

:   Check peer hostname, related to wildcard `mask`. Wildcard can
    contain any shell-like mask, such as \"\*.myhost.com\" Peer can set
    self hostname with `set l2tp hostname` command.

**`set l2tp secret secret`**

:   Sets the L2TP tunnel secret. Used to authenticate tunnel connection
    and encrypt important control packets avpairs. For server side, only
    one unique secret supported for every pair of listening IP (set l2tp
    self \...) and peer ip (set l2tp peer \...). If several secrets
    defined, only the first matching will be used for all incoming
    connections.

    NOTE: This options is not related with usual PPP authentication.
    Windows client does not support tunnel authentication.

**`set l2tp callingnum number`**

:   

**`set l2tp callednum number`**

:   Sets the calling and called telephone number to use when initiating
    a L2TP connection. For most VPN applications this is ignored, but in
    certain cases an actual phone number is required. The default is the
    empty string.

**`set l2tp enable option ... `**

:   

**`set l2tp disable option ... `**

:   Enable and disable L2TP device type options for the link.

The following options are supported:

**`outcall`**

:   Inside L2TP tunnel, each individual PPP connection (there may be
    several), is initiated as either an incoming or an outgoing call.
    This allows to make an outgoing phone call (by LNS) via a remote
    access server (LAC), as well as in more common case forward an
    incoming phone call from an access server (LAC) to a remote L2TP
    server (LNS).

    When this option is enabled, mpd will initiate outgoing calls (LNS);
    otherwise mpd will initiate incoming calls (LAC).

    The default is disable.

**`hidden`**

:   When L2TP tunnel secret is configured it is possible hide (encrypt)
    some control data for additional protection.

    The default is disable.

**`length`**

:   By default L2TP uses header Length field for control packets, but
    not for data packets. This option enables Length field for data
    packets. This feature enabled may be useful on links where packets
    padding may happend. Disabling it reduces overhead by 2 bytes per
    packet.

    The default is disable.

**`dataseq`**

:   By default L2TP requires header sequence fields for control packets,
    but not require them for data packets. This option enables sequence
    fields for data packets. This feature enabled may be useful on links
    where packets reordering may happend but it is intolerable.
    Disabling it reduces overhead by 4 bytes per packet.

    The default is enable.

**`resolve-once`**

:   Enables resolving peer address only once, on startup, or on manual
    typing in CLI.

    The default is enable.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *L2TP device type commands*\
**Previous:** [*PPTP device type commands*](mpd47.md)\
**Next:** [*PPPoE device type commands*](mpd49.md)
