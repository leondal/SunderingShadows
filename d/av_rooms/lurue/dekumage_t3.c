// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_t3");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat tunnel");
    set_travel("rubble");
    set_climate("tropical");

    set_short("%^RESET%^%^ORANGE%^An Unfinished Tunnel%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This tight crawl space is barely big enough for a person to crawl through.  Clearly dug by claws, the walls, floor and ceiling are raw and unfished.  %^RESET%^%^ORANGE%^Dust%^BOLD%^%^"
	"BLACK%^ and the occasional %^RESET%^rock%^BOLD%^%^BLACK%^ sift from the ceiling making moving through this area difficult and stuffy.  The space ends abruptly at a wall of dark stone.  The stone slab "
	"is smooth and polished but for several small depressions within the %^RESET%^%^CYAN%^mirror %^BOLD%^%^BLACK%^like surface.%^RESET%^"
	);

    set_smell("default","
The air is heavy with the smell of dirt and something wet.");
    set_listen("default","You can hear the earth shifting all around you.");

    
set_items(([ 
	({ "rock", "rocks", "dirt", "earth" }) : "%^BOLD%^%^BLACK%^Thankfully all that keeps falling are tiny %^RESET%^pebbles%^BOLD%^%^BLACK%^ and a find mist of dust.%^RESET%^",
	({ "center depression", "center" }) : "%^BOLD%^%^WHITE%^The symbol in the center of the center depression has the meaning of: %^RESET%^smoke%^RESET%^",
	({ "east depression", "east" }) : "%^BOLD%^%^CYAN%^The symbol in the center of the eastern depression has the meaning of: %^RESET%^silk%^RESET%^",
	({ "west depression", "west" }) : "%^BOLD%^%^BLUE%^The symbol in the center of the western depression has the meaning of: %^RESET%^canvas%^RESET%^",
	({ "south depression", "south" }) : "%^BOLD%^%^RED%^The symbol in the center of the southern depression has the meaning of: %^RESET%^gem%^RESET%^",
	({ "north depression", "north" }) : "%^RESET%^%^ORANGE%^The symbol in the center of the northern depression has the meaning of: %^RESET%^lead%^RESET%^",
	({ "depressions", "depression" }) : "%^BOLD%^%^BLACK%^Each of the depressions is about the size of a gold coin.  The entire surface of each depression is covered in tiny markings that look like magical symbols.  As small as they are, it is almost impossible to make out what most of the markings are, but you notice the central marking is large enough to figure out.  There are five depressions, one in the %^RESET%^%^ORANGE%^north%^BOLD%^%^BLACK%^, one in the %^CYAN%^east%^BLACK%^, one in the %^RED%^south%^BLACK%^, one in the %^BLUE%^west%^BLACK%^ and finally one in the %^WHITE%^center%^BLACK%^.  What fits into them, or what must be done with each isn't clear.%^RESET%^",
	"pebbles" : "%^BOLD%^%^WHITE%^Tiny little pebbles litter the crawlspace, making your hands and knees hurt as you crawl along.%^RESET%^",
	"mirror" : "%^RESET%^%^CYAN%^There isn't a mirror here, but the smooth inky black surface of the rock slab that this tunnel ends in, is very polished and could work as one, if you had enough light to cause it to reflect.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/dekumage_t2",
		"south" : "/d/av_rooms/lurue/dekumage_t4",
	]));

}