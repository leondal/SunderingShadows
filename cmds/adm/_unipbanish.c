//      /bin/adm/_unregister.c
//      from the Nightmare Mudlib
//      takes a site off of the list of sites needing to register
//      created by Shadowwolf@Nightmare 93????
//      rewritten for the new 3.0 security system

#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

int cmd_unipbanish(string str) {
    if(!member_group(geteuid(previous_object()), "superuser")) {
    if(!member_group(geteuid(previous_object()), "law")) return 0;
    }
    if(!str) return 0;
    seteuid(UID_BANISH);
    if(member_array(str, (string *)BANISH_D->query_blocked()) == -1) {
        write("That site is not on the list of sites being blocked by ip address..\n");
        return 1;
    }
    BANISH_D->unblock_site(str);
    seteuid(UID_LOG);
    log_file("watch/set-ipblock", (string)previous_object()->query_name()+
      " UNBLOCKED "+str+": "+ctime(time())+"\n");
    write("Site : "+str+" is now not on the block list.\n");
    seteuid(getuid());
    return 1;
}


void help() {
    write("Syntax: <unipbanish [site]>\n\n"
      "Takes a site off the list of sites which cannot be logged in to SG.\n"
      "\nSee also:\n"
      "register, whoregistered, banish, unbanish, whobanished, letin,\n"
      "wholetin, unletin\n"
    );
}
