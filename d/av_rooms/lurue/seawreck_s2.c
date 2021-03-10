// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("seawreck_s2");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("shallow water");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^The wide open sea%^RESET%^");

    set_long("%^RESET%^%^CYAN%^Drifting on the vast open %^BOLD%^%^BLUE%^sea%^RESET%^%^CYAN%^. the rise and drop of each swell reminds you just how small a being you truly are.  The dark b%^BLUE%^l%^CYAN%^u%^GREEN%"
	"^e%^BLUE%^-%^GREEN%^g%^BLUE%^r%^CYAN%^e%^BOLD%^%^BLUE%^e%^RESET%^%^GREEN%^n%^CYAN%^ waters prevent you from seeing much more then your feet feebly kicking back and forth as you fight to stay afloat.  "
	"To the east, an underwater structure, covered in %^ORANGE%^coral%^CYAN%^ causes the waves to break and splash, but you are far too distant to make out what it is.%^RESET%^"
	);

    set_smell("default","
Salt spray tingles your nose.");
    set_listen("default","The constant roar of the ocean is all around you.");

    
set_items(([ 
	({ "structure", "coral" }) : "%^RESET%^%^ORANGE%^From here all you can tell is that there is something under the water to the east.  What it is you're not sure, but at least out here you might be able to %^BLACK%^%^BOLD%^dive%^RESET%^%^ORANGE%^ without having to worry about being shoved into the sharp coral shelves.%^RESET%^",
	]));

    set_exits(([ 
		"dive" : "/d/av_rooms/lurue/seawreck_u2",
		"east" : "/d/av_rooms/lurue/seawreck_s3",
	]));



    set_invis_exits(({ "dive" }));

}