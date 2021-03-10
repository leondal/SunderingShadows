// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_b8");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat tunnel");
    set_travel("foot path");
    set_climate("tropical");

    set_short("%^ORANGE%^an underground passage%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Another narrow corridor cuts through the earth, leaving the safety of the stone cave behind and twisting slowly through the sodden swamp till it comes to a small set of stone stairs"
	" that lead up to a blank wall.%^RESET%^"
	);

    set_smell("default","
You can smell the wet earth of the swamp.");
    set_listen("default","Things seem very quiet here.");

    
set_items(([ 
	"wall" : "%^BOLD%^%^BLACK%^The wall looks blank and bare, like the walls all around you, except as you look away, you're sure you caught a glimpse of %^RESET%^%^MAGENTA%^something%^BOLD%^%^BLACK%^.%^RESET%^",
	]));

    set_exits(([ 
		"stairs" : "/d/av_rooms/lurue/dekumage_b5",
		"southwest" : "/d/av_rooms/lurue/dekumage_b9",
	]));

}