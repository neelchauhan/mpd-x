[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** [*Sets*](mpd55.md) **:** *Special sets and targets*\
**Previous:** [*Sets*](mpd55.md)\
**Next:** [*Variables*](mpd57.md)

------------------------------------------------------------------------

## []{#56}6.3.1. Special sets and targets

The `timer`, `match` and `regex` commands may specify (by omission) the
**default set**. This set is exactly like any other set, except that it
is automatically cancelled after the occurrence of *any* event. It may
be explicitly named by using the empty string, (ie, `""`).

The `timer`, `match` and `regex` commands may also specify (by omission)
the **default target**. This target, whose name is also the empty
string, has the special propery that it always refers to \`\`the
statement immediately following the next wait statement.\'\' That is, if
the target of any event is the default target, the occurrence of that
event just causes execution to continue starting with the statement
following the wait statement.

Finally, when **`all`** is used with the \`\`cancel\'\' command, *all*
sets (i.e., all pending events) are cancelled.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** [*Sets*](mpd55.md) **:** *Special sets and targets*\
**Previous:** [*Sets*](mpd55.md)\
**Next:** [*Variables*](mpd57.md)
