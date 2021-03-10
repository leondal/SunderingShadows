// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ship3");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("beach");
    set_travel("ledge");
    set_climate("temperate");

    set_short("%^MAGENTA%^Forecastle of a merchant ship");

    set_long("forecastle, ship3, arrgh");

    set_smell("default","
%^ORANGE%^You smell fresh ocean air minced with the smell of charred wood.");
    set_listen("default","%^GREEN%^You hear the boards of the ship creak in an unsettling way.");


    set_exits(([ 
		"maindeck" : "/d/av_rooms/tiamat/ship1",
	]));

}