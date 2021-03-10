// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_g5");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("marsh");
    set_travel("dirt road");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^A marshy plantation%^RESET%^");

    set_long("%^RESET%^%^GREEN%^The heavy foliage of the swamp has been beaten back here, revealing a small, ill tended %^BOLD%^lawn %^RESET%^%^GREEN%^that leads up to the dilapidated %^WHITE%^%^BOLD%^mansion %^RES"
	"ET%^%^GREEN%^ahead.  A flat stone path curves around a %^CYAN%^allege laden pond %^GREEN%^and leads up to rickety looking stairs and a narrow %^ORANGE%^porch%^GREEN%^.  Two great %^ORANGE%^oaks %^GREE"
	"N%^stand to either side of the pond, their sagging limbs the water's edge with each faint breeze.%^RESET%^"
	);

    set_smell("default","
The heavy smell of rotten vegetation hangs in the air.");
    set_listen("default","You can hear the deep throated croake of a bullfrog.");

    set_search("right tree","%^RESET%^%^ORANGE%^You climb up into the limbs and search around a bit only to discover there's nothing here but %^GREEN%^swamp moss%^ORANGE%^ and a small inscription carved into one of the thick limbs.%^RESET%^");
    set_search("pond","%^RESET%^%^CYAN%^You hand brushes against something slimy.  Hopefully that was just a fish.%^RESET%^");
    set_search("left tree","%^RESET%^%^ORANGE%^You climb up into the limbs and search around a bit only to discover there's nothing here but %^GREEN%^swamp moss%^ORANGE%^.%^RESET%^");
    set_search("trees","*%^RESET%^%^ORANGE%^There are two, one on the %^RESET%^left %^ORANGE%^of the pond and one on the %^RESET%^right.%^RESET%^");
    
set_items(([ 
	({ "oak", "oaks" }) : "%^RESET%^%^ORANGE%^There are two large oaks here, one to either side of the pond.  You could probably climb up and %^RESET%^search%^ORANGE%^ around in their branches if you wanted.%^RESET%^",
	({ "trees", "tree" }) : "%^RESET%^%^ORANGE%^There are two large oaks here, one to either side of the pond.  You could probably climb up and %^RESET%^search%^ORANGE%^ around in their branches if you wanted.%^RESET%^",
	"pond" : "%^BOLD%^%^WHITE%^The pond is covered in algae and water lilies, though you do notice a flash of movement below the surface.%^RESET%^",
	"water" : "%^BOLD%^%^WHITE%^The pond is covered in algae and water lilies, though you do notice a flash of movement below the surface.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/dekumage_g4",
		"east" : "/d/av_rooms/lurue/dekumage_m1",
	]));

}