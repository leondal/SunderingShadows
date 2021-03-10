#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_qmsg(string str){
    string who, type;
    object targ;
    string *stuff;
    int i, j;

    if(!str) return notify_fail("Try again.\n");

    if(sscanf(str, "%s %s", who, type) != 2) return notify_fail("Try again.\n");
    if(!targ = find_player(who)) return notify_fail("Player not here.\n");

    if(type == "tell") type = "reply";
    stuff = targ->query_messages(type);

    if(!stuff || !(j = sizeof(stuff)))
      return notify_fail("There are no saved mesages of that type.\n");

    write("%^BOLD%^Last lines of "+type);
    for(i=0;i<j;i++){
      write("%^CYAN%^>>>%^RESET%^ "+stuff[i]);
    }
    return 1;
}
