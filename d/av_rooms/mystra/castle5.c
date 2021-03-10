// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("castle5");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Castle Path%^RESET%^");

    set_long("Castle 5");

    set_smell("default","
smells");
    set_listen("default","noise");


    set_exits(([ 
		"northeast" : "/d/av_rooms/mystra/castle6",
		"south" : "/d/av_rooms/mystra/castle4",
	]));

}