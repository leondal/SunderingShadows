// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("parmt_p2");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("old mounts");
    set_travel("ledge");
    set_climate("mountain");

    set_short("%^RESET%^%^ORANGE%^a sheltered ledge in the mountains%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^Sheltered by an overhang, this ledge is wide and flat and rather perfect for resting in.  The %^BLACK%^dark granite stone %^WHITE%^curving around two sides and part of a third forming"
	" a wind block, while the shelf above protects part of the area from the %^RESET%^%^CYAN%^rain %^BOLD%^%^WHITE%^and snow.  A %^BLACK%^deep crag %^WHITE%^can be seen toward the back, a fissure or break "
	"in the stone. %^RESET%^"
	);

    set_smell("default","
There is a bitter, foul order coming from the pile of debris.");
    set_listen("default","The wind howls past this sheltered area.");

    
set_items(([ 
	({ "fissure", "crag" }) : "%^BOLD%^%^BLACK%^It looks narrow, but you think you could fit into it and see what is further in.%^RESET%^",
	]));

    set_exits(([ 
		"fissure" : "/d/av_rooms/lurue/dekumage_t5",
		"ride" : "/d/av_rooms/lurue/parmt_p1",
	]));

}