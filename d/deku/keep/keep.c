#include <std.h>
#include "keep.h"
inherit CROOM;
void create() 
{
    ::create();
    if(base_name(TO) != KEEP) 
    {
        set_monsters(({KEEPM + "keep_guard"}),({random(2) + 1}));
    }
	set_repop(35);
    set_property("light",1);
    set_name("keep blacktongue");
    set_property("indoors",0);
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_property("traps_known_to_monsters", KEEPM);
    set_property("random trap frequency", 15);
    set_property("random traps", "mid");
    
    set_smell("default","An odor of decay mixes with the smell of the forest.");
    set_listen("default","An occasional shout can be heard from within the keep.");
}

