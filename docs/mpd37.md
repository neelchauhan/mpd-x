[*mpdx User Manual*](README.md) **:** [*Configuring mpdx*](mpd17.md)
**:** [*Traffic accounting*](mpd33.md) **:** *Typed Accounting
Update*\
**Previous:** [*Accounting Update*](mpd36.md)\
**Next:** [*IP address pools*](mpd38.md)

------------------------------------------------------------------------

## []{#37}4.12.4. Typed Accounting Update

In addition to standard Accounting Update stats, mpd is able to provide
accounting information for any specified traffic types. Traffic types
may be defined using optional third component of mpd-limit\'s left part.

In accounting requests mpd can provide such attributes: for radius-acct:

**`mpd-input-packets`**

:   traffic type : 64bit input packets counter,

**`mpd-output-packets`**

:   traffic type : 64bit output packets counter,

**`mpd-input-octets`**

:   traffic type : 64bit of input bytes counter,

**`mpd-output-octets`**

:   traffic type : 64bit of output bytes counter,

for ext-acct:

**`MPD_INPUT_PACKETS`**

:   traffic type : 64bit input packets counter,

**`MPD_OUTPUT_PACKETS`**

:   traffic type : 64bit output packets counter,

**`MPD_INPUT_OCTETS`**

:   traffic type : 64bit input bytes counter,

**`MPD_OUTPUT_OCTETS`**

:   traffic type : 64bit output bytes counter.

NOTE: as Typed Accounting Update is implemented on interface layer
instead of link as usual Accounting Update, same data will be reported
for every link of multilink connection. Some special care should be
taken by AAA to not account same traffic twice in multilink case.

For example, specification:

    mpd-filter += "1#1=match dst net 10.0.0.0/8",
    mpd-limit += "in#1#Local=flt1 pass",
    mpd-limit += "in#2#Biz=all shape 64000 4000",

, or for ext-auth:

    MPD_FILTER:1#1=match dst net 10.0.0.0/8
    MPD_LIMIT:in#1#Local=flt1 pass
    MPD_LIMIT:in#2#Biz=all shape 64000 4000

will instruct mpd to account traffic of two types: \"Local\" and
\"Biz\". Traffic going from client to the 10.0.0.0/8 network will be
accounted as \"Local\", all other incoming traffic after shaping will be
accounted as \"Biz\". In accounting request mpd will provide to RADIUS
something like:

    mpd-input-packets = Local:213213
    mpd-input-octets = Local:32132132
    mpd-input-packets = Biz:21321
    mpd-input-octets = Biz:3213213

, and for ext-acct:

    ACCT_INPUT_PACKETS:Local:213213
    ACCT_INPUT_OCTETS:Local:32132132
    ACCT_INPUT_PACKETS:Biz:21321
    ACCT_INPUT_OCTETS:Biz:3213213

To simplify AAA integration mpd able to return specified traffic types
using standard RADIUS attributes. Required traffic type can be specified
using mpd-input-acct/mpd-output-acct attributes.

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Configuring mpdx*](mpd17.md)
**:** [*Traffic accounting*](mpd33.md) **:** *Typed Accounting
Update*\
**Previous:** [*Accounting Update*](mpd36.md)\
**Next:** [*IP address pools*](mpd38.md)
