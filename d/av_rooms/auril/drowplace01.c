// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("battleforest01");
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("heavy forest");
    set_travel("ledge");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^Within a hidden town%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This is a well-constructed town, nestled into the valley here. It seems completely isolated with the surrounding mountains seeming impassable.%^RESET%^"
	);

	
    set_smell("default","
%^BOLD%^%^GREEN%^You smell the leaves and sap of the forest.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLUE%^You hear birds chirping.%^RESET%^");


    set_exits(([ 
		"cave"	: "/d/av_rooms/auril/cave04",

	]));

}