[*mpdx User Manual*](README.md) **:** [*Introduction*](mpd1.md)
**:** *Overview*\
**Previous:** [*Introduction*](mpd1.md)\
**Next:** [*Organization of this manual*](mpd3.md)

------------------------------------------------------------------------

## 1.1. Overview

mpdx is a netgraph(4) based implementation of the multi-link PPP protocol
for FreeBSD. It is designed to be both fast and flexible as it handles
configuration and negotiation in user land, while routing all data
packets strictly in the kernel.

mpdx has unified support for many link types:

-   **modem** to connect using different asynchronous serial
    connections, including modems, ISDN terminal adapters, and
    null-modem. mpdx includes event-driven scripting language for modem
    identification, setup, manual server login, etc.
-   **pptp** to connect over the Internet using the Point-to-Point
    Tunneling Protocol (PPTP). This protocol is supported by the most
    OSes and hardware vendors.
-   **l2tp** to connect over the Internet using the Layer Two Tunneling
    Protocol (L2TP). L2TP is a PPTP successor supported with modern
    clients and servers.
-   **pppoe** to connect over an Ethernet port using the
    PPP-over-Ethernet (PPPoE) protocol. This protocol is often used by
    DSL providers.
-   **tcp** to tunnel PPP session over a TCP connection. Frames are
    encoded in the same was as asychronous serial connections.
-   **udp** to tunnel PPP session over a UDP connection. Each frame is
    encapsulated in a UDP datagram packet.
-   **ng** to connect using different devices supported by netgraph.
    Netgraph is highly modular kernel networking system, supporting
    synchronous serial connections, Cisco HDLC, Frame Relay, and other
    protocols.

It supports numerous PPP sub-protocols and extensions, such as:

-   Multi-link PPP
-   PAP, CHAP, MS-CHAP and EAP authentication
-   traffic compression (MPPC, Deflate, Predictor-1)
-   traffic encryption (MPPE, DESE, DESE-bis)
-   IPCP and IPV6CP parameter negotiation

Depending on configured rules and connection parameters mpd can operate
as usual PPP client/server or forward connection unmodified to other
host using any supported link type providing LAC/PAC/TSA functionality
for building distributed access networks.

mpdx also includes many additional features:

-   IPv4 and IPv6 support
-   Telnet and HTTP control interfaces.
-   Different authentication and accounting methods (RADIUS, PAM,
    script, file, \...)
-   NetFlow traffic accounting
-   Network address translation (NAT)
-   Dial-on-demand with idle timeout
-   Dynamic demand based link management (also known as \`\`rubber
    bandwidth\'\')
-   Powerful chat scripting language for asynchronous serial ports
-   Pre-tested chat scripts for several common modems and ISDN TAs
-   Clean device-type independent design
-   Comprehensive logging

mpdx is a fork of mpd5, the latter of whom was originally developed at Whistle
Communications, Inc. for use in the Whistle InterJet. The original mpd was
based on the original `iij-ppp` user-mode PPP code, although it was completely
rewritten since then. mpdx is now hosted on GitHub, and mpd5 at
[SourceForge](http://sourceforge.net/projects/mpd/).

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Introduction*](mpd1.md)
**:** *Overview*\
**Previous:** [*Introduction*](mpd1.md)\
**Next:** [*Organization of this manual*](mpd3.md)
