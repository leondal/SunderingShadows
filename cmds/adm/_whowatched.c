#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_whowatched(string str) {
    string *who;

    if(!str) {
        notify_fail("Check site or name?\n");
        return 0;
    }
    if(!archp(previous_object())) return 0;
    seteuid(UID_BANISH);
    if(str == "name") who = (string *)BANISH_D->query_watched_names();
    else if(str == "site") who = (string *)BANISH_D->query_watched_sites();
    else {
        notify_fail("Whowatched what?\n");
        seteuid(getuid());
        return 0;
    }
    seteuid(getuid());
    message("info", sprintf("These %ss are being watched:", str),this_player());
    this_player()->more(explode(format_page(who, 4), "\n"));
    return 1;
}
