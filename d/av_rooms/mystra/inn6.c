// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("inn6");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^Northern Hallway%^RESET%^");

    set_long("It is slightly darker here than in other portions of the inn.  %^BOLD%^%^YELLOW%^Light %^RESET%^from the chandelier in the main hall barely reaches this far into the hallway and no sconces or candles "
	"can be found hanging on the walls for fear of damaging the many %^MAGENTA%^paintings %^RESET%^hanging about.  At the end of the hallway here is a large %^BOLD%^white door%^RESET%^.  It is mostly plain"
	" in design with only four lightly-beveled squares the only thing seperating it from a painted slab of %^ORANGE%^wood%^RESET%^."
	);

    set_smell("default","
%^CYAN%^The hallway smells fresh and clean%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^It is quiet in this part of the inn%^RESET%^");


    set_exits(([ 
		"north" : "/d/av_rooms/mystra/inn8",
		"south" : "/d/av_rooms/mystra/inn5",
	]));

}