// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel16");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^MAGENTA%^A narrow pit");

    set_long("tunnel16");

    set_smell("default","
%^ORANGE%^A strange foulness catches your nose");
    set_listen("default","%^GREEN%^You hear rustling nearby");


    set_exits(([ 
		"up" : "/d/av_rooms/tiamat/tunnel14",
	]));

}