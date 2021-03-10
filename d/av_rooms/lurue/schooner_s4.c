// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_s4");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^YELLOW%^Cargo Hold of a Schooner Ship%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Large support beams jut and curve up through the large hold, helping to reinforce the main deck as well as divide up the hull's interior space into several sections.  Designed as a "
	"space for holding cargo, the hull is open with a number of %^RESET%^ropes%^ORANGE%^, %^BOLD%^%^BLACK%^pulleys %^RESET%^%^ORANGE%^and other %^CYAN%^devices %^ORANGE%^for securing cargo secured to suppo"
	"rt beams.  Along either side of the hull, %^CYAN%^portholes %^ORANGE%^can be seen where %^BOLD%^%^BLACK%^cannons %^RESET%^%^ORANGE%^are secured.  Chests beside them, bolted to the floor, provide holdi"
	"ng spaces for the cannon balls, powder and other supplies needed to maintain and use the cannons.  Empty of cargo at the moment, you can only imagine how well this ship could both transport and defend"
	" itself.%^RESET%^"
	);

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");

    
set_items(([ 
	({ "supports", "wood", "ropes", "pulleys", "devices" }) : "%^CYAN%^The various devices that are secured to the many supports that crisscross through the ship's hull appear to be made for securing cargo when there is cargo.  Oddly, at the moment there is no cargo, leaving the hull wide and open and oddly abandoned.%^RESET%^",
	({ "chests", "chest" }) : "%^BOLD%^%^BLACK%^Scraps of cloth, small, rolled bags of powder, wicks and dozens of very heavy round iron balls are located in each chest.  Supplies for the cannons.%^RESET%^",
	({ "portholes", "holes", "port holes", "cannons", "chests", "cannon" }) : "%^BOLD%^%^BLACK%^These large hollow tubes are supported on large wooden structures with wheels and tracks that allow them to be moved forward into the portholes behind which they are positioned.  They can also be rolled back quickly to be reloaded with new ammunition.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/lurue/schooner_m4",
		"east" : "/d/av_rooms/lurue/schooner_s5",
	]));

}