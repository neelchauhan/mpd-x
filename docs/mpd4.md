[*mpdx User Manual*](README.md) **:** [*Introduction*](mpd1.md)
**:** *Change history*\
**Previous:** [*Organization of this manual*](mpd3.md)\
**Next:** [*Installation*](mpd5.md)

------------------------------------------------------------------------

## 1.3. Change history

Changes since version 5.8:

-   New features:
    -   Added new option \`override\` for the command \`set iface mtu\`.
-   Changes:
    -   Improve compatibility with new implementation of ipfw tables for
        FreeBSD versions when ipfw table delete command takes list of
        addresses.
    -   Use only 64-bit counters on modern FreeBSD.
-   Bugfixes:
    -   Properly clean console mutex lock in case of thread cancellation
        to prevent deadlock.
    -   Fix buffer overflow introduced in version 5.8: processing of
        template %aX in a RADIUS authentication response might lead to
        unexpected termination of the mpd5 process. Installations not
        using RADIUS or not using %aX templates in RADIUS attributes
        were not affected.
    -   LCP negotiation fixed for rare case of remote peer restarting it
        when in phase AUTHENTICATE or NETWORK.
    -   Fix buffer overflow in parsing of L2TP control packets
        introduced in version 4.0 that initially brought in L2TP
        support: a specially crafted incoming L2TP control packet might
        lead to unexpected termination of the process. Installations not
        using L2TP clients nor L2TP server configuration were not
        affected.

Changes since version 5.7:

-   New features:
    -   Added JSON format output into the web console.
    -   Added \`set l2tp pmask \...\` command.
    -   Added \`set pppoe mac-format \...\` command.
    -   Added \`set pppoe max-payload \...\` command from RFC 4638.
    -   Added \'set radius src-addr \...\' command.
    -   Added \`set iface keep-timeout\` options.
    -   Added \`set console auth\` options.
    -   Added \`agent-cid\` global option to control display PPPoE
        ADSL-Agent-Circuit-Id option in \`show session\` command.
        Default is disabled.
    -   Added \`session-time\` global option to control display session
        time in seconds in \`show session\` command. Default is
        disabled.
    -   Using \`peer_addr\` in ACL tell to use mpd-table with the peer
        negotiated IP address.
    -   Added more wildcards, passed from ACL\'s.
    -   Added more wildcards, passed from \`set iface description \...\`
        command or \`mpd-iface-descr\` RADIUS attribute.
    -   Added \`Filter-Id\` RADIUS attribute.
    -   Added support for Backtrace Access Library.
    -   Added support for LibreSSL Library.
-   Changes:
    -   Rename \`quit\` command to \`shutdown\`.
    -   \`authname \...\` command can be case insensitive.
-   Bugfixes:
    -   Restore send mac address to RADIUS server in unformatted value.
    -   Fix long living bug with ECP.
    -   Fix ability to use both IPv4 and IPv6 addresses on the same
        interface.

Changes since version 5.6:

-   New features:
    -   Added global \`qthreshold\` option.
    -   Added \`unset radius server \...\` command.
    -   Added \`unset nat \...\` command.
    -   Added \`Class\` CoA attribute from RFC 2865.
    -   New command \`show netflow\` added.
-   Changes:
    -   NAT rules may be added/deleted without shutdowning interface.
    -   NetFlow can export IPv6 data.
    -   Interface description may be construct from predefined variables
        in bundle template.
-   Bugfixes:
    -   Restore \`show sessions\` as unprivileged command.
    -   Fix infinite event loop when STDIN redirected to /dev/null after
        it recently got non-blocking mode support.
    -   Fix invalid output of \`show nat\` command in some times.
    -   Fix some possible memory leaks.

Changes since version 5.5:

-   New features:
    -   Added \`mpd-iface-name\` RADIUS attribute.
    -   Added \`mpd-iface-descr\` RADIUS attribute.
    -   Added \`mpd-iface-group\` RADIUS attribute.
    -   Added \`mpd-peer-ident\` RADIUS attribute.
    -   Added \`set iface name \...\` command.
    -   Added \`set iface description \...\` command.
    -   Added \`set iface group \...\` command.
    -   Added support for NetFlow v9 export.
    -   Added \`set l2tp\|pptp\|tcp\|udp resolve-once \...\` command.
        They allow to resolve peer address every time on reconnect.
-   Changes:
    -   Remove dependency from libpdel library. Import required files
        into the MPD tree.
-   Bugfixes:
    -   Fix invoke \`set iface up\|down-script\` without arguments.
    -   Fix \`show eap\` command
    -   Fix build on older FreeBSD versions.
    -   Fix several memory leaks.
    -   Fix building without SYSLOG_FACILITY option.
    -   Fix byte order in ports in \`set nat red-port\`.
    -   Fix some potential crashes because of NULL dereferences.

Changes since version 5.4:

-   New features:
    -   Added \`set link redial-delay \...\` command.
    -   Print global filters on \`show iface\|customer\` commands.
    -   Added protocol/port forwarding support for NAT.
    -   Added utmpx support on 9-CURRENT.
-   Bugfixes:
    -   Fix memory leaks on PPTP and RADIUS on some reason.
    -   Really make RESULT a mandatory option in ext-auth.

Changes since version 5.3 (most of this work was sponsored by [JSC
\'Ufanet\'](http://ufanet.ru/)):

-   New features:
    -   Added built-in RADIUS server, supporting RFC 3576: Dynamic
        Authorization Extensions to RADIUS.
    -   Added Disconnect-Request extension support from RFC 3576.
    -   Added CoA-Request extension support from RFC 3576.
    -   Added \`authname \...\` command to choose active link by peer
        auth name.
    -   Added support for DSL Forum vendor-specific Circuit-ID/Remote-ID
        PPPoE tags and respective RFC 4679 RADIUS VSA.
    -   Peer address argument added to interface up/down scripts.

Changes since version 5.2:

-   New features:
    -   Added \'drop\' link action and \'set link action clear\'
        command.
    -   Added ability to receive link action from AAA in auth reply. It
        allows AAA to select bundle/repeater configuration for specific
        user or session.
    -   Added global traffic filters support to reduce auth reply size.
        \'set global filter \...\' commands.
    -   Added ability to include other local or remote config files.
        \'load \...\' command able to accept configuration file path/URI
        as first argument.
    -   Added support for new ng_netflow node features to improve
        bidirectional accounting performance.
    -   Added \'acct-mandatory\' auth option to control accounting start
        errors handeling. Default is enabled.
-   Changes:
    -   Improved build modularization to allow more customized builds.
    -   Reduced memory usage by more effective ACL memory allocation.
    -   Allowed MRRU less then 1500 bytes. RFC claims that 1500 must be
        supported, but lower values are acceptable.
-   Bugfixes:
    -   Fix possible crash on nonterminated ident string receive.
    -   Fix memory leaks on auth failures.
    -   Change NCPs join/leave sequences to avoid ENXIO errors on
        connect.
    -   Use separate socket for getting CCP node ID to avoid fake
        reports.

Changes since version 5.1:

-   New features:
    -   Added \'set radius identifier\' command.
    -   Added \'\$CallingID\' and \'\$CalledID\' modem chat variables.
        Their values will be reported to the auth backend.
    -   Added tunnel related RADIUS attributes of RFC2868 support.
    -   \'set auth max-logins\' feature can now be case insensitive.
    -   Added force ability to the \'set iface addrs\' command.
    -   IPCP/IPv6CP now closing on interface address assign error or
        up-script error.
    -   Accounting start error now closes link.
    -   PPPoE peer address format changed to more traditional.
    -   Link peer-as-calling option default changed to disabled. PPTP
        and L2TP users are advised to check configurations!
    -   Some of RADIUS accounting update log messages moved from radius
        to radius2 log level.
-   Bugfixes:
    -   Fix PPTP peer address reporting for real LAC/PAC mode.
    -   Fix auth thread busy check.
    -   Fix incorrect L2TP self address used for outgoing calls when
        several different addresses configured.

Changes since version 5.0:

-   New features:
    -   Added support for NS-related RADIUS attributes from RFC 2548.
    -   Added global max-children option.
    -   Added link, bundle, iface and iface-index RADIUS VSA.
    -   Added \'set link mrru \...\' command. Set default MRRU to 2048
        and maximum to 4096 bytes.
    -   Added USER_NT_HASH and USER_LM_HASH ext-auth attributes for
        MS-CHAP authentication.
    -   Added mpd-input-acct/mpd-output-acct RADIUS attributes to allow
        sending typed traffic accounting using standard RADIUS
        attributes.
    -   Added support for local side IP management using IP pools.
    -   Added support for auth/acct-only RADIUS servers. It allows to
        specify different servers for authentication and accounting in
        mpd configuration file.
    -   Added support for the new ng_pptpgre node design, supporting
        multiple calls per node. It improves performance, when multiple
        calls active between two IPs.
-   Changes:
    -   peer-as-calling and report-mac options moved from radius to link
        to improve LAC operation.
-   Bugfixes:
    -   Fixed incorrect link creation error handeling.
    -   Added workaround for some incorrect PAP implementations.
    -   Changed processing of NAK on multilink options. NAK enables
        rejected options back.
    -   Added missing multilink parameters check in BundJoin().
    -   Fixed sending of incoming traffic typed accounting on accounting
        stop.
    -   Fixed using correct proxy-arp MAC when more then one interface
        matches.
    -   Fixed some L2TP and PPPoE errors processing.
    -   Fixed TCP and UDP link type nodes naming.

Changes since version 5.0rc2:

-   New features:
    -   Sending LCP Time-Remaining packet implemented.
-   Bugfixes:
    -   Fixed MPPC options loss on link disconnect.
    -   Fixed crash on PPTP CDN sending error.
    -   Fixed incorrect IPCP options reject processing.
    -   Fixed MP SHORTSEQ option.
    -   Fixed packet order on accepting outgoing PPTP call.

Changes since version 5.0rc1:

-   New features:
    -   \'auth2\' log level added.
-   Changes:
    -   Always prefer MS-CHAP to others to get encryption keys.
-   Bugfixes:
    -   Fixed bug in tcpmssfix when compression or encryption is used.
    -   Fixed build on FreeBSD 5.x.
    -   Fixed build without PPTP or L2TP support.
    -   Fixed netflow node creation.

Changes since version 5.0b4:

-   New features:
    -   \'show pptp\' and \'show l2tp\' commands added.
-   Bugfixes:
    -   Rewritten ippool to avoid races on IPCP renegotiation.
-   Changes:
    -   Rewritten message engine using internal circular queue instead
        of system pipe.
    -   L2TP/PPTP tunnel shutdown is now delayed for better LAC/PAC
        interoperation.

Changes since version 5.0b3:

-   New features:
    -   If Framed-Netmask RADIUS attribute != 255.255.255.255 mpd will
        create Framed-IP-Address/Framed-Netmask route to the client
        side.
    -   Added reporting peer MAC address and interface to AAA. Added
        NAS-Port-Id RADIUS attribute support.
    -   New \'iface\' command added.
    -   Added IPv6 support for Tee and DialOnDemand.
    -   \'set iface addrs\' now able to set IPv6 addresses.
    -   ACCT_INTERIM_LIM_RECV and ACCT_INTERIM_LIM_XMIT attributes added
        to ext-auth.
-   Bugfixes:
    -   Fixed /32 routes processing.
    -   Fixed crash on repeater shutdown.
    -   Fixed \'create link \' command syntax check.
    -   Fixed redial delay.
    -   Many small tunings and fixes.
-   Performance improvements:
    -   Netgraph management completely rewritten. Now 6 sockets per
        daemon used to communicate with netgraph instead of 4 sockets
        per link before. This gives significant performance benefit due
        to reduced pevent engine overhead.
    -   Internal memory management rewritten.

Changes since version 5.0b1:

-   New features:
    -   Implemented type-differentiated traffic accounting based on
        mpd-limit traffic filters.
    -   Added \'set link max-children \...\' command for DoS protection.
    -   Implemented user privilege levels
        \"admin\"/\"operator\"/\"user\".
    -   Web console rewritten and allows now execute any commands
        allowed by privileges. Added plain-text command interface.
    -   New \'show sessions\' and \'show customer\' commands added.
    -   Implemented one-shot operation mode to allow mpd to be used in
        complicated dial setups.
    -   Acct-Session-Id attribute now present in auth request.
    -   Show to auth real PPPoE session name received from peer.
-   Changes:
    -   Rewritten PPPoE, L2TP, TCP and UDP link types to fulfill new
        dynamic design.
    -   MPPC related options moved from \'set ccp\' to the new \'set
        mppc\' command.
    -   \'set bundle retry\' command renamed to \'set bundle
        fsm-timeout\'.
    -   Number of auth retries increased to 5.
    -   PPTP windowing is disabled by default.
    -   Improved unified command error reporting.
    -   Users list is now global and the same for console and web.
-   Bugfixes:
    -   Fixed memory leak on link/bundle shutdown.
    -   Fixed reference (memory) leak on console close.
    -   Fixed netflow setup errors handeling.
    -   Improved IfaceIp\[v6\]IfaceUp() errors handeling.
    -   Restore link MRU to default after use. Should help with some
        EAP-TLS cases.
    -   MPPC now automaically disables unusable subprotocols. For
        example, it is impossible to use MPPE encryption without MSCHAP.
    -   Fixed FSM instantiation to fix LCP keep-alives.
    -   Fixed \'set eap \...\' context.
    -   Implemented PAP-ACK packet retransmit.
    -   \'show mem\' command now returns output to console instead of
        stdout.
    -   Many small fixes.

Changes since version 4:

-   Design changes:
    -   Removed static link - bundle relations. Links now choose their
        bundles using negotiated parameters when they reach NETWORK
        phase. The benefit of it is simple and complete client and
        server multilink operation. Also it gives ability to implement
        more complicated LAC, PAC and TSA setups then it was possible
        before.
    -   Implemented template based dynamic link/bundle creation. It
        allows significantly reduce amount of configuration required to
        operate big access servers. Link may be autocreated by incoming
        call request from device or by DoD/BoD request from bundle.
        Bundle may be autocreated by the link reached NETWORK phase.
    -   To simplify configuration link and phys layers separated since
        version 4.2 are now rejoined again into a single link layer.
-   New features:
    -   Added PAM authentication and accounting.
    -   Added dynamic IP addresses pools support.
    -   Added new \'ext-acct\' accounting backend as full-featured
        alternative to \'radius-acct\'.
-   Changes:
    -   Massive changes in configuration commands. You should read the
        manual and examples for the new configuration techniques.
    -   FreeBSD 4.x and old DragonFly releases are not supported
        anymore.

Changes since version 4.2.2:

-   New features:
    -   Added L2TP local hostname configuration.
    -   Added L2TP length and dataseq options.
    -   L2TP local hostname and secret at server side is now
        configurable depending on client address.
    -   Reimplemented RADIUS Class attribute support.
    -   Added PPPoE AC-name specification for the server side.
    -   Added IP accounting with ng_ipacct node support.
    -   Added configure script for better system features detection.
    -   \'show version\' command now shows compiled-in system features.
    -   \'session \...\' and \'msession \...\' commands to select
        link/bundle by their current session IDs added.
-   Bugfixes:
    -   Fixed race condition on PPTP tunnel creation/death.
    -   Fixed crash when stdout redirected to /dev/null.
    -   Fixed memory leak in proxy-arp.
    -   Fixed Dial-on-Demand functionality broken in 4.2.
    -   Do not set ACCM for a Sync links.
    -   Fixed Sync mode detection for L2TP links.
-   Performance improvements:
    -   Added support for 64bit ng_ppp counters where available.

Changes since version 4.2.1:

-   Bugfixes:
    -   Fixed build and stack overflow on FreeBSD 5.x.
    -   Fixed startup script dependencies.

Changes since version 4.2:

-   Bugfixes:
    -   Fixed default route support bug.
    -   Fixed memory leak in L2TP link creation.

Changes since version 4.1:

-   New features:
    -   Implemented link repeater functionality (aka LAC/PAC). New
        \"phys\" and \"repeater\" layers added.
    -   PPTP now supports listening on multiple different IPs.
    -   L2TP now supports tunnel authentication with shared secret.
    -   Implemented traffic filtering using ng_bpf.
    -   Implemented fast traffic shaping/rate-limiting using ng_car.
    -   Added workaround for Windows 2000 PPPoE MRU negotiation bug.
    -   Implemented minimal client side of auth-driven callback (w/o
        number specification).
    -   Restored control console on stdin.
    -   Added multiline console command history.
    -   Added new \'ext-auth\' auth backend as full-featured alternative
        to \'radius-auth\'.
    -   Added support for some new ng_nat features.
    -   Implemented PPTP/L2TP SetLinkInfo sending to PAC/LAC.
    -   NetFlow generation for both incoming and outgoing packets same
        time is now supported. NOTE: To have more then 1000 interfaces
        with NetFlow in 6-STABLE you may need to increase
        NG_NETFLOW_MAXIFACES constant in netflow.h and rebuild
        ng_netflow kernel module.
    -   Added mpd-drop-user vendor specific accounting reply attribute
        support.
-   Changes:
    -   \'set link type \...\' command is deprecated now. Use \'set phys
        type \...\' instead.
    -   -a, -n, -N, and -t bundle options are deprecated now. Use \'set
        iface enable \...\' instead.
    -   ng_tee, ng_nat, ng_netflow and other netgraph nodes between
        ng_ppp anf ng_iface now created when NCP (IPCP/IPV6CP) goes up
        instead of startup time.
    -   Auth subsystem refactored to avoid incorrect cross-level
        dependencies.
    -   Physical device level refactored to remove link and bundle
        levels dependencies.
    -   While accepting calls PPTP, L2TP, TCP and UDP links are now
        trying to use link with most specific peer address configured.
    -   Removed setting up local IPv4 address routing to loopback.
        /usr/sbin/ppp does not doing it.
-   Bugfixes:
    -   Fixed thread-safety related crash in accounting.
    -   Fixed assertion in PPTP on control connection fail while
        answering.
    -   Fixed assertion in L2TP on control message sending failure.
    -   Fixed broken L2TP outcall mode.
    -   Updated chat scripts to detect incoming modem calls speed.
-   Performance improvements:
    -   Calls to ifconfig and route programs replaced by internal
        functions.
    -   Where possible system() calls replaced by fork()+execv() to
        avoid shell execution.
    -   Added connect requests storm overload protection. mpdx will drop
        incoming requests when message queue reach some defined length.

Changes since version 4.1rc2:

-   Changes:
    -   Default value of link\'s max-redial parameter changed to -1.
    -   Bundle\'s noretry option is enabled by default now.
-   Bugfixes:
    -   Better up/down reason tracking.

mpdx version was bumped from 4.0rc2 to 4.1rc2 due to large number of
changes done since 4.0b4 and FreeBSD ports version number conflict.

Changes since version 4.0rc1:

-   Bugfixes:
    -   Idle timeout fixed.
    -   Fixed bug with \'set l2tp self \' specified at the server side.
    -   Device type check for device-specific commands added.
    -   IPCP reject is not fatal by itself now.
    -   Up/down-script will now be called not for the whole interface,
        but for each of negotiated protocols. Proto parameter should be
        checked in the script!
    -   Fixed ng_ppp link bandwidth configuration.

Changes since version 4.0b5:

-   New features:
    -   Integrated Web server added.
    -   NAT support by ng_nat(4) added.
    -   L2TP (RFC 2661) device type implemented.
    -   UDP device type was completely rewritten. Now it:
        -   does not require manual \'open\' command on the server side,
            it behaves just like any other device type;
        -   allows many connections to the same server UDP port;
        -   allows not to specify peer address/port for incoming
            connections (so it will work through different NATs and
            firewalls);
        -   allows not to specify self address/port for outgoing
            connections (so it is easier to configure);
    -   TCP device type was completely rewritten. It has some minor
        issues due to limitation of ng_ksocket module, but now IT WORKS!
        :)
    -   Compression Predictor-1 (RFC 1978) added.
    -   Compression Deflate (RFC 1979) added.
    -   Encryption DESE (RFC 1969) support was reimplemented.
    -   Encryption DESE-bis (RFC 2419) support added.
    -   New command \'show phys\' added.
    -   New command \'show summary\' added.
    -   Support for ipfw tables added to RADIUS ACL\'s.
    -   New commands \'set global start\...\' added..
    -   Added support of calling/called numbers (mostly for PPTP/L2TP).
-   Changes:
    -   \"lcp\" layer in open/close commands replaced by \"link\".
    -   Auth configuration (set auth \...) moved from bundle layer to
        lcp. It works per link now.
    -   MPPE policy option moved from auth layer to ccp.
-   Bugfixes:
    -   Fixed a few bugs on amd64 and sparc64 platforms.
    -   Phys layer was made stateless to remove race condition.
    -   Link layer changed to remove race conditions on LinkDown().
    -   Fixed race condition in accepting PPPoE connections.
    -   Link up/down reason recording is now more accurate.
    -   Complete link shutdown procedure on auth failure implemented.
    -   Fixed several small PPTP level processing issues.
    -   Removed limitation about PPTP which must be in the bundle alone.
    -   Fixed MSCHAP auth which was broken in 4.0b5.
    -   Fixed memory leak in PAP and CHAP auth on the client side.
    -   Fixed some CCP negotiation issues.
    -   Fixed threads-related crash in internal auth.
    -   Fixed crash on incoming when no free PPTP link found.
    -   Bug in \"rubber bandwidth\" algorithm fixed.
    -   Bug and possible crash fixed in DoD code.
    -   Fixed bug in AUTHPROTO negotiation.
    -   Fixed bug in RAD_MICROSOFT_MS_CHAP2_SUCCESS handeling. Needs
        testing.

Changes since version 4.0b4:

-   New features:
    -   IPv6 support:
        -   IPV6CP support added, NCPs and IFACE calls was rewritten to
            support many NCPs.
        -   Console now supports IPv6.
        -   UDP and TCP link types now support IPv6.
        -   PPTP link type is ready to support IPv6, but requires
            ng_pptpgre(4) to support IPv6.
        -   NetFlow export over IPv6 is supported.
        -   The following features do not yet support IPv6: TcpMSSFix,
            NetFlow, Tee, DialOnDemand.
    -   TCP link type now compiles and works but is not yet ready for
        production usage.
    -   NetFlow data generation on outgoing interface is supported.
    -   Added a possibility to use an existing ng_netflow(4) node.
    -   Added a possibility to specify network interface names instead
        of IP addresses.
    -   Added more log levels to decrease log file size.
-   Changes:
    -   Default argument of open/close commands changed from iface to
        lcp.
-   Bugfixes:
    -   Fixed races between startup process and client connecting.
    -   Fixed a few crashes in console.
    -   Incoming call processing significantly reworked to fix some
        aspects of multilink server functionality.
    -   The shutdown of mpd is now much more graceful: the netgraph
        nodes are closed, the accounting RADIUS packets for closing
        links are sent, new connections are not accepted during
        shutdown.
    -   Fixed races in filling of RADIUS packets. In particular,
        RAD_NAS_PORT value in the RADIUS could be wrong.
    -   RADIUS support rewritten to use poll(2) instead of select(2),
        allowing to create a bigger number of links.
    -   Fixed a problem with identifying correct interface for proxy-arp
        when alias addresses are used.
    -   Fixed memory leaks and crashes when more than 256 PPTP bundles
        are in use.
    -   Fixed crash in PPPoE when more than 64 parent Ethernet
        interfaces used.
-   Performance improvements:
    -   Message and PPPoE subsystems reworked to decrease number of open
        files per bundle.

Changes since version 4.0b3:

-   BugFix: fix crash in processing of MS domain name from RADIUS
    server.
-   New feature: automatic creation, configuring and attaching of
    ng_netflow(4) node.
-   ng_tee(4) now can be inserted on a per bundle basis.
-   New feature: on FreeBSD 6.0 and higher ng_tcpmss(4) is utilized if
    doing TCP MSS fixup.
-   BugFix: tcpmssfix now works for both incoming and outgoing TCP
    segments.
-   New options: update-limit-in, update-limit-out.
-   Fixed loss of statistics when -t options is used.
-   Fixed chat scripting, modem links not broken anymore.

Changes since version 4.0b2:

-   BugFix: make PPPoE interface control events recurring, PPPoE is not
    broken anymore.
-   Added a new `startup` section to the config-file, wich is loaded
    once at startup.
-   Added a new `global` config space for all the global settings.
-   BugFix: do not generate new challenges while retransmitting them.
-   Fix `va_args` bug on certain non-i386 platforms.
-   Auto-load `ng_ether` for PPPoE connections; fix default path for
    undefined service.
-   Rewrite the console-stuff. Multiple telnet connections are now
    allowed. There is no input-console anymore, must use telnet instead.
-   BugFix: The directly configured password was not taken into account
    when using PAP.
-   Disallow empty usernames safely.

Changes since version 4.0b1:

-   Fixed a race-condition wich caused a dead-lock.
-   RADIUS
    -   Fixed several race-conditions when sending accounting requests.
    -   Use the username from the access-accept packet (if present) for
        accounting requests.

Changes since version 3 (most of this work was sponsored by
[SURFnet](http://www.surfnet.nl/)):

-   Design changes: mpdx uses now a thread-based event system using
    libpdel, these libpdel parts are now integrated:
    -   typed_mem(3)
    -   pevent(3)
    -   alog(3)

    mpdx uses a \"Giant Mutex\" for protecting its resources.
-   Major new features:
    -   Implemented the Extensible Authentication Protocol RFC 2284
        (EAP). Currently only EAP-MD5 is supported (client and server
        side). EAP negotiaton can be enabled at link level.
    -   Implemented OPIE (One-time Passwords In Everything).
    -   Implemented authentication against systems password database
        `master.passwd`.
    -   utmp/wtmp logging.
-   Rewrites of the authentication subsystem:
    -   Make authentication and accounting requests asynchronous using
        paction(3).
    -   Authentication backends are acting now independently from the
        rest of mpdx, using some internal structs as interface.
    -   The `mpd.secret` file is now used as one authentication backends
        of many, it has no special role anymore, i.e. it could be
        disabled.
    -   Generate a session-id at bundle and link level for using with
        accounting requests.
-   RADIUS related changes:
    -   **IMPORTANT**: mpdx needs now an enhanced libradius, here are the
        patchsets: `4-STABLE` `5-CURRENT`
    -   Remember and send the RAD_STATE attribute.
    -   Message-Authenticator support.
    -   EAP Proxy Support.
-   Added a new option for PPTP links for disabling the windowing
    mechanism specified by the protocol. Disabling this will cause mpdx
    to violate the protocol, possibly confusing other PPTP peers, but
    often results in better performance. The windowing mechanism is a
    design error in the PPTP protocol; L2TP, the successor to PPTP,
    removes it. You need a recent version of FreeBSD
    (NGM_PPTPGRE_COOKIE \>= 1082548365) in order to get this feature.\
    `set pptp disable windowing`
-   Added a new commandline option `-t` for adding ng_tee into the
    netgraph.\
    Submitted by: Gleb Smirnoff, glebius at cell dot sick dot ru
-   Removed configuration parameters:
    -   bundle: `radius-fallback`
    -   iface: `radius-session`, `radius-idle`, `radius-mtu`,
        `radius-route`, `radius-acl`
    -   ipcp: `radius-ip`

    Moved configuration parameters:
    -   bundle to auth: `radius-auth`, `radius-acct`, `authname`,
        `password`, `max-logins`
    -   radius to auth: `acct-update`
    -   ccp to auth: `radius` and renamed to `mppc-pol`

    New configuration parameters:
    -   link: `keep-ms-domain`, this prevents mpdx from stripping the
        MS-Domain, this is can be useful when using IAS as RADIUS
        server.
    -   radius: `message-authentic`, this adds the Message-Authenticator
        attribute to the RADIUS request.
    -   auth: `internal`, controles the usage of the `mpd.secret` file
        (internal authentication backend).
    -   auth: `opie`, enables/disables the OPIE authentication backend.
    -   auth: `system`, enables/disables authentication against systems
        password database.
    -   auth: `utmp-wtmp`, enables/disables utmp/wtmp logging. database.
    -   auth: `timeout`, configureable timeout for the authentication
        phase.
    -   eap: `radius-proxy`, this causes mpdx to proxy all EAP requests
        to the RADIUS server, mpdx only makes the initial
        Identity-Request (this saves one round-trip), every other
        requests are forwarded to the RADIUS server. This adds the
        possibility supporting every EAP-Type of the RADIUS server,
        without implementing each EAP-Type into mpdx.
    -   eap: `md5`, EAP-Type MD5, it\'s the same as CHAP-MD5, but inside
        EAP frames.
-   Removed defines `ENCRYPTION_MPPE` and `COMPRESSION_MPPC`, they are
    now built in.
-   Get rid of `IA_CUSTOM` define.
-   BugFix: Fixed a mem-leak in the pptp-ctrl stuff.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Introduction*](mpd1.md)
**:** *Change history*\
**Previous:** [*Organization of this manual*](mpd3.md)\
**Next:** [*Installation*](mpd5.md)
