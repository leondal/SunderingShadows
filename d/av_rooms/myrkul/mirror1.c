// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("mirror1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^H%^CYAN%^a%^WHITE%^ll of M%^CYAN%^i%^WHITE%^rr%^CYAN%^o%^WHITE%^rs%^RESET%^");

    set_long("This is a hall of mirrors. You can see your reflection.");

    set_smell("default","
You smell nothing.");
    set_listen("default","You hear your own footsteps and breathing.");


    set_exits(([ 
		"mirror" : "/d/av_rooms/myrkul/carn_pride",
	]));

}