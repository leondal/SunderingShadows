// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("senbeach_01");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^A natural %^GREEN%^s%^RESET%^%^CYAN%^e%^BOLD%^%^GREEN%^a %^WHITE%^cave%^RESET%^");

    set_long("%^RESET%^A %^BOLD%^%^BLACK%^crack %^RESET%^in the wall, little more then a jagged weakening of the cliff's stone, makes for an opening into this natural %^GREEN%^s%^CYAN%^e%^GREEN%^a %^RESET%^cave.  T"
	"iny, there is barely enough room for one person to stand up straight without bumping their head against the %^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^RESET%^ veined stone.  A pool of %^BOLD%^%^BLUE%"
	"^sea water %^RESET%^fills the base of this cave, eluding to another way out.%^RESET%^ "
	);

    set_smell("default","
The clean scent of the ocean rises on the breeze.");
    set_listen("default","You can hear the crashing of waves on the shore above the occasional cry of a seagull.");

    set_search("water","%^BOLD%^%^BLUE%^You search around in the water and find a hole under the surface!%^RESET%^");
    
set_items(([ 
	({ "wall", "gold" }) : "%^YELLOW%^The golden veins of the cliff wall continue into this cave, giving the brown stone walls a bit of sparkle and brightness.  Unfortunately, there doesn't appear to be any real value to the golden highlights, crushing your dreams of making it rich by mining here.%^RESET%^",
	({ "water", "sea water" }) : "%^BOLD%^%^BLUE%^The water appears to be about three or so feet deep.  Deep enough to make seeing through it difficult.  Perhaps if you searched around you could figure out what's below the surface.%^RESET%^",
	"crack" : "%^BOLD%^%^BLACK%^The crack isn't much, but you're certain you could wedge yourself through and escape this small chamber. %^RESET%^",
	]));

    set_exits(([ 
		"out" : "/d/attaya/newseneca/rooms/beach1",
		"hole" : "/d/av_rooms/lurue/senbeach_02",
	]));



    set_invis_exits(({ "hole" }));

}