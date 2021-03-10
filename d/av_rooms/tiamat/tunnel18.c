// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel18");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^MAGENTA%^Before a large crack");

    set_long("tunnel18, with exit, yay");

    set_smell("default","
%^ORANGE%^It smells like age and dampness");
    set_listen("default","%^GREEN%^You hear little here");

    
set_items(([ 
	({ "pictogram", "pictograms" }) : "%^ORANGE%^The pictograms here have faded into oblivion from sunlight and magic.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/tiamat/tunnel17",
		"out" : "/d/antioch/ruins/rooms/ruins10",
	]));

}