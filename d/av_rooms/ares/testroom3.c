// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("testroom3");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("rubble");
    set_climate("temperate");

    set_short("a short desc");

    set_long("a long desc");

    set_smell("default","
smells bad");
    set_listen("default","sounds worse");


    set_exits(([ 
		"west" : "/realms/ares/workroom",
		"south" : "/realms/ares/workroom",
		"north" : "/realms/ares/workroom",
		"east" : "/realms/ares/workroom",
	]));



	set_invis_exits(({ "north", "east" }));

}