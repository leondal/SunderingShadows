// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("basement_north");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Chapel Basement%^RESET%^");

    set_long("The chamber here is rather dank. At one time, this basement may have been used for storage. This seems like a dead end. The passageway continues south into the gloom. The marble floors, wall, and ceil"
	"ing seem stable enough. The only light here is that which you carry. "
	);

    set_smell("default","
You smell nothing.");
    set_listen("default","It is rather quiet.");


    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/basement_mid",
	]));

}