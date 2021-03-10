// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_m4");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^RESET%^%^CYAN%^The Maindeck of a Schooner%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The wide expanse of the foredeck stretches out before you.  Highly polished wood of the deck itself is smooth and easy to walk upon, while the rails and %^YELLOW%^brass %^RESET%^%^O"
	"RANGE%^fixtures gleam from the careful attention to their forms.  Deep shades of brown and mahogany, chestnut and ash blend into a warm and rich display, while above the %^GREEN%^emerald %^ORANGE%^col"
	"ored Jibsail snaps upon its %^BOLD%^%^WHITE%^snow-white %^RESET%^%^ORANGE%^rigging, extending from the foremast down to the bowsprit that extends out over the knife like bow.  A set of stairs leads do"
	"wn into the hull and cargo area of the ship here.%^RESET%^"
	);

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");

    
set_items(([ 
	({ "sails", "sail", "rigging", "ropes" }) : "%^GREEN%^The sails are a deep emerald green in color.  Colorful against the white of the rigging.%^RESET%^",
	({ "rails", "wood", "wood rails", "fixtures", "brass" }) : "%^YELLOW%^The brass fixtures gleam against the highly polished wood, giving a bright contrast and sparkle.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/schooner_m2",
		"southeast" : "/d/av_rooms/lurue/schooner_m9",
		"stairs" : "/d/av_rooms/lurue/schooner_s4",
		"south" : "/d/av_rooms/lurue/schooner_m8",
		"north" : "/d/av_rooms/lurue/schooner_m1",
		"east" : "/d/av_rooms/lurue/schooner_m5",
	]));

}