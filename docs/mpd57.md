[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *Variables*\
**Previous:** [*Special sets and targets*](mpd56.md)\
**Next:** [*Special variables*](mpd58.md)

------------------------------------------------------------------------

## []{#57}6.4. Variables

**Variables** hold simple strings. They are global and come in two
types: **temporary** and **permanent**. Permanent variables persist over
multiple invocations of the chat script, while temporary variables are
forgotten each time the script completes.

Variables are specified with a dollar sign, then a letter, followed by
letters, digits, and underscores. If the first letter is upper case the
variable is permanent; otherwise it is temporary. The variable name may
be optionally enclosed in curly braces.

Examples:

> ``
>
>     $initString
>     $My_variable_234
>     ${i_am_safely_followed_by_a_letter}

### 6.4.1. [Special variables](mpd58.md#58)

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *Variables*\
**Previous:** [*Special sets and targets*](mpd56.md)\
**Next:** [*Special variables*](mpd58.md)
