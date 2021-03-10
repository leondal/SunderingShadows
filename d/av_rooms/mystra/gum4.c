// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("gum4");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Gum St.%^RESET%^");

    set_long("Gum 4");

    set_smell("default","
Odors");
    set_listen("default","Noise");


    set_exits(([ 
		"west" : "/d/av_rooms/mystra/gum3",
		"east" : "/d/av_rooms/mystra/gum5",
	]));

}