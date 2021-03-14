[*mpdx User Manual*](README.md) **:** [*Troubleshooting*](mpd62.md)
**:** *Troubleshooting*\
**Previous:** [*Troubleshooting*](mpd62.md)\
**Next:** [*Internals*](mpd64.md)

------------------------------------------------------------------------

## 7.1. Troubleshooting

Some tips for troubleshooting.

For further help, ask to the `freebsd-net@freebsd.org` mailing list or
sourceforge.net mpd project forum.

****It does not work and I do not understand why.****

:   mpdx has extensive logging system supporting syslog. To direct logs
    into a file add lines

        !mpd
        *.*                                             /var/log/mpd.log

    into your /etc/syslog.conf file, create /var/log/mpd.log file and
    send SIGHUP to syslogd to reread config.

    To enable all possible logging you can use \'log +all\' command.

****Packets won\'t flow.****

:   Make sure you have set `gateway_enable="YES"` in `/etc/rc.conf`,
    otherwise your FreeBSD box will not route packets.

    Also, check your firewall settings. mpdx will create new interfaces
    which may need to be incorporated into your firewall rules. If
    you\'re doing PPTP, you need to allow TCP port 1723 and IP protocol
    47 (GRE).

****It does not work and there are strange netgraph-related errors in the log.****

:   Make sure you have all the required netgraph KLD\'s loaded. You can
    check them by doing ` kldstat -v | grep ng_ `.

    Usually these are loaded on demand. If not, you can load them
    manually using `kldload(8)`.

    The following node types are or may be needed:

    -   `ng_async`
    -   `ng_bpf`
    -   `ng_car`
    -   `ng_deflate`
    -   `ng_ether`
    -   `ng_iface`
    -   `ng_ksocket`
    -   `ng_l2tp`
    -   `ng_mppc`
    -   `ng_ppp`
    -   `ng_pppoe`
    -   `ng_pptpgre`
    -   `ng_nat`
    -   `ng_netflow`
    -   `ng_pred1`
    -   `ng_socket`
    -   `ng_tcpmss`
    -   `ng_tee`
    -   `ng_tty`
    -   `ng_vjc`

****My configuration does not seem to be working as expected.****

:   Make sure your `mpd.conf` file formatted properly. Labels must be
    left-justified, while other lines must not.

****I am getting no valid response from the RADIUS server.****

:   Double-check the shared secret in the RADIUS servers config and the
    one specified in `mpd.conf` or `radius.conf`. Check the ports of the
    RADIUS server: they should be 1812 (authentication) and 1813
    (accounting), wich are also the default ports of mpd. In the past
    unofficial port numbers (1645 and 1646) were used for RADIUS, but
    these are deprecated.

****I am getting \`\`Operation not permitted\'\' errors trying to run mpd.****

:   This is often caused by a combination of (a) using netgraph in KLD
    module form instead of statically compiling the various modules into
    the kernel via kernel `config(8)` options, and (b) increasing your
    kernel security level (see the `init(8)` man page), which prevents
    KLD modules from being loaded. Change one of these things to fix the
    problem.

****I have configured a link for dial-in and sometimes after disconnecting mpd gets into some kind of infinite loop.****

:   This is because mpd is trying to \`\`redial\'\' which of course is
    not appropriate for dial-in links. Use `set link max-redial -1` and
    `set bundle yes noretry` to disable the redial function.

****I use mpd as PPTP server for Windows XP clients. While accessing bigger websites or listing larger ftp directories the connection seems to hang.****

:   Windows XP insists on a very low MTU (usually 1396 Bytes). This
    needs fragmentation if bigger packets should be transmitted over the
    link. Fragmentation is negotiated at ICMP level. If there is a bad
    router somewhere in the network dropping such packets then the
    connection hangs. The first thing what you can try is reducing
    mpd\'s MTU value, by setting: `set link mtu 1300` and
    `set bundle disable multilink`, this should help in most cases. For
    TCP connections it is possible enabling the TCP-MSS-Fix:
    `set iface enable tcpmssfix`.

****Problems with MPPE stateless when connecting to Cisco devices.****

:   Upgrade the IOS of your device, see:
    `CSCdu30944  MPPE rejects stateless        Fixed in 12.3(11.4)`

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Troubleshooting*](mpd62.md)
**:** *Troubleshooting*\
**Previous:** [*Troubleshooting*](mpd62.md)\
**Next:** [*Internals*](mpd64.md)
