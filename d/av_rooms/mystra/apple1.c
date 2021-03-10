// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("apple1");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Apple St.%^RESET%^");

    set_long("Apple 1");

    set_smell("default","
Aromas");
    set_listen("default","Sounds");


    set_exits(([ 
		"south" : "/d/av_rooms/mystra/gum6",
		"north" : "/d/av_rooms/mystra/apple2",
		"east" : "/d/av_rooms/mystra/gallows1",
	]));

}