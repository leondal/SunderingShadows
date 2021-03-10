    ///bin/dev/_people.c
    //from the Nightmare mudlib
    //created by Cynosure@Nightmare
    //      check_invis() added by Plura 930201
    //      sort_by_name() added by Plura 930201
    //     parameters mort, newbie, wiz, arch, dead added by Plura 930204
    //      and hmort aswell.

#include <writef.h>
#include <daemons.h>
#include <std.h>

cmd_people(string args)
{
    object * people = users();
    object peep;

    foreach(peep in people) {
        write(sprintf("%4s %12s %s", query_ip_number(peep) == "127.0.0.1" ? "tun" : "lnk", peep->query_name(), peep->query_position()));
    }

    return 1;
}
