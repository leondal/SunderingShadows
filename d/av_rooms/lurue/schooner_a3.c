// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_a3");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^YELLOW%^Quarterdeck of a Schooner%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^A large polished wheel dominates the setting of the Quarterdeck, it's many-spired form turning easily on a %^YELLOW%^brass %^RESET%^%^ORANGE%^and %^CYAN%^steel %^ORANGE%^obelisk jut"
	"ting out of the polished plank woods.  Above the %^GREEN%^emerald %^ORANGE%^canvas of the Mainsail snaps and tugs at the secured boom, keeping the ship on course and allowing the wheel to be used for "
	"minor course corrections.  Narrowing toward the back to conform with the ship's oval-diamond shape, the view from the highest point of the deck, gives a commanding view of the ship, the sails and the "
	"open %^BLUE%^sea%^ORANGE%^.%^RESET%^"
	);

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");

    
set_items(([ 
	({ "wheel", "obelisk" }) : "%^CYAN%^The wheel spins easily on the support that extends from the floor of the quarterdeck.  Several ropes are affixed to the obelisk like structure that allow the wheel to be tied off when needed, while they can easily be slipped free when its time to take more control of direction.  Atop the support, behind the wheel a glass compass can be seen, allowing the wheelman to navigate the vessel.%^RESET%^",
	({ "rails", "wood", "wood rails", "fixtures", "brass" }) : "%^YELLOW%^The brass fixtures gleam against the highly polished wood, giving a bright contrast and sparkle.%^RESET%^",
	({ "sails", "sail", "rigging", "ropes" }) : "%^GREEN%^The sails are a deep emerald green in color.  Colorful against the white of the rigging.%^RESET%^",
	]));

    set_exits(([ 
		"southwest" : "/d/av_rooms/lurue/schooner_m10",
		"northwest" : "/d/av_rooms/lurue/schooner_m3",
	]));

}