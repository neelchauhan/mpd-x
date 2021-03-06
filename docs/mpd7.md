[*Mpd 5.9 User Manual*](README.md) **:** [*Installation*](mpd5.md)
**:** *Installing mpd*\
**Previous:** [*Getting mpd*](mpd6.md)\
**Next:** [*Building mpd*](mpd8.md)

------------------------------------------------------------------------

## []{#7}2.2. Installing mpd[]{#installing}

If you use the FreeBSD package or port, mpd will be automatically
installed into `/usr/local/sbin/mpd5`. with the default set of device
types compiled into it. In order to run, mpd needs a few configuration
files. The directory `/usr/local/etc/mpd5` is created to hold them. In
it you will find some sample configuration files.

Before you can run mpd, you must set up your site-specific configuration
files. These files are:

****`mpd.conf`****

:   This file defines one or more **configurations**. When mpd is
    invoked, you specify the name of a configuration on the command
    line. This configuration (which merely consists of a series of mpd
    commands) is loaded. If no configuration is given, \'default\'
    configuration is loaded.

    Each configuration defines one or more bundles, links and repeaters.
    They can be defined with the **`create`** command. Subsequent
    commands in the configuration configure the various layers for that
    item.

****`mpd.secret`****

:   This file contains login, password pairs. This is where mpd looks to
    find all authentication information. This file should be readable
    only by `root`.

****`mpd.script`****

:   This file contains chat scripts for modem devices.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Installation*](mpd5.md)
**:** *Installing mpd*\
**Previous:** [*Getting mpd*](mpd6.md)\
**Next:** [*Building mpd*](mpd8.md)
