// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("hurse4");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^BLACK%^%^BOLD%^Hurse Lane%^RESET%^");

    set_long("Hurse Land description here.");

    set_smell("default","
A good smell");
    set_listen("default","Wierd sounds");


    set_exits(([ 
		"south" : "/d/av_rooms/mystra/hurse3",
		"west" : "/d/av_rooms/mystra/boore1",
		"north" : "/d/av_rooms/mystra/hurse5",
	]));

}