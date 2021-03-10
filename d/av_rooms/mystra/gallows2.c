// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("gallows2");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Gallows Path%^RESET%^");

    set_long("Gallows 2");

    set_smell("default","
smells");
    set_listen("default","sounds");


    set_exits(([ 
		"west" : "/d/av_rooms/mystra/gallows1",
	]));

}