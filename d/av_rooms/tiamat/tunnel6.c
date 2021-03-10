// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel6");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("back alley");
    set_climate("temperate");

    set_short("%^MAGENTA%^Under the City%^RESET%^");

    set_long("tunnel6");

    set_smell("default","
%^ORANGE%^It smells damp and old");
    set_listen("default","%^GREEN%^You hear the dripping of water%^RESET%^");

    
set_items(([ 
	({ "pictogram", "pictograms" }) : "%^ORANGE%^The pictograms here depict figures in hawk masks wearing dark clothing.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/tiamat/tunnel5",
		"east" : "/d/av_rooms/tiamat/tunnel7",
	]));

}