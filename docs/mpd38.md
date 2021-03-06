[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** *IP address pools*\
**Previous:** [*Typed Accounting Update*](mpd37.html)\
**Next:** [*Network Address Translation (NAT)*](mpd39.html)

------------------------------------------------------------------------

## []{#38}4.13. IP address pools[]{#ippool}

Mpd implements dynamic IP addresses pool management. When user is
authenticated and auth backend have not provided IP address, it can be
taken from pool. To make it work you should create one or more address
pools with \'set ippool add \...\' command and define which pool should
be used with \'set ipcp ranges \... ippool \...\' command, radius-auth
Framed-Pool attribute or ext-auth FRAMED_POOL attribute.

**`set ippool add pool first last`**

:   This command creates new IP address pool if it not exists and adds
    specified address range to it.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** *IP address pools*\
**Previous:** [*Typed Accounting Update*](mpd37.html)\
**Next:** [*Network Address Translation (NAT)*](mpd39.html)
