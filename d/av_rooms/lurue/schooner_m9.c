// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_m9");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^RESET%^%^CYAN%^The Maindeck of a Schooner%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Growing wider as the foredeck gives way to Midships, the wooden expanse of the deck stretches out before you.  %^BOLD%^%^WHITE%^Snow-white %^RESET%^%^ORANGE%^rigging ties to rails a"
	"nd fixtures with precision and intricate knotting.  Stretched upon their taut forms, the many %^GREEN%^emerald %^ORANGE%^sails of the ship catch the wind and guide the ship forward, cutting through th"
	"e water at a swift pace. All around, the polished wood glows from attention and the clear sense of pride the Captain must have in his ship.%^RESET%^"
	);

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");

    
set_items(([ 
	({ "sails", "sail", "rigging", "ropes" }) : "%^GREEN%^The sails are a deep emerald green in color.  Colorful against the white of the rigging.%^RESET%^",
	({ "rails", "wood", "wood rails", "fixtures", "brass" }) : "%^YELLOW%^The brass fixtures gleam against the highly polished wood, giving a bright contrast and sparkle.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/schooner_m6",
		"west" : "/d/av_rooms/lurue/schooner_m8",
		"north" : "/d/av_rooms/lurue/schooner_m5",
		"east" : "/d/av_rooms/lurue/schooner_m10",
		"northwest" : "/d/av_rooms/lurue/schooner_m4",
	]));

}