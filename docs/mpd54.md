[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** [*Events*](mpd52.md) **:** *Match events*\
**Previous:** [*Timer events*](mpd53.md)\
**Next:** [*Sets*](mpd55.md)

------------------------------------------------------------------------

## []{#54}6.2.2. Match events

Match events are created with the `match` and `regex` commands. A match
event occurs when the pattern specified in the `match` or `regex`
command has been matched in the input. Characters are only input during
the execution of `wait` commands. In order for a pattern to match, the
first matching character of the pattern must be read *after* the event
is created (i.e., during a subsequent `wait` command).

When the pattern is matched, chat script execution continues starting at
the target label. When multiple patterns match on the same input
character, mpd chooses the first one defined to be the one that matches.

The pattern is either plain text or an extended regular expression (see
below).

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** [*Events*](mpd52.md) **:** *Match events*\
**Previous:** [*Timer events*](mpd53.md)\
**Next:** [*Sets*](mpd55.md)
