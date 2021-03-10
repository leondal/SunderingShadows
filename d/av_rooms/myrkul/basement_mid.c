// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("basement_mid");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^RESET%^%^CYAN%^Chapel Basement%^RESET%^");

    set_long("The chamber here is rather dank. At one time, this basement may have been used for storage. The passageways continues north, south, east, and west into the gloom. The marble floors, wall, and ceiling "
	"seem stable enough. The only light here is that which you carry. "
	);

    set_smell("default","
You smell nothing.");
    set_listen("default","It is rather quiet.");


    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/basement_west",
		"north" : "/d/av_rooms/myrkul/basement_north",
		"south" : "/d/av_rooms/myrkul/basement_south",
		"east" : "/d/av_rooms/myrkul/basement_east",
	]));

}