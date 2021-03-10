// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_chapel_salcove");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Chapel's Southern Alcove%^RESET%^");

    set_long("This is a plain room with a set of stairs leading into the basement of the chapel, probably where the crypt is located. To the north is the main section of the chapel with row upon row of pews. To the"
	" northwest is the back of the chapel. The stone walls and floor are made of marble and you can see the ceiling extending into a towering arch."
	);

    set_smell("default","
The air is stale and heavy here.");
    set_listen("default","You can hear the tramp and tread of many feet outside the chapel.");


    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/location_chapel_mid",
		"down" : "/d/av_rooms/myrkul/basement_south",
		"northwest" : "/d/av_rooms/myrkul/location_chapel_back",
	]));

}