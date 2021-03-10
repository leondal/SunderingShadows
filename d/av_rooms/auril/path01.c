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

    set_short("%^BOLD%^%^WHITE%^A path to a cave");

    set_long("%^BOLD%^%^WHITE%^This path goes up until a hole in the mountain here, a %^BOLD%^%^BLACK%^cave %^BOLD%^%^WHITE%^that is hard to see do to the heavy forested area around it.%^RESET%^");

    set_smell("default","
%^BOLD%^%^WHITE%^It smells like stone%^RESET%^");
    set_listen("default","%^BOLD%^%^BLUE%^It sounds deathly quiet.");


    set_exits(([ 
		"cave" : "/d/av_rooms/auril/cave01",
		"northwest" : "/d/av_rooms/auril/battleforest25",
	]));

}