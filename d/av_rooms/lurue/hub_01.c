// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("hub_01");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^A central hall%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This central hall is circular in shape and leads to many different places.  Archways can be found every few feet, leading off in many different locations.  Crafted from ancient stones"
	" that have seen the ware of years and the passing of ages, the hall is silent and cool, giving it a feel of the oldest structures.  A place where time can be seen ticking away in a slow decay toward o"
	"blivion.%^RESET%^"
	);

    set_smell("default","
The air is faintly tinged with a hint of moss and earth.");
    set_listen("default","The room is silent except for the quiet ticking of your heartbeat.");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/hub_02",
		"north" : "/d/av_rooms/lurue/hub_05",
		"south" : "/d/av_rooms/lurue/hub_03",
		"east" : "/d/av_rooms/lurue/hub_06",
		"southwest" : "/d/av_rooms/lurue/zoo_01",
		"northwest" : "/d/av_rooms/lurue/hub_04",
	]));

}