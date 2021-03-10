// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_t4");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("stairway");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A hole in the ground%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The tight crawl space opens up here into a hole in the ground.  Half filled with %^BLUE%^water %^BLACK%^and %^GREEN%^plants%^BLACK%^, the hole is ripe with the smell of rotting vegeta"
	"tion.  Flies and mosquitos buzz about, making for a constant drone of sound.  %^GREEN%^Vines %^BLACK%^and %^RESET%^%^ORANGE%^roots %^BOLD%^%^BLACK%^stretch down from above, a few even appear strong en"
	"ough for climbing, and judging by the fresh %^RED%^scratch marks %^BLACK%^on the earthen wall, someone has climbed up a set recently. %^RESET%^"
	);

    set_smell("default","
The air is thick with the smell of rotting vegetation.");
    set_listen("default","You hear the drone of insects all around you.");

    
set_items(([ 
	({ "marks", "scratch marks" }) : "%^RED%^Claw marks can be seen going up and down the earthen walls beside various vines and roots, making you think that a few of these natural ropes are strong enough to support someone's weight.%^RESET%^",
	({ "plants", "vines", "roots" }) : "%^GREEN%^Most of the plant life is sickly and wouldn't be useful for much.  But there are a few roots and vines that look strong enough to pull yourself up by.%^RESET%^",
	({ "flies", "mosquitos" }) : "%^BOLD%^%^BLACK%^They buzz about over the water or hover around your face, attracted to the smell of your breath!%^RESET%^",
	"water" : "%^BLUE%^The water is pretty foul and thick with the rotten vegetation that's fallen into this hole.%^RESET%^",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/lurue/dekumage_g1",
		"north" : "/d/av_rooms/lurue/dekumage_t3",
	]));

}