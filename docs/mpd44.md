[*Mpd 5.9 User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *Netgraph device type commands*\
**Previous:** [*Modem type commands*](mpd43.md)\
**Next:** [*TCP device type commands*](mpd45.md)

------------------------------------------------------------------------

## []{#44}5.2. Netgraph device type commands[]{#netgraph}

This chapter describes commands that are specific to netgraph type
links. These commands apply to the currently active link, and are only
valid if the currently active link has type **ng**.

Note that this device type has no direct way to detect a physical layer
disconnection (i.e., what would be analogous to loss of carrier detect)
except by receiving a write error. One way to achieve this is to insure
that when the physical layer goes down, the connection to the Netgraph
hook is broken.

**`set ng node nodepath`**

:   

**`set ng hook hook`**

:   These commands configure which Netgraph node, and which hook on that
    node, mpd is supposed to connect to. The node is found via the
    absolute Netgraph address `nodepath` and must have a free hook named
    `hook`. Both of these commands are required.

    The hook should be connectable directly to a link hook of the
    `ng_ppp(3)` netgraph node type. That is, it should be prepared to
    transmit and receive PPP frames starting with the address and
    control fields (unless compressed), followed by the PPP protocol
    number and information fields, but containing no checksum field.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Device Types*](mpd42.md)
**:** *Netgraph device type commands*\
**Previous:** [*Modem type commands*](mpd43.md)\
**Next:** [*TCP device type commands*](mpd45.md)
