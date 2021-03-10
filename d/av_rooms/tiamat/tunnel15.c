// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel15");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^MAGENTA%^A low ledge underground");

    set_long("tunnel15");

    set_smell("default","
%^ORANGE%^It smells like dampness");
    set_listen("default","%^GREEN%^You hear little here");


    set_exits(([ 
		"down" : "/d/av_rooms/tiamat/tunnel14",
	]));

}