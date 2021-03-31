// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("rockytemple");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("foot path");
    set_climate("temperate");

    set_short("An abandoned shrine");

    set_long("%^BOLD%^%^BLACK%^You are in what appears to be the %^RESET%^%^MAGENTA%^hollow %^BOLD%^%^BLACK%^of a %^RESET%^%^MAGENTA%^massive geode%^BOLD%^%^BLACK%^.  %^WHITE%^Crystals %^BLACK%^in many a %^ORANGE%^"
	"h%^CYAN%^u%^ORANGE%^e %^BLACK%^adorn the sides of the spherical wall like so many %^RESET%^stalactites%^BOLD%^%^BLACK%^. The %^RESET%^smooth floo%^BOLD%^%^BLACK%^r, composed of %^RESET%^worked obsidia"
	"n %^BOLD%^%^BLACK%^tiles, was grouted with %^RESET%^%^ORANGE%^molten bronze%^BOLD%^%^BLACK%^, lending its surface a v%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ne%^BOLD%^%^BLACK%^d, livi"
	"ng appearance. This temple has been abandoned for years. However, in recent months, it appears someone has moved back in. There are %^RESET%^%^ORANGE%^blankets %^BOLD%^%^BLACK%^on the floors, a few %^"
	"RESET%^%^ORANGE%^crates %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^logs %^BOLD%^%^BLACK%^set up to form a camp-site of sorts. Some food has been left out, as though whoever lives here left in a hurry. Th"
	"ere are a few %^RESET%^%^MAGENTA%^toys %^BOLD%^%^BLACK%^scattered about the cave. %^RESET%^"
	);

    set_smell("default","
It smells of stale decay and food.");
    set_listen("default","You can hear yourself breathing, and a faint metallic melody.");

    set_search("crates","You find fresh produce in one crate and the remnants of a skeleton in the other.");
    set_search("toys","There are many toys here. A wooden horse, a leather ball, a broken rag doll, among other things.");
    set_search("search","stalactite");
    set_search("stalactite","You search the shadowy alcoves among the stalactites and find a passage leading down into the darkness.");
    
set_items(([ 
	"crates" : "There are some crates spread around, used as tables and chairs, and for storage.",
	"skeleton" : "You find broken pieces of a skeleton in one of the crates.",
	"stalactite" : "There are shadowy alcoves hidden by stalactites and stalagmites.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/karma/rockymountaintrail",
		"down" : "/d/av_rooms/karma/rockybasement",
	]));



    set_invis_exits(({ "down" }));

}