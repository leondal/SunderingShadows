#ifndef __UDP_H
#define __UDP_H

#define UDP_PATH "/adm/daemon/udp/"

#define PING_Q (UDP_PATH+"ping_q")
#define PING_A (UDP_PATH+"ping_a")

/*
 * We need the ip number, the current socket efuns don't handle using names.
 */
#define MUDLIST_UDP  ({ "146.101.64.2", 4250 }) // discworld
#define MUDLIST_BAK  ({ "129.10.114.86", 5563 }) // tmi-2

/* The currently known types */
#define UDP_STARTUP "startup"
#define UDP_SHUTDOWN "shutdown"
#define INTERMUD_CHANNELS ({ "gwiz" })
#define UDP_PING_Q "ping_q"
#define UDP_PING_A "ping_a"
#define UDP_SUPPORT_Q "support_q"
#define UDP_SUPPORT_A "support_a"
#define UDP_RWHO_Q "rwho_q"
#define UDP_RWHO_A "rwho_a"
#define UDP_MUDLIST_Q "mudlist_q"
#define UDP_MUDLIST_A "mudlist_a"
#define UDP_GFINGER_Q "gfinger_q"
#define UDP_AFFIRMATION_A "affirmation_a"
#define UDP_GFINGER_A "gfinger_a"
#define UDP_GWIZMSG "gwizmsg"
#define UDP_LOCATE_A "locate_a"
#define UDP_LOCATE_Q "locate_q"
#define UDP_WARNING "warning"
#define UDP_GTELL "gtell"

/*
 * This is the number of retrys we ping the mud for before we decide
 * it has gone down.
 */
#define MAX_RETRYS 2
#define UDP_NO_CONTACT "_udp_no_contact"

#endif //__UDP_H
