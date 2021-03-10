// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_s6");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^YELLOW%^Ship's Hull%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This narrow hallway leads between the back half of the hull where cabins for the crew are tucked away.  Little more then closet sized rooms with two hammocks per, these cabins would"
	" create a sense of claustrophobia for even a ground dwelling dwarf.  Ahead, a stairwell provides access to the lowest part of the ship.%^RESET%^"
	);

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");

    set_search("cabin,cabins","%^RESET%^%^ORANGE%^Very small cabins extend off of the hallway, each seems to have a couple hammocks and little more.  A few have a rucksack hanging off hooks on the wall, but otherwise these appear to be little more then sleeping places for the sailors in their off hours.%^RESET%^");
    
set_items(([ 
	({ "sewage", "water" }) : "%^RESET%^%^GREEN%^The water is about two inches high here and is full of the rot and remains are shed by prisoners.  You're certain you wouldn't want to search around in it without good cause.  Especially considering you can't identify most of what sloshes about.%^RESET%^",
	({ "bars", "iron bars" }) : "%^BOLD%^%^BLACK%^Driven into deep supports, they don't look like they could be pulled free without destroying part of the ship.  They look in surprisingly good condition, despite the slosh of liquid that covers the floor.%^RESET%^",
	]));

    set_exits(([ 
		"stairs" : "/d/av_rooms/lurue/schooner_b2",
		"west" : "/d/av_rooms/lurue/schooner_s5",
	]));

}