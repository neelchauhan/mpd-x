[*mpdx User Manual*](README.md) **:** [*Configuring mpdx*](mpd17.md)
**:** *General mpd commands*\
**Previous:** [*Configuring mpdx*](mpd17.md)\
**Next:** [*mpdx Layers*](mpd19.md)

------------------------------------------------------------------------

## []{#18}4.1. General mpd commands[]{#gencmd}

This chapter describes general mpd commands that do not apply to a
specific layer.

**`create bundle [ template | static ] name [ template ] `**

:   Create new bundle with specified name, optionally based on specified
    template. If \'template\' option is specified, bundle will not
    operate itself, but will be used to create new bundles on demand. If
    \'static\' option is specified, it will be a permanent bundle which
    will not disappear after operation completes. Maximum name length is
    10 characters for templates and 15 characters for the rest of
    bundles.

**`create link [ template | static ] name ( type | template ) `**

:   Create new link with specified name and type, optionally based on
    specified template. If \'template\' option is specified, link will
    not operate itself, but will be used to create new links on demand.
    If \'static\' option is specified, it will be a permanent link which
    will not disapear after operation complete. Maximum name length is
    10 characters for templates and 15 characters for the rest of links.

**`destroy bundle [ name ] destroy link [ name ]`**

:   Destroy existing link/bundle. Note that if link is in use, it may
    not disapear after command returns, it may take some time to
    properly close it.

**`bundle [ name ] `**

:   This command changes the currently active bundle to the bundle named
    `name`. The currently active link is also changed, to the first link
    of the bundle. If no `name` is given, this command lists all of the
    defined bundles and their constituent links. The new bundle will be
    reflected in the prompt.

**`link [ name | [number] ] `**

:   This command changes the currenly active link to the link named
    `name`. If this link does not belong to the currently active bundle,
    then the currently active bundle is changed to the bundle that owns
    link `name`. The new link will be reflected in the prompt. Link
    *number* (RAD_NAS_PORT) can be specified in hex form in square
    brackets in place of name.

**`repeater [ name ] `**

:   This command changes the currenly active repeater to the repeater
    named `name`. The currently active phys is also changed, to the
    first phys of the repeater. If no `name` is given, this command
    lists all of the defined repeaters and their constituent physes. The
    new phys will be reflected in the prompt.

**`iface [ iface ] `**

:   This command changes the currenly active bundle to the bundle using
    interface `iface`.

**`msession [ msesid ] `**

:   This command changes the currenly active bundle to the bundle
    holding session with multilink session ID `msesid`.

**`session [ sesid ] `**

:   This command changes the currenly active link to the link holding
    session with session ID `sesid`.

**`authname [ name ] `**

:   This command changes the currenly active link to the link holding
    session with peer auth name `name`. If CI argument is present login
    comparasion will be case insensitive.

**`load [ file ] label`**

:   This command causes mpd to read the entry for `label` out of
    `mpd.conf` or other file if specified and execute the corresponding
    commands. *file* can be relative or absolute file path or
    http/https/ftp URL. Note, that remote file access may be less
    reliable.

**`show [ item ] `**

:   This command displays various status information. The valid values
    for `item` are:

    **bundle**

    :   Show status information about the currently active bundle.

    **link**

    :   Show status information about the currently active link.

    **repeater**

    :   Show status information about the currently active repeater.

    **iface**

    :   Show status information about the interface layer associated
        with the currently active bundle.

    **routes**

    :   Show the current IP routing table.

    **ipcp**

    :   Show status information about the IP control protocol associated
        with the currently active bundle.

    **ippool**

    :   Show status information about configures IP pools.

    **ccp**

    :   Show status information about the compression control protocol
        associated with the currently active bundle.

    **lcp**

    :   Show status information about the link control protocol
        associated with the currently active link.

    **nat**

    :   Show information about NAT on the currently active bundle.

    **auth**

    :   Show status information about Authentication.

    **eap**

    :   Show status information about EAP.

    **radius**

    :   Information relating to RADIUS authentication.

    **proto**

    :   Show protocol statistics for the currently active bundle and
        link.

    **types**

    :   Show the device types supported by this version of mpd.

    **layers**

    :   Show the names of the layers that are valid as arguments to the
        `open` and `close` commands.

    **l2tp**

    :   Show active L2TP tunnels.

    **pptp**

    :   Show active PPTP tunnels.

    **events**

    :   Show all pending events (for debugging mpd).

    **mem**

    :   Show distribution of dynamically allocated memory (for debugging
        mpd).

    **version**

    :   Show running mpd version and supported features.

    **sessions \[ *param* *value* \]**

    :   Show active sessions conforming specified param/value. Available
        params: iface, ip, bundle, msession, link, session, user, peer.

    **customer**

    :   Show active customer details.

    **summary**

    :   Show status summary.

    **console**

    :   Show console summary.

    **web**

    :   Show web server summary.

    **user**

    :   Show defined console users.

    **netflow**

    :   Show status information about NetFlow.

**`set ...`**

:   This command sets various configuration information. Further details
    are contained in later sections in this chapter. The valid
    completions for `set` are:

    **`set global startrule num set global startpipe num set global startqueue num set global starttable num`**

    :   These commands define initial values for autonumeration of ipfw
        rules, pipes, queues and tables. Defaults are 10000, 10000,
        10000 and 32 accordingly.

    **`set global pptptimeout seconds set global l2tptimeout seconds`**

    :   Set PPTP/L2TP tunnels inactivity shutdown delay.

        Default is 10 seconds.

    **`set global pptplimit num set global l2tplimit num`**

    :   Limit maximum number of calls per PPTP/L2TP tunnel. When limit
        is reached new tunnel will be created for the next call. This
        option violates PPTP RFC which requires only one tunnel existing
        for the PAC/PNS pair, but it can increase busy tunnels
        stability.

        Defaults are 100 (10 for L2TP before FreeBSD 6.3-STABLE and
        7.0-RELEASE).

    **`set global max-children num`**

    :   This option specifies global maximum number of links, created
        using template, that could exist at the same time.

        The default value is 10000.

    **`set global qthreshold min max`**

    :   This option specifies global message queue limit thresholds.

        The default values are 64 and 256.

    **`set global filter num add fltnum flt set global filter num clear`**

    :   These commands define or clear traffic filters to be used by
        rules submitted by [AAA](mpd30.md#radius) during
        authentication.

    **`set global enable option ... set global disable option ...`**

    :   These commands configure various global options.

        The `enable` and `disable` commands determine whether or not we
        want the corresponding option.

        The options available are:

    **`one-shot`**

    :   This option forces mpd terminate itself after the last link
        disappear. Link templates are not counted as links.

        The default is disable.

    **`tcp-wrapper`**

    :   With this option mpd uses `/etc/hosts.allow` everytime a
        connection is made from the client. This is useful if you would
        like to restrict access to mpd. This option affects all TCP
        connections, including PPTP and the TCP device layer.

        The default is disable.

    **`agent-cid`**

    :   Display PPPoE *ADSL-Agent-Circuit-Id* option in *show session*
        command.

        The default is disable.

    **`session-time`**

    :   Display session time in seconds in *show session* command.

        The default is disable.

    **`set user username password [admin|operator|user]`**

    :   This command configures which users are allowed to connect to
        the console. It may be invoked multiple times with different
        usernames.

    **`set bundle ...`**

    :   Set bundle layer configuration parameters for the currently
        active bundle.

    **`set link ...`**

    :   Set link layer configuration parameters for the currently active
        link.

    **`set iface ...`**

    :   Set interface layer configuration parameters for the currently
        active bundle.

    **`set nat ...`**

    :   Set NAT configuration parameters for the currently active
        bundle.

    **`set ipcp ...`**

    :   Set IP control protocol configuration parameters for the
        currently active bundle.

    **`set ccp ...`**

    :   Set compression control protocol configuration parameters for
        the currently active bundle.

    **`set auth ...`**

    :   Configures the authentication subsystem.

    **`set radius ...`**

    :   Configures RADIUS.

    **`set eap ...`**

    :   Configures the EAP.

    **`set debug ...level`**

    :   Sets the `netgraph(3)` debugging level. Default is zero.

    **`set modem ...`**

    :   Sets device specific configuration parameters for the currently
        active link, which must have type **modem**.

    **`set ng ...`**

    :   Sets device specific configuration parameters for the currently
        active link, which must have type **netgraph**.

    **`set tcp ...`**

    :   Sets device specific configuration parameters for the currently
        active link, which must have type **tcp**.

    **`set udp ...`**

    :   Sets device specific configuration parameters for the currently
        active link, which must have type **udp**.

    **`set pptp ...`**

    :   Sets device specific configuration parameters for the currently
        active link, which must have type **pptp**.

    **`set l2tp ...`**

    :   Sets device specific configuration parameters for the currently
        active link, which must have type **l2tp**.

    **`set pppoe ...`**

    :   Sets device specific configuration parameters for the currently
        active link, which must have type **pppoe**.

    **`set console ...`**

    :   Sets console specific configuration parameters

    **`set web ...`**

    :   Sets web server specific configuration parameters

**`unset ...`**

:   This command allows to unsets some of configuration information set
    using `set` command.

**`open [ layer ] `**

:   This command causes an OPEN event to be sent to the corresponding
    layer or finite state machine (FSM). The valid layers are:

    **iface**

    :   Interface layer. Opening this layer configures the interface and
        installs any routes. If dial-on-demand is enabled, nothing else
        happens until there is outgoing traffic. If dial-on-demand is
        disabled there no reason to open this layer manually.

    **bund**

    :   Bundle layer. This layer represents the multi-link bundle
        \`\`virtual link\'\' and is normally opened and closed
        automatically.

    **ipcp**

    :   IP control protocol FSM. This is normally opened and closed
        automatically.

    **ccp**

    :   Compression control protocol FSM. This is normally opened and
        closed automatically.

    **link**

    :   Link control protocol FSM. This is default layer for open/close
        commands. Opening of this layer initiates outgoing call by this
        link.

    **device**

    :   Device layer. This is normally opened and closed automatically.

    Normally, only the `iface` and `link` layers should be explicitly
    opened or closed. This is because the other layers are programmed to
    automatically open and close when appropriate. Note that the
    **SIGUSR1** and **SIGUSR2** signals are an alternative way to open
    and close the first link.

**`close [ layer ] `**

:   This command causes a CLOSE event to be sent to the corresponding
    layer or finite state machine (FSM).

**`log [ +/-flag ... ] `**

:   mpdx supports several different logging flags. Every line logged by
    mpd is tagged with one (or more) of these flags. By turning the
    flags on or off, that particular type of logging is enabled or
    disabled. This allows you to customize logging verbosity.

    Without any arguments, the `log` command shows the current set of
    logging flags. To enable a logging flag, add the `+flag` argument.
    To disable a logging flag, add the `-flag` argument.

    These are the various flags supported by mpd and their corresponding
    categories:

    **auth\***

    :   Link authentication events

    **bund\***

    :   Bundle layer events

    **ccp\***

    :   Compression events and negotiation

    **chat\***

    :   Modem chat script

    **console\***

    :   Log to the console as well as the log file

    **echo**

    :   Echo/reply packets for all FSM\'s

    **ecp\***

    :   Encryption events and negotiation

    **frame**

    :   Dump all frames transmitted and received

    **fsm\***

    :   All FSM events (except echo and resets)

    **iface\***

    :   Interface layer events

    **ipcp\***

    :   IP control protocol events and negotiation

    **ipv6cp\***

    :   IPv6 control protocol events and negotiation

    **lcp\***

    :   Link control protocol events and negotiation

    **link\***

    :   Link layer events

    **phys\***

    :   Device layer events

    **radius\***

    :   RADIUS authentication events

    **rep\***

    :   Repeater layer events

**`help [ command ] `**

:   This gives a brief description of the supplied command, or if an
    incomplete command is given, lists the available alternatives.

**`exit`**

:   This command exits the console, but does not quit the mpd process.
    This command is useful for disconnecting a telnet connection.

**`shutdown`**

:   Close down all connections and quit the mpd process.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Configuring mpdx*](mpd17.md)
**:** *General mpd commands*\
**Previous:** [*Configuring mpdx*](mpd17.md)\
**Next:** [*mpdx Layers*](mpd19.md)
