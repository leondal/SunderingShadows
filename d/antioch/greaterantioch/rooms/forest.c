#include <std.h>
#include "../gantioch.h"

inherit ROOM;

void create()
{
        ::create();
		set_name("forest");
        set_property("indoors",0);
        set_property("light",2);
		set_climate("temperate");

        set_short("%^BOLD%^%^GREEN%^King's Forest%^RESET%^");
        set_long(
		"%^RESET%^%^GREEN%^Surrounding you are the massive trees of %^BOLD%^%^GREEN%^King's Forest%^RESET%^%^GREEN%^"+ 
		" which rise high into the air. The undergrowth here is fairly sparse and you can see a fair"+
		" distance into the woods in all directions. The mixture of %^BOLD%^%^GREEN%^pine %^RESET%^%^GREEN%^"+
		" and %^BOLD%^%^GREEN%^spruce %^RESET%^%^GREEN%^make for an interesting contrast while also providing"+ 
		" ample wood for both beast and people alike. %^RESET%^%^ORANGE%^Animals %^RESET%^%^GREEN%^roam quite"+
		" plentifully here, as it seems the hunters are careful not to over hunt the game.%^RESET%^"
        );
        set_smell("default","\n%^BOLD%^%^GREEN%^The smell of pine permeates the air.%^RESET%^");
        set_listen("default","%^RESET%^%^CYAN%^You hear the sound of movement in the woods.%^RESET%^");
        set_items(([
        "trees" : "%^RESET%^%^GREEN%^The massive trees surround you. A mixture of pine and spruce,"+
		" the trees seem to interact well and are thriving quite well, and seem to have been doing so for centuries.%^RESET%^",
        "animals" : "%^RESET%^%^ORANGE%^Every so often a glimps of deer, squirrel, badgers, and other forest"+
		" creatures are visible.",
        "undergrowth" : "The undergrowth here does not seem to obstruct movement or vision, it's fairly minimal due"+
		" to the foliage types in this region."
		]));
        set_exits(([
        "north" : ROOMS"grassland",
]));
}




