[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** *Mpd Layers*\
**Previous:** [*General mpd commands*](mpd18.html)\
**Next:** [*Link layer*](mpd20.html)

------------------------------------------------------------------------

## []{#19}4.2. Mpd Layers[]{#layers}

Mpd consists of several **layers**, corresponding to the layered nature
of the PPP protocol. There are two types of layers hierarchy connected
with two different operation modes as \"ppp terminator\" and \"ppp
repeater\". Operation mode is getting chosen dynamically depending on
link configuration and user auth name (see \'set link action \...\'
command).

In \"ppp terminator\" mode such hierarchy used:
**[Interface](mpd28.html#interface)** -\> **[NCPs](mpd26.html#ipcp)**
-\> **[Compression](mpd24.html#compression)** -\>
**[Encryption](mpd23.html#encryption)** -\>
**[Bundle](mpd22.html#bundle)** -\> **[Links](mpd20.html#links)**

In \"ppp repeater\" mode different hierarchy used:
**[Link1](mpd20.html#links)** -\> **Repeater** -\>
**[Link2](mpd20.html#links)**

A **[link](mpd20.html#links)** is a single point-to-point connection
between the local machine and a remote peer machine, implemented by some
kind of physical device, such as a serial modem connection or a virtual
PPTP connection.

Link parameters include whether authentication is enabled in either
direction, the authentication type (PAP or CHAP) used, keep-alive
packets, multilink negotiation options and various other link specific
parameters.

Lower half of the link layer is the physical devices layer.
Configuration of device type specific parameters happens at this layer.
Each device has a specific *type* corresponding to one of the supported
device types in mpd. The type dictates how the device dependent part is
configured and what it\'s capabilities are.

A **[bundle](mpd22.html#bundle)** is a collection of one or more links,
all connecting to the same remote peer, that together form a single
multi-link PPP connection whose effective bandwidth is the sum of the
bandwidths of the individual links.

The bundle layer in effect lies just above the link layer. The bundle
layer handles the task of making multiple physical links appear as a
single virtual link.

At the bundle layer you configure multi-link PPP settings and the link
management policy. The link management policy determines whether mpd
tries to keep all the links connected all the time, or whether it adds
and subtracts links depending on demand, and if so, according to what
parameters.

With each bundle is a corresponding
**[interface](mpd28.html#interface)** layer, which corresponds directly
to a system network interface accessible via `ifconfig(8)`, such as
`ng0`. The interface layer handles configuring the interface, bringing
it up or down as appropriate, assigning IP addresses, setting up static
routes and configuring proxy-ARP. The interface layer is also
responsible for implementing Dial-on-Demand and idle timeout
functionality.

Each bundle has several corresponding NCP layers as **[IP Control
Protocol (IPCP)](mpd26.html#ipcp)** and **[IPv6 Control Protocol
(IPv6CP)](mpd27.html#ipv6cp)**, which manages the protocol specific
configuration of the interface. This layers handle the negotiation of
local and remote addresses and TCP header compression, as well as other
optional IP related information such as DNS servers and NBNS servers.

Each bundle also has corresponding **[compression
(CCP)](mpd24.html#compression)** and **[encryption
(ECP)](mpd23.html#encryption)** layers, which allow you to enable and
configure compression and encryption for data sent and received over the
bundle.

A **repeater** is a collection of two physical devices (links). It is
getting created when there is need to forward connection coming from one
physical device to another without modification. This technology is also
known as LAC (L2TP Access Concentrator) and PAC (PPTP Access
Concentrator).

While the combination of all the various layers presents a large number
of configuration options, mpd tries to have reasonable defaults for
everything.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** *Mpd Layers*\
**Previous:** [*General mpd commands*](mpd18.html)\
**Next:** [*Link layer*](mpd20.html)
