// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ship4");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("beach");
    set_travel("back alley");
    set_climate("temperate");

    set_short("%^MAGENTA%^Corridor within a merchant ship%^RESET%^");

    set_long("corridor, ship4, matey");

    set_smell("default","
%^ORANGE%^You smell fresh ocean air minced with the smell of charred wood.");
    set_listen("default","%^GREEN%^You hear the boards of the ship creak in an unsettling way.");


    set_exits(([ 
		"south" : "/d/av_rooms/tiamat/ship6",
		"west" : "/d/av_rooms/tiamat/ship5",
		"east" : "/d/av_rooms/tiamat/ship7",
		"maindeck" : "/d/av_rooms/tiamat/ship1",
	]));

}