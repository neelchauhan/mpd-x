[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** *Bundle layer*\
**Previous:** [*EAP*](mpd21.html)\
**Next:** [*Encryption (ECP) layer*](mpd23.html)

------------------------------------------------------------------------

## []{#22}4.4. Bundle layer[]{#bundle}

This chapter describes commands that configure the bundle layer. All of
these commands (except **`new`**) apply to the currently active bundle,
i.e., the bundle shown at the command line prompt.

**`set bundle period seconds set bundle hiwat percent set bundle lowat percent set bundle min-con seconds set bundle min-dis seconds set bundle links link1 [ ... ]`**

:   These commands are only meaningful when bandwidth management is
    enabled. Mpd will attempt to bring up a new link from the list
    specified or take down an existing link when the utilization goes
    above `hiwat` or below `lowat` percent, respectively. The
    utilization is sampled every `period` divided by 6 points, and is
    averaged over the past `period` seconds.

    Mpd will not attempt to disconnect a link unless previous one was
    disconnected at least `min-dis` seconds before. Similarly, mpd will
    not open a link unless previous was opened at least `min-con`
    seconds before. These two parameters help prevent oscillations, but
    cause slower response time.

**`set bundle fsm-timeout seconds`**

:   This sets the finite state machine (FSM) retry interval for all
    FSM\'s on this bundle. This command should only be used in
    exceptional situations, such as doing PPP over high-latency
    satellite links. The default is 2 seconds.

**`set bundle accept option ... set bundle deny option ... set bundle enable option ... set bundle disable option ... set bundle yes option ... set bundle no option ...`**

:   These commands configure various bundle options. Most options are
    *bi-directional* in that they can be independently enabled and
    disabled in each direction.

    The `enable` and `disable` commands determine whether we want the
    corresponding option. The `accept` and `deny` commands determine
    whether we will allow the peer to request the corresponding option.

    The **`yes`** command is the same as `enable` and `accept`. The
    **`no`** command is the same as `disable` and `deny`.

The options available at the bundle layer are:

**`bw-manage`**

:   This command enables *bandwidth management*, in which mpd attempts
    to dynamically adjust the number of connected links depending on the
    traffic load.

    The proper functioning of bandwidth management depends on the
    correct latency and bandwidth information configured for each link;
    see the `set link latency` and `set link bandwidth` commands.

    The default for this option is off \-- mpd connects the links
    \`\`all or none.\'\'

**`round-robin`**

:   When multilink PPP is enabled and there are two or more links
    connected, this option enables round robin packet scheduling across
    the links. That is, instead of breaking each packet into fragments
    and delivering the individual fragments over all the links in the
    bundle, each packet is delivered whole over single link. The link is
    chosen by rotating in round-robin fashion over all the links in the
    bundle.

    This option normally would result in higher latency and possible
    delays due to TCP packets being received out of order; however, it
    may help in certain situations of high packet loss or broken peer
    equipment.

    The default is disable.

**`ipcp`**

:   Enable/Disable IPCP negotiation. For details see [the IPCP layer
    chapter](mpd26.html#ipcp).

    The default is enable.

**`ipv6cp`**

:   Enable/Disable IPV6CP negotiation.

    The default is disable.

**`compression`**

:   Enable/Disable CCP (Compression Control Protocol) negotiation. For
    details see [the compression layer chapter](mpd24.html#compression).

    The default is disable.

**`encryption`**

:   Enable/Disable ECP (Encryption Control Protocol) negotiation. For
    details see [the encryption layer chapter](mpd23.html#encryption).

    The default is disable.

**`crypt-reqd`**

:   Require encryption. When encryption support is compiled into mpd,
    this option causes mpd to drop the link if encryption cannot be
    successfully negotiated in both directions. This means in effect,
    \`\`use encryption or do not connect at all.\'\'

    The default is disable.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** *Bundle layer*\
**Previous:** [*EAP*](mpd21.html)\
**Next:** [*Encryption (ECP) layer*](mpd23.html)
