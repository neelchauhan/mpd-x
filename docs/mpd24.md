[*mpdx User Manual*](README.md) **:** [*Configuring mpdx*](mpd17.md)
**:** *Compression (CCP) layer*\
**Previous:** [*Encryption (ECP) layer*](mpd23.md)\
**Next:** [*MPPC protocol*](mpd25.md)

------------------------------------------------------------------------

## 4.6. Compression (CCP) layer

This chapter describes commands that configure the Compression Control
Protocol (CCP) layer. All of these commands apply to the currently
active bundle.

To use CCP you should enable compression at the bundle level. To allow
compression to be negotiated you should enable here some of compression
protocols.

**`set ccp accept option ... `**

:   

**`set ccp deny option ... `**

:   

**`set ccp enable option ... `**

:   

**`set ccp disable option ... `**

:   

**`set ccp yes option ... `**

:   

**`set ccp no option ... `**

:   These commands configure various CCP options. Each direction of
    traffic (transmit and receive) is independent from the other. All
    options default to `disable` and `deny`.

    The `enable` and `disable` commands determine whether we desire the
    corresponding option on received data. The `accept` and `deny`
    commands determine whether we will allow the peer to request the
    corresponding option (which we must enable on our transmitted data).

    The **`yes`** command is the same as `enable` and `accept`. The
    **`no`** command is the same as `disable` and `deny`.

The options available at the CCP layer are listed below.

**`pred1`**

:   This option enables Predictor-1 (RFC 1978) compression. Predictor-1
    compression is much faster then Deflate.

    This option requires ng_pred1 Netgraph node type, which is present
    since FreeBSD 6.2-STABLE of 2007-01-28. If there is no ng_pred1 in
    system, this algorithm is supported in user-level, but will consume
    more CPU power.

    The default is disable.

**`deflate`**

:   This option enables Deflate (RFC 1979) compression. Deflate
    compression usually gives better compression ratio then Predictor-1.

    This option requires ng_deflate Netgraph node type, which is present
    since FreeBSD 6.2-STABLE of 2007-01-28.

    The default is disable.

**`mppc`**

:   This option enables MPPC compression/encryption subprotocol. For
    details see [the MPPC protocol chapter](mpd25.md#mppc).

    The default is disable.

### 4.6.1. [MPPC protocol](mpd25.md#25)

------------------------------------------------------------------------

[*mpdx User Manual*](README.md) **:** [*Configuring mpdx*](mpd17.md)
**:** *Compression (CCP) layer*\
**Previous:** [*Encryption (ECP) layer*](mpd23.md)\
**Next:** [*MPPC protocol*](mpd25.md)
