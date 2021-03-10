// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("inspiration_station");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^I%^RESET%^n%^BOLD%^s%^RESET%^p%^BOLD%^i%^RESET%^r%^BOLD%^a%^RESET%^t%^BOLD%^i%^RESET%^o%^BOLD%^n S%^RESET%^t%^BOLD%^a%^RESET%^t%^BOLD%^i%^RESET%^o%^BOLD%^n%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This is where Hlal likes to relax. Bring treats if you want to visit. She enjoys peanut butter cookies best. There is a lot of empty space here for remodeling. Hopefully she has plans"
	" to do so. More cookies please.%^RESET%^"
	);

    set_smell("default","
%^ORANGE%^It smells like cookies in the oven%^RESET%^");
    set_listen("default","%^YELLOW%^Somewhere in the distance a timer goes off%^RESET%^");


    set_exits(([ 
		"paint3" : "/d/av_rooms/hlal/paint_r3",
		"paint2" : "/d/av_rooms/hlal/paint_r2",
		"paint1" : "/d/av_rooms/hlal/paint_r1",
		"paint6" : "/d/av_rooms/hlal/paint_r6",
		"paint5" : "/d/av_rooms/hlal/paint_r5",
		"paint4" : "/d/av_rooms/hlal/paint_r4",
	]));

}