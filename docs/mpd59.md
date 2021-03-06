[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *Script commands*\
**Previous:** [*Special variables*](mpd58.md)\
**Next:** [*Errors*](mpd60.md)

------------------------------------------------------------------------

## []{#59}6.5. Script commands

**`set $variable-name string `**

:   Set the `$variable-name` equal to `string`. The `string` is variable
    expanded first.

**`match name string label `**

:   

**`match string label `**

:   

**`match string `**

:   Add a new pending event to event set `name` such that when `string`
    is seen in the input, resume execution at `label`. The match must be
    exact. All arguments are variable expanded.

    If no `name` is given, or if `name` is the empty string, add the new
    event to the default set.

    If no `label` is given, or if `label` is the empty string, the event
    causes execution to resume starting with the statement following the
    `wait` command (i.e., use the default target).

**`regex name pattern label `**

:   

**`regex pattern label `**

:   

**`regex pattern `**

:   Same as the `match` command, but matches an extended regular
    expression instead of an exact string. If `pattern` is not a valid
    extended regular expression, the script fails.

    Regular expressions are matched on a line-by-line basis; the input
    matching the pattern cannot span more than one line. A line is
    terminated with either a newline or a carriage return-newline pair
    (the latter is more common). An end-of-line should be matched using
    a dollar sign rather than trying to match these characters directly,
    as mpd elides them from the input when testing the regular
    expression.

    See `re_format(7)` for more information about extended regular
    expressions.

**`timer name seconds label `**

:   

**`timer seconds label `**

:   

**`timer seconds `**

:   Add a new pending event to set `name` such that when `seconds`
    seconds have elapsed, resume execution at `label`. All arguments are
    variable expanded.

    If no `name` is given, or if `name` is the empty string, add the new
    event to the default set.

    If no `label` is given, or if `label` is the empty string, the event
    causes execution to resume starting with the statement following the
    `wait` command (i.e., use the default target).

**`wait `**

:   

**`wait seconds `**

:   In the first form, wait indefinitely for any event to happen. When
    an event happens, continue execution starting at the target label
    for that event.

    The second form is equivalent to:

    > ` timer seconds wait`

**`if string1 == string2 command `**

:   

**`if string1 != string2 command `**

:   Executes `command` if the two variable expanded strings are equal or
    not equal.

**`if string match pattern command `**

:   

**`if string !match pattern command `**

:   Tests `string` against the regular expression `pattern` and executes
    `command` if `string` matches or does not match. Both `string` and
    `pattern` are variable expanded first.

**`print string `**

:   Ouput the `string` to the serial port. Variables are expanded, and
    the normal mpd C-style character escapes may be used.

**`cancel name1 [ name2 ... ] `**

:   Cancel all pending events in the sets `name1`, `name2`, etc. It is
    not an error to cancel a set which is already empty.

**`goto label `**

:   Jump to label `label`.

**`call label `**

:   Call a subroutine at `label`.

**`return `**

:   Return from subroutine.

**`success `**

:   Exit the script successfully.

**`failure `**

:   Exit the script unsuccessfully.

**`log string `**

:   Print `string`, variable expanded, to the log file under logging
    level CHAT.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *Script commands*\
**Previous:** [*Special variables*](mpd58.md)\
**Next:** [*Errors*](mpd60.md)
