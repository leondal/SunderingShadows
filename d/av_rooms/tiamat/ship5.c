// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ship5");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("beach");
    set_travel("back alley");
    set_climate("temperate");

    set_short("%^MAGENTA%^A Small Room");

    set_long("ship5, small room");

    set_smell("default","
%^ORANGE%^You smell fresh ocean air minced with the smell of charred wood.");
    set_listen("default","%^GREEN%^You hear the boards of the ship creak in an unsettling way.");


    set_exits(([ 
		"east" : "/d/av_rooms/tiamat/ship4",
	]));

}