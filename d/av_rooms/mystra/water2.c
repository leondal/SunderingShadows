// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("water2");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Water St.%^RESET%^");

    set_long("Water 2");

    set_smell("default","
Smells");
    set_listen("default","Sound");


    set_exits(([ 
		"west" : "/d/av_rooms/mystra/water3",
		"east" : "/d/av_rooms/mystra/water1",
	]));

}