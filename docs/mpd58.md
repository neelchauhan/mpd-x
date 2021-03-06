[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** [*Variables*](mpd57.md) **:** *Special variables*\
**Previous:** [*Variables*](mpd57.md)\
**Next:** [*Script commands*](mpd59.md)

------------------------------------------------------------------------

## []{#58}6.4.1. Special variables

These variables have special meaning in chat scripts:

**`$Login`**

:   Authorization login name as set by `set auth authname`.

**`$Password`**

:   The password corresponding to `$Login`.

**`$modemDevice`**

:   The serial port device in use as set by the `set modem device`
    command, e.g., `/dev/cuau0`. Changing this string does not change
    the port being used.

**`$Baudrate`**

:   Always equals the current baudrate (e.g., \`\`57600\'\'). This is a
    read/write variable; setting it changes the baudrate. Attempting to
    set an invalid baudrate causes the script to fail.

**`$matchedString`**

:   When a `match` event occurs this string contains the input string
    that matched the pattern.

**`$matchedString0 `**

:   

**`$matchedString1 `**

:   

**`$matchedString2 `**

:   

**`... `**

:   When a `regex` event occurs or the `if match` or `if !match`
    commands are executed, and the regular expression pattern contains
    parenthesized subexpressions, these strings will be equal to the
    substrings matching each subexpression. `$matchedString0` is equal
    to the entire string, while `$matchedString1` equals the first
    subexpression match, `$matchedString2` the second, etc.

**`$IdleResult`**

:   This variable is used to return the result of an **idle script**; If
    the value is `answer`, mpd assumes an incoming call has been
    answered. If the value is `ringback`, mpd will initiate an outgoing
    connection. See the chapter on [Modem type
    commands](mpd43.md#modem) for more information.

**`$$`**

:   Always expands to a single dollar sign.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** [*Variables*](mpd57.md) **:** *Special variables*\
**Previous:** [*Variables*](mpd57.md)\
**Next:** [*Script commands*](mpd59.md)
