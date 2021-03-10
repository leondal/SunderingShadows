#include <std.h>
#include <daemons.h>
#include "forest.h"
inherit CROOM;
int getmobs;
void create() {
    getmobs = random(2);
	if(getmobs) 
	{
      	if(base_name(TO) != "/d/deku/inherits/flametemplei") 
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
    ::create();
    set_short("%^RED%^A massive chamber of fl%^ORANGE%^a%^RESET%^%^RED%^"+
    "m%^ORANGE%^e%^RESET%^%^RED%^s%^RESET%^");
    set_name("A massive chamber of flames");
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("no teleport",1);
    set_property("no sticks",1);
    set_long("%^RED%^You are inside a massive chamber made entirely "+
    "from fire.  The ceiling is so far overhead that all you can "+
    "make out of it is a dim red %^CYAN%^glow%^RESET%^%^RED%^.  "+
    "The floor of this chamber is made from the simmering %^YELLOW%^"+
    "embers%^RESET%^%^RED%^ left from a fire that only recently "+
    "flickered and died, yet somehow the embers cause you no "+
    "pain.  P%^YELLOW%^i%^RESET%^%^RED%^ll%^YELLOW%^a%^RESET%^%^RED%^"+
    "rs of flame acend up from the floor to reach at least "+
    "several dozen feet into the air.  They burn brilliantly "+
    "and intensly, radiating an oppressive amount of heat.  "+
    "You realize that a light %^BLUE%^blue%^RESET%^%^RED%^ "+
    "barrier surrounds all of the flame in this chamber, as if "+
    "holding its destructive power back.  However, you witness "+
    "the barrier occassionally waver and you're very unsure of "+
    "its strength and very wary of how long it might hold.%^RESET%^");
     
   
    set_listen("default","%^RED%^The roar of out of control "+
    "fire drowns out any and all other sounds.%^RESET%^");
    set_smell("default","The scent of sulfur and burning flesh "+
    "hangs so heavily in the air here that it is almost tangible.");
    
    set_items(( [       
        "ceiling" : "%^RED%^The ceiling here hangs so far overhead "+
        "that you can make out only a dim %^CYAN%^glow%^RESET%^%^RED%^ "+
        "from it.%^RESET%^",
        "floor" : "%^RED%^The floor is made from the simmering "+
        "embers of a recently extinguished fire.%^RESET%^",
        "fire" : "%^RED%^This entire chamber is made from a "+
        "raging and out of control fire.  The fire is held at bay "+
        "by a wavering light %^BLUE%^blue%^RESET%^%^RED%^ barrier.%^RESET%^",
        "barrier" : "%^BLUE%^This light blue barrier contains "+
        "the raging and out of control fire here.  It occassionally "+
        "wavers, leaving you unsure of its strength and wary of "+
        "how long it might hold.%^RESET%^",
        "pillars" : "%^RED%^These pillars are made from roaring "+
        "flame and ascend upward from the floor to at least several "+
        "dozen feet overhead.  They are covered by the "+
        "light %^BLUE%^blue%^RESET%^%^RED%^ barrier.%^RESET%^",
        "embers" : "%^RED%^These simmering embers are all that "+
        "remains of some recently extinguished fire.%^RESET%^",
    ] ));
    set_search("default","%^RED%^This chamber is made entirely "+
    "from flames, there are no debris or places for anything to "+
    "be concealed.%^RESET%^");// except perhaps inside the fire itself.%^RESET%^");
}

