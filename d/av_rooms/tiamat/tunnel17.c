// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel17");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^MAGENTA%^Under the City");

    set_long("more tunnel17");

    set_smell("default","
%^ORANGE%^It smells damp");
    set_listen("default","%^GREEN%^You hear water dripping");

    
set_items(([ 
	({ "pictogram", "pictograms" }) : "%^ORANGE%^The pictograms here depict figures dressed in black leaving their desert homeland.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/tiamat/tunnel14",
		"east" : "/d/av_rooms/tiamat/tunnel18",
	]));

}