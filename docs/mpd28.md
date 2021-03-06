[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** *Interface layer*\
**Previous:** [*IPv6CP layer*](mpd27.md)\
**Next:** [*Authentication, Authorization and Accounting
(AAA)*](mpd29.md)

------------------------------------------------------------------------

## []{#28}4.9. Interface layer[]{#interface}

This chapter describes commands that configure the interface layer. All
of these commands apply to the currently active bundle.

Note that while most of the time mpd is used for transmitting IP
traffic, it is designed to support other (currently unimplemented)
protocols such as AppleTalk, IPX, etc. This is why the Interface layer
(which is protocol independent) is distinct from the [IP Control
Protocol (IPCP) layer](mpd26.md#ipcp) which is specific to IP.

**`set iface name [ name ]`**

:   This command changes interface name from default ngX to specified
    one. If name argument is not specified, original ngX name is
    restored. Note that inside Netgraph original ngX name is always
    used.

**`set iface description [ description ]`**

:   This command changes interface description.

    Template may contain conversion specifications:

        %% expands to single % sign;
        %a for interface local address;
        %A for peer local address;
        %i for system interface index;
        %I for interface name;
        %l for name of bundle's first link
        %M for peer MAC address of bundle's first link
        %o for local outer ("physical") address of bundle's first link
        %O for peer outer ("physical") address of bundle's first link
        %P for peer outer ("physical") port of bundle's first link
        %S for interface status (DoD/UP/DOWN)
        %t for type of bundle's first link (pppoe, pptp, l2tp etc.)
        %u for self auth name (or dash if self auth name not used)
        %U for peer auth name (or dash if peer has not authenticated)

**`set iface group [ group ]`**

:   This command add interface to specific group.

**`set iface addrs [!]local-ip [!]remote-ip`**

:   This command is usually required when dial-on-demand is enabled.
    Normally, mpd configures the interface with the IP addresses that
    were negotiated when connecting the link. Since dial-on-demand
    configures the interface before actually connecting, mpd has to be
    told initial local and remote IP addresses to give the interface.
    These addresses do not have to correspond to the \`\`real\'\' ones;
    in fact, both addresses can be completely fictional. If and when
    different addresses are negotiated later, mpd will automatically
    renumber the interface and adjust the routes.

    Also this command may be used to force specified addresses usage
    instead of negotiated ones. It may be useful in some specific cases,
    for example, to avoid routing loop with misconfigured PPTP server.
    In such case \'!\' mark specifies IPs to be forced.

**`set iface route address[/width]`**

:   This command associates a route with the bundle. Whenever the
    interface is configured up, all associated routes are added. A route
    of `default` indicates the default route. Otherwise, the route is a
    network address with optional netmask width (e.g.,
    `192.168.1.0/24`). If the netmask width is omitted, a single host
    route is assumed (i.e., a width of 32).

    Routes are automatically removed when the interface is brought down.

**`set iface mtu value [ override ]`**

:   Without optional keyword `override`, this command sets an upper
    bound on the MTU that will be configured on the interface when the
    bundle comes up. This value is not used at all during link
    negotiation; there are separate bundle and link commands for
    configuring that. Even if a higher bundle MTU is negotiated, this
    limit will still apply.

    This command is useful when you want to manually restrict the MTU of
    the interface for other reasons, e.g., if you\'re also doing IPSec.

    The default is 1500.

    Optional keyword `override` allows you to override the result of
    link negotiation and set interface MTU to specified value. Such
    override can violate RFC 1661, so use with caution and at your own
    risk. This is useful when you deal with broken PPP peer negotiating
    too low value while higher MTU is known to work.

**`set iface idle seconds`**

:   Sets the idle timeout value for the bundle. If no incoming or
    outgoing packets are transmitted for `seconds` seconds, the
    connection is brought down. An idle timeout of zero disables this
    feature.

    When the idle timeout occurs, if the dial-on-demand option is
    enabled, mpd goes back into dial-on-demand mode. Otherwise, the
    interface is brought down and all associated routes removed.

    The default is 0.

**`set iface session seconds`**

:   Sets the session timeout value for the bundle. An session timeout of
    zero disables this feature.

    The default is 0.

**`set iface up-script script `**

:   

**`set iface down-script script `**

:   Mpd can optionally run a user program every time one of network
    protocols (IPCP/IPv6CP) at the interface is brought up or down. The
    `up-script` is called like this:

    > ` script interface proto local-ip remote-ip authname [ dns1 server-ip ] [ dns2 server-ip ] peer-address`

    If up-script exit status is not 0, mpd will kill respective
    protocol.

    The `down-script` is called like this:

    > ` script interface proto local-ip remote-ip authname peer-address`

**`set iface enable option ... set iface disable option ...`**

:   Enable and disable the various interface layer options for the
    bundle.

The options available at the interface layer are:

**`on-demand`**

:   This option causes the interface to operate in dial-on-demand mode,
    allowing you to have a \`\`virtual full time\'\' connection. An OPEN
    event causes the interface to be configured, but the actual
    connection of the link is delayed until qualifying outgoing traffic
    is detected. Moreover, after an idle timeout, the interface is not
    brought down; further traffic will bring the link back up again.

    The default is disable.

**`proxy-arp`**

:   When this option is enabled, if after link negotiation the peer\'s
    IP address is determined to lie on a local subnet, then mpd will
    arrange for the local machine to install a proxy ARP entry for the
    remote machine\'s IP address.

    For example, suppose the local machine lies on a LAN with address
    192.168.1.10, and another machine will be connecting via mpd and
    using the LAN address 192.168.1.20. Then these commands would set up
    proxy ARP for the remote machine:

    > ` set iface enable proxy-arp set ipcp ranges 192.168.1.10/32 192.168.1.20/32`

    The default is disable.

**`keep-timeout`**

:   When this option is enabled, we are not clear \`\`session
    timeout\'\' counter. This is useful together with CoA requests.

    The default is disable.

**`tcpmssfix`**

:   This option causes mpd to adjust incoming and outgoing TCP SYN
    segments so that the requested maximum segment size is not greater
    than the amount allowed by the interface MTU.

    This is necessary in many setups to avoid problems caused by routers
    that drop ICMP Datagram Too Big messages. Without these messages,
    the originating machine sends data, it passes the rogue router then
    hits a machine that has an MTU that is not big enough for the data.
    Because the IP Don\'t Fragment option is set, this machine sends an
    ICMP Datagram Too Big message back to the originator and drops the
    packet. The rogue router drops the ICMP message and the originator
    never gets to discover that it must reduce the fragment size or drop
    the IP Don\'t Fragment option from its outgoing data.

    The code is based on tcpmssd wich was written by Ruslan Ermilov
    <%3Cru@FreeBSD.org%3E> based on work done by Patrick Bihan-Faou
    <%3Cpatrick@mindstep.com%3E>.

    The default is disable.

**`tee`**

:   If enabled, a ng_tee(4) node will be inserted into the bundle graph,
    right after the interface node. The tee node can be useful for
    debugging or traffic accounting.

    The default is disable.

**`nat`**

:   Enable NAT for this bundle. See [the NAT chapter](mpd39.md#nat)
    for more information.

    The default is disable.

**`netflow-in`**

:   

**`netflow-out`**

:   

**`netflow-once`**

:   If enabled, the bundle will participate in NetFlow generation. See
    [the NetFlow chapter](mpd34.md#netflow) for more information. The
    netflow-out option is like netflow-in, but generates NetFlow data
    for outgoing packets instead of incoming. If netflow-once enabled -
    packet will be accounted only once while in kernel.

    The default is disable.

**`ipacct`**

:   If enabled, the bundle will participate in IP accounting with
    ng_ipacct node. See [the IP Accounting chapter](mpd35.md#ipacct)
    for more information.

    The default is disable.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** *Interface layer*\
**Previous:** [*IPv6CP layer*](mpd27.md)\
**Next:** [*Authentication, Authorization and Accounting
(AAA)*](mpd29.md)
