// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_shrine");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Shrine%^BOLD%^%^BLACK%^ to %^RED%^Lolth%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^A %^RED%^bloodstained %^YELLOW%^altar%^BLACK%^ stands at the back of the shrine. Before it, a %^RESET%^%^MAGENTA%^giant spider%^BOLD%^%^BLACK%^ has been etched into the marble floor w"
	"ith %^RED%^tiny rubies%^BLACK%^. The shrine is eight-sided, and shaped like an octagon. A single row of pews line the walls, and the altar is directly across from the entrance. A single orb of light h"
	"overs above the center of the room near the ceiling casting a %^RESET%^gritty%^RED%^ red%^YELLOW%^ glow%^BLACK%^. This place reeks of evil. %^RESET%^"
	);

    set_smell("default","
You smell musty books and incense nearby.");
    set_listen("default","You hear the sound of Drow voices and walking nearby.");

    set_search("symbols","The symbols are arcane in nature perhaps indicating a magical alarm.");
    set_search("wards","The wards do appear to be magical perhaps an alarm.");
    
set_items(([ 
	"books" : "There are various tomes related to magic, ancient history, deities, and especially Lolth.",
	"table" : "The table is clear and quite clean.",
	"floor" : "The floor is solid rock and not much to look at.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/x_nhall",
	]));

}