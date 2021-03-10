// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("boore4");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Boore St.%^RESET%^");

    set_long("%^BOLD%^This will become boore street when completed.%^RESET%^");

    set_smell("default","
Smell");
    set_listen("default","sounds");


    set_exits(([ 
		"west" : "/d/av_rooms/mystra/boore5",
		"east" : "/d/av_rooms/mystra/boore3",
	]));

}