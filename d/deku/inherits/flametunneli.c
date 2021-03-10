#include <std.h>
#include <daemons.h>
#include "forest.h"
inherit CROOM;
int getmobs;
void create() {
    getmobs = random(2);
    if(!getmobs) {
        if(base_name(TO) != FIRE_TUNI)
	  {
		if(strsrch(base_name(TO), "war_mongrels_tunnel") != -1)
		{
			if(base_name(TO) != FTUN_ROOMS"war_mongrels_tunnel10")
			{	
				switch(random(2))
				{
					case 0:
						set_monsters(({DEKU_MON"fire_imp"}), ({random(2)}));
						set_monsters(({DEKU_MON"hellhound"}), ({1 + random(2)}));
						break;
					case 1:
						set_monsters(({DEKU_MON"hellfire_golem"}), ({1 + random(2)}));
						set_monsters(({DEKU_MON"fire_elemental"}), ({random(2)}));
						break;
				}
	      	      set_repop(50);
			}
		}		
		else if(base_name(TO)[43..43] == "n")
		{
                	set_monsters(({DEKU_MON"fire_imp"}),({1 + random(3)}));
                	set_repop(50);
		}
		else if(base_name(TO)[43..43] == "s")
		{
			set_monsters(({DEKU_MON"fire_elemental"}),({1 + random(2)}));
                	set_repop(50);
		}
		else if(base_name(TO)[43..43] == "e")
		{
			set_monsters(({DEKU_MON"hellhound"}),({1 + random(3)}));
                	set_repop(50);
		}
		else if(base_name(TO)[43..43] == "w")
		{
			set_monsters(({DEKU_MON"hellfire_golem"}),({1 + random(2)}));
                	set_repop(50);
		}
        }
    }
    ::create();
    set_short("%^RED%^A tunnel of fl%^ORANGE%^a%^RESET%^%^RED%^"+
    "m%^ORANGE%^e%^RESET%^%^RED%^s%^RESET%^");
    set_name("A tunnel of flames");
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("no teleport",1);
    set_property("no sticks",1);
    set_long("%^RED%^You are inside a tunnel made entirely from "+
    "fire.  The walls and ceiling of this tunnel are "+
    "entirely circular and smooth, the ceiling hangs some "+
    "undeterminable distance overhead and the walls are far enough "+
    "apart for several wagons to easily pass through.  The floor "+
    "here is jagged and rugged, the fire roaring upward to conceal "+
    "your feet, but the sting from it is light, as if something "+
    "is keeping it's destructive power at bay.  As you ponder this "+
    "you realize that there is a barely visible light %^BLUE%^"+
    "blue%^RESET%^%^RED%^ barrier surrounding the fire on the "+
    "inside of the tunnel.  You realize that just beyond the "+
    "barrier the fire is raging and out of control and "+
    "occassionally the barrier wavers, leaving you unsure of its "+
    "strength and very wary of how long it might hold.%^RESET%^");
  
   
    set_listen("default","%^RED%^The roar of out of control "+
    "fire drowns out any and all other sounds.%^RESET%^");
    set_smell("default","The scent of sulfur and burning flesh "+
    "hangs so heavily in the air here that it is almost tangible.");
    
    set_items(( [
        ({"walls","wall"}) : "%^RED%^The walls here are made "+
        "entirely from fire.  They are entirely smooth and "+
        "covered with a %^BLUE%^blue%^RESET%^%^RED%^ barrier."+
        "%^RESET%^",
        "ceiling" : "%^RED%^The ceiling here is made from fire and "+
        "covered by a %^BLUE%^blue%^RESET%^%^RED%^ barrier.  "+
        "It is entirely smooth and hangs some undeterminable "+
        "distance overhead.%^RESET%^",
        "floor" : "%^RED%^The floor is made from a fire that roars "+
        "upward to conceal your feet.  The fire gives it an "+
        "appearance of being jagged and uneven, yet somehow "+
        "the flame does not harm you.%^RESET%^",
        "fire" : "%^RED%^This entire tunnel is made from a raging and "+
        "out of control fire.  It is somehow held at bay by a "+
        "light %^BLUE%^blue%^RESET%^%^RED%^ barrier.%^RESET%^",
        "barrier" : "%^BLUE%^This light blue barrier contains "+
        "the raging and out of control fire here.  It occassionally "+
        "wavers, leaving you unsure of its strength and wary of "+
        "how long it might hold.%^RESET%^",
    ] ));
    
    set_search("default","%^RED%^The tunnel around you is made entirely "+
    "from flames, there are no debris or places for anything to "+
    "be concealed.%^RESET%^");// except perhaps inside the fire itself.%^RESET%^");
}

void reset()
{
	string type;
	if(strsrch(base_name(TO), "war_mongrels_tunnel") != -1) 
	{
		::reset();
		return;
	}
	if(base_name(TO)[44..44] == "e" ||
	   base_name(TO)[44..44] == "w" ||
	   base_name(TO)[44..44] == "s" ||
	   base_name(TO)[44..44] == "n")
		{
			if(!present("chest", TO) && !TO->query_property("had_treasure_chest"))
			{
				if(!random(3))
				{
					switch(random(10))
					{
						case 0..4:
							type = "A";
							break;
						case 5..7: 
							type = "B";
							break;
						case 8..9: 
							type = "C";
							break;
						default:
							type = "A";
							break;
					}
					DEKU_TR->make_fire_chest(TO,type,1);
					TO->set_property("had_treasure_chest", 1);
				}
			}
		}
	::reset();
}