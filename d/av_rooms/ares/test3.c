// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("test3");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("meadows");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("short desc");

    set_long("long desc");

    set_smell("default","
smells bad");
    set_listen("default","sounds bad");


    set_exits(([ 
		"north" : "/realms/ares/workroom",
	]));

    set_door("wooden door","/realms/ares/workroom","north","nokey","testlock");
    add_lock("wooden door","nokey","testlock","a test lock");
    set_locked("wooden door",1,"testlock");
    lock_difficulty("wooden door",-100,"testlock");
    add_lock("wooden door","no_key","padlock","a big padlock");
    set_locked("wooden door",1,"padlock");
    lock_difficulty("wooden door",-100,"padlock");
    set_open("wooden door",0);
    set_string("wooden door","knock","knocks on the");
    set_string("wooden door","open","the door opens");
    set_string("wooden door","close","the door closes");
    set_door_description("wooden door","it's a door");
}