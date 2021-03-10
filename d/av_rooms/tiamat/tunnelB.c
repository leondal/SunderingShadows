// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnelB");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat tunnel");
    set_travel("back alley");
    set_climate("temperate");

    set_short("%^MAGENTA%^A long forgotten crypt%^RESET%^");

    set_long("tunnel B, the crypt");

    set_smell("default","
%^ORANGE%^You smell the stench of age");
    set_listen("default","%^GREEN%^Very little sound penetrates the deep here");


    set_exits(([ 
		"west" : "/d/av_rooms/tiamat/tunnelA",
	]));

}