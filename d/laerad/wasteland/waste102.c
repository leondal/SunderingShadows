#include <std.h>
//Updated by ~Circe~ 8/13/15 to add the swamp
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_long(::query_long()+"\n%^BOLD%^%^BLACK%^To the east, an %^RESET%^eerie "
       "swamp%^BOLD%^%^BLACK%^ spreads across the land. Twisted, dead "
       "trees stretch up from the stale water, dotted here and there by "
       "diseased %^RESET%^%^GREEN%^lily pads%^BOLD%^%^BLACK%^.%^RESET%^\n");
    add_item("swamp","The swamp stretches as far as the eye can see, "
       "an endless waste of foul water broken by decaying trees and diseased lily pads.");
    set_exits( ([
	"west":"/d/laerad/wasteland/waste95",
        "east":"/d/laerad/swamp/swamp01",
	"north":"/d/laerad/wasteland/waste101",
	"south":"/d/laerad/wasteland/waste103"
    ]) );
//    new("/d/laerad/mon/fiend")->move(this_object());
// he also loads in waste78 so removing this one  *Styx*  8/21/03
}
// void clean_up(){return 1;}    and don't need this to stop cleanup now either
