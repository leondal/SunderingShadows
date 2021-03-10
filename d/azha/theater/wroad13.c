//wroad stuff
//Cythera - added in path to Desert Sun Theater 3/05
#include <std.h>

inherit ROOM;

void create(){
	::create();
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);
	
	set_properties((["light":2,"indoors":0]));
	set("short","Road between Tharis and the Tsarven Empire");
        set("long",
@OLI
	%^BOLD%^%^YELLOW%^The road connecting Tharis and the Tsarven Empire%^RESET%^
The road you are on is the long straight road between the city of Tharis 
and the border of the Tsarven empire. To the west is the border to the 
grand empire and to the east lies the wealth trading city of Tharis.
To the north lies the vast forest which is the source the lumber for Tharis.
To the south lies an impenetrable mountain range. You hear myths about
both areas frequently. The chaos and danger that lies to the south of the 
mountains and the grand elven civilization hidden in the forest. This road
is well traveled by the caravans and travelers. The mountain sides are 
riddled with mines, used and abandoned. An old overgrown trade route cuts"+
" into a forest of cypress trees.
OLI
	);
	set_exits(([
		"east":"/d/tharis/road/wroad12",
		"west":"/d/tharis/road/wroad14",
		"south":"/d/azha/theater/azp9",
		]));
	set_items(([]));
	
	set_smell("default","The dusty road combines with the fragrances of the forest.");
	set_listen("defualt","A bird calls, a tree toad chirps, the wind rustles the trees.");
}
