[*mpdx User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *Modem type commands*\
**Previous:** [*Device Types*](mpd42.md)\
**Next:** [*Netgraph device type commands*](mpd44.md)

------------------------------------------------------------------------

## []{#43}5.1. Modem type commands[]{#modem}

This chapter describes commands that are specific to modem type links.
These commands apply to the currently active link, and are only valid if
the currently active link has type **modem**.

**`set modem device devname`**

:   Modem links operate over serial ports. This command tells mpd which
    serial port to use for this link, and is required. The `devname`
    should be the pathname of a serial device, e.g., `/dev/cuau0`.

**`set modem var $variable string`**

:   Pre-sets the chat script variable `$variable` to contain the string
    `string`. See [the chapter on chat scripting](mpd50.md#chat) for
    more information on chat variables.

**`set modem speed speed`**

:   This commands sets the initial serial port speed when opening the
    serial device, e.g., 9600, 57600, 115200. Note that you can always
    change the serial port speed later from within the chat script.

**`set modem script connect-script`**

:   This command tells mpd which chat script to run in order to initiate
    a PPP connection for this link. The `connect-script` should
    correspond to a label in `mpd.script`. mpdx will jump to this label
    after opening the serial port device. If `connect-script` is not
    set, then the chat phase of the connection is skipped (e.g., if you
    have a direct null modem connection).

**`set modem idle-script idle-script`**

:   This command tells mpd what to do with the serial port when the link
    is not connected. If no `idle-script` is set, then mpd will leave
    the serial port closed when not connected. Otherwise, when the link
    is disconnected mpd runs the `idle-script` chat script. If this
    script returns `failure`, then mpd restarts the script.

    Otherwise, (i.e., if it returns `success`) mpd examines the contents
    of the `$IdleResult` chat variable to decide what to do next. If it
    equals `answer` then mpd will assume that an incoming call has been
    answered and immediately enter PPP negotiation. If it equals
    `ringback` then mpd will close the serial port, reopen it, and
    initiate an outgoing connection normally (i.e., using
    `connect-script`).

    If `$IdleResult` contains anything else or is not set, then mpd acts
    as if `failure` had occurred and simply restarts the script.

**`set modem watch +/-signal ...`**

:   mpdx normally tracks the carrier detect signal on the serial port and
    drops the connection when this signal is lost. You can disable this
    behavior with `set modem watch -cd`. Also, mpd can do the same thing
    with the DSR signal, though the default is to ignore DSR. To enable
    watching of the DSR signal, use `set modem watch +dsr`.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *Modem type commands*\
**Previous:** [*Device Types*](mpd42.md)\
**Next:** [*Netgraph device type commands*](mpd44.md)
