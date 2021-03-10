// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_m1");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^RESET%^%^CYAN%^The Maindeck of a Schooner%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The boat widens here, angling back from the knife like bow ahead.  Polished wood rails and %^YELLOW%^brass %^RESET%^%^ORANGE%^fixtures gleam with attention and the wood of the deck "
	"itself is brilliant with shades of brown, mahogany, chestnut and ash.  Above, the %^GREEN%^emerald %^ORANGE%^Jibsail snaps and pulls at its %^BOLD%^%^WHITE%^snow-white%^RESET%^%^ORANGE%^ rigging stret"
	"ched between the foremast and the bowsprit.%^RESET%^"
	);

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");

    
set_items(([ 
	({ "sails", "sail", "rigging", "ropes" }) : "%^GREEN%^The sails are a deep emerald green in color.  Colorful against the white of the rigging.%^RESET%^",
	({ "rails", "wood", "wood rails", "fixtures", "brass" }) : "%^YELLOW%^The brass fixtures gleam against the highly polished wood, giving a bright contrast and sparkle.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/schooner_m5",
		"south" : "/d/av_rooms/lurue/schooner_m4",
		"east" : "/d/av_rooms/lurue/schooner_m2",
	]));

}