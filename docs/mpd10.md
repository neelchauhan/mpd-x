[*mpdx User Manual*](README.md) **:** [*Running mpdx*](mpd9.md) **:**
*Invoking mpd*\
**Previous:** [*Running mpdx*](mpd9.md)\
**Next:** [*Configuration file format*](mpd11.md)

------------------------------------------------------------------------

## []{#10}3.1. Invoking mpd[]{#invoke}

mpdx is invoked by first setting up your configuration files, and then
running

> ` mpd [ options ] [ configuration ] `

On startup mpd run commands from the `startup` label. After that, if
`configuration` is supplied, mpd looks in `mpd.conf` for a matching
label, and runs the corresponding commands. If `configuration` is not
supplied, mpd looks for the configuration named `default`.

mpdx can either be run in interactive mode or in the background as a
daemon. In interactive mode mpd accepts commands typed at the console.

mpdx understands the following command line options. Each option has a
short, single character form, as well as an equivalent long form.

**`-b  --background`**

:   Run as a background daemon.

**`-d  --directory dir`**

:   This option allows you to specify a different directory for the mpd
    configuration files other than the default `/usr/local/etc/mpd`.

**`-f  --file filename`**

:   Specify an initial configuration file other than the default,
    `mpd.conf`.

**`-o  --one-shot`**

:   This option forces mpd terminate itself after the last link
    disappear. Link templates are not counted as links.

**`-p  --pidfile filename`**

:   mpdx will open and lock `filename` and write its process ID before
    starting. If another mpd process is already running, mpd will not
    start. The default is `/var/run/mpd.pid`.

**`-k  --kill`**

:   With this option, pd will attempt to kill any existing mpd process
    before beginning execution. The previous process must have written
    its process ID in the PID file `/var/run/mpd.pid` (or the file you
    specify with the `--pidfile` option).

**`-s  --syslog-ident ident`**

:   mpdx normally logs via `syslog(3)` with the identifier `mpd`. This
    option allows you to change that identifier.

**`-m  --pam-service service`**

:   mpdx normally invoke `pam(3)` with the service `mpd`. This option
    allows you to change that service.

**`-v  --version`**

:   Displays the version number of mpd and exits.

**`-h  --help`**

:   Displays a usage message and exits.

mpdx responds to the following signals while it is running:

**SIGTERM**

:   Attempt to gracefully shut down all active connections and exit.

**SIGUSR1**

:   This signal causes mpd to initiate a connection with the first link.
    If mpd is already attempting to connect, this signal has no effect.

**SIGUSR2**

:   This signal has the opposite effect, namely, it causes mpd to close
    the first link. If the link is already in a closed state, this
    signal has no effect.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Running mpdx*](mpd9.md) **:**
*Invoking mpd*\
**Previous:** [*Running mpdx*](mpd9.md)\
**Next:** [*Configuration file format*](mpd11.md)
