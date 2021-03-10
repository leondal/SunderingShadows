// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel10");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^MAGENTA%^An old pit%^RESET%^");

    set_long("tunnel10");

    set_smell("default","
%^ORANGE%^It smells like waste");
    set_listen("default","%^GREEN%^You hear little");


    set_exits(([ 
		"down" : "/d/av_rooms/tiamat/tunnel7",
	]));

    set_door("grate","/d/av_rooms/tiamat/tunnel7","down","grate key","grate lock");
    add_lock("grate","grate key","grate lock","A keylock in the grate");
    set_locked("grate",1,"grate lock");
    lock_difficulty("grate",-10,"grate lock");
    set_open("grate",0);
    set_string("grate","knock","taps on the grate");
    set_string("grate","open","You lift the grate");
    set_string("grate","close","You re set the grate");
    set_door_description("grate","A thick metal grate with a lock on the left side");
}