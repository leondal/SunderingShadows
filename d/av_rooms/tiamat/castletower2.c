// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("castletower2");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("back alley");
    set_climate("temperate");

    set_short("Tower Stairs");

    set_long("You are within a tower.  Like the rest of the castle, this small corridor is made up of roughly cut stone.  There is little decor except for the empty %^BOLD%^%^BLACK%^sconces%^RESET%^.  A spiraling s"
	"tone stairwell hugs to walls of the room, leading up the tower.  Although the steps are narrow, they appear sturdy and functional.  Thin arrow slits built into the tower let the slightest bit of light"
	" in, although it is dulled by a net of %^BOLD%^webbing%^RESET%^."
	);

    set_smell("default","
%^GREEN%^It smells like age and mildew.%^RESET%^");
    set_listen("default","%^ORANGE%^You hear distant dripping.%^RESET%^");

    
set_items(([ 
	({ "webs", "cobwebs" }) : "Cobwebs riddle the castle ruins, everywhere they can.  The webbing is just a little too thick, suggesting very big spiders.",
	({ "hanging", "hangings" }) : "%^ORANGE%^The walls look like they once proudly displayed a variety of hangings, tapestries and banners.  They have long since decayed so as to be unrecognizable.%^RESET%^",
	({ "sconce", "sconces" }) : "Rusting sconces probably once held torches.  Very little light penetrates here now.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/tiamat/castletower3",
		"down" : "/d/av_rooms/tiamat/castletower1",
	]));

}