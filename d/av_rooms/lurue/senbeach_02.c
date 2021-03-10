// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("senbeach_02");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("shallow water");
    set_travel("fresh blaze");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^An underwater sea cave%^RESET%^");

    set_long("%^RESET%^%^CYAN%^Carved from the %^BOLD%^%^BLACK%^stone bedrock %^RESET%^%^CYAN%^of the sea cliffs, this passage makes its way through the dark %^BOLD%^%^BLUE%^cold waters %^RESET%^%^CYAN%^down toward"
	" the open ocean.  Dark stone surrounds you with jagged, sharp edges, and bits of %^GREEN%^seaweed %^CYAN%^drift by obscuring your view.  Above you can see a %^BOLD%^%^BLACK%^hole %^RESET%^%^CYAN%^in t"
	"he ceiling and the faint hint of %^YELLOW%^l%^WHITE%^i%^RESET%^g%^YELLOW%^h%^WHITE%^t%^RESET%^%^CYAN%^ suggesting a way out of this dark chamber.%^RESET%^"
	);

    set_smell("default","
You can't smell anything underwater.");
    set_listen("default","The sound of the water moving past your ears is the only sound.");

    
set_items(([ 
	({ "bedrock", "rock", "stone", "stone bedrock" }) : "%^BOLD%^%^BLACK%^Darkened from the seawater and the ever present silt, the stones seem black, despite being made up of the same deep brown stone that the cliffs above are formed out of.  The sparkle of gold is lost down here in the dark, leaving you to drift in an in inky field of sharply jutting rocks.%^RESET%^",
	({ "seaweed", "silt" }) : "%^RESET%^%^GREEN%^Bits of plant and the silt drift in the water, obscuring your view and making the salt water gritty against your skin.%^RESET%^",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/lurue/senbeach_01",
		"southwest" : "/d/av_rooms/lurue/senbeach_03",
	]));

}