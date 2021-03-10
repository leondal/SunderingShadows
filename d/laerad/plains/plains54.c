//Coded by Bane//
//Updated by ~Circe~ 8/13/15 to add the swamp

#include <std.h>

inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_long(::query_long()+"\nTo the south, an %^RESET%^eerie "
       "swamp%^BOLD%^%^BLACK%^ spreads across the land. Twisted, dead "
       "trees stretch up from the stale water, dotted here and there by "
       "diseased %^RESET%^%^GREEN%^lily pads%^BOLD%^%^BLACK%^.%^RESET%^\n");
    add_item("swamp","The swamp stretches as far as the eye can see, "
       "an endless waste of foul water broken by decaying trees and diseased lily pads.");
    set_exits( ([
	"west":"/d/laerad/plains/plains41",
	"east":"/d/laerad/plains/plains65",
	"south":"/d/laerad/swamp/swamp05",
	"north":"/d/laerad/plains/plains53"
    ]) );
}
