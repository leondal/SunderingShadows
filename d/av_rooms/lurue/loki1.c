// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("loki1");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("short");

    set_long("long");

    set_smell("default","
There is a strange scent in the air.");
    set_listen("default","Things seem strangely quiet.");


    set_exits(([ 
		"east" : "/d/av_rooms/lurue/loki2",
	]));

}