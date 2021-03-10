// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("parmt_r6");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("game track");
    set_climate("mountain");

    set_short("%^BOLD%^%^CYAN%^Following the River%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The shore and river begin to rise more steeply here, lifting up out of the %^GREEN%^valley floor %^ORANGE%^and rising into the true granite of the mountains.  Ahead you can see a wi"
	"de pool of water where a %^BOLD%^%^CYAN%^majestic waterfall %^RESET%^%^ORANGE%^spills down into the basin.  It is from here that the river forms and makes its way to the valley below.  %^RESET%^Rocks "
	"%^ORANGE%^and small %^BOLD%^%^BLACK%^boulders %^RESET%^%^ORANGE%^line the shore line and make footing difficult here, and the river flows much more rapid then before, warning you to be careful in your"
	" travels.%^RESET%^"
	);

    set_smell("default","
The mountain air is fresh and clean, and scented with the smell of damp earth.");
    set_listen("default","The sound of the river burbling over rocks and boulders fills the air.");

    
set_items(([ 
	({ "bank", "shore", "river bank" }) : "%^RESET%^%^ORANGE%^The river bank is very narrow and appears to have at once been under the river.  Likely during spring melt the river overflows its usual boundaries and scars this part of the land, leaving a narrow trail to follow.  Small, well worn %^RESET%^rocks%^ORANGE%^, scraggly %^GREEN%^grass %^ORANGE%^and various %^BLACK%^%^BOLD%^twigs %^RESET%^%^ORANGE%^and roots line the narrow bank, making a difficult path to follow.%^RESET%^",
	({ "river", "water" }) : "%^RESET%^%^CYAN%^The river here swiftly flowing, obscuring what is below the surface.%^RESET%^",
	({ "cliff", "cliff face", "waterfall" }) : "%^BOLD%^%^BLUE%^Ahead, spilling down the face of a sheered off cliff is a large waterfall and the deep pool which collects the water before it forms a river and travels southward toward the forest. Though sheer, the cliff face has been battered by the years of water and holes, cracks and other damage has made it possible to climb.%^RESET%^",
	({ "mountains", "mountain" }) : "%^BOLD%^%^BLACK%^Further to the north you can see a tall, %^WHITE%^snow capped %^BLACK%^mountain range which is likely the source of water for this river.  Dark granite stone crags jut upward, offering a stunning display against the deep blues and cloud grays of the sky.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/lurue/parmt_r5",
		"north" : "/d/av_rooms/lurue/parmt_r8",
	]));

}