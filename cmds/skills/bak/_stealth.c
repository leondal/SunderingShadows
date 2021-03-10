//      /bin/user/_stealth.c
//      from the Nightmare mudlib
//      rogue ability
//      created by Descartes of Borg 10 april 1993

#include <std.h>

inherit DAEMON;

int cmd_stealth(string str) {
    int stealth, dex;

    if(this_player()->query_ghost()) return 0;
    stealth = (int)this_player()->query_skill("stealth");
    dex = (int)this_player()->query_stats("dexterity");
    if(stealth < 15) {
        notify_fail("You are not quite sly enough to do that.\n");
        return 0;
    }
    if((int)this_player()->query_sp() < 30) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->set_property("stealth", stealth+dex);
    write("You blend in with your surroundings to move with stealth.\n");
    return 1;
}

void help() {
    write("Syntax: <stealth>\n\n"
      "Allows you to move without being noticed by other players.\n"
    );
}
