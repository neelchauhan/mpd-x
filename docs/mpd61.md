[*mpdx User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *The included `mpd.script`*\
**Previous:** [*Errors*](mpd60.md)\
**Next:** [*Troubleshooting*](mpd62.md)

------------------------------------------------------------------------

## 6.7. The included `mpd.script`

The `mpd.script` that ships with mpd can usually be used as it is
without modification for typical PPP applications. This script defines
the following labels:

**`DialPeer`**

:   This script causes mpd to attempt to identify the attached modem or
    ISDN Terminal Adapter device, configure the device, and dial a
    remote peer. This the label you want to use for the
    `set modem script` when acting as a dialup client.

    The variables that are used by this script are:

    **`$Telephone`**

    :   The telephone number to dial.

    **`$DialPrefix`**

    :   Dialing prefix to get an outside line, if any.

    **`$ConnectTimeout`**

    :   Time in seconds to wait for the modems to connect. Default 45
        seconds.

    **`$SpeakerOff`**

    :   Set this to `yes` if you want to silence the modem speaker while
        dialing.

    **`$Serial230K`**

    :   If your serial port is capable of running at 230K baud, set this
        to `yes`. Note: normal PC hardware is not capable of 230K.

    In addition, the following variables are required to be set for ISDN
    terminal adapters:

    **`$TA_Bonding`**

    :   If the terminal adapter should do 2 B-channel multi-link PPP,
        set this to `yes`. Note: a terminal adapter doing multi-link PPP
        still *appears* to mpd as a single link PPP connection and
        should be configured as such.

    **`$TA_NoDoubleTelno`**

    :   When `$TA_Bonding` is `yes`, do not double the dialed number.
        Normally, in such situations mpd dials using the command
        `ATDT${Telephone}&${Telephone}`. If your `$Telephone` string
        already contains both numbers, then set `$TA_NoDoubleTelno` to
        `yes`.

    **`$TA_56K`**

    :   If you need to restrict the B channels to to 56K, set this to
        `yes`. Only necessary for some North American ISDN lines.

    **`$TA_VoiceCall`**

    :   If you need to place a voice mode call, set this to `yes`. Only
        necessary for some North American ISDN lines. Not all terminal
        adapters support this.

    **`$TA_AuthChap`**

    :   Some older terminal adapters require you to specify *a priori*
        whether CHAP or PAP authentication will be requested by the
        remote side. Set to `yes` to tell the terminal adapter to use
        CHAP.

    **`$TA_SwitchType`**

    :   Set this to your ISDN line\'s switch type. Should be one of
        `NI-1`, `DMS-100`, `5ESS P2P`, or `5ESS MP`. Only required for
        North American ISDN.

    **`$TA_Dirno1`**

    :   

    **`$TA_Dirno2`**

    :   

    **`$TA_SPID1`**

    :   

    **`$TA_SPID2`**

    :   Set these to your ISDN line\'s directory numbers and SPID\'s for
        both B channels. Only required for North American ISDN.

**`AnswerCall`**

:   This is an **idle script** that waits for an incoming call and then
    answers it. The variables that are used by this script are:

    **`$ConnectTimeout`**

    :   Time in seconds to wait for the modems to connect. Default 45
        seconds.

    **`$RingTimeout`**

    :   How long to wait for a RING before giving up and trying again.
        Default 10 minutes.

**`Ringback`**

:   This is also an idle script that waits for an incoming call, but
    instead of answering the call it ignores it and initiates an
    outgoing connection. This is useful for remotely bringing up a
    dialup client machine.

    **`$RingbackTimeout`**

    :   How long before giving up (reset and try again). Default: 60
        minutes.

    **`$RingStoppedTime`**

    :   For analog modems, we have to wait for the ringing to stop
        before trying to dial out, otherwise we\'ll inadvertently answer
        the incoming call. This value is set to the minimum time to wait
        before declaring that the ringing has stopped. Default: 8
        seconds.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *The included `mpd.script`*\
**Previous:** [*Errors*](mpd60.md)\
**Next:** [*Troubleshooting*](mpd62.md)
