[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** [*Traffic accounting*](mpd33.html) **:** *Accounting Update*\
**Previous:** [*IP Accounting*](mpd35.html)\
**Next:** [*Typed Accounting Update*](mpd37.html)

------------------------------------------------------------------------

## []{#36}4.12.3. Accounting Update

Mpd provides summary traffic statistics in every accounting Update/Stop
call of radius-acct or ext-acct.

For radius-acct it provides such attributes:

**`Acct-Input-Packets`**

:   32bit input packets counter,

**`Acct-Output-Packets`**

:   32bit output packets counter,

**`Acct-Input-Octets`**

:   lower 32bit of input bytes counter,

**`Acct-Output-Octets`**

:   lower 32bit of output bytes counter,

**`Acct-Input-Gigawords`**

:   higher 32bit of input bytes counter,

**`Acct-Output-Gigawords`**

:   higher 32bit of output bytes counter.

For ext-acct it provides:

**`ACCT_INPUT_PACKETS`**

:   64bit input packets counter,

**`ACCT_OUTPUT_PACKETS`**

:   64bit output packets counter,

**`ACCT_INPUT_OCTETS`**

:   64bit input bytes counter,

**`ACCT_OUTPUT_OCTETS`**

:   64bit output bytes counter.

NOTE: as Accounting Update is implemented on a link layer it accounts
traffic via single physical link (without link overhead). So it accounts
traffic after compression, encryption and multilink were applied to it.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** [*Traffic accounting*](mpd33.html) **:** *Accounting Update*\
**Previous:** [*IP Accounting*](mpd35.html)\
**Next:** [*Typed Accounting Update*](mpd37.html)
