// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("faircamp1");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("light forest");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^ORANGE%^An Occupied Campground%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Tents and carvans are in various states of setup as some group or other has started settling in close together. A large open space has been left in the center of the camp for those "
	"in the area to gather. Whoever is in charge of the camp is keeping it well kept and free of litter.%^RESET%^"
	);

    set_smell("default","
%^RESET%^%^GREEN%^Exotic scents fill the air around the camp.");
    set_listen("default","%^BOLD%^%^GREEN%^Laughter and song fill the area as people practice their performances.%^RESET%^");

    
set_items(([ 
	"caravans" : "%^BOLD%^%^CYAN%^Some are old, some are new, but almost all of them are designed and painted in random themes and colors.%^RESET%^",
	"tents" : "%^BOLD%^%^GREEN%^Tents of all sizes, shapes, and colors are set up all over the grounds.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/koenig/streams/camp1",
		"red" : "/d/av_rooms/hlal/faircamp4",
		"blue" : "/d/av_rooms/hlal/faircamp2",
		"green" : "/d/av_rooms/hlal/faircamp3",
	]));

}