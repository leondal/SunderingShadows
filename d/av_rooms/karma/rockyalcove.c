// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("rockyalcove");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("A small side alcove");

    set_long("%^BOLD%^%^BLACK%^This side alcove appears to be a natural cave inside the mountain, about 15 feet across. A few crystals poke out from the cave walls and water drips down from the stalactites, creatin"
	"g a shallow pool in the center of the cave. It is hard for a normal human to stand upright, so be careful not to bump your head on a stalactite when you walk.%^RESET%^"
	);

    set_smell("default","
It smells damp and stale.");
    set_listen("default","You hear water dripping from the ceiling.");


    set_exits(([ 
		"chute" : "/d/av_rooms/karma/rockybasement",
	]));

}