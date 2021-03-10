// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("vampireden");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^V%^RED%^a%^BLACK%^mpire D%^RED%^e%^BLACK%^n%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^A hidden door leads out of this room, and peering into the %^RESET%^gloom%^BOLD%^%^BLACK%^ you see very little. Yet out of the %^RESET%^%^MAGENTA%^shadows%^BOLD%^%^BLACK%^ you can see"
	" a regal sarcophagus of a noble. It is embossed with the figure of a %^BLUE%^Duke%^BLACK%^ bearing an ominous coat of arms: %^BOLD%^%^WHITE%^A Skull with a %^GREEN%^Venomous Snake%^WHITE%^ crawling th"
	"rough the eyesocket%^BLACK%^. Beyond that, not much can be seen, except for a simple wooden desk, and a chair.%^RESET%^"
	);

    set_smell("default","
The room smells of old mold.");
    set_listen("default","Its very quiet, and you can hear your own breathing.");

    set_search("floor","There are bloodstains on the floor!");
    set_search("sarcophagus","The sarcophagus is empty as far as you can see.");
    set_search("desk","You can see that someone has written here often, but there's no papers just an inkwell and pen.");
    
set_items(([ 
	"floor" : "There are bloodstains on the floor!",
	"sarcophagus" : "The sarcophagus is very old, and the coat of arms would require an expert to track it down. It is not a current insignia that is known in the lands.",
	"desk" : "The desk should have rotted by now. It must be preserved by some old magic.",
	]));

    set_exits(([ 
		"out" : "/d/deku/fortress/tomb3",
	]));

}