[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** *Network Address Translation (NAT)*\
**Previous:** [*IP address pools*](mpd38.md)\
**Next:** [*Control console*](mpd40.md)

------------------------------------------------------------------------

## []{#39}4.14. Network Address Translation (NAT)[]{#nat}

This chapter describes commands for configuring Network Address
Translation on Mpd\'s interfaces. NAT is implemented by `ng_nat(4)`
node. To enable it on a particular interface `nat` option should be
used.

**Note:** ng_nat node is available only on FreeBSD 6.0-RELEASE and
newer. Some additional options like setting target address implemented
in later versions.

**`set nat address ip`**

:   Set alias IP address. If not specified, interface IP will be used.

**`set nat target ip`**

:   Set target IP address for unknown incoming packets. If not
    specified, packet will not be modified.

**`set nat red-addr alias_addr local_addr`**

:   Redirect traffic for public (alias) IP address to a machine on the
    local network.

**`set nat red-proto proto alias_addr local_addr [ remote_addr ]`**

:   Redirect traffic of specified protocol for public (alias) IP address
    (optionally from specified remote address) to a machine on the local
    network.

**`set nat red-port proto alias_addr alias_port local_addr local_port [ remote_addr remote_port ]`**

:   Redirect incoming connections arriving to given public (alias)
    address and port, (optionally from specified remote address) to a
    host and port of a machine on the local network.

**`unset nat red-addr alias_addr local_addr`**

:   Deletes specific *set nat red-addr \...* rule.

**`unset nat red-proto proto alias_addr local_addr [ remote_addr ]`**

:   Deletes specific *set nat red-proto \...* rule.

**`unset nat red-port proto alias_addr alias_port local_addr local_port [ remote_addr remote_port ]`**

:   Deletes specific *set nat red-port \...* rule.

**`set nat enable option ... `**

:   

**`set nat disable option ... `**

:   Enable and disable nat options.

The following options are supported:

**`log`**

:   Enable statistics logging.

    Default is disable.

**`incoming`**

:   Allow unknown incoming packets to pass.

    Default is enable.

**`same-ports`**

:   Try to use same ports while aliasing.

    Default is enable.

**`unreg-only`**

:   Enables aliasing only for unregistered networks.

    Default is disable.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** *Network Address Translation (NAT)*\
**Previous:** [*IP address pools*](mpd38.md)\
**Next:** [*Control console*](mpd40.md)
