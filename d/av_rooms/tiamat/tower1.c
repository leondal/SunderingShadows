// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tower1");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("ledge");
    set_climate("tropical");

    set_short("%^MAGENTA%^The Tower of Devils%^RESET%^");

    set_long("tower1");

    set_smell("default","
%^BOLD%^%^BLACK%^You smell sulfur%^RESET%^");
    set_listen("default","%^GREEN%^You hear a low hum");


    set_exits(([ 
		"up" : "/d/av_rooms/tiamat/tower2",
		"down" : "/d/av_rooms/tiamat/tiamattowerA",
	]));

}