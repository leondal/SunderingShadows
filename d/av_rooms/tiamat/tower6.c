// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tower6");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("ledge");
    set_climate("tropical");

    set_short("%^BOLD%^%^BLACK%^The Ritual Site%^RESET%^");

    set_long("tower6");

    set_smell("default","
%^BOLD%^%^BLACK%^Your nose is assualted by brimstone and heat");
    set_listen("default","%^GREEN%^You hear chanting and chaos from within the portal");


    set_exits(([ 
		"down" : "/d/av_rooms/tiamat/tower5",
	]));

}