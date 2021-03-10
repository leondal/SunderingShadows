// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_gate");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^T%^WHITE%^h%^BLACK%^e C%^BOLD%^%^RED%^e%^BLACK%^met%^WHITE%^a%^BLACK%^ry G%^BLUE%^a%^BLACK%^te%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^An ancient gate to the cemetery stands sentry against time and hope. It has bars of steel that never seem to rust, and not a hint of grass grows near its reach. A symbol has been torn"
	" from the front of the gate, and the scales of Kelemvor can be seen, bent and trampled in the mud. An %^BLACK%^entity%^WHITE%^ seems to have taken residence here for a time, for all %^MAGENTA%^hope%^W"
	"HITE%^ seems to have dried up from the very air.%^RESET%^"
	);

    set_smell("default","
The stench of death and dread reaches your nostrils.");
    set_listen("default","The tramp and tread of skeletal feet is very loud.");

    set_search("grave","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    set_search("graves","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    
set_items(([ 
	({ "grave", "graves" }) : "%^BOLD%^%^BLACK%^Hmmm. This now empty grave looks to be, oh, %^MAGENTA%^about your size!%^RESET%^",
	({ "restless dead", "dead" }) : "%^BOLD%^%^GREEN%^The %^BLACK%^dead%^GREEN%^ walk. Villagers, soldiers, farmers, young, old. The %^BLACK%^h%^YELLOW%^orror%^GREEN%^ of this place is %^RESET%^%^MAGENTA%^unspeakable.%^RESET%^",
	"evil" : "%^RED%^The presence of evil in this place is undeniable.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/boneyard_south_gate",
	]));

}