// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_g6");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("marsh");
    set_travel("rutted track");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^A marshy plantation%^RESET%^");

    set_long("%^RESET%^%^GREEN%^The highest part of the marsh has been formed into misshapen patches of tilled ground where sickly looking %^BOLD%^vegetables %^RESET%^%^GREEN%^struggle between the oppressive heat a"
	"nd moisture.  Each patch is in a different stage of growth, providing a year round %^RED%^harvest%^GREEN%^, though many of the plants appear to be strangling one another.  Tucked back in the foliage b"
	"eyond these fields are small %^BOLD%^%^BLACK%^huts %^RESET%^%^GREEN%^that must be servant's quarters to the nearby manner.  Like the stately building, they appear to be in poor repair and crumbling un"
	"der time's yield.  One to the west, however, looks to be in better repair.%^RESET%^"
	);

    set_smell("default","
The heavy smell of rotten vegetation hangs in the air.");
    set_listen("default","The air is alive with the heavy drone of insects.");

    set_search("vegetables","%^BOLD%^%^GREEN%^You search around in the vegetables but all you come up with is rotted plant matter.%^RESET%^");
    
set_items(([ 
	({ "vegetables", "plants", "plots" }) : "%^RESET%^%^GREEN%^The plants look sickly and ill kept, though you see a few edible vegetables here and there, so the plots do yield.  Still it must be a meager living if this is all that is to be had.%^RESET%^ ",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/lurue/dekumage_p4",
		"west" : "/d/av_rooms/lurue/dekumage_g7",
		"north" : "/d/av_rooms/lurue/dekumage_g4",
	]));

}