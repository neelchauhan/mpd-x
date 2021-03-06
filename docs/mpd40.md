[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** *Control console*\
**Previous:** [*Network Address Translation (NAT)*](mpd39.md)\
**Next:** [*Web server*](mpd41.md)

------------------------------------------------------------------------

## []{#40}4.15. Control console[]{#console}

This chapter describes commands for configuring Mpd\'s console. The
console can be accessed via IPv4 or IPv6 using telnet. Multiple telnet
connections are allowed.

**`set console open`**

:   Opens the console, i.e., creates the listening TCP socket.

**`set console close`**

:   Closes the console, i.e., closes the listening TCP socket. Only the
    listener is affected; active sessions are not closed.

**`set console self ip [ port ]`**

:   Sets the credentials for the console-listener. After changing one of
    these options, the console must be closed and re-opened for the
    changes to take effect.

    The default is \'127.0.0.1 5005\'.

```{.md}
<!-- -->
```

**`set console enable option ... set console disable option ...`**

:   These commands configure various console options.

    The options available for the console are:

**`logging`**

:   This options enables writing of logging messages to the current
    console.

    The default is enable for stdout and disable for the rest.

**`auth`**

:   This options enables authorized login to console. This is a
    read-only value.

    The default is enable.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** *Control console*\
**Previous:** [*Network Address Translation (NAT)*](mpd39.md)\
**Next:** [*Web server*](mpd41.md)
