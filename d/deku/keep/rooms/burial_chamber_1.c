#include <std.h>
#include "../keep.h"

inherit TUNNELBUR;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^RED%^  This massive chamber "+
    "opens up to others in three directions here, the north, east, and west.  "+
    "The southern wall, however, seems to be pulsing with a %^BOLD%^%^BLACK%^strange "+
    "darkness%^RESET%^%^BOLD%^%^RED%^.  A pool of %^BOLD%^%^GREEN%^"+
    "stagnant water%^RESET%^%^BOLD%^%^RED%^ has also gathered in the center of "+
    "this chamber.%^RESET%^");  
    set_exits(([
        "north": KEEPR + "burial_chamber_2", "east" : KEEPR + "burial_chamber_3",
        "west" : KEEPR + "burial_chamber_4"
    ] ));
    
    add_items(({"water", "pool", "pool of water", "stagnant water", "stagnant pool"}), 
    "%^BOLD%^%^GREEN%^You look carefully at this pool of water and "+
    "realize that you are unable to determine its depth.  However, it appears "+
    "quite deep and you could probably %^BOLD%^%^RED%^dive%^RESET%^%^BOLD%^%^GREEN%^ "+ 
	"into it, if you were brave enough.%^RESET%^"); 
    
    add_items(({"south wall", "strange darkness", "darkness", "message"}), 
    ({"%^BOLD%^%^BLACK%^The darkness on the southern wall here is constantly "+
    "pulsating and for some reason you believe that it might be a living "+
    "thing.  A sense of fear and dread, mixed with a deep longing is given "+
    "off by it.  You notice that there appears to be a barely noticable "+
    "message written in it.", "\nMy names are three.... \nThe first is written on the "+
    "same grave stone...this one you must read..."+
    "\n\nThe second is written inside the fire, in the blood "+
    "of another who has been forgotten...  you must take on the foolish quest "+
    "for yourself...\n\nThe last is uttered from the dying "+
    "throat of a dead assassin....  you must watch him die.. "+
    "\nShould you face me, say them in order as one "+
    "and let us meet...!"}));
}

void init()
{
    ::init();
    add_action("dive_em", "dive");
    add_action("say_function","say");
}

int dive_em(string str)
{
    if(!str)
    {
        tell_object(TP, "What do you want to dive into?");
        return 1;
    }
    if(str == "water" || str == "pool" || str == "pool of water" ||
    str == "stagnant pool" || str == "stagnant water")
    {
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
        || TP->query_tripped()) 
		{
            TP->send_paralyzed_message("info",TP);
            return 1;
        }
        tell_object(TP, "You decided, against your better judgement, "+
        "to dive head first into the stagnant water!");	
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN + " dives head first into the pool of "+
            "%^BOLD%^%^GREEN%^stagnant water%^RESET%^!", TP);
        }
        TP->move(KEEPR+"tunnel_uw12");
        TP->force_me("look");
        return 1;
    }
    else 
    {
        tell_object(TP, "What do you want to dive into?");
        return 1;
    }
}

int say_function(string str) 
{
    int flag, i;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if((string)TP->query("last say") == str) 
    {
        return 0;
    }

    if(strsrch(str,"salvirius enagmus maltoore") != -1 || 
    strsrch(str, "Salvirius Enagmus Maltoore")!= -1) 
    {
        if((string)TP->query("first_burial_name") != "salvirius" ||	
        (string)TP->query("second_burial_name") != "enagmus" ||
        (string)TP->query("last_burial_name") != "Maltoore")
        {
            tell_object(TP, "%^BOLD%^%^RED%^A voice yells inside your head:  "+
            "%^RESET%^You DID NOT LISTEN TO "+
            "my INSTRUCTIONS!! YOU ARE NOT WORTHY!!!");
            
            tell_object(TP, "%^BOLD%^%^BLACK%^As you're trying to comprehend this "+
            "a massive black tendril jumps out from the darkness and smacks you "+
            "across the room!");
			
            TP->do_damage("head", roll_dice(4,6));
            tell_room(TO, TPQCN + "%^BOLD%^%^BLACK%^ begins speaking and before "+
            TP->QS + "%^BOLD%^%^BLACK%^ finishes "+TP->QP+" sentence a "+
            "massive black tendril jumps out from the darkness and smacks "+
            TP->QO+ " across the room!%^RESET%^", TP);
            TP->set_paralyzed(8, "%^BOLD%^%^BLACK%^You are recovering from "+
            "the tendril's brutal assault!%^RESET%^"); 
            return 1;
        }
        else
        {
            tell_object(TP, "%^BOLD%^%^BLACK%^Before you can completely finish "+
            "your words, a massive black tendril jumps out from the darkness and "+
            "grabs you, pulling you back with it!%^RESET%^");
            tell_room(TO, TPQCN + "%^BOLD%^%^BLACK%^ begins speaking and before "+
            TP->QS + "%^BOLD%^%^BLACK%^ finishes "+TP->QP+" sentence a "+
            "massive black tendril jumps out from the darkness and pulls "+
            TP->QO+ " back with it into the darkness!%^RESET%^", TP);
            TP->move(KEEPR+"burial_chamber_5");
            TP->force_me("look");
            return 1;
        }
    }    
    return 0;
}

