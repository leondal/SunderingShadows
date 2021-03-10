// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel1");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Under the City");

    set_long("room one");

    set_smell("default","
%^GREEN%^It smells damp and old");
    set_listen("default","%^ORANGE%^You hear dripping water%^RESET%^");

    
set_items(([ 
	({ "pictogram", "pictograms" }) : "%^ORANGE%^The pictograms here depict images of a beautiful city which reminds you of present day Antioch, but was much larger",
	"pictogram" : "%^ORANGE%^The pictograms here depict images of a beautiful city which reminds you of present day Antioch, but was much larger",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/tiamat/tunnel2",
	]));

}