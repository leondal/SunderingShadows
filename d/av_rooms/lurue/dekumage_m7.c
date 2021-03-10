// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_m7");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("decayed floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^WHITE%^An old manor house%^RESET%^");

    set_long("%^RESET%^Thick counters line one side of this room, supplying a large space for butchering or preparing meals.  The other side of the room holds a wide %^RED%^fireplace %^RESET%^and two %^BLACK%^%^BOL"
	"D%^metal %^RESET%^cooking surfaces which appear to heat from vents out of the fireplace.  A circular counter in the middle of the room offers access to an underground %^BLUE%^well%^RESET%^, via the wi"
	"de hole in its center.  All around the room, shelves hold old %^ORANGE%^crockery %^RESET%^and cooking %^BOLD%^%^WHITE%^utensils%^RESET%^, leading you to think this kitchen was once well supplied.%^RES"
	"ET%^"
	);

    set_smell("default","
The air smells of ruin and mold.");
    set_listen("default","The boards under your feet groan with your weight.");

    
set_items(([ 
	({ "crockery", "utensils", "cookware" }) : "%^RESET%^%^ORANGE%^Dusty and mostly ruined, there's little to be found amongst the remains of the kitchen.%^RESET%^",
	({ "fireplace", "metal", "cooking surfaces", "stoves" }) : "%^BOLD%^%^BLACK%^Two metal structures flank the sides of this wide fireplace.  Each fed by the heated air that flows up the flues and is directed back down into the metal chambers.  This offers a easy surface to cook upon, while roasting an animal or heating a pot of stew in the fireplace.%^RESET%^",
	"well" : "%^BLUE%^A hole in the floor feeds down into an underground aquifer and can be accessed via a circular counter, which is clearly an indoor well.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/dekumage_m6",
	]));

}