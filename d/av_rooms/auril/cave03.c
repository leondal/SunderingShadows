// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("path01");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("rubble");
    set_climate("mountain");

    set_short("%^BOLD%^%^WHITE%^In a cave");

    set_long("%^BOLD%^%^BLACK%^This cave is dark and continues deeper and deeper as you wind your way through its passageways.");

    set_smell("default","
%^BOLD%^%^WHITE%^It smells like stone.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLUE%^It sounds deathly quiet.");


    set_exits(([ 
		"upper" : "/d/av_rooms/auril/cave02",
		"deeper" : "/d/av_rooms/auril/cave04",
	]));

}