// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_chapel_altar");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Chapel Altar%^RESET%^");

    set_long("%^RESET%^%^GREEN%^You stand before the %^MAGENTA%^Chapel altar%^GREEN%^. The altar itself is a %^WHITE%^white marble%^GREEN%^ embossed with the symbol of %^BOLD%^%^BLACK%^Kelemvor%^RESET%^%^GREEN%^: a"
	"n uplifted skeletal hand holding %^YELLOW%^sc%^BLACK%^a%^YELLOW%^l%^WHITE%^e%^YELLOW%^s of j%^BLACK%^u%^YELLOW%^s%^WHITE%^t%^YELLOW%^ice%^RESET%^%^GREEN%^. The view is commanding from the pulpit. A %^"
	"BLUE%^balcony%^GREEN%^ where a chorus once sang is in the northeastern corner. The middle of the chapel has many %^ORANGE%^pews%^GREEN%^, most of which are now beyond repair. %^RED%^Great doors%^GREEN"
	"%^ to the outside are just visible in the entryway. Up above, a vaulted ceiling soars above the stone floor below. Behind the altar and against the back wall is a %^YELLOW%^s%^CYAN%^t%^GREEN%^a%^BLUE%"
	"^i%^WHITE%^n%^RED%^e%^MAGENTA%^d%^CYAN%^ glass window%^RESET%^%^GREEN%^ above a tattered tapestry.%^RESET%^"
	);

    set_smell("default","
Stale air with a hint of mold and a dash of rotted flesh.");
    set_listen("default","You hear something stirring further out in the chapel.");

    set_search("wall","Amongst the cracks on the wall you find the seems of a <door> through which you might pass.");
    set_search("marble wall","Amongst the cracks on the wall you find the seems of a <door> through which you might pass.");
    set_search("cracked marble wall","Amongst the cracks on the wall you find the seems of a <door> through which you might pass.");
    set_search("tapestry","You find nothing behind the tapestry but the cracked marble wall.");
    set_search("pulpit","There is nothing mysterious about the altar but the oddly red stains in it that seem far older than the more recent symbol of Kelemvor placed upon it.");
    set_search("altar","There is nothing mysterious about the altar but the oddly red stains in it that seem far older than the more recent symbol of Kelemvor placed upon it.");
    
set_items(([ 
	({ "window", "stained glass window", "stained glass" }) : "%^YELLOW%^The glass window far above casts a %^WHITE%^glimmering%^YELLOW%^ image of %^BLACK%^Kelemvor%^YELLOW%^ stepping out of the wreckage of the godswar to rule as %^BLACK%^Lord of the Dead%^YELLOW%^ even as an elder %^WHITE%^skeletal %^BLACK%^figure fades%^YELLOW%^ into scattered light.%^RESET%^",
	({ "great doors", "pews", "balcony" }) : "You'll have to get closer to see the doors, pews, and balcony.",
	({ "great doors", "pews", "balcony" }) : "You'll have to get closer to see the doors, pews, and altar.",
	({ "ceiling", "floor" }) : "Solid marble.",
	"tapestry" : "The tapestry seems almost shredded beyond recognition, but it seems to bear the skeletal hand of %^BOLD%^%^BLACK%^Kelemvor%^RESET%^.",
	"stains" : "A careful search of the altar might reveal more, but at a glance the stains seem very old.",
	"altar" : "The altar seems plain enough except for the mable stone with some stains on it and the symbol of Kelemvor.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/location_chapel_mid",
		"door" : "/d/av_rooms/myrkul/location_chapel_hidden",
	]));



    set_invis_exits(({ "door" }));

}