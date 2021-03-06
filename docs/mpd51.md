[*mpdx User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *Script file format and execution*\
**Previous:** [*Chat Scripting*](mpd50.md)\
**Next:** [*Events*](mpd52.md)

------------------------------------------------------------------------

## 6.1. Script file format and execution

The syntax for `mpd.script` is similar to the other mpd configuration
files. Lines beginning with a hash sign are ignored. A **label** sits on
its own line, starting in the first column and ends with a colon
character.

**Chat commands** are indented with tab characters and written one per
line.

Commands are executed sequentially. Execution continues without stopping
until there is an error or one of the following commands is encountered:

-   **`success`** The script returns success.
-   **`failure`** The script returns failure.
-   **`wait`** Execution of the script is halted until an **event**
    occurs.

Events are described in the next section.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *Script file format and execution*\
**Previous:** [*Chat Scripting*](mpd50.md)\
**Next:** [*Events*](mpd52.md)
