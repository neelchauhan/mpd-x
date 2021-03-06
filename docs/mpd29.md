[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** *Authentication, Authorization and Accounting (AAA)*\
**Previous:** [*Interface layer*](mpd28.html)\
**Next:** [*RADIUS*](mpd30.html)

------------------------------------------------------------------------

## []{#29}4.10. Authentication, Authorization and Accounting (AAA)[]{#auth}

Mpd currently supports authentication against (tried in this order)
[external script](mpd31.html#extauth), [RADIUS](mpd30.html#radius), PAM,
systems password database (`master.passwd`), OPIE and internal
`mpd.secret` file.

This chapter describes commands that configure the Authentication
subsystem of LCP layer. All of these commands apply to the currently
active link.

**`set auth authname login`**

:   This command sets the authentication login name associated with the
    link (in multi-link PPP, though each link is authenticated
    individually, they all must use the same login name). The `login`
    may have a corresponding entry in `mpd.secret`. The `login` and
    password are used when the peer requires us to authenticate
    ourselves.

**`set auth password password`**

:   This command is normally not necessary. It causes mpd to *not*
    lookup the password corresponding to `login` in `mpd.secret`, but
    rather to use `password` instead. If you\'re too lazy to set up
    `mpd.secret` and are only dialing out, you can use this command
    instead.

**`set auth max-logins num [CI]`**

:   Limit the max. amount of concurrent logins with the same username.
    If set to zero, then this feature is disabled. If CI argument is
    present login comparasion will be case insensitive.

**`set auth acct-update seconds`**

:   Enables periodic accounting updates, if set to a value greater then
    zero.

**`set auth timeout seconds`**

:   Sets the timeout for the whole authentication process. It defaults
    to 40 seconds. Under some circumstances the value should be changed;
    it usually depends on the authentication backend and protocol. E.g.
    when using EAP with a slow RADIUS server this value should be
    increased.

**`set auth extauth-script script set auth extacct-script script`**

:   Sets scripts names for external authentication and accounting.

**`set auth enable option ... set auth disable option ...`**

:   

The options available are:

**`internal`**

:   Enables authentication against the `mpd.secret` file.

    Default `enable`.

**`radius-auth`**

:   Enable authentication via RADIUS. For details see [the RADIUS
    chapter](mpd30.html#radius).

    Default `disable`.

**`radius-acct`**

:   Enable per link accounting via RADIUS. For details see [the RADIUS
    chapter](mpd30.html#radius).

    Default `disable`.

**`ext-auth`**

:   Enable authentication by calling external script. This method
    pretended to be a fullfeatured alternative to the `radius-auth`. For
    details see [the External authentication
    chapter](mpd31.html#extauth).

    Default `disable`.

**`ext-acct`**

:   Enable accounting by calling external script. This method pretended
    to be a fullfeatured alternative to the `radius-acct`. For details
    see [the External authentication chapter](mpd31.html#extauth).

    Default `disable`.

**`pam-auth`**

:   Enables authentication using PAM service \"mpd\". This options can
    only be used with PAP.

    Default `disable`.

**`pam-acct`**

:   Enable accounting using PAM service \"mpd\".

    Default `disable`.

**`system-auth`**

:   Enables authentication against the systems password database. This
    options can only be used with PAP and MS-CHAP, but not with
    CHAP-MD5. If you intend to use this with MS-CHAP, then the passwords
    in the `master.passwd` must be NT-Hashes. You can enable this by
    putting `:passwd_format=nth:` into your `/etc/login.conf`, but you
    need at least FreeBSD 5.2.

    Default `disable`.

**`system-acct`**

:   Enable accounting via utmp/wtmp.

    Default `disable`.

**`opie`**

:   Enables authentication using OPIE. When using PAP there is nothing
    more todo. For all other authentication protocols you have to put
    the username into the `mpd.secret` file, but the specified password
    is then interpreted as secret pass phrase. This is needed, because
    Mpd must be aware of the plaintext password when using CHAP. The
    (windows) endusers could generate their actual responses themselfs
    using Winkey.\
    **IMPORTANT**: Disable the internal authentication when using OPIE
    and CHAP, because otherwise users are also able to authenticate with
    their secret pass phrase.

    Default `disable`.

**`acct-mandatory`**

:   Makes accounting start mandatory. If enabled, on accounting start
    failure connection will be dropped.

    Default `enable`.

### 4.10.1. [RADIUS](mpd30.html#30)

### 4.10.2. [External authentication](mpd31.html#31)

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** *Authentication, Authorization and Accounting (AAA)*\
**Previous:** [*Interface layer*](mpd28.html)\
**Next:** [*RADIUS*](mpd30.html)
