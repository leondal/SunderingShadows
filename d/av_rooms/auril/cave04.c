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

    set_long("%^BOLD%^%^BLACK%^This cave ends here and you feel the %^BOLD%^%^YELLOW%^light %^BOLD%^%^BLACK%^hit you as you realize you can finally leave. Before you is a beautiful area, tucked away from civilization. There looks to be some sort of large town here.");

    set_smell("default","
%^BOLD%^%^WHITE%^It smells like stone.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLUE%^It sounds deathly quiet.");


    set_exits(([ 
		"upper" : "/d/av_rooms/auril/cave02",
		"out" : "/d/av_rooms/auril/drowplace01",
	]));

}