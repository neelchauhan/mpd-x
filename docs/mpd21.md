[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** [*Link layer*](mpd20.html) **:** *EAP*\
**Previous:** [*Link layer*](mpd20.html)\
**Next:** [*Bundle layer*](mpd22.html)

------------------------------------------------------------------------

## []{#21}4.3.1. EAP[]{#eap}

This chapter describes commands that configure the EAP (Extensible
Authentication Protocol). Mpd supports natively only the EAP-Type MD5;
other EAP-Types may be used in conjunction with a RADIUS server. All of
these commands apply to the currently active link.

**`set eap accept option ... `**

:   

**`set eap deny option ... `**

:   

**`set eap enable option ... `**

:   

**`set eap disable option ... `**

:   

**`set eap yes option ... `**

:   

**`set eap no option ... `**

:   These commands configure various EAP options. Most options are
    *bi-directional* in that they can be independently enabled and
    disabled in each direction.

**`md5`**

:   EAP-Type MD5. It\'s the same as CHAP-MD5, except that is framed
    inside EAP packets.

    The default is disable and accept.

**`radius-proxy`**

:   Causes Mpd to proxy all EAP requests to the RADIUS server.

    The default is disable.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** [*Link layer*](mpd20.html) **:** *EAP*\
**Previous:** [*Link layer*](mpd20.html)\
**Next:** [*Bundle layer*](mpd22.html)
