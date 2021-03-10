// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("camp");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("ledge");
    set_climate("mountain");

    set_short("%^BOLD%^%^RED%^A merchant camp%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^A %^GREEN%^boisterous%^RESET%^%^ORANGE%^ bunch of merchants are huddled around a fire, cooking food, and resting. They are bringing their goods from all across the lands to the far "
	"flung reaches of %^BLUE%^Kinaro,%^GREEN%^ Shadow,%^YELLOW%^ Tharis, %^MAGENTA%^Tonovi%^RESET%^%^ORANGE%^, and all points in between. They are a hard partying bunch, and they have already dipped %^RED%"
	"^deep%^RESET%^%^ORANGE%^ into their store of booze.%^RESET%^"
	);

    set_smell("default","
It smells of smoke and cooking.");
    set_listen("default","You hear the raucous sounds of a hard partying band of merchants.");


    set_exits(([ 
		"pens" : "/d/av_rooms/myrkul/pen_slave",
		"lookout" : "/d/av_rooms/myrkul/camp_lookout",
	]));

}