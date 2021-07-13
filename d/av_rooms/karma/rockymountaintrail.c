// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("rockymountaintrail");
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("foot path");
    set_climate("temperate");

    set_short("A rocky mountain road");

    set_long("This is a rocky path that winds slowly through the foothills of the mountains. The path has been mostly cleared of the larger rocks, but smaller stones make for rough traveling. The surrounding area i"
	"s also rocky, not many plants seem to like the mountain climate. A cool wind seems to be constantly blowing, and you can hear it whistling through the peaks far above. The path here isn't very steep, "
	"and it stays relatively close to the sheer mountain cliff. There is a shrine to the north."
	);

    set_smell("default","
The air is crisp and fresh.");
    set_listen("default","You hear your footsteps echo through the pass.");


    set_exits(([ 
		"north" : "/d/av_rooms/karma/rockytemple",
	]));

}