[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** [*Authentication, Authorization and Accounting (AAA)*](mpd29.html)
**:** *External authentication*\
**Previous:** [*RADIUS*](mpd30.html)\
**Next:** [*Dynamic Authorization*](mpd32.html)

------------------------------------------------------------------------

## []{#31}4.10.2. External authentication[]{#extauth}

Mpd supports authentication and accounting by calling external scripts.
Pathes to that scripts must be specified using
`set auth extauth-script ...` and `set auth extacct-script ...`
commands.

On invocation extauth/extacct scripts receive on stdin set of request
attribute:value pairs terminated by empty line and must generate
response in same format on stdout.

Supported attributes:

    Name                           Access    Accounting
                            Req Resp    Req Resp
    USER_NAME           +   +   +   -
    AUTH_TYPE           +   -   -   -
    USER_PASSWORD           +   +   -   -
    USER_NT_HASH            -   +   -   -
    USER_LM_HASH            -   +   -   -
    LINK                +   -   +   -
    NAS_PORT            +   -   +   -
    NAS_PORT_TYPE           +   -   +   -
    CALLING_STATION_ID      +   -   +   -
    CALLED_STATION_ID       +   -   +   -
    SELF_NAME           +   -   +   -
    PEER_NAME           +   -   +   -
    SELF_ADDR           +   -   +   -
    PEER_ADDR           +   -   +   -
    PEER_PORT           +   -   +   -
    PEER_MAC_ADDR           +   -   +   -
    PEER_IFACE          +   -   +   -
    PEER_IDENT          +   -   +   -
    RESULT              -   +   -   -
    FRAMED_IP_ADDRESS       -   +   +   -
    PRIMARY_DNS_SERVER      -   +   -   -
    SECONDARY_DNS_SERVER        -   +   -   -
    PRIMARY_NBNS_SERVER     -   +   -   -
    SECONDARY_NBNS_SERVER       -   +   -   -
    FRAMED_ROUTE            -   +   -   -
    FRAMED_IPV6_ROUTE       -   +   -   -
    FRAMED_MTU          -   +   -   -
    FRAMED_COMPRESSION      -   +   -   -
    FRAMED_POOL         -   +   -   -
    SESSION_TIMEOUT         -   +   -   -
    IDLE_TIMEOUT            -   +   -   -
    ACCT_INTERIM_INTERVAL       -   +   -   -
    ACCT_INTERIM_LIM_RECV       -   +   -   -
    ACCT_INTERIM_LIM_XMIT       -   +   -   -
    REPLY_MESSAGE           -   +   -   -
    MS_CHAP_ERROR           -   +   -   -
    IFACE               -   -   +   -
    IFACE_INDEX         -   -   +   -
    BUNDLE              -   -   +   -
    ACCT_STATUS_TYPE        -   -   +   -
    ACCT_SESSION_ID         +   -   +   -
    ACCT_MULTI_SESSION_ID       -   -   +   -
    ACCT_LINK_COUNT         -   -   +   -
    ACCT_TERMINATE_CAUSE        -   -   +   -
    ACCT_SESSION_TIME       -   -   +   -
    ACCT_INPUT_OCTETS       -   -   +   -
    ACCT_INPUT_PACKETS      -   -   +   -
    ACCT_OUTPUT_OCTETS      -   -   +   -
    ACCT_OUTPUT_PACKETS     -   -   +   -
    MPD_RULE            -   +   -   -
    MPD_PIPE            -   +   -   -
    MPD_QUEUE           -   +   -   -
    MPD_TABLE           -   +   -   -
    MPD_TABLE_STATIC        -   +   -   -
    MPD_FILTER          -   +   -   -
    MPD_LIMIT           -   +   -   -
    MPD_INPUT_OCTETS        -   -   +   -
    MPD_INPUT_PACKETS       -   -   +   -
    MPD_OUTPUT_OCTETS       -   -   +   -
    MPD_OUTPUT_PACKETS      -   -   +   -
    MPD_ACTION          -   +   -   -
    MPD_DROP_USER           -   -   -   +
    MPD_IFACE_NAME          -   +   -   -
    MPD_IFACE_DESCR         -   +   -   -
    MPD_IFACE_GROUP         -   +   -   -

Attribute USER_PASSWORD provided in Access-Request only for PAP auth.
Attributes USER_NT_HASH and USER_LM_HASH in Access-Reply used for
MS-CHAP auth only.

In reply script may specify any combination of attributes it needs. The
only mandatory attribute in Access-Response is RESULT. RESULT must be
one of SUCCESS, UNDEF or FAIL. RESULT UNDEF means that mpd should
authenticate user itself using USER_PASSWORD/USER_NT_HASH attribute
supplied by script.

For description of most attributes look their RADIUS alternatives.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](mpd.html) **:** [*Configuring Mpd*](mpd17.html)
**:** [*Authentication, Authorization and Accounting (AAA)*](mpd29.html)
**:** *External authentication*\
**Previous:** [*RADIUS*](mpd30.html)\
**Next:** [*Dynamic Authorization*](mpd32.html)
