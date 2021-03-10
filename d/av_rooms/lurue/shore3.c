// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("shore3");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("beach");
    set_travel("fresh blaze");
    set_climate("temperate");

    set_short("%^YELLOW%^A hidden part of the beach%^RESET%^");

    set_long("%^ORANGE%^A ladder makes its way up to a dock here, while the beach stretches to the east and west following the coast line.  Dunes rise and fall further back, obscuring areas from view and providing "
	"several small hideaway spots. %^RESET%^"
	);

    set_smell("default","
You can smell the salt air of the open sea.");
    set_listen("default","Waves crash nearby.");

    
set_items(([ 
	({ "hideaways", "hideaway", "spots" }) : "%^BOLD%^%^BLACK%^Maybe there really is something behind that next dune.%^RESET%^",
	"ladder" : "%^BOLD%^%^BLACK%^Made from iron rods, the ladder goes up to a worn looking dock of a cove.  Perhaps you could climb it to figure out where it leads.%^RESET%^",
	"beach" : "%^RESET%^%^ORANGE%^The beach stretches out around this little cove.  A small inlet of a river winds its way through some dunes and down to the ocean.%^RESET%^",
	]));

    set_exits(([ 
		"ladder" : "/d/shadow/virtual/sea/pirate.dock",
		"northwest" : "/d/av_rooms/lurue/shore2",
	]));

}