//	/cmds/guild/assassin/_go.c
//	For the Nightmare Guild of Assassins
//	By Kalinash@Nightmare on 3 Jan 94

#define MP_COST 150

#include <std.h>

inherit DAEMON;

int cmd_go(string drow) {
    int amt;

    if(!drow || drow != "home")
        return notify_fail("Go where?\n");
    if((string)this_player()->query_guild() != "assassin")
        return notify_fail("You can't do that.\n");
    if((int)this_player()->query_mp() < MP_COST) 
        return notify_fail("You don't have the mental strength right now.\n");
    amt = random(10) + 11;
    if((int)this_player()->query_hp() < amt) 
        return notify_fail("You are too weak.\n");
    this_player()->add_mp(-MP_COST);
    this_player()->add_hp(-amt);
    this_player()->move_player("/realms/kalinash/guild/assassin/room/lounge");
    return 1;
}

void help() {
    message("help", "Usage : go home\n\nUse this command to "
      "return to the guild lounge.  It taxes your body to use it.", this_player());
    return;
}
