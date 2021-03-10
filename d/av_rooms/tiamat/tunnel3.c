// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel3");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^MAGENTA%^Under the City%^RESET%^");

    set_long("room three, with down");

    set_smell("default","
%^GREEN%^It smells damp and old%^RESET%^");
    set_listen("default","%^ORANGE%^You hear dripping water%^RESET%^");

    
set_items(([ 
	({ "pictogram", "pictograms" }) : "%^ORANGE%^The pictograms here depict images of mighty birds of prey, they are performing intelligent and religious actions.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/tiamat/tunnel2",
		"down" : "/d/av_rooms/tiamat/tunnel4",
		"east" : "/d/av_rooms/tiamat/tunnel5",
	]));

}