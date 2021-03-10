// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("parmt_r5");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("game track");
    set_climate("mountain");

    set_short("%^BOLD%^%^CYAN%^Far Side of the River%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^A somewhat wide swath of %^RESET%^gravel %^ORANGE%^and %^YELLOW%^sand %^RESET%^%^ORANGE%^makes for a curving bank on this side of the river.  Across the shallow currents you can see"
	" the %^BOLD%^%^BLACK%^large gray stone%^RESET%^%^ORANGE%^ that has forced the river to make such a wide curve, as well as a narrow shoreline that leads south and back down toward the %^GREEN%^Parnelli"
	" Valley%^ORANGE%^.  Ahead, you can see where the stone must have come from, as there is a %^CYAN%^waterfall %^ORANGE%^gushing down a sharp faced cliff.%^RESET%^"
	);

    set_smell("default","
The mountain air is fresh and clean, and scented with the smell of damp earth.");
    set_listen("default","The sound of the river burbling over rocks and boulders fills the air.");

    
set_items(([ 
	({ "boulder", "stone", "gray stone" }) : "%^BOLD%^%^BLACK%^The large stone appears to be a chunk of the nearby mountains, likely shorn from a cliff side during a seismic event or through the natural erosion of the river.  Either way, it now blocks the river's normal course and forces the stream to widen outward into a flat spot where only the center is swiftly flowing.%^RESET%^",
	({ "sand", "gravel", "bank", "shore", "river bank" }) : "%^RESET%^%^ORANGE%^The river bank widens here into a strip of rocky sand that is a little easier to navigate then the shore on the far side.  Vanishing to the south, it continues along the river edge to the north where the %^CYAN%^waterfall %^ORANGE%^waits.%^RESET%^",
	({ "mountains", "mountain" }) : "%^BOLD%^%^BLACK%^Further to the north you can see a tall, %^WHITE%^snow capped %^BLACK%^mountain range which is likely the source of water for this river.  Dark granite stone crags jut upward, offering a stunning display against the deep blues and cloud grays of the sky.%^RESET%^",
	({ "cliff", "cliff face", "waterfall" }) : "%^BOLD%^%^BLUE%^Ahead, spilling down the face of a sheered off cliff is a large waterfall and the deep pool which collects the water before it forms a river and travels southward toward the forest. Though sheer, the cliff face has been battered by the years of water and holes, cracks and other damage has made it possible to climb.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/parmt_r6",
		"west" : "/d/av_rooms/lurue/parmt_r4",
	]));

}