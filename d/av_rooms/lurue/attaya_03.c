// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("attaya_03");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^YELLOW%^A chamber that leads through Illusions%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This chamber leads through the realm of Attaya.  In the reality of what it is today, and of the change that is coming.  It even reaches to the future where that which is waiting lur"
	"ks.  From here, access to all the regions that need swift access for the Attaya Plot can be reached.%^RESET%^"
	);

    set_smell("default","
You can smell earth, air, fire and water as the world changes.");
    set_listen("default","The sound of the world bending reaches your ears.");


    set_exits(([ 
		"boardwalk" : "/d/av_rooms/lurue/attaya_04",
		"maze" : "/d/av_rooms/lurue/maze_in",
		"broiler" : "/d/av_rooms/lurue/arena_09",
		"fountain" : "/d/av_rooms/lurue/attaya_10",
		"lich" : "/d/av_rooms/lurue/lich_01",
		"house" : "/d/av_rooms/lurue/attaya_01",
		"cave" : "/d/av_rooms/lurue/senbeach_01",
		"arena" : "/d/av_rooms/lurue/arena_01",
		"underwater" : "/d/av_rooms/lurue/senbeach_07",
	]));

}