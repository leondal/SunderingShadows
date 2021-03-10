// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel8");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^MAGENTA%^A crack in the earth%^RESET%^");

    set_long("tunnel8, the gorge");

    set_smell("default","
%^ORANGE%^There is a foul smell coming from the gorge");
    set_listen("default","%^GREEN%^You hear the distant claw of legions in the gorge");


    set_exits(([ 
		"up" : "/d/av_rooms/tiamat/tunnel7",
	]));

}