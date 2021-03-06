[*mpdx User Manual*](README.md) **:** [*Configuring mpdx*](mpd17.md)
**:** *Dynamic Authorization*\
**Previous:** [*External authentication*](mpd31.md)\
**Next:** [*Traffic accounting*](mpd33.md)

------------------------------------------------------------------------

## []{#32}4.11. Dynamic Authorization[]{#dynauth}

After session has been first time authorized by AAA subsystem, mpdx
provides you several ways to affect it\'s further operation. Process of
affecting established session called dynamic authorization.

There are two types of dynamic authorization activities exist:
Disconnect (terminate session, causing it\'s graceful shutdown) and
Change of Authorization, CoA (changing session operation parameters,
such as speed, ACLs and so on, on-flight)

**Control consoles**

:   The basic method of controlling mpd is it\'s STDIN and TCP
    **[consoles](mpd40.md#console)**.

    You can disconnect any session by connecting to console, selecting
    required session with any command for changing current context, such
    as: *link*, *bundle*, *session*, *msession* and so on, and using
    *close* command.

**Web server**

:   mpdx provides two **[Web](mpd41.md#web)** interfaces: human
    (text.md) and binary (text/plain).

    Human web interface allows you disconnect specified session just by
    clicking on respective *\[Close\]* link on the \"Current status
    summary\" web page on mpd built-in web server.

    Binary web interface provides API for executing any of control
    console commands via HTTP request. For example, to disconnect
    session on link named L125 you may use such HTTP request:
    */bincmd?link%20L125&close*

**RADIUS accounting**

:   mpdx provides simple, but non-standard method of disconnecting
    session using **[RADIUS](mpd30.md#radius)** accounting reply. To
    disconnect arbitrary session you may just include *mpd-drop-user*
    attribute with nonzero value into any accounting reply packet.

    This method considered not to be completely reliable, as AAA
    receives no acknowledge that accounting reply packet was received by
    mpd. The only thing guarantied, is that on packet loss mpd will
    retry accounting sending for specified number of times before
    giveup.

**Built-in RADIUS server**

:   RFC 3576: \"Dynamic Authorization Extensions to RADIUS\" defines
    standard way to implement dynamic authorization. It defines two
    additional RADIUS request types: Disconnect-Request and CoA-Request,
    to be sent from AAA server to dedicated UDP port on NAS with regular
    RADIUS protocol.

    To have this function working, mpd should be built with *libradius*
    library, having RADIUS server functionality (FreeBSD 7/8-STABLE
    after 2009-10-30).

    This chapter describes commands that configure mpd\'s built-in
    RADIUS server. All of these commands are executed in global context.

    **`set radsrv open`**

    :   Opens the RADIUS server, i.e., creates the listening UDP socket.

    **`set radsrv close`**

    :   Closes the RADIUS server, i.e., closes the listening UDP socket.

    **`set radsrv self ip [ port ]`**

    :   Sets the credentials for the RADIUS-listener. After changing one
        of these options, the RADIUS server must be closed and re-opened
        for the changes to take effect.

        The default is \'0.0.0.0 3799\'.

    **`set radsrv peer ip secret`**

    :   Defines additional AAA server, allowed to contact this NAS.
        After changing one of these options, the RADIUS server must be
        closed and re-opened for the changes to take effect.

    **`set radsrv enable option ... set radsrv disable option ...`**

    :   These commands configure various RADIUS server options.

        The `enable` and `disable` commands determine whether we want
        the corresponding option.

        The options available for the RADIUS server are:

    **`coa`**

    :   This option enables CoA-Request support on RADIUS server.

        The default is enable.

    **`disconnect`**

    :   This option enables Disconnect-Request support on RADIUS server.

        The default is enable.

    Dynamic authorization RADIUS server receives three groups of
    attributes: NAS identification (to be sure that request got to the
    right server), session identification (to identify session that
    should be affected) and session parameters (to describe new session
    state to set). NAS and session identification attributes are native
    part of any Disconnect or CoA request, while session parameters
    could be used only with CoA. At least one session identification
    attribute must be present in request. If there are several
    identification attributes present, session should match all of them
    to be affected.

    NAS identification attributes supported by mpd:

        N   Name
        4   NAS-IP-Address

    Session identification attributes supported by mpd:

        N   Name
        1   User-Name
        5   NAS-Port
        8   Framed-IP-Address
        30  Called-Station-Id
        31  Calling-Station-Id
        44  Acct-Session-Id
        50  Acct-Multi-Session-Id

            mpd VSA (12341)
        12  mpd-link
        13  mpd-bundle
        14  mpd-iface
        15  mpd-iface-index

    Session parameters attributes supported by mpd:

        N   Name
        24  State
        25  Class
        27  Session-Timeout
        28  Idle-Timeout
        85  Acct-Interim-Interval

            mpd VSA (12341)
        1   mpd-rule
        2   mpd-pipe
        3   mpd-queue
        4   mpd-table
        5   mpd-table-static
        7   mpd-filter
        8   mpd-limit
        16  mpd-input-acct
        17  mpd-output-acct

    Received in CoA session parameters replace existing ones. If some
    parameter is not received, it keeps it\'s previous value for
    standard attributes, and getting cleared for mpd\'s VSAs.

    Note that CoA request always restarts Session and Idle timers for
    matching interfaces, and restarts Accounting Update timer for
    matching links, if new value received.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Configuring mpdx*](mpd17.md)
**:** *Dynamic Authorization*\
**Previous:** [*External authentication*](mpd31.md)\
**Next:** [*Traffic accounting*](mpd33.md)
