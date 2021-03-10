// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_m5");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^RESET%^%^CYAN%^The Maindeck of a Schooner%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Above, the %^GREEN%^emerald %^ORANGE%^hues of the Staysail and Foresail snap and flutter upon their %^BOLD%^%^WHITE%^snow-white %^RESET%^%^ORANGE%^rigging stretched between the forw"
	"ard Foremast and the imposing rear Mainmast. Like the rest of the ship, the masts are polished to bring out the beautiful tones of the wood.  %^YELLOW%^Brass %^RESET%^%^ORANGE%^fixtures hide away the "
	"rougher metals that keep the ship together and provide a warm counterbalance to the soft wooden shades.%^RESET%^"
	);

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");

    
set_items(([ 
	({ "rails", "wood", "wood rails", "fixtures", "brass" }) : "%^YELLOW%^The brass fixtures gleam against the highly polished wood, giving a bright contrast and sparkle.%^RESET%^",
	({ "sails", "sail", "rigging", "ropes" }) : "%^GREEN%^The sails are a deep emerald green in color.  Colorful against the white of the rigging.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/schooner_m3",
		"southeast" : "/d/av_rooms/lurue/schooner_m10",
		"north" : "/d/av_rooms/lurue/schooner_m2",
		"west" : "/d/av_rooms/lurue/schooner_m4",
		"south" : "/d/av_rooms/lurue/schooner_m9",
		"east" : "/d/av_rooms/lurue/schooner_m6",
		"northwest" : "/d/av_rooms/lurue/schooner_m1",
		"southwest" : "/d/av_rooms/lurue/schooner_m8",
	]));

}