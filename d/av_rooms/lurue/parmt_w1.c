// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("parmt_w1");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("ledge");
    set_climate("mountain");

    set_short("%^BOLD%^%^BLUE%^Top of a Waterfall%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^Several mountain streams, fed by %^WHITE%^snow melt%^CYAN%^ and %^BLUE%^rain%^CYAN%^, converge into a wide lake at the top of this cliff before spilling over the side and down a sheer "
	"cliff face.  %^RESET%^Rocks %^BOLD%^%^CYAN%^and %^BLACK%^boulders %^CYAN%^cluster about, creating a funnel that guides the water to the shelf.  Time and erosion have dug away at the solid granite ston"
	"e and the channel is both wide and deep.  Beyond the mirror bright lake, the Paranelli Mountains rise up quickly toward the sky, their jagged, rough shapes dotted with %^RESET%^%^GREEN%^scraggly brush"
	"%^BOLD%^%^CYAN%^, %^RESET%^%^ORANGE%^wiry trees %^BOLD%^%^CYAN%^and the occasional %^RESET%^%^CYAN%^small valley%^BOLD%^.  High above a %^BLACK%^plateau %^CYAN%^can be seen, though how big it is, is i"
	"mpossible to tell.  An old, dry stream bed snakes its way upward toward the east, providing a path of sorts that might lead closer to that plateau.%^RESET%^"
	);

    set_smell("default","
The air is heavy with the scent of water.");
    set_listen("default","The roar of the waterfall is deafening.");

    
set_items(([ 
	({ "valley", "city", "asgard" }) : "%^RESET%^%^GREEN%^From this height you can see the large sweep of the Parnelli Valley that sweeps across the south end of the mountain range.  Located in the center of that valley is the grand city of %^WHITE%^Asgard %^GREEN%^with its spires and turrets.  A beautiful valley, full of lush green trees and rich grassy fields, it is bordered by a second set of mountains further south that cut off the Gods plains.%^RESET%^",
	({ "mountains", "mountain", "mountain range", "range" }) : "%^BOLD%^%^BLACK%^The Parnelli Mountains extend east and west, curving to the south toward the eastern edge of the valley far below.  Dark granite makes up the majority of the stone that juts from the earth and forms these peaks, but you can see %^RESET%^%^ORANGE%^deep browns%^BOLD%^%^BLACK%^, %^RESET%^%^RED%^rusty reds %^BOLD%^%^BLACK%^and the occasional %^YELLOW%^glimmer %^BLACK%^throughout.%^RESET%^",
	({ "rocks", "boulders", "rock", "boulder" }) : "%^BOLD%^%^BLACK%^Rocks and boulders that have been jarred loose from the surrounding mountains and carried down stream gather here.  Most are the same dark stone as the mountains appear to be, though many have specks of color that suggest there might be mineral deposits throughout the range.%^RESET%^",
	({ "snow", "snow melt", "rain" }) : "%^BOLD%^%^WHITE%^Most of the peaks of the surrounding mountain range are dotted with snow caps that grow and shrink with the season.  The main source of water for the mountain streams, it is further enhanced by the occasional rainstorm.%^RESET%^",
	({ "lake", "pool", "water", "stream", "river" }) : "%^BOLD%^%^BLUE%^A large lake forms at the top of the cliff and is ringed by %^BLACK%^boulders %^BLUE%^and %^WHITE%^stones %^BOLD%^%^BLUE%^that have been broken away from the surrounding mountains.  Deep and mirror bright, the water is both cold and clear, reflecting the sky and the mountain range surrounding it.%^RESET%^",
	({ "river beds", "riverbeds", "stream bed", "bed" }) : "%^RESET%^%^ORANGE%^Not completely dry, only a tiny trickle makes its way down what appears to have been a much larger stream at some point.  The bed makes for a reasonably safe pathway if someone wished to continue upward into the mountains.%^RESET%^",
	({ "brush", "bushes", "trees", "grass", "landscape" }) : "%^GREEN%^Here in the lower part of the mountains, brush and trees can still be found, mostly pines and aspens, there are a few oaks, ash and birch to be found.  Further up the mountains, the trees give way to brush and the brush gives way to bare stone.%^RESET%^",
	({ "crags", "crag", "gouge", "gouges", "hole", "holes" }) : "%^BOLD%^%^BLACK%^You can see that the rockface has many gouges, holes and crags.  These might provide enough support along the edge of the waterfall for you to climb %^WHITE%^down%^BLACK%^, if you were skilled.%^RESET%^",
	({ "cliff", "rockface", "rock face", "face" }) : "%^BOLD%^%^BLACK%^Looking upon the sheer rockface, you can see that the rock is nearly shorn flat, only a slight angle can be seen and even that appears to be wearing away under the constant attack of the water.  Crags, holes and gouges can be seen upon the surface, they might make good hand holds if someone was skilled at climbing.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/parmt_m1",
		"down" : "/d/av_rooms/lurue/parmt_r8",
	]));



    set_invis_exits(({ "down" }));

}