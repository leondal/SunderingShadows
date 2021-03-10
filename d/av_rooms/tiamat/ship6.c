// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ship6");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("beach");
    set_travel("back alley");
    set_climate("temperate");

    set_short("%^MAGENTA%^Holding deck");

    set_long("ship6, cargo hold");

    set_smell("default","
%^ORANGE%^You smell fresh ocean air minced with the smell of charred wood.");
    set_listen("default","%^GREEN%^You hear the boards of the ship creak in an unsettling way.");


    set_exits(([ 
		"north" : "/d/av_rooms/tiamat/ship4",
		"south" : "/d/av_rooms/tiamat/shipA",
	]));

    set_door("cargo door","/d/av_rooms/tiamat/shipA","south","ship key","ship lock");
    add_lock("cargo door","ship key","ship lock","A padlock");
    set_locked("cargo door",1,"ship lock");
    lock_difficulty("cargo door",-75,"ship lock");
    set_open("cargo door",0);
    set_string("cargo door","knock","knocks on the cargo door");
    set_string("cargo door","open","You open the cargo door");
    set_string("cargo door","close","You close the cargo door");
    set_door_description("cargo door","A thick wooden door reinforced in steel.  It has a single keylock.");
}