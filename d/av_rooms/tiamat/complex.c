// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("complex");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^ORANGE%^The Lair Complex%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This is a huge cavern complex, stretching out far in every direction and rising high above your head.  It appears to serve as a central chamber with huge %^RED%^tunnel mouths%^ORANG"
	"E%^ leading further into various parts of the cave.  %^RED%^Exits%^ORANGE%^ honeycomb the complex, some running along the floor and others high above, branching out at irregular intervals.  The chambe"
	"r is %^BOLD%^%^BLACK%^poorly lit%^RESET%^%^ORANGE%^ with fading torches that cast %^BOLD%^%^BLACK%^dancing shadows%^RESET%^%^ORANGE%^ all around.  Near many of the cavern paths are small piles of %^BO"
	"LD%^%^WHITE%^ch%^GREEN%^ro%^BLUE%^ma%^BLACK%^ti%^RED%^c dragon%^RESET%^%^ORANGE%^ scales, shed through centuries of use.%^RESET%^"
	);

    set_smell("default","
%^GREEN%^It smells like oil and fungi.");
    set_listen("default","%^ORANGE%^It sounds as though the caves are breathing.");


    set_exits(([ 
		"dungeons" : "/d/av_rooms/tiamat/dungeons",
		"lounge" : "/d/dagger/avalounge",
		"lair" : "/d/avrooms/tiamat",
	]));

}