[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *Events*\
**Previous:** [*Script file format and execution*](mpd51.md)\
**Next:** [*Timer events*](mpd53.md)

------------------------------------------------------------------------

## []{#52}6.2. Events

An **event** is either the expiration of a timer, or the matching of
some pattern in the input. Events that have not happened yet are
**pending events**. Pending events are created with the `timer` and
`match` commands, respectively.

Each pending event has an associated label (called the **target label**)
of the event. When and if the event occurs, execution resumes starting
at the target label. Events only occur during the execution of a `wait`
command.

Events are grouped into named **sets**. Events in the same set are
usually related, in the sense that they represent alternate outcomes to
the same situation.

A set of pending events may be explicitly **cancelled** (i.e.,
forgotten) before they occur with the **`cancel`** command. All events
in the set are cancelled.

The other way a set of pending events may be cancelled is implicitly,
when any event in the set occurs. Execution resumes at the target label
associated with the event that occurred, and all other events in that
set are immediately cancelled.

### 6.2.1. [Timer events](mpd53.md#53)

### 6.2.2. [Match events](mpd54.md#54)

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *Events*\
**Previous:** [*Script file format and execution*](mpd51.md)\
**Next:** [*Timer events*](mpd53.md)
