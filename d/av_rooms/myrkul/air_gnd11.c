// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("air_gnd11");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("barren");
    set_travel("paved road");
    set_climate("temperate");

    set_short("Ground");

    set_long("After a long drop, this is the splat at the end. Ouch!");

    set_smell("default","
It smells like ground.");
    set_listen("default","Its quiet.");


    set_exits(([ 
		"up" : "/d/av_rooms/myrkul/air_sky11",
	]));

}