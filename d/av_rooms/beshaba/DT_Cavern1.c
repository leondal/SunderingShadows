// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("DT_Cavern1");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("desert");

    set_short("%^YELLOW%^C%^RESET%^%^ORANGE%^avern %^BOLD%^T%^RESET%^%^ORANGE%^unnel%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This tunnel continues off to the east in a meandering fashion. Long stalactites hang from the cave ceiling, mirrored by the stalagmites reaching up to meet them. The occasional drip"
	" of milky water breaks the quiet atmosphere.%^RESET%^"
	);

    set_smell("default","
The air is stale and stagnant.");
    set_listen("default","A few stonefalls echo in the distance.");


    set_exits(([ 
		"east" : "/d/av_rooms/beshaba/DT_CavernChamber",
	]));

}