#include <std.h>
inherit DAEMON;

int cmd_unswarm(string str){
    object ob;

    if(!str) return notify_fail("unswarm what?\n");
    if(!ob = present(str, ETP)) return notify_fail("that is not here\n");
    if(ob->query_property("swarm")) ob->remove_property("swarm");
    tell_object(TP, "Monster unswarmed.");
    return 1;
}

int help(){
    write(
      "Syntax:  unswarm <monster>"
      +"\n\n  Stops monsters that attack in groups from doing so..  E.G. using this on a hobgoblin the the DD caves would cause it not to attack if you attacked his friends."
    );
    return 1;
}
