// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_c8");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^A room within an underwater structure%^RESET%^");

    set_long("%^RESET%^%^CYAN%^Once a large and well appointed dining room, this chamber has long since fallen away into decay.  The large and stately %^ORANGE%^table %^CYAN%^has collapsed against one of the walls,"
	" shattering its chairs and creating a large pile of %^BLACK%^%^BOLD%^rubble %^RESET%^%^CYAN%^over which several tattered %^RESET%^curtains %^CYAN%^have fallen.  This has created a %^BOLD%^%^BLACK%^cav"
	"e like area %^RESET%^%^CYAN%^within the room.  One within which even the ever present tiny %^RESET%^fish %^CYAN%^dare not to enter.%^RESET%^"
	);

    set_smell("default","
There is nothing to smell here.");
    set_listen("default","The bubbles escape from your lip and nose making a constant buzz against your ear.");

    set_search("rubble","%^BOLD%^%^BLACK%^You search about and realize that there is a way under all this rubble.  Maybe you could squeeze through that %^RESET%^%^CYAN%^hole%^BOLD%^%^BLACK%^ there, and climb under.%^RESET%^");
    
set_items(([ 
	({ "curtains", "curtain" }) : "%^GREEN%^Most of the curtains appear to be tattered scraps, worn by the water and time.%^RESET%^",
	({ "table", "chair", "chairs" }) : "%^RESET%^%^ORANGE%^There isn't much left of any of them, but the large, heavy wood slabs that were used to make the dinning table appear to have weathered the damage better then its surrounding chairs.  This has created a small cave within the dinning room.%^RESET%^",
	"cave" : "%^BOLD%^%^BLACK%^It looks like something or someone has removed one of rotted chairs from the table and made an opening, much like a cave.  You could probably squeeze into that %^RESET%^%^CYAN%^hole%^BOLD%^%^BLACK%^ if you tried.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/seawreck_c7",
		"hole" : "/d/av_rooms/lurue/seawreck_c10",
	]));



    set_invis_exits(({ "hole" }));

}