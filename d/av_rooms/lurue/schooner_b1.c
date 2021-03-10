// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_b1");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^Ship's Brig%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The brig is a foul, horrible place.  A low ceiling causes all but the shortest of captives to hunch and stoop, while the floor is covered in several inches of what could only be con"
	"sidered %^GREEN%^sewage%^ORANGE%^.  The ripe, bitter smell of fear lingers here, making it an even more miserable place to be trapped.  %^BOLD%^%^BLACK%^Iron bars %^RESET%^%^ORANGE%^block the way to a"
	" narrow stairwell that leads up into the more suitable parts of the ship.%^RESET%^"
	);

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");

    set_search("sewage","%^GREEN%^Oh yuck! Why would you want to touch that with your bare hands?!%^RESET%^");
    set_search("water","%^BLUE%^Oh yuck! Why would you want to touch that with your bare hands?!%^RESET%^");
    
set_items(([ 
	({ "sewage", "water" }) : "%^RESET%^%^GREEN%^The water is about two inches high here and is full of the rot and remains are shed by prisoners.  You're certain you wouldn't want to search around in it without good cause.  Especially considering you can't identify most of what sloshes about.%^RESET%^",
	({ "bars", "iron bars" }) : "%^BOLD%^%^BLACK%^Driven into deep supports, they don't look like they could be pulled free without destroying part of the ship.  They look in surprisingly good condition, despite the slosh of liquid that covers the floor.%^RESET%^",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/lurue/schooner_b2",
	]));

}