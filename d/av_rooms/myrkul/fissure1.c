// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("fissure1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Inside a %^YELLOW%^f%^RED%^i%^YELLOW%^ssu%^RED%^r%^YELLOW%^e%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^You find yourself clinging to the wall, or leaping from boulder to boulder deep inside the fissure. The %^CYAN%^crack%^ORANGE%^ itself is wide enough for a couple horse drawn carria"
	"ges. Fortunately, the Earth seems to have fashioned itself in a zig-zag pattern as it plumbs the depths. The greatest %^RED%^drops%^ORANGE%^ seem to be about ten or fifteen feet at most. It seems very"
	" dangerous here.%^RESET%^"
	);

    set_smell("default","
It smells like dirt.");
    set_listen("default","%^ORANGE%^Faint vibrations can be felt rather than heard from the shifting Earth%^RESET%^");


    set_exits(([ 
		"up" : "/d/islands/tonerra/village/vil78",
		"cave" : "/d/av_rooms/myrkul/fissure2",
	]));

}