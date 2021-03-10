// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("uzodo_c1");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^RESET%^A foul smelling cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This large, smelly cave is little more then a hole in the ground formed in part by the torn up earth of a %^RESET%^%^ORANGE%^fallen tree%^BOLD%^%^BLACK%^, and covered by several thick"
	" branches of decaying %^RESET%^%^GREEN%^tree limbs%^BOLD%^%^BLACK%^.  The floor of the cave is littered with a nest of %^GREEN%^nettle %^BLACK%^and other %^RESET%^%^ORANGE%^plant rubbish%^BOLD%^%^BLAC"
	"K%^, along with several broken and chewed upon %^WHITE%^bones%^BLACK%^.  Crude %^RED%^drawings %^BLACK%^are etched into the earthen wall, clearly indicating that there is more to the inhabitant then t"
	"he location might suggest.%^RESET%^"
	);

    set_smell("default","
You're not sure what all the rank smells are, but they're horrible.");
    set_listen("default","Twigs and bones break and snap under your feet with every foot step.");

    set_search("floor","%^BOLD%^%^WHITE%^Those bones you dug out look to be humanoid!%^RESET%^");
    
set_items(([ 
	({ "drawings", "wall" }) : "%^RED%^The drawings are crude and strange, looking very childish in form, but their bloody message is clear.  Whatever lives here hunts people and is clearly delighting in the aftermath of capture.  Things that are both vile and disgusting have been carved into the walls of this cave, things that would make even the darkest of souls cringe a little.%^RESET%^",
	({ "bones", "ground", "nettle", "floor" }) : "%^RESET%^%^ORANGE%^The ground is littered with nettles, plant remains, dirt and other things best left unidentified.  At least a few bones can be found amongst the rest if you searched about.%^RESET%^",
	({ "branches", "trees" }) : "%^BOLD%^%^GREEN%^A tree appears to have fallen some time ago, the roots tearing up a hole in the ground and creating a type of cave under its remains.  Branches have been cut and fashioned over what's uncovered to make a blind and prevent too much of the weather from coming in.%^RESET%^",
	]));

    set_exits(([ 
		"out" : "/d/av_rooms/lurue/uzodo_p2",
	]));

}