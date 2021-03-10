// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("parmt_r7");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("ledge");
    set_climate("mountain");

    set_short("%^BOLD%^%^WHITE%^Atop a large boulder%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This large piece of the mountains fell down some time ago and became wedged in the %^RESET%^%^ORANGE%^muddy base %^BOLD%^%^BLACK%^of the river.  With time, the river diverted its cour"
	"se around the boulder and continued on its way, leaving the smooth topped stone as a nice low outcropping to %^YELLOW%^sun %^BLACK%^oneself on after a swim.  From here you can see that a %^RESET%^%^CY"
	"AN%^waterfall %^BOLD%^%^BLACK%^rushes down a sheer cliff just a ways off to the north.%^RESET%^"
	);

    set_smell("default","
The mountain air is fresh and clean, and scented with the smell of damp earth.");
    set_listen("default","The sound of the river burbling over rocks and boulders fills the air.");

    set_search("rock","%^BOLD%^%^BLACK%^You search around the large rock and find a little %^RESET%^%^GREEN%^moss%^BOLD%^%^BLACK%^ and a bit of %^RESET%^%^ORANGE%^dirt%^BOLD%^%^BLACK%^.%^RESET%^");
    
set_items(([ 
	({ "cliff", "cliff face", "waterfall" }) : "%^BOLD%^%^BLUE%^Ahead, spilling down the face of a sheered off cliff is a large waterfall and the deep pool which collects the water before it forms a river and travels southward toward the forest. Though sheer, the cliff face has been battered by the years of water and holes, cracks and other damage has made it possible to climb.%^RESET%^",
	({ "sand", "gravel", "bank", "shore", "river bank" }) : "%^RESET%^%^ORANGE%^The river bank widens here into a strip of rocky sand that is a little easier to navigate then the shore on the far side.  Vanishing to the south, it continues along the river edge to the north where the %^CYAN%^waterfall %^ORANGE%^waits.%^RESET%^",
	({ "mountains", "mountain" }) : "%^BOLD%^%^BLACK%^Further to the north you can see a tall, %^WHITE%^snow capped %^BLACK%^mountain range which is likely the source of water for this river.  Dark granite stone crags jut upward, offering a stunning display against the deep blues and cloud grays of the sky.%^RESET%^",
	({ "river", "water" }) : "%^RESET%^%^CYAN%^The river here is wide and gentle, though you can see in the center there is a faster current.  Below the surface, %^RESET%^rocks%^CYAN%^, %^BOLD%^%^BLACK%^boulders %^RESET%^%^CYAN%^and an occasional %^ORANGE%^tree limb can %^CYAN%^be seen, causing the water to froth and ripple as it travels down into the Parnelli Valley.%^RESET%^",
	({ "stone", "gray stone" }) : "%^BOLD%^%^BLACK%^The large stone appears to be a chunk of the nearby mountains, likely shorn from a cliff side during a seismic event or through the natural erosion of the river.  Either way, it now blocks the river's normal course and forces the stream to widen outward into a flat spot where only the center is swiftly flowing.%^RESET%^",
	]));

    set_exits(([ 
		"southwest" : "/d/av_rooms/lurue/parmt_r3",
	]));

}