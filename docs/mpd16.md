[*mpdx User Manual*](README.md) **:** [*Running mpdx*](mpd9.md) **:**
*mpdx command line interface*\
**Previous:** [*`mpd.script`*](mpd15.md)\
**Next:** [*Configuring mpdx*](mpd17.md)

------------------------------------------------------------------------

## []{#16}3.3. mpdx command line interface[]{#cli}

mpdx provides to user a command line interface on stdin and TCP port.
Here mpd commands can be entered to configure the various layers and
check the status of the defined bundles and links. The commands
available at the command line interface are exactly the same ones
available in the `mpd.conf` config file.

At any given time, there is always exists an *active context* shich
includes active link, bundle and repeater. These name are shown in the
prompt. Here is an example of running mpd with a configuration in
`mpd.conf` that defines a bundle `myisp` containing two links `modem1`
and `modem2`:

> ``
>
>     $ mpd config1
>     Multi-link PPP daemon for FreeBSD
>
>     process 26177 started, version 5.0 (root@orphanage.alkar.net 13:16 22-Sep-2007)
>     [modem1]

By that time, mpd has already read in and executed all the commands
associated with the configuration `config1`, which defines the bundle
`myisp`.

To control mpd runtime you also can connect to mpd\'s Telnet console.

> ``
>
>     > telnet 0 5005
>     Trying 0.0.0.0...
>     Connected to 0.
>     Escape character is '^]'.
>     Multi-link PPP daemon for FreeBSD
>
>     Username: Admin
>     Password: 
>     mpdx pid 1419, version 5.0a1 (root@orphanage.alkar.net 13:16 22-Sep-2007)
>
>     [modem1]

The prompt `[modem1]` shows the currently active link (`modem1`). Any
link specific commands issued at this point will apply to `modem1`.

To change the active link, bundle or repeater, use the `link`, `bundle`
or `repeater` command:

> ``
>
>     [modem1] link modem2
>     [modem2] 

Now any commands entered apply to `myisp` or `modem2`, as appropriate.
This technique works the same way in `mpd.conf`. Also, if changing the
link requires changing bundles as well, mpd will do that too.

The available commands are described in the next chapter. When mpd is
running, the `help` can be used to get more information on a specific
command:

> ``
>
>     [modem2] help show
>     Commands available under "show":
>      bundle   : Bundle status                repeater : Repeater status
>      ccp      : CCP status                   ecp      : ECP status
>      eap      : EAP status                   events   : Current events
>      ipcp     : IPCP status                  ipv6cp   : IPV6CP status
>      iface    : Interface status             routes   : IP routing table
>      layers   : Layers to open/close         device   : Physical device status
>      link     : Link status                  auth     : Auth status
>      radius   : RADIUS status                lcp      : LCP status
>      nat      : NAT status                   mem      : Memory map
>      console  : Console status               web      : Web status
>      global   : Global settings              types    : Supported device types
>      version  : Version string               summary  : Daemon status summary
>     [modem2]

mpdx allows you to use only a prefix of a command, as long as the command
is unambigous:

> ``
>
>     [modem2] b
>     Defined bundles:
>             Bundle         Links
>             ------         -----
>             myisp          modem2[DOWN]
>     [modem2] s
>     s: ambiguous command

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Running mpdx*](mpd9.md) **:**
*mpdx command line interface*\
**Previous:** [*`mpd.script`*](mpd15.md)\
**Next:** [*Configuring mpdx*](mpd17.md)
