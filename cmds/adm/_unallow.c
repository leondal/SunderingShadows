#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

int cmd_unallow(string str) {
    if(!member_group(geteuid(previous_object()), "superuser")) {
    if(!member_group(geteuid(previous_object()), "law")) return 0;
    }
    if(!str) {
        notify_fail("Correct syntax: <unallow [str]>\n");
        return 0;
    }
    seteuid(UID_BANISH);
    if(member_array(str = lower_case(str), 
      (string *)BANISH_D->query_allowed()) == -1) {
        notify_fail(capitalize(str)+" is not set to be let in.\n");
        return 0;
    }
    BANISH_D->unallow_name(str);
    seteuid(UID_LOG);
    log_file("watch/players", (string)previous_object()->query_name()+
      " UNLETIN "+str+": "+ctime(time())+"\n");
    seteuid(getuid());
    return 1;
}

void help() {
    write("Syntax: <unallow [name]>\n\n"
      "Removes a name from the list of names which may be used by\n"
      "players from banned sites to create a new character.\n"
      "\nSee also:\nletin, wholetin, banish, whobanished, unbanish,\n"
      "register, unregister, whoregistered\n"
    );
}
