#include <std.h>
#include "../keep.h"
inherit DUNGEON;

void create() 
{
	int x;
    	::create();
    	set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  This corridor slopes "+
	"gradually upward to the south and levels off near the northern "+
	"wall.  Inset directly into the center of the northern wall are "+
	"heavy %^RESET%^%^WHITE%^iron double doors%^BOLD%^%^WHITE%^.  "+
    	"Only darkness and what may lurk within greet you to the south.%^RESET%^\n");
    	set_exits(([
      	"south": KEEPR + "blacktonguelair9","north" : KEEPR + "blacktonguelair11",
    	] ));

    	set_door("iron double doors",KEEPR + "blacktonguelair11","north");
    	set_string("iron double doors", "open", "%^RED%^The massive iron doors "+
	"swing open with suprising ease.%^RESET%^");
    	set_door_description("iron double doors","%^WHITE%^These heavy doors "+
	"are made completely from iron.  A massive wolf head is engraved into "+
	"the center of them.%^RESET%^");

    	for(x = 0;x < sizeof(LITEMS);x++) 
	{
		add_item(LITEMS[x], "%^BOLD%^%^BLACK%^These symbols depict "+
		"numerous wolf-like creatures kneeled before a massive wolf-like "+
		"creature seated on a %^YELLOW%^golden"+
		"%^BOLD%^%^BLACK%^ throne and garbed with an "+
		"%^BLUE%^obsidian%^BOLD%^%^BLACK%^ robe.  "+
		"An uneasy feeling stirs within you.%^RESET%^");
	}


    	add_item("walls","%^BOLD%^%^WHITE%^The walls of this corridor "+
	"are decorated with hieroglyphic symbols.  Inset into the northern "+
	"wall are heavy iron double doors."+
    	"%^RESET%^");
    	set_trap_functions(({"north"}),({"fried"}),({"north"}));

}

int fried()
{	
	toggle_trap("north","north");
	if(!objectp(TP)) return 0;
    	if("daemon/saving_d"->saving_throw(TP,"spell")) 
	{
      	tell_object(TP,"%^BOLD%^%^YELLOW%^A bolt of lightning arcs "+
		"from out of nowhere and grazes you!%^RESET%^");
        	tell_room(TO,"%^BOLD%^%^YELLOW%^A bolt of lightning arcs from "+
		"out of nowhere and grazes " + TPQCN+ "!%^RESET%^",TP);
        	TP->do_damage("torso",roll_dice(5,6));
        	TP->add_attacker(TO);
       	TP->continue_attack();
        	if(objectp(TP)) 
		{
            	TP->remove_attacker(TO);
		}
        	return 1;
    	}
    	else 
	{
      	tell_object(TP,"%^BOLD%^%^YELLOW%^A bolt of lightning arcs "+
		"from out of nowhere and slams into your chest!%^RESET%^");
        	tell_room(TO,"%^BOLD%^%^YELLOW%^A bolt of lightning arcs from out "+
		"of nowhere and slams into " + TPQCN + "'s%^BOLD%^%^YELLOW%^ chest!%^RESET%^",TP);
        	set_property("magic",1);
        	TP->do_damage("torso",roll_dice(10,6));
        	TP->set_paralyzed(6 + random(5),"%^YELLOW%^You're paralyzed from "+
		"the intense pain!%^RESET%^");
        	TP->add_attacker(TO);
        	TP->continue_attack();
        	if(objectp(TP)) 
		{
            	TP->remove_attacker(TO);
        	}
        	set_property("magic",-1);
        	return 1;
    	}

}

