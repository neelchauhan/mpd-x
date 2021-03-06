[*Mpd 5.9 User Manual*](mpd.html) **:** [*Internals*](mpd64.html) **:**
*Hints for developers*\
**Previous:** [*Authentication*](mpd66.html)\
**Next:** [*References*](mpd68.html)

------------------------------------------------------------------------

## []{#67}8.3. Hints for developers[]{#developer}

This chapter describes describes some hints for developers.

**Source-Code-Style**

:   There is not so much to say about that, just take a look at the
    existing source files.\
    The Tab-Width is eight with an indent of fore. Please make a space
    between operators and operands.

**NgFuncGetStats**

:   NEVER call NgFuncGetStats() with the *clear* parameter set to true,
    because there are other functions (echo requests/replies, bandwidth
    management) wich relies on increasing link-stats. Mpd carries a copy
    of the netgraph link-stats at link-level, just use these instead.
    You can call LinkUpdateStats() for updating the internal
    stats-struct.

**New Authentication-Backends**

:   Authentication backends must run independently from the rest of Mpd,
    i.e. you must not access any Mpd resource, because the
    authentication process is started in its own thread (you have to
    take care about thread-safety). An `AuthData` object is passed to
    your authenticating function which carries a copy of all required
    information. If your backend provides other parameters, like MTU,
    IP, etc. then put these at the appropriate place into `AuthData` or
    `Auth`.

    If you can not avoid reading from Mpd\'s internal data, then acquire
    the Giant Mutex:

    ------------------------------------------------------------------------

        [...]
          pthread_mutex_lock(&gGiantMutex);
          [do whatever]
          pthread_mutex_unlock(&gGiantMutex);
        [...]

    ------------------------------------------------------------------------

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Internals*](mpd64.html) **:**
*Hints for developers*\
**Previous:** [*Authentication*](mpd66.html)\
**Next:** [*References*](mpd68.html)
