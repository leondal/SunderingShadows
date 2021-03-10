// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_c10");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^Under the rubble%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^There is not much to see in this narrow space under a large pile of rubble.  The remains of a %^RESET%^%^ORANGE%^dining table %^BOLD%^%^BLACK%^create the ceiling, while piles of wood "
	"chairs, swollen with water and shattered by the pressure, circle it.  The tatters of %^RESET%^fabric curtains %^BOLD%^%^BLACK%^further augment the deteriorating pile, while a floor to ceiling %^RESET%"
	"^%^CYAN%^glass window %^BOLD%^%^BLACK%^has broken away to allow escape out of this suffocating space.%^RESET%^"
	);

    set_smell("default","
There is nothing to smell here.");
    set_listen("default","The bubbles escape from your lip and nose making a constant buzz against your ear.");

    
set_items(([ 
	({ "window", "glass", "glass window" }) : "%^CYAN%^The glass window has been broken away and the green canvas fabric that covers the outside is torn open to allow you to continue your exploration.%^RESET%^",
	({ "curtains", "curtain" }) : "%^GREEN%^Most of the curtains appear to be tattered scraps, worn by the water and time, but there is one section with a emerald cast to it which not only looks fairly new, but like canvas.%^RESET%^",
	({ "table", "chair", "chairs" }) : "%^RESET%^%^ORANGE%^There isn't much left of any of them, but the large, heavy wood slabs that were used to make the dinning table appear to have weathered the damage better then its surrounding chairs.  This has created a small cave within the dinning room.%^RESET%^",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/lurue/seawreck_c8",
		"out" : "/d/av_rooms/lurue/seawreck_b1",
	]));

}