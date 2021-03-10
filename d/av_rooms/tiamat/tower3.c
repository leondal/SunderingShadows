// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tower3");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("ledge");
    set_climate("tropical");

    set_short("%^MAGENTA%^Tower of Devils%^RESET%^");

    set_long("tower3");

    set_smell("default","
%^BOLD%^%^BLACK%^You smell sulfur%^RESET%^");
    set_listen("default","%^GREEN%^You hear a low hum%^RESET%^");


    set_exits(([ 
		"north" : "/d/av_rooms/tiamat/tower4",
		"east" : "/d/av_rooms/tiamat/tower2",
	]));

}