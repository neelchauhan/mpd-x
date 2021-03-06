[*mpdx User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *PPTP device type commands*\
**Previous:** [*UDP device type commands*](mpd46.md)\
**Next:** [*L2TP device type commands*](mpd48.md)

------------------------------------------------------------------------

## []{#47}5.5. PPTP device type commands[]{#pptp}

This chapter describes commands that are specific to PPTP type links.
These commands apply to the currently active link, and are only valid if
the currently active link has type **pptp**.

The PPTP protocol can be most easily understood as just another link
layer type, where the link layer medium just happens to be an IP
connection. So, for example, instead of configuring a telephone number
to dial as you would with a modem, you configure an IP address to
connect to. Everything else that\'s above the link layer functions
exactly the same. Hence PPTP allows you to \`\`tunnel\'\' PPP frames
over IP.

Note that PPTP connections are initiated by a TCP connection from one
machine to another, and that servers usually listen to TCP port 1723
(and this is the default for `port` in the commands below). PPTP also
uses the GRE protocol, which has IP protocol number 47. Your firewall
may need to be adjusted to allows this type of IP packet.

Complete PPTP network topology looks like:

    client <- some link type -> PAC <- PPTP tunnel -> PNS

PAC is physical level repeater, which receives PPP connection of some
type and forwards it to PNS using PPTP protocol. PNS is a PPP endpoint,
which receives PPP frames via PPTP tunnel and processes them.

In simple case, when physical conversion is not required, topology can
be simplified to:

    client (PAC emulator) <- PPTP tunnel -> PNS

mpdx is able to operate in both PAC and PNS modes. As PAC mpd supports
both simple case PAC emulator and complete PAC topologies. Complete PAC
can be configured by joining two physical devices using mpd\'s repeater
functionality.

**`set pptp self ipaddr [ port ]`**

:   Sets the local IP address and port for the PPTP connection.

**`set pptp peer ipaddr [ port ]`**

:   Sets the peer IP address and port for the PPTP connection. This
    command applies to both incoming and outgoing connections. For
    outgoing connections, this command is required in order to specify
    where to connect to. For incoming connections, this command is
    optional; if not given, mpd accepts incoming connections from any
    host. Otherwise, only connections from the stated IP address (and,
    optionally, port) are allowed.

**`set pptp callingnum number`**

:   

**`set pptp callednum number`**

:   Sets the calling and called telephone number to use when initiating
    a PPTP connection. For most VPN applications this is ignored, but in
    certain cases an actual phone number is required. The default is the
    empty string.

**`set pptp enable option ... `**

:   

**`set pptp disable option ... `**

:   Enable and disable PPTP device type options for the link.

The following options are supported:

**`outcall`**

:   In PPTP, each individual PPP connection between two IP hosts (there
    may be several, and these are not to be confused with the *single*
    TCP connection between any two IP hosts), is initiated as either an
    incoming or an outgoing call. This allows to make an outgoing phone
    call (by PNS) via a remote access server (PAC), as well as in more
    common case forward an incoming phone call from an access server
    (PAC) to a remote PPTP server (PNS).

    When this option is enabled, mpd will initiate outgoing calls (PNS);
    otherwise mpd will initiate incoming calls (PAC). Although it seems
    that incoming would be more correct, the default is outgoing, as
    this is consistent with the behavior of the Microsoft PPTP dial-up
    adapter client.

    mpdx will accept either type of call on an incoming PPTP connection.

**`delayed-ack`**

:   Enable delayed ACK\'s. This can improve throughput on reliable
    links.

    The default is enable.

**`always-ack`**

:   Always include ACK even if already sent. This can improve throughput
    on unreliable links.

    The default is disable.

**`windowing`**

:   Enables the windowing mechanism specified by the protocol. Disabling
    this will cause mpdx to violate the protocol, possibly confusing some
    PPTP peers, but usually results in better performance. The windowing
    mechanism is a design error in the PPTP protocol; L2TP, the
    successor to PPTP, removes it.

    The default is disable.

**`resolve-once`**

:   Enables resolving peer address only once, on startup, or on manual
    typing in CLI.

    The default is enable.

Note that if you are connecting to an NT server, your authentication
name must include the NT domain name. For example:

> ``
>
>         set auth authname "DOMAIN\\username"

For updating Windows 95 and 98 clients so they work properly, see [VPN
Update for Windows 98 and Dial-Up Networking 1.3
Available](http://support.microsoft.com/default.aspx?scid=KB;EN-US;Q191540)

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *PPTP device type commands*\
**Previous:** [*UDP device type commands*](mpd46.md)\
**Next:** [*L2TP device type commands*](mpd48.md)
