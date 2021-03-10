// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("faircamp4");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^Inside a dimly lit caravan%^RESET%^");

    set_long("%^RED%^Strategically placed in the center of the seven foot wide caravan is a round table set with four chairs furnished with dark brown leather cushions. Dim motes of light seep through the windows, "
	"adding mood lighting to the room. To the right and left of the doorway, multiple shelves and cupboards hold various things behind neatly closed and latched doors, all a deep wood color. Beside one of "
	"the spaces nearest the door, where a pair of newly polished shoes are removed and left, the floor is lined in a deep red colored rug, soft, almost heavenly for bare feet to tread upon. Dominating the "
	"farthest space of the caravan is a large, king sized bed veiled behind dark curtains. Full pillows and sheets shine softly, the crimson red satin reflecting some of the light that filters through the "
	"curtains. Before it at the foot end is a large dresser, where a multitude of costumes and evening wear are kept neatly at hand."
	);

    set_smell("default","
%^ORANGE%^An exotic cologne mixes with the scent of heated romance.");
    set_listen("default","%^BOLD%^%^BLACK%^It is quiet enough to hear a pin drop. ");


    set_exits(([ 
		"out" : "/d/av_rooms/hlal/faircamp1",
	]));

}