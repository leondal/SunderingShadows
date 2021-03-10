// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tecqumin_01");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("jungle");
    set_travel("fresh blaze");
    set_climate("tropical");

    set_short("%^GREEN%^Passage to the Jungle%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^You find yourself standing deep in the jungle, surrounded by many %^MAGENTA%^wonders %^GREEN%^and %^YELLOW%^treasures%^GREEN%^.  All you must do is follow the many %^RESET%^%^CYAN%^tr"
	"ails%^GREEN%^%^BOLD%^ that crisscross here and you can go to explore them all.%^RESET%^"
	);

    set_smell("default","
The air is crisp and filled with jungle scents.");
    set_listen("default","You can hear the sounds of the jungle all around you.");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/orogcave_h1",
		"south" : "/d/av_rooms/lurue/tecqumin_05",
		"west" : "/d/av_rooms/lurue/tecqumin_04",
		"north" : "/d/av_rooms/lurue/tecqumin_02",
		"east" : "/d/av_rooms/lurue/tecqumin_03",
		"northwest" : "/d/av_rooms/lurue/cliff_01",
		"lujkeorog" : "/realms/lujke/tecqumin/tabaxi/rooms/orogs01",
	]));

}