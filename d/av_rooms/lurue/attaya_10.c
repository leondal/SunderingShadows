// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("attaya_10");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^Center of the City of Seneca%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^A huge, circular fountain dominates the center of this plaza.  Surrounded by four dilapidated %^RESET%^%^GREEN%^gardens%^WHITE%^%^BOLD%^, the fountain at one time was a majestic centr"
	"al focal point.  Shooting its jets of %^CYAN%^water %^WHITE%^high into the sky in ever shortening concentric circles that danced and spilled into the wide %^BLUE%^pool%^WHITE%^.  Now the jets don't ap"
	"pear to work but a pool of %^RESET%^%^CYAN%^stagnate water %^BOLD%^%^WHITE%^remains within the pool.  The surrounding landscaping has likewise taken to seed, and the once bright and beautiful %^BOLD%^"
	"%^RED%^f%^CYAN%^l%^BLUE%^o%^YELLOW%^w%^GREEN%^e%^WHITE%^r%^MAGENTA%^b%^CYAN%^e%^RED%^d%^YELLOW%^s%^WHITE%^ are little more then over run patches of green.%^RESET%^"
	);

    set_smell("default","
The clean scent of the ocean rises on the breeze.");
    set_listen("default","You can faintly hear the crashing of waves on the shore.");

    
set_items(([ 
	({ "flowers", "flowerbeds", "beds", "flower beds" }) : "%^BOLD%^%^RED%^These once colorful beds of flowers appear to have been stunning.  They have since gone to seed and been reduced to little more then overgrown weeds and flowerless plants.%^RESET%^",
	({ "fountain", "pool", "water" }) : "%^BOLD%^%^CYAN%^This once impressive fountain would have commanded the center of the town square, spraying crystalline water high into the air in several concentric circles.  It has since been reduced to little more then a pool of stagnate water.%^RESET%^",
	({ "statues", "gardens" }) : "%^GREEN%^In each of the four ordinal directions, you see a small park that has its own benches and flowers.  The centerpiece of each park is a monument you could probably go take a closer look at.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/attaya_12",
		"northeast" : "/d/av_rooms/lurue/attaya_11",
		"north" : "/d/attaya/seneca/street3",
		"south" : "/d/attaya/seneca/street4",
		"west" : "/d/attaya/seneca/street7",
		"down" : "/d/av_rooms/lurue/maze_in",
		"east" : "/d/attaya/seneca/street5",
		"northwest" : "/d/av_rooms/lurue/attaya_14",
		"southwest" : "/d/av_rooms/lurue/attaya_13",
	]));

}