// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("parmt_r8");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("ledge");
    set_climate("mountain");

    set_short("%^BOLD%^%^BLUE%^Base of a Waterfall%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^You stand at the base of a %^BLUE%^majestic waterfall%^CYAN%^.  Towering several stories above you, the water rushes over a curved lip high above and falls nearly straight down along a"
	" sheer %^BLACK%^rockface%^CYAN%^.  Large boulders and smaller rocks jumble up at its base creating a large basin wherein the cold mountain waters flood and spill over down into a swiftly moving river "
	"to the south.  Though the cliff is sheer, time and erosion have dug %^BLACK%^holes%^CYAN%^, %^RESET%^gouges %^BOLD%^%^CYAN%^and %^RESET%^%^CYAN%^crags %^BOLD%^into the surface, making for a difficult,"
	" but possible, climb to the top.  An oasis of sorts, patches of %^RESET%^%^GREEN%^grass %^BOLD%^%^CYAN%^and small %^RESET%^%^ORANGE%^trees %^BOLD%^%^CYAN%^dot the surrounding landscape, hidden amongst"
	" the %^BLACK%^shadows %^CYAN%^of the granite mountains.%^RESET%^"
	);

    set_smell("default","
The air is heavy with the scent of water.");
    set_listen("default","The roar of the waterfall is deafening.");

    set_search("pool","%^BOLD%^%^BLUE%^You dive into the cold, cold waters of the pool and search, but come up with nothing more then chattering teeth and a great appreciation for whatever warmth your clothing can provide.%^RESET%^");
    set_search("basin","%^BOLD%^%^BLUE%^You dive into the cold, cold waters of the pool and search, but come up with nothing more then chattering teeth and a great appreciation for whatever warmth your clothing can provide.%^RESET%^");
    set_search("water","%^BOLD%^%^BLUE%^You dive into the cold, cold waters of the pool and search, but come up with nothing more then chattering teeth and a great appreciation for whatever warmth your clothing can provide.%^RESET%^");
    
set_items(([ 
	({ "oasis", "trees", "tree", "grass" }) : "%^GREEN%^Fed by the water and sheltered by the surrounding mountains, thick blankets of grass are studded with a few small trees here and there, making for a bit of an oasis near the waterfall.%^RESET%^",
	({ "crags", "crag", "gouge", "gouges", "hole", "holes" }) : "%^BOLD%^%^BLACK%^You can see that the rockface has many gouges, holes and crags.  These might provide enough support along the edge of the waterfall for you to climb %^WHITE%^up%^BLACK%^, if you were skilled.%^RESET%^",
	({ "cliff", "rockface", "rock face", "face" }) : "%^BOLD%^%^BLACK%^Looking upon the sheer rockface, you can see that the rock is nearly shorn flat, only a slight angle can be seen and even that appears to be wearing away under the constant attack of the watter.  Crags, holes and gouges can be seen upon the surface, they might make good hand holds if someone was skilled at climbing.%^RESET%^",
	({ "river", "basin", "pool", "water" }) : "%^BOLD%^%^WHITE%^Small and large boulders have gathered at the base of the falls and created a deep basin in the earth here by blocking the immediate flow of the river.  The result of which is a deep pool of cold mountain water that snakes its way over the boulders to spill down into a river that winds its way southward toward the distant valley.%^RESET%^",
	({ "waterfall", "water fall", "fall" }) : "%^BOLD%^%^BLUE%^The majestic waterfall is awe inspiring with the rush and flood of cold mountain water.  The heavy falls spill into a deep basin partly created by the rocks and boulders that have broken away due to the river's erosion.%^RESET%^",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/lurue/parmt_w1",
		"south" : "/d/av_rooms/lurue/parmt_r6",
	]));



    set_invis_exits(({ "up" }));

}