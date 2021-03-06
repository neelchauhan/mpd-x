[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** *Link layer*\
**Previous:** [*Mpd Layers*](mpd19.html)\
**Next:** [*EAP*](mpd21.html)

------------------------------------------------------------------------

## []{#20}4.3. Link layer[]{#links}

This chapter describes commands that configure the link layer. All of
these commands apply to the currently active link, i.e., the link shown
at the command line prompt.

**`set link action (bundle|forward) name [ regexp ]`**

:   

**`set link action drop [ regexp ]`**

:   List of such command describes how incoming calls should be
    processed. \"bundle\" means that connection should be processed
    locally with specified bundle. \"forward\" means that connection
    should be forwarded using repeater to the specified link. \"drop\"
    means that connection should be dropped. Optional \"regexp\"
    parameter defines regular expression which will be checked against
    peer auth name.

    Actions from list are checked in order of definition until regexp
    match will be found. Actions processed at three points. First time
    they are checked just after connection acception, second time just
    after receiving peer\'s auth during LCP negotiation and third time
    when link is authenticated. As during first check there is no peer
    auth name known yet, check will be skipped if there are more then
    one action specified for link or if action has regexp specified.

**`set link action clear`**

:   Clears link actions list.

**`set link latency microseconds`**

:   

**`set link bandwidth bits-per-second`**

:   These commands are relevant when multi-link PPP is active. They
    affect the way in which packets are chopped up into fragments before
    being sent over the various links that make up the bundle.

    To motivate the idea, imagine a bundle that had a modem link and a
    1.5Mbps T1 link. If mpd sent each packet in two equal sized
    fragments over these links, then by the time the modem got around to
    transmitting the first byte of its fragment, the T1 link would have
    probably already sent the whole other fragment. Clearly this is not
    very good. By factoring in the latency and bandwidth parameters for
    each link, mpd can distribute the fragments in a more intelligent
    way.

    Mpd attempts to distribute bytes over the links so that (if the
    configured parameters are accurate) the last byte of each fragment
    arrives at the peer at the same time on each link. This minimizes
    latency. However, if you only care about maximizing throughput,
    simply set all of the latency values to zero.

    If all of your links are of the same type and speed (which is often
    the case), then they should be configured with the same values (or
    just not configured at all, since all links default to the same
    values anyway). Then mpd will distribute packets in equal sized
    fragments over the links.

**`set link mtu numbytes`**

:   

**`set link mru numbytes`**

:   

**`set link mrru numbytes`**

:   The `set link mtu` command sets the maximum transmit unit (MTU)
    value for the link. This is the size of the largest single PPP frame
    (minus PPP header) that this link will transmit, unless the peer
    requests an even lower value. The default value is 1500 bytes.

    The `set link mru` command sets maximum receive unit (MRU) value for
    the link, which is the size of the largest single PPP frame (minus
    PPP header) that this link is capable of receiving. The default
    value is 1500 bytes.

    If PPP multilink is negotiated on a link, then these values are less
    important, because multilink allows PPP frames themselves to be
    fragmented, so a PPP frame up to MRRU bytes can always pass through
    no matter how small the MTU is in a particular direction.

    Otherwise, mpd is responsible for making sure that the MTU
    configured on the system networking interface is low enough so that
    the largest transmitted IP packet does not exceed the peer\'s
    negotiated MRU after it becomes a PPP frame. This includes e.g. PPP
    encryption and/or compression overhead.

    However, mpd does not account for overhead that occurs
    \`\`outside\'\' of the PPP frame. For example, when using link types
    such as PPTP that encapsulate PPP frames within IP packets, a large
    outgoing \`\`inner\'\' IP packet can result in a fragmented
    \`\`outer\'\' IP packet, resulting in suboptimal performance. In
    this situation it may be useful to set the link MTU to a lower value
    to avoid fragmentation.

**`set link accmap value`**

:   This sets the desired asynchronous control-character map for the
    link at the local end. This option is only relevant for the
    asynchronous link types (i.e., **modem** and **tcp**). It determines
    which control characters need to be escaped.

    The `value` is expressed as a 32-bit hex value; the default is
    `0x000a0000`, which escapes the Control-S and Control-Q characters.

**`set link ident string`**

:   This enables the sending of an identification string to the peer via
    the LCP Ident code. The Ident string is sent when the link is
    brought up. This is useful for debugging, etc. and is meant to be
    human-readable. However, it confuses some broken PPP
    implementations.

    Setting an empty string disables this feature; this is the default.

**`set link fsm-timeout seconds`**

:   This command is analogous to the same command at the bundle layer,
    but it applies to link-layer FSM\'s such as Link Control Protocol
    (LCP). The default is two seconds; normally this value should not be
    changed.

**`set link keep-alive seconds max`**

:   This command enables the sending of LCP echo packets on the link.
    The first echo packet is sent after `seconds` seconds of quiet time
    (i.e., no frames received from the peer on that link). After
    `seconds` more seconds, another echo request is sent. If after `max`
    seconds of doing this no echo reply has been received yet, the link
    is brought down.

    If `seconds` is zero, echo packets are disabled. The default values
    are five second intervals with a maximum no-reply time of forty.

    This feature is especially useful with modems when the carrier
    detect signal is unreliable. However, in situations where lines are
    noisy and modems spend a lot of time retraining, the `max` value may
    need to be bumped up to a more generous value.

**`set link max-redial num`**

:   When a link fails to connect, mpd automatically retries the
    connection. This command limits the number of consecutive retries.
    After `num` attempts, mpd will give up.

    When there is another open event, new dial-on-demand traffic, etc.
    mpd will try again, starting over at zero.

    If `max-redial` is set to -1, then mpd will never redial. This
    setting should be used with links that are dedicated for dial-in.

    If `max-redial` is set to 0, then mpd will redial infinitely.

    The default value is -1.

**`set link redial-delay seconds`**

:   This command defines time between connection retries.

    The default value is 1.

**`set link max-children num`**

:   This template option specifies maximum number of links, created
    using this template, that could exist at the same time. Value 0
    disables template.

    The default value is 10000.

**`set link accept option ... `**

:   

**`set link deny option ... `**

:   

**`set link enable option ... `**

:   

**`set link disable option ... `**

:   

**`set link yes option ... `**

:   

**`set link no option ... `**

:   These commands configure various link options. Most options are
    *bi-directional* in that they can be independently enabled and
    disabled in each direction.

    The `enable` and `disable` commands determine whether we want the
    corresponding option. The `accept` and `deny` commands determine
    whether we will allow the peer to request the corresponding option.

    Note that when talking about the authentication options PAP and
    CHAP, when you `enable` an option you\'re saying you are going to
    require a login and password from the peer. When you `accept` an
    option you\'re saying you will allow the peer to require a login and
    password from us.

    The **`yes`** command is the same as `enable` and `accept`. The
    **`no`** command is the same as `disable` and `deny`.

The options available at the link layer are:

**`pap`**

:   PAP style authentication. Note that this style of authentication is
    insecure, since the password crosses the link in plaintext.

    Default `disable` and `accept`.

**`chap`**

:   CHAP style authentication. This style of authentication is safer
    than PAP, because only a hash of the password is passed over the
    link. Mpd supports MD5 style CHAP and Microsoft style CHAP versions
    1 and 2. Mpd will prefer Microsoft CHAP over MD5 CHAP to get
    encryption keys.

    This option is an alias for `chap-md5` `chap-msv1` `chap-msv2`

**`chap-md5`**

:   Traditional CHAP MD5 style authentication.

    Default `disable` and `accept`.

**`chap-msv1`**

:   Microsoft CHAP style authentication.

    Default `disable` and `deny`.

**`chap-msv2`**

:   Microsoft CHAP style authentication Version 2.

    Default `disable` and `accept`.

**`eap`**

:   Extensible Authentication Protocol. For details see [the EAP
    chapter](mpd21.html#eap).

    Default `disable` and `accept`.

**`incoming`**

:   This option enables the acceptance of incoming connections. If this
    option is disabled, mpd will not accept incoming connections using
    this link. To avoid races it is advised to enable it after all other
    link options are configured.

    The default is `disable`.

**`multilink`**

:   This command enables multi-link PPP on the link. This option is
    required in both directions if there is more than one link in the
    bundle. However, multi-link PPP is sometimes useful on single links
    when the link MTU is low; multi-link PPP allows arbitrarily long
    packets to go over a link in fragments.

    The default is `disable` (i.e., normal non-multilink PPP).

**`shortseq`**

:   This option is only meaningful if multi-link PPP is negotiated. It
    proscribes shorter multi-link fragment headers, saving two bytes on
    every frame.

    The default is `enable` and `accept`.

**`acfcomp`**

:   Address and control field compression. This option only applies to
    asynchronous link types. It saves two bytes per frame.

    The default is `enable` and `accept`.

**`protocomp`**

:   Protocol field compression. This option saves one byte per frame for
    most frames.

    The default is `enable` and `accept`.

**`magicnum`**

:   

**`check-magic`**

:   The `magicnum` option enables using a magic number for the local end
    of the PPP link. This causes a unique number to be included in each
    LCP packet we send, which helps detect loopback conditions.

    The `check-magic` option causes mpd to verify that the peer\'s magic
    number is correct in all received LCP frames.

    Some old broken PPP implementations do not handle magic numbers
    correctly, so these options need to be disabled in these cases.

    Default for both options is `enable`.

    Note that the two most common reasons for seeing \`\`loopback
    condition detected\'\' on a modem link are:

    -   The modem is in command mode and is echoing back all of our
        frames.
    -   The PPP server is not in PPP mode, but is giving a shell prompt
        or somesuch and echoing back all of our frames.

**`passive`**

:   Enables passive mode for this link. This is useful on some full time
    connections. See RFC 1661 for more information about this option.

    Default `disable`.

**`callback`**

:   Enables PPP callback request. If the remote peer can/wants to, it
    will hangup immediately after connecting and call us back.

    Default `disable`.

**`no-orig-auth`**

:   Normally, if PAP or CHAP is enabled, we require the peer to
    authenticate to us at the beginning of each connection. This option
    temporarily disables this requirement if we are the one who
    originated the connection and the peer rejects our request for a
    login.

    This is useful when the same link is used for both dial-in and
    dial-out.

    Default `disable`.

**`keep-ms-domain`**

:   Normally, if using MS-CHAP, the MS-Domain is stripped and only the
    plain username is used. Under certain circumstances the MS-Domain
    should be kept, for instance if IAS is used as RADIUS server.

    Default `disable`.

**`time-remain`**

:   Send Time-Remaining LCP packet to the peer if AAA returned session
    timeout.

    Default `disable`.

**`peer-as-calling`**

:   Forces mpd to send remote tunnel address in Calling-Station-Id
    instead of address supplied by remote peer via tunnel (for PPTP and
    L2TP). Can be enabled for untrusted peers.

    Default is `disable`.

**`report-mac`**

:   Forces mpd to send peer MAC address and interface in
    Calling-Station-Id.

    Default `disable`.

### 4.3.1. [EAP](mpd21.html#21)

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** *Link layer*\
**Previous:** [*Mpd Layers*](mpd19.html)\
**Next:** [*EAP*](mpd21.html)
