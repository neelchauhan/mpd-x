[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** [*Authentication, Authorization and Accounting (AAA)*](mpd29.md)
**:** *RADIUS*\
**Previous:** [*Authentication, Authorization and Accounting
(AAA)*](mpd29.md)\
**Next:** [*External authentication*](mpd31.md)

------------------------------------------------------------------------

## []{#30}4.10.1. RADIUS[]{#radius}

This chapter describes RADIUS authentication backend. Mpd supports both
user authentication and session accounting using RADIUS.
RADIUS-Accounting and RADIUS-Authentication are independant so it is
possible to use them in any combination.

All authentication methods are supported with RADIUS (PAP, CHAP,
MS-CHAPv1, MS-CHAPv2, EAP). Password changing is currently not
supported.

All of these commands apply to the currently active link.

**`set radius server name secret [ auth-port [ acct-port ]]`**

:   Configure RADIUS server parameters. Multiple RADIUS servers may be
    configured by repeating this command, and up to 10 servers may be
    specified. If one of auth/acct ports specified as 0, it will not be
    used for requests of that type.

**`unset radius server name [ auth-port [ acct-port ]]`**

:   Deletes cpecific RADIUS server from pool.

**`set radius src-addr ipaddr`**

:   Configure IP address on the multihomed host that is used as a source
    address for all requests.

**`set radius timeout seconds`**

:   Set the timeout for completion of RADIUS requests.

    The default is 5 second.

**`set radius retries #retries`**

:   Set the number of retries for RADIUS requests.

    The default is 3 retries.

**`set radius me IP|ifname|hostname`**

:   Send the given IP in the RAD_NAS_IP_ADDRESS attribute to the server.

**`set radius v6me IPv6`**

:   Send the given IP in the RAD_NAS_IPV6_ADDRESS attribute to the
    server.

**`set radius identifier name`**

:   Send the given name in the RAD_NAS_IDENTIFIER attribute to the
    server. If not set the local hostname is used.

**`set radius enable message-authentic`**

:   Adds the Message-Authenticator attribute to the RADIUS request. The
    Message-Authenticator is an HMAC-MD5 checksum of the entire
    Access-Request packet using the shared secret as the key. This
    should protect the RADIUS server against online dictionary attacks.
    This is mandatory when using the EAP-RADIUS-Proxy and it\'s
    implicitly added to the request by Mpd.

**RADIUS internals**

:   RADIUS attributes supported by mpd:

        N   Name                           Access    Accounting
                                Req Resp    Req Resp
        1   User-Name           +   +   +   -
        2   User-Password       +   -   -   -
        3   CHAP-Password       +   -   -   -
        4   NAS-IP-Address      +   -   +   -
        5   NAS-Port            +   -   +   -
        6   Service-Type        +   -   +   -
        7   Framed-Protocol     +   -   +   -
        8   Framed-IP-Address       -   +   +   -
        9   Framed-IP-Netmask       -   +   +   -
        11  Filter-Id           -   +   -   -
        12  Framed-MTU          -   +   -   -
        13  Framed-Compression      -   +   -   -
        18  Reply-Message       -   +   -   -
        22  Framed-Route        -   +   -   -
        24  State           +   +   +   -
        25  Class           -   +   +   -
        27  Session-Timeout     -   +   -   -
        28  Idle-Timeout        -   +   -   -
        30  Called-Station-Id       +   -   +   -
        31  Calling-Station-Id      +   -   +   -
        32  NAS-Identifier      +   -   +   -
        40  Acct-Status-Type        -   -   +   -
        42  Acct-Input-Octets       -   -   +   -
        43  Acct-Output-Octets      -   -   +   -
        44  Acct-Session-Id     +   -   +   -
        45  Acct-Authentic      -   -   +   -
        46  Acct-Session-Time       -   -   +   -
        47  Acct-Input-Packets      -   -   +   -
        48  Acct-Output-Packets     -   -   +   -
        49  Acct-Terminate-Cause    -   -   +   -
        50  Acct-Multi-Session-Id   -   -   +   -
        51  Acct-Link-Count     -   -   +   -
        52  Acct-Input-Gigawords    -   -   +   -
        53  Acct-Output-Gigawords   -   -   +   -
        60  CHAP-Challenge      +   -   -   -
        61  NAS-Port-Type       +   -   +   -
        64  Tunnel-Type         +   -   +   -
        65  Tunnel-Medium-Type      +   -   +   -
        66  Tunnel-Client-Endpoint  +   -   +   -
        67  Tunnel-Server-Endpoint  +   -   +   -
        85  Acct-Interim-Interval   -   +   -   -
        87  NAS-Port-Id         +   -   +   -
        88  Framed-Pool         -   +   -   -
        90  Tunnel-Client-Auth-ID   +   -   +   -
        91  Tunnel-Server-Auth-ID   +   -   +   -
        95  NAS-IPv6-Address        +   -   +   -
        99  Framed-IPv6-Route       -   +   -   -

            Microsoft VSA (311)
        1   MS-CHAP-Response        +   -   -   -
        2   MS-CHAP-Error       -   +   -   -
        7   MS-MPPE-Encryption-Policy   -   +   -   -
        8   MS-MPPE-Encryption-Types    -   +   -   -
        10  MS-CHAP-Domain      -   +   -   -
        11  MS-CHAP-Challenge       +   -   -   -
        12  MS-CHAP-MPPE-Keys       -   +   -   -
        16  MS-MPPE-Send-Key        -   +   -   -
        17  MS-MPPE-Recv-Key        -   +   -   -
        25  MS-CHAP2-Response       +   -   -   -
        26  MS-CHAP2-Success        -   +   -   -
        28  MS-Primary-DNS-Server   -   +   -   -
        29  MS-Secondary-DNS-Server -   +   -   -
        30  MS-Primary-NBNS-Server  -   +   -   -
        31  MS-Secondary-NBNS-Server    -   +   -   -

            DSL Forum VSA (3561)
        1   ADSL-Agent-Circuit-Id   +   -   +   -
        2   ADSL-Agent-Remote-Id    +   -   +   -

            mpd VSA (12341)
        1   mpd-rule            -   +   -   -
        2   mpd-pipe            -   +   -   -
        3   mpd-queue           -   +   -   -
        4   mpd-table           -   +   -   -
        5   mpd-table-static        -   +   -   -
        6   mpd-filter          -   +   -   -
        7   mpd-limit           -   +   -   -
        8   mpd-input-octets        -   -   +   -
        9   mpd-input-packets       -   -   +   -
        10  mpd-output-octets       -   -   +   -
        11  mpd-output-packets      -   -   +   -
        12  mpd-link            +   -   +   -
        13  mpd-bundle          -   -   +   -
        14  mpd-iface           -   -   +   -
        15  mpd-iface-index     -   -   +   -
        16  mpd-input-acct      -   +   -   -
        17  mpd-output-acct     -   +   -   -
        18  mpd-action          -   +   -   -
        19  mpd-peer-ident      +   -   +   -
        20  mpd-iface-name      -   +   -   -
        21  mpd-iface-descr     -   +   -   -
        22  mpd-iface-group     -   +   -   -
        154 mpd-drop-user       -   -   -   +

    To use mpd VSA you should add such dictionary to your RADIUS server:

        #----------------------------------------------------------
        # dictionary.mpd                                                                                   
                                                                                                           
        VENDOR          mpd             12341                                                              
                                                                                                           
        BEGIN-VENDOR    mpd

        ATTRIBUTE   mpd-rule    1   string
        ATTRIBUTE   mpd-pipe    2   string
        ATTRIBUTE   mpd-queue   3   string
        ATTRIBUTE   mpd-table   4   string
        ATTRIBUTE   mpd-table-static    5   string
        ATTRIBUTE   mpd-filter  6   string
        ATTRIBUTE   mpd-limit   7   string
        ATTRIBUTE   mpd-input-octets    8   string
        ATTRIBUTE   mpd-input-packets   9   string
        ATTRIBUTE   mpd-output-octets   10  string
        ATTRIBUTE   mpd-output-packets  11  string
        ATTRIBUTE   mpd-link    12  string
        ATTRIBUTE   mpd-bundle  13  string
        ATTRIBUTE   mpd-iface   14  string
        ATTRIBUTE   mpd-iface-index 15  integer
        ATTRIBUTE   mpd-input-acct  16  string
        ATTRIBUTE   mpd-output-acct 17  string
        ATTRIBUTE   mpd-action  18  string
        ATTRIBUTE   mpd-peer-ident  19  string
        ATTRIBUTE   mpd-iface-name  20  string
        ATTRIBUTE   mpd-iface-descr 21  string
        ATTRIBUTE   mpd-iface-group 22  string
        ATTRIBUTE   mpd-drop-user   154 integer

        END-VENDOR  mpd
        #----------------------------------------------------------

    Mpd allows RADIUS server to terminate user session by setting vendor
    specific mpd-drop-user attribute to nonzero value in accounting
    start/update reply packet.

**RADIUS ACL\'s**

:   Mpd can use the Access Control Lists (ACLs) given by the RADIUS
    server. This ACLs may include ipfw rules, pipes, queues and tables
    and also mpd internal traffic filtering/shaping/limiting features.
    That two sets are redundant. ipfw proposed as standard and universal
    solution, while internal filter/shaper/limiter based on
    ng_bpf+ng_car expected to work faster with big number of active
    links.

**ipfw**

:   You can write in your RADIUS configuration something like:

        mpd-table += "1=10.0.0.1",
        mpd-table += "1=10.0.0.15",
        mpd-pipe += "1=bw 10Kbyte/s",
        mpd-pipe += "5=bw 20Kbyte/s",
        mpd-rule += "1=pipe %p1 all from any to table\\(%t1\\) in",
        mpd-rule += "2=pipe %p5 all from table\\(%t1\\) to any out",
        mpd-rule += "100=allow all from any to any",

    When mpd receives these parameters it will call ipfw(8) to create
    firewall rules, pipes and queues with unique numbers starting from
    10000 (configurable via \'set global start\...\'). %rX, %pX, %qX,
    %tX and %aX macroses will be expanded within mpd-rule and mpd-queue.
    To the end of each rule will be added \"via ngX\" to make the rule
    apply only to that client\'s networking interface.

    Allowed macroses:

        %rX IPFW rule pool
        %pX IPFW pipe pool
        %qX IPFW queue pool
        %tX IPFW table pool
        %a1 peer negotiated IP address
        %a2 self negotiated IP address

    As a result of this example we would get these commands executed:

        ipfw table 32 add 10.0.0.1
        ipfw table 32 add 10.0.0.15
        ipfw pipe 10000 config bw 10Kbyte/s
        ipfw pipe 10001 config bw 20Kbyte/s
        ipfw add 10000 pipe 10000 all from any to table\(32\) in via ng0
        ipfw add 10001 pipe 10001 all from table\(32\) to any out via ng0
        ipfw add 10002 allow all from any to any via ng0

    When the link goes down, all created rules will be removed.

    Note: As soon as mpd executes ipfw commands using shell, shell\'s
    special characters like \"(\" and \")\" must be slashed.

    You can specify *mpd-table += \"1=peer_addr\"* to use mpd-table with
    the peer negotiated IP address.

**internal (ng_bpf/ng_car)**

:   Mpd can create complex per-interface traffic filtering/limiting
    engines inside netgraph when it is requested by mpd-filter and
    mpd-limit RADIUS attributes.

    mpd-filter attribute is a packet filter declaration for using in
    mpd-limit. mpd-filter consists of two main parts: match/nomatch
    verdict and the condition. tcpdump (libpcap) expression syntax used
    for conditions.

    mpd-filter: *match*\|*nomatch* *{condition}*

    mpd-limit attribute is an action which should be done for packet. It
    consists of two main parts: filter and action.

    mpd-limit: *{filter}* *{action}*

    Filter can be or \"all\" (any packet) or \"fltX\" (packets matching
    to specified mpd-filter).

    filter: *any*\|*fltX*

    Action can be: \"\" (do nothing, just account), \"pass\" (stop
    processing and pass packet), \"deny\" (stop processing and drop
    packet), \"rate-limit\" (do Cisco-like rate-limit), \"shape\" (do
    simple RED aware traffic shaping).

    Actions \"rate-limit\" and \"shape\" can have optional \"pass\"
    suffix to stop processing after doing this action.

    action: \| *pass* \| *deny* \| *rate-limit* *{rate(bits/s)}*
    \[*{normal burst(bytes)}* \[*{extended burst(bytes)}*\]\] \[*pass*\]
    \| *shape* *{rate(bits/s)}* \[*{burst(bytes)}*\] \[*pass*\]

    As example you can write in your RADIUS configuration something
    like:

        mpd-filter += "1#1=nomatch dst net 10.0.0.0/24",
        mpd-filter += "1#2=match dst net 10.0.0.0/8",
        mpd-filter += "2#1=nomatch src net 10.0.0.0/24",
        mpd-filter += "2#2=match src net 11.0.0.0/8",
        mpd-limit += "in#1=flt1 pass",
        mpd-limit += "in#2#Biz=all shape 64000 4000",
        mpd-limit += "out#1=flt2 pass",
        mpd-limit += "out#2#Biz=all rate-limit 1024000 150000 300000",

    As result, one ng_bpf node will be created to implement traffic
    filters and several (two for this example) ng_car nodes for traffic
    shaping and rate-limiting. Incoming traffic to 10.0.0.0/8 except
    10.0.0.0/24 will be passed, other traffic will be shaped to
    64Kbits/s. Outgoing traffic from 10.0.0.0/8 except 10.0.0.0/24 will
    be passed, all other will be limited to 1024Kbit/s. Also traffic
    that passed mpd-limit rules marked \"Biz\" will be accordingly
    accounted and present with that name in AAA accounting requests.

------------------------------------------------------------------------

[*Mpd 5.9 User Manual*](README.md) **:** [*Configuring Mpd*](mpd17.md)
**:** [*Authentication, Authorization and Accounting (AAA)*](mpd29.md)
**:** *RADIUS*\
**Previous:** [*Authentication, Authorization and Accounting
(AAA)*](mpd29.md)\
**Next:** [*External authentication*](mpd31.md)
