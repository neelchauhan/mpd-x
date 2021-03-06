[*Mpd 5.9 User Manual*](mpd.html) **:** [*Chat Scripting*](mpd50.html)
**:** [*Events*](mpd52.html) **:** *Match events*\
**Previous:** [*Timer events*](mpd53.html)\
**Next:** [*Sets*](mpd55.html)

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

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Chat Scripting*](mpd50.html)
**:** [*Events*](mpd52.html) **:** *Match events*\
**Previous:** [*Timer events*](mpd53.html)\
**Next:** [*Sets*](mpd55.html)
