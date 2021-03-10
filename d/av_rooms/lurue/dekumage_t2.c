// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_t2");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat tunnel");
    set_travel("rubble");
    set_climate("tropical");

    set_short("%^RESET%^%^ORANGE%^An Unfinished Tunnel%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This tight crawl space is barely big enough for a person to crawl through.  Clearly dug by claws, the walls, floor and ceiling are raw and unfished.  %^RESET%^%^ORANGE%^Dust%^BOLD%^%^"
	"BLACK%^ and the occasional %^RESET%^rock %^BOLD%^%^BLACK%^sift from the ceiling making moving through this area difficult and stuffy. %^RESET%^"
	);

    set_smell("default","
The air is heavy with the smell of dirt and something wet.");
    set_listen("default","You can hear the earth shifting all around you.");

    
set_items(([ 
	({ "rock", "rocks", "dirt", "earth" }) : "%^BOLD%^%^BLACK%^Thankfully all that keeps falling are tiny %^RESET%^pebbles%^BOLD%^%^BLACK%^ and a fine mist of dust.%^RESET%^",
	"pebbles" : "%^BOLD%^%^WHITE%^Tiny little pebbles litter the crawlspace, making your hands and knees hurt as you crawl along.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/dekumage_t5",
		"east" : "/d/av_rooms/lurue/dekumage_t1",
		"southwest" : "/d/av_rooms/lurue/dekumage_t3",
	]));

}