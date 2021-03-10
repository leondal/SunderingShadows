// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("t_kitchen");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^YELLOW%^Camp kitchens%^RESET%^");

    set_long("A large iron pot on a huge fire dominates this section of the camp. There are tables here to do the chopping and serving of stews. This appears to be a popular area of the camp, except during the form"
	"al announcements. A tent stands next to the walls where the cook gets shade and stores foodstuffs."
	);

    set_smell("default","
It smells a lot like onions and potatoe over here.");
    set_listen("default","You can hear the noise of the camp to the east.");

    set_search("tent","You find that the lazy ass cook has made a <hole> in the Pallisade wall as a shortcut to the spring. He must not like to walk all the way around the walls with a pot full of water and so made this defect in the Pallisade defenses. You could easily squeeze in and out here.");
    
set_items(([ 
	({ "table", "tables" }) : "The tables are surprisingly clean.",
	({ "pot", "pots", "kettle", "kettles" }) : "The huge cooking pots are full of water and are currently stewing some kind of broth made of potatoe and onion.",
	"tent" : "The foodstuffs here are plentiful but it is mostly onion and potatoe. The cooks can get shade under the tent flaps.",
	"fire" : "The cooking fires are dull now, but are kept going to allow the stew to simmer.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/t_camp",
		"hole" : "/d/av_rooms/myrkul/t_spring",
	]));



    set_invis_exits(({ "hole" }));

}