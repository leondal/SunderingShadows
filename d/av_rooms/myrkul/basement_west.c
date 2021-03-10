// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("basement_west");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^RESET%^%^CYAN%^Chapel Basement%^RESET%^");

    set_long("The chamber here is rather dank. At one time, this basement may have been used for storage. A massively heavy stone slab has been moved revealing stairs leading downstairs into the crypt. The passagew"
	"ay continues east into the gloom. The marble floors, wall, and ceiling seem stable enough. The only light here is that which you carry. "
	);

    set_smell("default","
You smell nothing.");
    set_listen("default","It is rather quiet.");


    set_exits(([ 
		"down" : "/d/av_rooms/myrkul/crypt_hall_west2",
		"east" : "/d/av_rooms/myrkul/basement_mid",
	]));

}