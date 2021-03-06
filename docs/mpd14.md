[*mpdx User Manual*](README.md) **:** [*Running mpdx*](mpd9.md) **:**
[*Configuration file format*](mpd11.md) **:** *`mpd.secret`*\
**Previous:** [*`mpd.conf`*](mpd13.md)\
**Next:** [*`mpd.script`*](mpd15.md)

------------------------------------------------------------------------

## 3.2.3. `mpd.secret`

This file contains login, password pairs, one entry per line. Each entry
may have an optional third argument, which is an IP address with
optional netmask width. This is used when negotiating IP addresses with
the corresponding peer. We restrict the allowable IP addresses we\'ll
assign to the peer to lie within the specified range.

In the example below, we define two ISP accounts that we use to connect
to the Internet. Also, we have three friends who are allowed to connect
to us, and we want to restrict the IP addresses that we\'ll let them
have. Finally, the last user\'s password is retrieved by an external
program.

> ``
>
>     #
>     # mpd.secret configuration file
>     #
>
>     # my two ISP accounts
>     mylogin1    password1
>     mylogin2    "Xka \r\n"
>
>     # my three friends
>     bob         "akd\"ix23"   192.168.1.100
>     jerry       "33dk88kz3"   192.168.1.101
>     phil        "w*d9m&_4X"   192.168.1.128/25
>
>     # An external password access program
>     gregory     "!/usr/local/etc/mpd/get_passwd.sh"

Here `bob` and `jerry` must negotiate `192.168.1.100` and
`192.168.1.101`, respectively, while `phil` can ask for any address from
`192.168.1.128` through `192.168.1.255`.

The leading \`\`!\'\' means that the password for user `gregory` is not
stored in the `mpd.secret` file directly. Instead, the named program is
run with the username being authenticated as an additional argument (so
in this case the command line would be
\`\``/usr/local/etc/mpd/get_passwd.sh gregory`\'\'). The command string
may include initial, fixed arguments as well. This program should print
the plaintext password for the named user as a single line to standard
output, and then exit. `mpdx` will block for this operation, so the
program should respond and exit quickly. If there is an error, the
command should print an empty line, or just not print anything.

As a special case, if the username in the `mpd.secret` file is
\`\`\*\'\', then this line must be last as it matches any username. Then
it is up to the external program to determine whether the username is
valid. This wildcard matching only works for \`\`!\'\' lines.

The total length of the executed command must be less than 128
characters. The program is run as the same user who runs `mpd`, which is
usually `root`, so the usual care should be taken with scripts run as
root, e.g., make sure the script is not world-readable or
world-writable. Standard input and standard error are inherited from the
parent `mpd` process. Note that any additional arguments will be visible
to users on the local machine running `ps(1)`.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Running mpdx*](mpd9.md) **:**
[*Configuration file format*](mpd11.md) **:** *`mpd.secret`*\
**Previous:** [*`mpd.conf`*](mpd13.md)\
**Next:** [*`mpd.script`*](mpd15.md)
