// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tombroad");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("rubble");
    set_climate("mountain");

    set_short("%^CYAN%^A trail on Winter Island%^RESET%^");

    set_long("%^CYAN%^The tunnels from shore lead into a deep ravine trail.  Hazardous rocks rise up at least two stories overhead and narrows near the top.  You can see through the opening above the high slopes of"
	" %^BOLD%^%^WHITE%^Winter island%^RESET%^%^CYAN%^ dotted with ice-caked %^GREEN%^evergreens%^CYAN%^.  The road is wide, winding and jagged, but serviceable.  Evidence of traffic exists here and there i"
	"n the form of %^WHITE%^bones%^CYAN%^, scraps and adventuring %^BOLD%^%^BLACK%^junk%^RESET%^%^CYAN%^.%^RESET%^"
	);

    set_smell("default","
%^ORANGE%^You smell pine trees.");
    set_listen("default","%^GREEN%^You hear an ugly bird call.");

    
set_items(([ 
	"evergreens" : "%^GREEN%^Tall evergreen pines line the distant slopes of Winter Island.  They would be lovely to paint, but maybe you should pay attention to the dangers ahead?",
	"junk" : "%^BOLD%^%^BLACK%^Odds and ends have ended up in a sort of refuse dump in the ravine.  You can make out rusted lanterns and climbing tools, shattered kits and mouldering coats.  Nothing is serviceable.",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/tiamat/tombroad2",
		"leave" : "/d/shadow/virtual/sea/winter.dock",
	]));

}