// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_g4");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("marsh");
    set_travel("game track");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^A hidden plantation%^RESET%^");

    set_long("%^RESET%^%^GREEN%^With much anticipation you breech the heavy foliage and find yourself standing on some form of plantation buried deep within the western woods of Deku.  To the east, along the path, "
	"a shabby, dilapidated %^RESET%^manor house%^GREEN%^ can be seen.  Its splendor lost under the heavy ravages of %^BOLD%^moss %^RESET%^%^GREEN%^and %^BLUE%^moisture%^GREEN%^.  To the west you can make o"
	"ut what's left of a %^ORANGE%^carriage house%^GREEN%^. The large front dome has caved in, but there appears to be a few of the stables still in tact.  Ahead a narrow cluster of %^BOLD%^fields %^RESET%"
	"^%^GREEN%^are planted, likely the only source of food beyond hunting.  Roofs of little huts hide behind the foliage further on, their %^BOLD%^%^BLACK%^dark slate %^RESET%^%^GREEN%^beams thick with mos"
	"s.%^RESET%^"
	);

    set_smell("default","
The heavy smell of rotten vegetation hangs in the air.");
    set_listen("default","The air is alive with the heavy drone of insects.");

    
set_items(([ 
	({ "manor", "house", "manor house" }) : "%^BOLD%^%^WHITE%^To the east you can see the shabby remains of a manor house.  The once beautiful structure has nearly surendered to time as moss and moisture do their best to claim it.%^RESET%^",
	({ "carriage house", "stables" }) : "%^RESET%^%^ORANGE%^At some point in the past this place must have been stately.  Time though has worn away at the structures and buildings, just like this carriage house.%^RESET%^",
	"woods" : "%^BOLD%^%^BLACK%^Thick trees and brush grow up around and through the swampy area here, blocking your view of the rest of the island.%^RESET%^",
	"fields" : "%^BOLD%^%^GREEN%^Several small plots of fields are arranged to the south.  You can see that there is a vast array of plants growing, leading you to believe this place is not uninhabited.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/dekumage_g3",
		"west" : "/d/av_rooms/lurue/dekumage_s1",
		"south" : "/d/av_rooms/lurue/dekumage_g6",
		"east" : "/d/av_rooms/lurue/dekumage_g5",
	]));

}