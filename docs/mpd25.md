[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** [*Compression (CCP) layer*](mpd24.md) **:** *MPPC protocol*\
**Previous:** [*Compression (CCP) layer*](mpd24.md)\
**Next:** [*IPCP layer*](mpd26.md)

------------------------------------------------------------------------

## []{#25}4.6.1. MPPC protocol[]{#mppc}

Mpd implements Microsoft Point-to-point compression (MPPC) CCP
subprotol. To enable it, \'mppc\' option should be enabled at the CCP
layer.

MPPC CCP subprotocol consists of MPPC compression and MPPE encryption
parts. To make MPPC CCP actually do something you should enable some of
them using options below.

**`set mppc accept option ... `**

:   

**`set mppc deny option ... `**

:   

**`set mppc enable option ... `**

:   

**`set mppc disable option ... `**

:   

**`set mppc yes option ... `**

:   

**`set mppc no option ... `**

:   These commands configure various MPPC options.

**`compress`**

:   Enables MPPC compression. This is the only compression method
    supported by Microsoft Windows RAS.

    Note: This option requires ng_mppc node to be built with compression
    support, which is disabled by default, requiring external compressor
    code. Open-source implementation of this code, based on RFC2118,
    could be found at http://mavhome.dp.ua/MPPC/. But MPPC compression
    algorithm itself covered by US patent, so you may need to contact
    Hi/Fn Inc. to obtain their proprietary implementation. If kernel
    support is not detected, compression will not be negotiated. Use
    \'show version\' command to get actual status.

    The default is disable.

**`e40`**

:   Enables 40-bit MPPE encryption.

    The default is disable.

**`e56`**

:   Enables 56-bit MPPE encryption.

    The default is disable.

**`e128`**

:   Enables 128-bit MPPE encryption.

    Note: in order for MPPE encryption to work, MS-CHAPv1 or MS-CHAPv2
    auth is mandatory, because the MPPE keys are generated using the
    authentication results. If MS-CHAP auth is not used by link,
    encryption will not be negotiated.

    The default is disable.

**`stateless`**

:   Enables stateless mode. This mode requires more CPU time and is
    somewhat less secure, but allows faster recovery in the face of lost
    packets.

    The default is disable.

**`policy`**

:   If enabled, Mpd uses the MPPE-Types and MPPE-Policy info from the
    authentication backend.

    The default is disable.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** [*Compression (CCP) layer*](mpd24.md) **:** *MPPC protocol*\
**Previous:** [*Compression (CCP) layer*](mpd24.md)\
**Next:** [*IPCP layer*](mpd26.md)
