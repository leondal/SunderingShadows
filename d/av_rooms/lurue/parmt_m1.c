// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("parmt_m1");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("old mounts");
    set_travel("game track");
    set_climate("mountain");

    set_short("%^BOLD%^%^WHITE%^a dry streambed in the mountains%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Climbing into the %^BOLD%^%^BLACK%^mountains%^RESET%^%^ORANGE%^, this streambed snakes its ways between the cracks and crags, climbing higher and higher toward the %^WHITE%^%^BOLD%^"
	"snow capped peaks%^RESET%^%^ORANGE%^.  Not completely dry, only a tiny %^BLUE%^trickle %^ORANGE%^makes its way down what appears to have been a much larger stream at some point.  Small %^GREEN%^shrubs"
	" %^ORANGE%^and the occasional tree dots the landscape but appears to be quickly giving way to barren rock and cold air.%^RESET%^"
	);

    set_smell("default","
The air is crisp and very cold.");
    set_listen("default","You can hear the shift of dirt and the occasional bird call.");

    
set_items(([ 
	({ "snow", "snow melt", "rain" }) : "%^BOLD%^%^WHITE%^Most of the peaks of the surrounding mountain range are dotted with snow caps that grow and shrink with the season.  The main source of water for the mountain streams, it is further enhanced by the occasional rainstorm.%^RESET%^",
	({ "mountains", "mountain", "mountain range", "range" }) : "%^BOLD%^%^BLACK%^The Parnelli Mountains extend east and west, curving to the south toward the eastern edge of the valley far below.  Dark granite makes up the majority of the stone that juts from the earth and forms these peaks, but you can see %^RESET%^%^ORANGE%^deep browns%^BOLD%^%^BLACK%^, %^RESET%^%^RED%^rusty reds %^BOLD%^%^BLACK%^and the occasional %^YELLOW%^glimmer %^BLACK%^throughout.%^RESET%^",
	({ "river beds", "riverbeds", "stream bed", "bed" }) : "%^RESET%^%^ORANGE%^Not completely dry, only a tiny trickle makes its way down what appears to have been a much larger stream at some point.  The bed makes for a reasonably safe pathway if someone wished to continue upward into the mountains.%^RESET%^",
	({ "shrubs", "brush", "bushes", "trees", "grass", "landscape" }) : "%^GREEN%^Here in the lower part of the mountains, brush and trees can still be found, mostly pines and aspens, there are a few oaks, ash and birch to be found.  Further up the mountains, the trees give way to brush and the brush gives way to bare stone.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/lurue/parmt_m2",
		"southwest" : "/d/av_rooms/lurue/parmt_w1",
	]));

}