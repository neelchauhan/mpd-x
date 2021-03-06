[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *Errors*\
**Previous:** [*Script commands*](mpd59.md)\
**Next:** [*The included `mpd.script`*](mpd61.md)

------------------------------------------------------------------------

## []{#60}6.6. Errors

Any errors in the script cause the script to exit unsuccessfully.
Examples of errors include:

-   A `call` or `goto` to a non-existent label
-   A `return` without a corresponding `call`
-   Executing `wait` without any events pending
-   Execution falling off the end of the script
-   Trying to assign `$Baudrate` an invalid baudrate
-   Trying to match with an invalid regular expression

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Chat Scripting*](mpd50.md)
**:** *Errors*\
**Previous:** [*Script commands*](mpd59.md)\
**Next:** [*The included `mpd.script`*](mpd61.md)
