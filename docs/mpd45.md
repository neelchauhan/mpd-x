[*Mpd 5.9 User Manual*](mpd.html) **:** [*Device Types*](mpd42.html)
**:** *TCP device type commands*\
**Previous:** [*Netgraph device type commands*](mpd44.html)\
**Next:** [*UDP device type commands*](mpd46.html)

------------------------------------------------------------------------

## []{#45}5.3. TCP device type commands[]{#tcp}

This chapter describes commands that are specific to TCP type links.
These commands apply to the currently active link, and are only valid if
the currently active link has type **tcp**.

Due to limitations of ng_ksocket module this device type have two
issues:

-   when there are no free incoming link, new connection will anyway be
    acceped and then dropped instead of not accepting it,
-   tcp connection status is not monitored, so you should use \'set link
    keep-alive\' to detect broken links.

**`set tcp self ipaddr [ port ]`**

:   Sets the local IP address and port for the TCP connection. Port
    field is required for accepting incoming connections.

**`set tcp peer ipaddr [ port ]`**

:   Sets the peer IP address and port for the TCP connection. Address
    and port fields are required for outgoing connections. For incoming
    connections it is not required, but can limit who can connect to us.

The following options are supported:

**`resolve-once`**

:   Enables resolving peer address only once, on startup, or on manual
    typing in CLI.

    The default is enable.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Device Types*](mpd42.html)
**:** *TCP device type commands*\
**Previous:** [*Netgraph device type commands*](mpd44.html)\
**Next:** [*UDP device type commands*](mpd46.html)
