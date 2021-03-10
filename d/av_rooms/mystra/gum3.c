// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("gum3");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Gum St.%^RESET%^");

    set_long("Gum 3");

    set_smell("default","
Odors");
    set_listen("default","Noise");


    set_exits(([ 
		"south" : "/d/av_rooms/mystra/hurse5",
		"west" : "/d/av_rooms/mystra/gum2",
		"east" : "/d/av_rooms/mystra/gum4",
	]));

}