//      /bin/adm/_whoguests.c
//      from the Nightmare Mudlib
//      shows the list of guests allowed in when the mud is locked
//      created by Descartes of Borg 08 july 1993

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_whoguests(string str) {
    string *guests;

    if(!archp(previous_object())) return 0;
    if(str) {
        notify_fail("Correct syntax: whoguests\n");
        return 0;
    }
    seteuid(UID_BANISH);
    catch(guests = (string *)BANISH_D->query_guests());
    seteuid(getuid());
    guests = sort_array(guests,"sort_em",this_object());
    message("info", "%^BOLD%^%^GREEN%^The following people are currently allowed in when the mud is locked: ", this_player());
    if(!sizeof(guests)) message("info", "No guests allowed.", this_player());
    else this_player()->more(explode(format_page(guests, 5), "\n"));
    return 1;
}
int sort_em(string one, string two) {
     return strcmp(one, two);
}


void help() {
    message("help",
      "Syntax: <whoguests>\n\n"
      "Lists all the guests allowed into the game when it is locked.\n\n"
      "See also: addguest, removeguest", this_player()
    );
}
