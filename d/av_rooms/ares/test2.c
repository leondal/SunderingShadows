// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("test2");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("scrub lands");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("short desc");

    set_long("long desc");

    set_smell("default","bad");
    set_listen("default","worse");


    set_exits(([ 
		"up" : "/realms/ares/workroom",
		"blah" : "/realms/ares/workroom",
		"east" : "/realms/ares/workroom",
	]));

}