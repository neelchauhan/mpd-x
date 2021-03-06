[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** *Encryption (ECP) layer*\
**Previous:** [*Bundle layer*](mpd22.md)\
**Next:** [*Compression (CCP) layer*](mpd24.md)

------------------------------------------------------------------------

## []{#23}4.5. Encryption (ECP) layer[]{#encryption}

This chapter describes commands that configure the Encryption Control
Protocol (ECP) layer. All of these commands apply to the currently
active bundle.

To use ECP you should enable encryption at the bundle level. To allow
encryption to be negotiated you should enable here some of encryption
protocols.

**Note:** In PPP, encryption should be handled by the ECP rather than
CCP. However, Microsoft combined both compression and encryption into
their \`\`compression\'\' algorithm (MPPC), which is confusing.

**`set ecp key string `**

:   Sets the encryption key.

**`set ecp accept option ... `**

:   

**`set ecp deny option ... `**

:   

**`set ecp enable option ... `**

:   

**`set ecp disable option ... `**

:   

**`set ecp yes option ... `**

:   

**`set ecp no option ... `**

:   These commands configure various ECP options. Each direction of
    traffic (transmit and receive) is independent from the other. All
    options default to `disable` and `deny`.

    The `enable` and `disable` commands determine whether we desire the
    corresponding option on received data. The `accept` and `deny`
    commands determine whether we will allow the peer to request the
    corresponding option (which we must enable on our transmitted data).

    The **`yes`** command is the same as `enable` and `accept`. The
    **`no`** command is the same as `disable` and `deny`.

The options available at the ECP layer are:

**`dese-bis`**

:   This option enables DESE-bis (rfc 2419) encryption. This algorithm
    implemented in user-level, so require much CPU power on fast
    (\>10Mbit/s) links.

    The default is disable.

**`dese-old`**

:   This option enables DESE (rfc 1969) encryption. This algorithm
    implemented in user-level, so require much CPU power on fast
    (\>10Mbit/s) links.

    **Note:** DESE protocol is deprecated. Because of data padding to
    the next 8 octets boundary, required by block nature of DES
    encryption, dese-old option can have interoperability issues with
    other protocols which work over it. As example, it is incompatible
    with Predictor-1 and Deflate compressions.

    The default is disable.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** *Encryption (ECP) layer*\
**Previous:** [*Bundle layer*](mpd22.md)\
**Next:** [*Compression (CCP) layer*](mpd24.md)
