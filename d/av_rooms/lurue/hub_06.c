// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("hub_06");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Hall of Guilds%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This hall leads away from the central hub and down along a tapestry lined corridor.  Each tapestry is life like and filled with detail so clear that it seems you might be able to step"
	" through them and stand upon the part of the world they display.%^RESET%^"
	);

    set_smell("default","
The air is faintly tinged with a hint of moss and earth.");
    set_listen("default","The room is silent except for the quiet ticking of your heartbeat.");


    set_exits(([ 
		"shadow" : "/d/shadow/room/city/cguild/thief/tgstore",
		"offestry" : "/d/newbie/rooms/town/fencer",
		"graez" : "/d/undead/rooms/town/thieves",
		"tabor" : "/d/darkwood/tabor/room/fencer",
		"west" : "/d/av_rooms/lurue/hub_01",
		"pirate" : "/d/islands/pirates/cove/thief5",
		"tharis" : "/d/tharis/Tharis/tstore",
		"seneca" : "/d/attaya/seneca/cguilds/thief/thief10",
		"torm" : "/d/dagger/Torm/city/thieves/vethor_store",
	]));

}