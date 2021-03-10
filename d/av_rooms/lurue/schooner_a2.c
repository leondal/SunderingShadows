// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_a2");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^YELLOW%^Crows Nest of a Schooner%^RESET%^");

    set_long("Ship Description");

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");


    set_exits(([ 
		"down" : "/d/av_rooms/lurue/schooner_m5",
	]));

}