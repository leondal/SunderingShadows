// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel4");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^MAGENTA%^Under the City%^RESET%^");

    set_long("a basement");

    set_smell("default","
%^GREEN%^It smells damp and old");
    set_listen("default","%^ORANGE%^You hear dripping water");


    set_exits(([ 
		"up" : "/d/av_rooms/tiamat/tunnel3",
		"east" : "/d/av_rooms/tiamat/tunnelA",
	]));
    set_door("seal door","/d/av_rooms/tiamat/tunnelA","east","Tiamat_keep_key","lock");
    set_locked("seal door", 1, "lock");
    lock_difficulty("seal door",-200, "lock");
    set_lock_description("seal door", "lock","This is a key lock built into the turning wheel.");
    set_open("seal door",0);
    set_string("seal door","knock","taps on the sealed door.");
    set_string("seal door","open","You turn the wheel and open the sealed door");
    set_string("seal door","close","You spin the wheel and close the sealed door");
    set_door_description("seal door","The door is a few feet off the ground.  It is round and made of dense metal.  A wheel is built into the door, providing a tight seal and locking mechanism.");
}