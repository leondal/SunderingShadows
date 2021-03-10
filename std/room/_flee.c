//

#include <std.h>

inherit DAEMON;


int cmd_flee(){
    
    object ob;
    if(!(object)TP->query_current_attacker()) {
      tell_object(TP,"You cannot flee when you are not in battle.\n");
      return 1;
    }
//added check for combat to avoid fleeing before going into the room.
//Circe 6/26/04
//also added check for property to keep people from spamming flee
//Circe 10/30/04
    if(objectp(TP->query_property("flee"))){
       tell_object(TP,"%^BOLD%^%^MAGENTA%^You are already trying "+
          "to run away!");
       return 1;
    } else {
    tell_room(ETP,"%^BOLD%^"+TPQCN+" attempts to flee combat.",TP);
    tell_object(TP,"%^BOLD%^You attempt to flee combat.");
    ob = new ("/cmds/mortal/obj/flee");
    TP->set_property("flee",ob);
    ob->set_tp(TP);
    ob->set_env(ETP);
    ETP->addObjectToCombatCycle(ob,random(2)+1);
    return 1;
    }
}

int help(){
    write(
@OLI
    flee
    Allows a player to run from combat to the closest exit. This happens much
faster then choosing an exit.
OLI
    );
}

