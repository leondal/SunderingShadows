// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("faircamp2");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^CYAN%^Inside a sky blue caravan%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^Shades of blue and white make up the inside of this airy caravan. It is small even as caravans go and the owner has obviously designed it to appear more roomy than it is. Puffy white c"
	"louds have been painted on the walls, almost completely hiding the small drawers and cabinets that have been built to ensure that whoever uses the caravan will have a place for everything. A curtain o"
	"f crystals falls from the ceiling in an attempt to hide the lofted bed in the back. Near the entrance is a table with a simple white lace tablecloth and a couple of chairs that sit facing each other."
	);

    set_smell("default","
%^RESET%^%^ORANGE%^The light scent of incense fills the room.");
    set_listen("default","The tingling of crystals can be heard.");


    set_exits(([ 
		"out" : "/d/av_rooms/hlal/faircamp1",
	]));

}