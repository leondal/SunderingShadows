// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("test");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("Test room just for me");

    set_long("This is a test room just for fun. Search for blah and look at blah.");

    set_smell("default","
No smell");
    set_listen("default","silent");

    set_search("blah","You search the blah and find a blah");
    
set_items(([ 
	"blah" : "You see a blah in the dirt",
	]));

    set_exits(([ 
		"out" : "/d/dagger/avalounge",
	]));

}