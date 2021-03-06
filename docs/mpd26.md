[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** *IPCP layer*\
**Previous:** [*MPPC protocol*](mpd25.md)\
**Next:** [*IPv6CP layer*](mpd27.md)

------------------------------------------------------------------------

## []{#26}4.7. IPCP layer[]{#ipcp}

This chapter describes commands that configure the IP Control Protocol
(IPCP) layer. To enable IPCP, `ipcp` option should be enabled at the
bundle layer. All of these commands apply to the currently active
bundle.

**`set ipcp ranges (local/width|ippool pool) (remote/width|ippool pool)`**

:   This command determines what IP addresses mpd will allow to be
    negotiated at the local and remote ends of the link. For each
    endpoint, we have a target address and a netmask width. The `width`
    determines how flexible we are, i.e., how close the actual
    negotiated address must be to the target address. A `width` of 32
    means they must match exactly; a `width` of zero means any address
    is suitable. For example, `192.168.1.17/25` means that IP address
    `192.168.1.17` is desired, but any IP address in the range
    `192.168.1.0` through `192.168.1.128` is acceptable.

    By convention, the `local` address may be `0.0.0.0` to request that
    the remote server assign us an IP address. Of course, for this to
    work the remote side must know *a priori* what our local IP address
    should be.

    The `remote` address should *not* be `0.0.0.0`. This is so if the
    peer requests `0.0.0.0`, we have some address to give him. The
    `width` may of course be zero.

    It is also possible to specify ippool name to use for assigning
    remote ip. In such case width 32 is assumed.

    If the two sides cannot agree on the IP address assignments after
    repeated negotiation attempts, then the connection will fail. This
    is manifested with the error message \`\`IPCP: not converging.\'\'

**`set ipcp dns primary [ secondary ]`**

:   Some PPP clients request DNS server information from their remote
    peer. This commands enables mpd to have an answer for any such
    clients. This command is especially useful for supplying information
    to PPTP clients. One or two DNS server IP addresses may be given. An
    address of `0.0.0.0` erases that entry.

**`set ipcp nbns primary [ secondary ]`**

:   Some Microsoft PPP clients request NetBIOS name server (NBNS)
    information from their remote peer. This commands enables mpd to
    have an answer for any such clients. This command is especially
    useful for supplying information to PPTP clients. One or two NBNS
    server IP addresses may be given. An address of `0.0.0.0` erases
    that entry.

**`set ipcp accept option ... `**

:   

**`set ipcp deny option ... `**

:   

**`set ipcp enable option ... `**

:   

**`set ipcp disable option ... `**

:   

**`set ipcp yes option ... `**

:   

**`set ipcp no option ... `**

:   These commands configure various IPCP options. The `vjcomp` option
    is *bi-directional* in that it can be independently enabled and
    disabled in each direction.

    The `enable` and `disable` commands determine whether we want the
    corresponding option. The `accept` and `deny` commands determine
    whether we will allow the peer to request the corresponding option.

    The **`yes`** command is the same as `enable` and `accept`. The
    **`no`** command is the same as `disable` and `deny`.

The options available at the IPCP layer are:

**`vjcomp`**

:   This option enables Van Jacobson TCP header compression, which saves
    several bytes per TCP data packet. You almost always want this
    option. This compression ineffective for TCP connections with
    enabled modern extensions like time stamping or SACK, which modify
    TCP options between sequential packets.

    Default `enable` and `accept`.

**`req-pri-dns `**

:   

**`req-sec-dns `**

:   

**`req-pri-nbns `**

:   

**`req-sec-nbns `**

:   Enabling these options causes mpd to request primary and/or
    secondary DNS and/or NBNS servers from the remote peer during
    negotiation.

    If any DNS servers are supplied by the peer, they will appear as
    parameters to the script specified by the `set iface up-script`
    command, if any.

    Currently, mpd does not use the NBNS values for anything; they just
    appear in the log. A future revision may actually do something with
    them.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** *IPCP layer*\
**Previous:** [*MPPC protocol*](mpd25.md)\
**Next:** [*IPv6CP layer*](mpd27.md)
