#include <std.h>

inherit DAEMON;

int cmd_setagg(string str){
    int x;
    string monname;
    object ob;

    if(!str) return notify_fail("Syntax: setagg <monster> <charisma to be attacked>\n");
    if(sscanf(str, "%s %d", monname, x) != 2) return notify_fail("Syntax: setagg <monster> <charisma to be attacked>\n");
    if(!ob = present(monname, ETP)) return notify_fail("That monster is not here.\n");
    if(interactive(ob) && x != 0){
      tell_object(TP, "Aggressiveness of players (and profiles) MUST be 0!  If you have set others to any other number, set them back to 0 NOW!  Love, G.");
      return 1;
    }

    ob->set("aggressive", x);
    ob->remove_property("swarm");
    tell_object(TP, "Aggressiveness of monster now set to "+x);
    return 1;
}

void help(){
    write(
@HELP
Syntax: setagg <monster> <charisma to be attacked>
Sets the 'aggressiveness' of the named monster to the number specified
in <charisma to attack>.
Aggressivness is the charisma that the monster will attack.
E.G. a monster with aggressiveness 15 will attack anyone with a charisma
lower than 15.
P.S. Don't use this command on players, it will mess things up.
HELP
);
}
