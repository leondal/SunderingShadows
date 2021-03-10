// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_b2");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^Ship's Brig%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^A narrow stairwell ends abruptly here at a small open area.  Deep in the bowels of the ship, there is a foul smell that lingers here and hints of %^RED%^rot %^ORANGE%^and %^BOLD%^%^"
	"BLACK%^fear%^RESET%^%^ORANGE%^.  %^GREEN%^Sewage %^ORANGE%^and %^CYAN%^water %^ORANGE%^slosh across the floor with every rocking motion of the ship, coating your foot ware with the slop.  Driven into "
	"the wooden supports of the lowest level of the ship, %^BOLD%^%^BLACK%^iron bars %^RESET%^%^ORANGE%^section off the rest of the bilge, forming a brig of sorts.  Beyond you can see several %^RESET%^capt"
	"ives %^ORANGE%^cowering.%^RESET%^"
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
		"stairs" : "/d/av_rooms/lurue/schooner_s6",
		"west" : "/d/av_rooms/lurue/schooner_b1",
	]));

}