[*mpdx User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *PPPoE device type commands*\
**Previous:** [*L2TP device type commands*](mpd48.md)\
**Next:** [*Chat Scripting*](mpd50.md)

------------------------------------------------------------------------

## []{#49}5.7. PPPoE device type commands[]{#pppoe}

This chapter describes commands that are specific to PPPoE type links.
These commands apply to the currently active link, and are only valid if
the currently active link has type **pppoe**.

PPPoE requires two pieces of configuration information: the name of the
Ethernet interface to use, and a service name, which should be supplied
by your ISP. If you do not have a service name, then the empty string
(the default) often suffices.

DSL Forum vendor-specific Circuit-ID/Remote-ID PPPoE tags extraction
supported in server mode.

**`set pppoe iface interface-name`**

:   Set the name of the Ethernet interface to use. PPPoE does not affect
    normal use of the interface.

**`set pppoe service service-name`**

:   Sets the requested PPPoE service name. Setting service name to
    \"\*\" on link with allowed incoming connections allows to accept
    incoming connection requests with any service name specified.

    Since FreeBSD 6.3-STABLE/7.0-STABLE of 2008-01-30 it is possible to
    use \"AC-Name\\Service-Name\" syntax to request specified access
    concentrator for outgoing connection.

    The default is \"\*\".

**`set pppoe acname name`**

:   Set name of this PPPoE access concentrator to be sent to clients. If
    not specified, local hostname will be used.

**`set pppoe mac-format format`**

:   Set RADIUS server attribute 31 MAC format as:

        unformatted aabbccddeeff
        unix-like   aa:bb:cc:dd:ee:ff
        cisco-like  aabb.ccdd.eeff
        ietf        aa-bb-cc-dd-ee-ff

    The default is \"unformatted\".

**`set pppoe max-payload size`**

:   Set PPP-Max-Payload PPPoE tag (RFC4638). This option works when mpd5
    acts as PPPoE client only. This option takes precedence over both
    `set link mtu` and `set link mru` options, if PPPoE server agrees
    with our setting.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *PPPoE device type commands*\
**Previous:** [*L2TP device type commands*](mpd48.md)\
**Next:** [*Chat Scripting*](mpd50.md)
