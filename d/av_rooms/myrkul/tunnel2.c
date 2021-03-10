// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel2");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Inside a fetid tunnel%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^You find yourself in a %^GREEN%^fetid tunnel%^ORANGE%^. It smells absolutely %^BOLD%^%^MAGENTA%^terrible%^RESET%^%^ORANGE%^. A cold, slimy river of raw %^YELLOW%^sewage%^RESET%^%^OR"
	"ANGE%^ floats past you. The walls of the tunnel are rounded, and at one point this must have been made to drain out %^MAGENTA%^waste%^ORANGE%^ from the city of Tabor. The light is dim, and while you c"
	"an't be positive, there might be something %^WHITE%^living%^ORANGE%^ down here!!%^RESET%^"
	);

    set_smell("default","
The smell of shit is so strong down here it could make a kobold cry!");
    set_listen("default","You here something moving in the sludge.");

    set_search("tunnel","There is nothing but a lack of fresh air.");
    set_search("waste","You find nothing in the waste. Icky!");
    
set_items(([ 
	"tunnel" : "It is rounded and made of some kind of stone or packed dirt.",
	"waste" : "Yep, its a river of turds.",
	"sewage" : "This place is gross!",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/tunnel3",
		"northwest" : "/d/av_rooms/myrkul/tunnel1",
	]));

}