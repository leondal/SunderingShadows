// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel5");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^MAGENTA%^Under the City%^RESET%^");

    set_long("More tunnel!");

    set_smell("default","
%^ORANGE%^You smell moisture and mold");
    set_listen("default","%^GREEN%^You hear water dripping");

    
set_items(([ 
	({ "pictogram", "pictograms" }) : "%^ORANGE%^The pictograms here have been rendered unreadable from age or weathering.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/tiamat/tunnel3",
		"east" : "/d/av_rooms/tiamat/tunnel6",
	]));

}