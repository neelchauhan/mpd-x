[*mpdx User Manual*](README.md) **:** [*Configuring mpdx*](mpd17.md)
**:** *Web server*\
**Previous:** [*Control console*](mpd40.md)\
**Next:** [*Device Types*](mpd42.md)

------------------------------------------------------------------------

## []{#41}4.16. Web server[]{#web}

mpdx provides HTTP interface for monitoring and control purposes. This
chapter describes commands for configuring mpdx\'s web server.

**`set web open`**

:   Opens the web server, i.e., creates the listening TCP socket.

**`set web close`**

:   Closes the web server, i.e., closes the listening TCP socket.

**`set web self ip [ port ]`**

:   Sets the credentials for the web-listener. After changing one of
    these options, the web must be closed and re-opened for the changes
    to take effect.

    The default is \'127.0.0.1 5006\'.

```{.md}
<!-- -->
```

**`set web enable option ... set web disable option ...`**

:   These commands configure various web server options.

    The `enable` and `disable` commands determine whether we want the
    corresponding option.

    The options available for the web are:

**`auth`**

:   This option enables basic authorization on web server.

    The default is enable.

You can send any set of command allowed by privileges via WEB server for
mpd infrastructure integration. Depending on URL used mpd supports two
response formats: text.md (/cmd?command1&\...) and text/plain
(/bincmd?command1&\...). Also you can see output \`show summary\`
command in JSON format, typing \`/json\` in URL.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Configuring mpdx*](mpd17.md)
**:** *Web server*\
**Previous:** [*Control console*](mpd40.md)\
**Next:** [*Device Types*](mpd42.md)
