//

#include <std.h>

inherit DAEMON;


int cmd_flee(string str)
{
    
    object ob;
   
    if(!(object)TP->query_current_attacker()) 
    {
        tell_object(TP,"You cannot flee when you are not in battle.\n");
        return 1;
    }
    
    if(str == "stop" || str == "end" || str == "cancel" || str == "abandon")
    {
        tell_object(TP, "Abandoning attempt to flee combat!");
        if(objectp(ob = TP->query_property("flee"))) 
        {
            ETP->removeObjectFromCombatCycle(ob);
            ob->remove();
        }
        if(objectp(ob = TP->query_property("my_exiteffect"))) 
        {
             ETP->removeObjectFromCombatCycle(ob);
            ob->remove();
        }
        return 1;
    }
    
    if(objectp(TP->query_property("flee")))
    {
        tell_object(TP,"%^BOLD%^%^MAGENTA%^You are already trying "+
        "to run away!");
        return 1;
    } 
    else 
    {
        tell_room(ETP,"%^BOLD%^"+TPQCN+" attempts to flee combat.",TP);
        tell_object(TP,"%^BOLD%^You attempt to flee combat.");
        ob = new ("/cmds/mortal/obj/flee");
        TP->set_property("flee",ob);
        ob->set_tp(TP);
        ob->set_env(ETP);
        ETP->addObjectToCombatCycle(ob,random(2)+1, 1);
        return 1;
    }
}

int help(){
    write(
"
%^CYAN%^NAME%^RESET%^


flee - escape the combat

%^CYAN%^SYNOPSIS%^RESET%^

flee [%^ULINE%^%^ORANGE%^stop%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

Without an argument will put you in a fleeing position. After some rounds of combat, you will escape the room to random unblocked exit. 

Stacking fleeing will increase flee time the number of rounds you have typed in flee command.

To abandon fleeing, use %^ORANGE%^<flee stop>%^RESET%^ command.

You can also start fleeing just by typing direction you want to flee to, but that won't be as fast.

%^CYAN%^SEE ALSO%^RESET%^

look, sneak, hide_in_shadows
"
    );
}

