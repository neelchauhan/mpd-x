[*mpdx User Manual*](README.md) **:** [*Running mpdx*](mpd9.md) **:**
[*Configuration file format*](mpd11.md) **:** *`mpd.conf`*\
**Previous:** [*General properties*](mpd12.md)\
**Next:** [*`mpd.secret`*](mpd14.md)

------------------------------------------------------------------------

## []{#13}3.2.2. `mpd.conf`

An *entry* consists of a *label* followed by a sequence of mpd commands.
A label begins at the first column and ends with a colon character.
Commands are indented with a tab character and follow the label on the
next and subsequent lines.

Here is an example `mpd.conf` that contains a single configuration
`client` that defines a single bundle template `B1` and one link `L1`:

> ``
>
>     #
>     # mpd.conf configuration file
>     #
>
>     client:
>         create bundle template B1
>
>         create link static L1 modem
>         set modem device /dev/cuau0
>         set modem speed 115200
>         set modem script DialPeer
>         set modem idle-script AnswerCall
>         set modem var $DialPrefix "DT"
>         set modem var $Telephone "1234567"
>         set link no pap chap eap
>         set link accept pap
>         set auth authname "MyLogin"
>         set auth password "MyPassword"
>         set link max-redial 0
>         set link action bundle B1
>         open

Commands are independent and executed one by one as if they were entered
using console. Most command operation depends on the active context,
which includes currently active link, bundle and repeater. Information
about active context is shown at the console command prompt. Some
commands, like `link`, `bundle`, `repeater` and `create` can change this
context.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Running mpdx*](mpd9.md) **:**
[*Configuration file format*](mpd11.md) **:** *`mpd.conf`*\
**Previous:** [*General properties*](mpd12.md)\
**Next:** [*`mpd.secret`*](mpd14.md)
