// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crypt_secret_vault");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("Secret Vault");

    set_long("This is the eastern wing of the crypt. Stairs lead downward.");

    set_smell("default","
Nothing");
    set_listen("default","Nothing");


    set_exits(([ 
		"southwest" : "/d/av_rooms/myrkul/crypt_hall_east3",
	]));

}