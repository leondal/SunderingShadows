// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("t_spring");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^Natural Spring%^YELLOW%^ near Camp%^RESET%^ ");

    set_long("There is a natural spring here that flows water into a nearby stream. The camp uses this as its water source. The pallisade walls are nearby and a footpath leads back southwest to the main entrance.");

    set_smell("default","
The air smells fresh here and clean.");
    set_listen("default","You hear the chirping of birds, and the muffled camp sounds from over the walls");

    set_search("spring","Its just water, clean and fresh. ");
    set_search("wall","You found a <hole> in the walls near the spring. Someone must have made this to make it easier to get water, rather than walk all the way around to the gates.");
    set_search("walls","You found a <hole> in the walls near the spring. Someone must have made this to make it easier to get water, rather than walk all the way around to the gates.");
    
set_items(([ 
	({ "walls", "wall" }) : "These pallisade walls are made out of logs and thick rope. The walls stand about 8 feet tall.",
	"spring" : "The water looks very clean from the spring, and is probably why the soldiers (or bandits) decided to base their camp here.",
	"path" : "The path has worn down the grasses into a dirt path that leads southwest to the main Gate.",
	]));

    set_exits(([ 
		"hole" : "/d/av_rooms/myrkul/t_kitchen",
		"southwest" : "d/av_rooms/myrkul/t_entrance",
	]));



    set_invis_exits(({ "hole" }));

}