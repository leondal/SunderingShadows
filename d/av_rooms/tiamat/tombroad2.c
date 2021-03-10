// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tombroad2");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("rubble");
    set_climate("mountain");

    set_short("%^CYAN%^A trail on Winter Island%^RESET%^");

    set_long("%^CYAN%^The path leads deeper into a deep ravine trail.  Hazardous rocks rise up at least two stories overhead and narrows near the top.  You can see through the opening above the high slopes of %^BOL"
	"D%^%^WHITE%^Winter island%^RESET%^%^CYAN%^ dotted with ice-caked %^GREEN%^evergreens%^CYAN%^.  The road is wide, winding and jagged, but serviceable.  Evidence of traffic exists here and there in the "
	"form of %^WHITE%^bones%^CYAN%^, scraps and adventuring %^BOLD%^%^BLACK%^junk%^RESET%^%^CYAN%^.  A stone %^RESET%^archway%^CYAN%^, partially concealed in ice, stands to the north.%^RESET%^"
	);

    set_smell("default","
%^ORANGE%^You smell pine trees.");
    set_listen("default","%^GREEN%^You hear an ugly bird call.");

    
set_items(([ 
	"evergreens" : "%^GREEN%^Tall evergreen pines line the distant slopes of Winter Island.  They would be lovely to paint, but maybe you should pay attention to the dangers ahead?",
	"junk" : "%^BOLD%^%^BLACK%^Odds and ends have ended up in a sort of refuse dump in the ravine.  You can make out rusted lanterns and climbing tools, shattered kits and mouldering coats.  Nothing is serviceable.",
	"archway" : "The stone archway stands approximately nine feet tall.  It is made from roughly cut stone. Any inscription it once had has long been weathered away by the climate here.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/tiamat/tombroad",
		"north" : "/d/av_rooms/tiamat/tomb1",
	]));

    set_door("door","/d/av_rooms/tiamat/tomb1","north");
    set_open("door",0);
    set_string("door","knock","knocks on the");
    set_string("door","open","%^BLUE%^The door opens with a rush of cold air!");
    set_string("door","close","You close the door.");
    set_door_description("door","%^ORANGE%^A feeble wooden door hangs off of primitive hinges carved into the archway.%^RESET%^");
}