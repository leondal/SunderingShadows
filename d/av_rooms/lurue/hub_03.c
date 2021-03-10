// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("hub_03");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Hall of Wizard's Projects%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This hall leads away from the central hub and down along a tapestry lined corridor.  Each tapestry is life like and filled with detail so clear that it seems you might be able to step"
	" through them and stand upon the part of the world they display.%^RESET%^"
	);

    set_smell("default","
The air is faintly tinged with a hint of moss and earth.");
    set_listen("default","The room is silent except for the quiet ticking of your heartbeat.");


    set_exits(([ 
		"plantation" : "/d/av_rooms/lurue/dekumage_g1",
		"tecqumin" : "/d/av_rooms/lurue/tecqumin_01",
		"tharis" : "/realms/loki/tharis/rooms/fountain",
		"north" : "/d/av_rooms/lurue/hub_01",
		"seawreck" : "/d/av_rooms/lurue/seawreck_b1",
		"preserve" : "/realms/loki/tharis/rooms/df17",
		"kelp" : "/d/av_rooms/lurue/kelpmaze_x1",
		"kobolds" : "/d/av_rooms/lurue/dekumage_t0",
		"sune" : "/d/av_rooms/lurue/sunetemple_01",
	]));

}