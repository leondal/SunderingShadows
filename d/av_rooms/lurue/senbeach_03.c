// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("senbeach_03");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("shallow water");
    set_travel("fresh blaze");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^An underwater sea cave%^RESET%^");

    set_long("%^RESET%^%^CYAN%^Carved from the %^BOLD%^%^BLACK%^stone bedrock %^RESET%^%^CYAN%^of the sea cliffs, this passage makes its way through the dark %^BOLD%^%^BLUE%^cold waters %^RESET%^%^CYAN%^down toward"
	" the open ocean.  Dark stone surrounds you with jagged, sharp edges, and bits of %^GREEN%^seaweed %^CYAN%^drift by obscuring your view.  In this tunnel, the current moves swiftly enough with the tide "
	"that little is able to survive, however, you notice the occasional tiny %^BLUE%^muscles%^RESET%^%^CYAN%^, %^BOLD%^%^BLACK%^barnacles %^RESET%^%^CYAN%^or %^RESET%^clam %^CYAN%^attached to a crevice whe"
	"re it clings against the insistent movement of water.%^RESET%^"
	);

    set_smell("default","
You can't smell anything underwater.");
    set_listen("default","The sound of the water moving past your ears is the only sound.");

    
set_items(([ 
	({ "bedrock", "rock", "stone", "stone bedrock" }) : "%^BOLD%^%^BLACK%^Darkened from the seawater and the ever present silt, the stones seem black, despite being made up of the same deep brown stone that the cliffs above are formed out of.  The sparkle of gold is lost down here in the dark, leaving you to drift in an in inky field of sharply jutting rocks.%^RESET%^",
	({ "seaweed", "silt" }) : "%^RESET%^%^GREEN%^Bits of plant and the silt drift in the water, obscuring your view and making the salt water gritty against your skin.%^RESET%^",
	({ "muscle", "clam", "barnacles", "barnacle", "muscles", "clams" }) : "%^RESET%^Here and there, niches and crevices spring up where the water has dug away at the surrounding stone.  In these relatively calm spots, muscles, clams and barnacles have found purchase and keep hold against the ever shifting tide.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/senbeach_04",
		"northeast" : "/d/av_rooms/lurue/senbeach_02",
	]));

}