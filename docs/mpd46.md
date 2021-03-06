[*Mpd 5.9 User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *UDP device type commands*\
**Previous:** [*TCP device type commands*](mpd45.md)\
**Next:** [*PPTP device type commands*](mpd47.md)

------------------------------------------------------------------------

## []{#46}5.4. UDP device type commands[]{#udp}

This chapter describes commands that are specific to UDP type links.
These commands apply to the currently active link, and are only valid if
the currently active link has type **udp**.

It is suggested that the `set iface mtu` command be used when this link
type is in use to avoid IP fragmentation if you want to get something
better channel utilization.

**Note:** Technically this device type is not completely correct,
because PPP links are not allowed to re-order frames, yet UDP packets
can be delivered out of order. Therefore, if you use this link type you
should not enable multi-link PPP, PPP encryption, or PPP compression.
Otherwise, out of order frames will be dropped, leading to performance
degradation.

**`set udp self ipaddr [ port ]`**

:   Sets the local IP address and port for the UDP connection. If none
    is specified, any suitable local IP address is used. Port
    specification is required for incoming connection accepting.

**`set udp peer ipaddr [ port ]`**

:   Sets the peer IP address and port for the UDP connection. Address
    and port specification is required for connection originating. For
    incoming connections it is not required, but can limit who can
    connect to us.

The following options are supported:

**`resolve-once`**

:   Enables resolving peer address only once, on startup, or on manual
    typing in CLI.

    The default is enable.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *UDP device type commands*\
**Previous:** [*TCP device type commands*](mpd45.md)\
**Next:** [*PPTP device type commands*](mpd47.md)
