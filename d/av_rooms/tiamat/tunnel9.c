// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel9");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("ledge");
    set_climate("temperate");

    set_short("%^MAGENTA%^Along a crack in the earth%^RESET%^");

    set_long("tunnel9");

    set_smell("default","
%^ORANGE%^There is a general mysterious odor here");
    set_listen("default","%^GREEN%^You hear little but distant clawing");

    
set_items(([ 
	({ "pictogram", "pictograms" }) : "%^ORANGE%^The pictograms here depict images of a king leading his armies on a holy war.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/tiamat/tunnel7",
		"up" : "/d/av_rooms/tiamat/tunnel12",
	]));

}