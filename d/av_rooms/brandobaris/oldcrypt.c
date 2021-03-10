// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("oldcrypt");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^an o%^RESET%^l%^BOLD%^%^BLACK%^d and f%^RESET%^o%^BOLD%^%^BLACK%^r%^WHITE%^g%^BLACK%^o%^RESET%^%^ORANGE%^t%^BOLD%^%^WHITE%^t%^RESET%^e%^BOLD%^%^BLACK%^n c%^RESET%^%^ORANGE%^r%^WHITE%^y%^ORANGE%^p%^BOLD%^%^BLACK%^t%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This %^RESET%^a%^ORANGE%^n%^WHITE%^c%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^e%^WHITE%^nt c%^BOLD%^r%^BLACK%^y%^RESET%^%^ORANGE%^p%^WHITE%^t %^BOLD%^%^BLACK%^evokes an immediate sense of "
	"claustrophobia, and the scarce %^RESET%^l%^BOLD%^i%^RESET%^ght %^BOLD%^%^BLACK%^that filters down through the opening above does little to light the dust-ridden blackness around you. A %^RESET%^%^ORAN"
	"GE%^d%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^cr%^WHITE%^e%^YELLOW%^p%^RESET%^%^ORANGE%^it wooden ladder %^BOLD%^%^BLACK%^hangs about a foot off of the weathered, stone-tiled floor, and seems to be your o"
	"nly access back to the surface. Twelve %^RESET%^stone s%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^%^BLACK%^p%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^gi %^BOLD%^%^BLACK%^encircle the r"
	"oom, firmly sealed and with a %^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^t%^BOLD%^%^BLACK%^t%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^BLUE%^b%^RESET%^a%^BOLD%^%^BLUE%^n%^RESET%^n%^BOLD%^%^B"
	"LUE%^e%^RESET%^r %^BOLD%^%^BLACK%^draped over each. Within an alcove set into one of the walls lies a %^WHITE%^st%^RESET%^o%^BOLD%^ne %^RESET%^table %^BOLD%^%^BLACK%^with two benches on either side, a"
	"ll of them carved from the cavern rock itself.%^RESET%^"
	);

    set_smell("default","
The smell of ancient decay permeates the dusty air");
    set_listen("default","The sounds of the outside world echo faintly in here");

    
set_items(([ 
	({ "sarcophagus", "sarcophagi", "coffins", "coffin" }) : "%^BOLD%^%^BLACK%^Each of these sarcophagi is large enough to suit an adult human, and is wrought of %^RESET%^sm%^BOLD%^oot%^RESET%^h g%^BOLD%^r%^RESET%^ay s%^BOLD%^t%^RESET%^o%^BOLD%^n%^RESET%^e%^BOLD%^%^BLACK%^. They look to have once borne elaborate engravings, and there is a place for an %^RESET%^inscription %^BOLD%^%^BLACK%^at the foot of each, but time has worn these down to the point of illegibility. The lids of the sarcophagi are of similar stone, and look far too heavy to lift in this space.%^RESET%^",
	"ladder" : "%^ORANGE%^The passage of time has not been kind to this ladder. With rungs missing and some parts of the wooden rails eaten clean through by rot, it's a miracle that it's not fallen apart completely yet. Fortunately, it looks as if it should hold out for at least one more climb out of this crypt...or at least you hope so.",
	]));

    set_exits(([ 
		"ladder" : "/d/laerad/parnelli/asgard/as86",
	]));

}