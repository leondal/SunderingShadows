// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ts_05");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A dark hole%^RESET%^");

    set_long("%^BOLD%^%^BLUE%^This dark chamber is little more then a hole in the ground that leads to a narrow drain.  Plugged mostly by %^BLACK%^rubble %^BLUE%^and %^RESET%^garbage%^BOLD%^%^BLUE%^ there is little"
	" of interest besides the hole leading out.%^RESET%^"
	);

    set_smell("default","
It smells horribly in here.");
    set_listen("default","You can hear the sound of running water.. you think.");


    set_exits(([ 
		"out" : "/d/av_rooms/lurue/ts_04",
	]));

}