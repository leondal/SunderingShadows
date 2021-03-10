//      /bin/adm/_removeguest.c
//      from the Nightmare Mudlib
//      removes a person from the guest list for when the mud is locked
//      created by Descartes of Borg 08 july 1993

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_removeguest(string str) {
    string *guests;
    int i;

    if(!archp(previous_object())) return 0;
    if(!str) {
        notify_fail("Correct syntax: removeguest [guestlist]\n");
        return 0;
    }
    i = sizeof(guests = explode(str, " "));
    seteuid(UID_BANISH);
    while(i--) BANISH_D->remove_guest(guests[i]);
    seteuid(getuid());
    message("info", "Guests removed.", this_player());
    return 1;
}

void help() {
    message("help",
      "Syntax: <removeguest [player list]>\n\n"
      "Removes a single player or a list of players from the guests"
      "allowed onto the mud when it is locked.  This function is generally used to"
      "remove access a player might have been granted by the addguest"
      "command.\n\n"
      "See also: addguest, whoguests", this_player()
    );
}
