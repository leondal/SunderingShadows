// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("klauth_p2");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("shore");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^YELLOW%^Shore of Aramanth Island%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This rutted, rock strewn path follows along the shore of the island, leaving the easy, soft sands of the beach behind and working its way up and through thick %^GREEN%^brush%^ORANGE"
	"%^, %^WHITE%^boulders %^ORANGE%^and other %^CYAN%^difficulties%^ORANGE%^.  Piles of %^GREEN%^seaweed%^ORANGE%^, dry and rotting in the air, make the pathway slippery, causing you to use care as you tr"
	"averse it.  Ahead, far to the northeast you can see a towering %^BOLD%^%^BLACK%^mountain %^RESET%^%^ORANGE%^spiraling upward toward a large crater high above.  You can even make out %^WHITE%^stairs %^"
	"ORANGE%^leading upward on one side, but it would take some effort to reach that point from where you're at.%^RESET%^"
	);

    set_smell("default","
The air is ripe with the briny scent of rotten seaweed.");
    set_listen("default","You hear the sound of the ocean.");

    
set_items(([ 
	({ "pathway", "path" }) : "%^ORANGE%^The path that you're following is less a path and more a jumble of rocks and cast off from the sea.  Large boulders, small rocks, piles of sand, bits of driftwood, and the occasional bush has gathered up here to create a weaving, difficult pathway for you to navigate.%^RESET%^",
	({ "boulders", "boulder", "rocks", "rock" }) : "%^BOLD%^%^BLACK%^Boulders and rocks cover this part of the shore, forcing you to climb and scramble over their surfaces as needed to progress.  Little holes here and there are filled with sea water and you see the occasional small crab scuttle away in fear as you pass nearby.%^RESET%^",
	({ "brush", "bushes" }) : "%^GREEN%^The occasional plant has grown up amongst the boulders and rocks, finding purchase in the sand and dirt drifts that have gathered in those crags.  For the most part, these plants are little more then scraggly trigs with a few sharp, thorny leaves, ready to cut and slice at tender skin.%^RESET%^",
	"seaweed" : "%^RESET%^%^ORANGE%^Brown%^CYAN%^, %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^,%^RESET%^ white%^CYAN%^,%^RED%^ red%^CYAN%^, %^GREEN%^green%^CYAN%^, every color you can imagine can be found caught in the rocks and boulders.  Washed up onto the shore by high, stormy tides, the seaweed rots and fill the air with a briny smell.%^RESET%^",
	({ "mountain", "stairs", "crater" }) : "%^BOLD%^%^BLACK%^To the north you can see mountains, at least one of which you traversed over to reach this place.  On the far one you can see that it has a large crater toward the top, likely the home of %^RED%^Klauth%^BLACK%^, the creature you are hunting.  Those stairs look inviting, almost encouraging considering the hardships of climbing over all these rocks.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/klauth_p1",
		"east" : "/d/av_rooms/lurue/klauth_p3",
	]));

}