// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnelA");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^MAGENTA%^A sealed Chamber%^RESET%^");

    set_long("tunnelA, a sealed chamber");

    set_smell("default","
%^GREEN%^It smells old and sterile%^RESET%^");
    set_listen("default","%^ORANGE%^You hear nothing but your own movements");


    set_exits(([ 
		"west" : "/d/av_rooms/tiamat/tunnel4",
		"east" : "/d/av_rooms/tiamat/tunnelB",
	]));

    set_door("seal door","/d/av_rooms/tiamat/tunnel4","west");
    set_open("seal door",0);
    set_string("seal door","knock","taps on the sealed door");
    set_string("seal door","open","You turn the wheel and open the sealed door");
    set_string("seal door","close","You spin the wheel and seal the door");
    set_door_description("seal door","The door is a few feet off the ground.  It is round and made of dense metal.  A wheel is built into the door, providing a tight seal and locking mechanism.");
}