#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit ROOM;

void create() {
    ::create();
    set_short("%^BOLD%^%^BLACK%^A pathway out of the forest%^RESET%^");
    set_name("A pathway out of the forest");
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_long("%^BOLD%^%^BLACK%^This %^GREEN%^pathway%^BOLD%^%^BLACK%^ "+
    "leads slowly out of the depths of the forest.  The %^GREEN%^"+
    "trees%^BOLD%^%^BLACK%^ around you quickly begin thinning and "+
    "moving back from the path.  The %^GREEN%^saplings%^BOLD%^%^BLACK%^ "+
    "of the forest are more plentiful here, yet still show no "+
    "signs of life.  The %^WHITE%^dark fog%^BOLD%^%^BLACK%^ "+
    "rises heavily from the bulk of the forest far to "+
    "the southwest of here and falls over the path and everything "+
    "surrounding it.%^RESET%^");
    
   
    set_listen("default","Strange sounds echo from all around "+
    "you.");
    set_smell("default","You smell the decaying of the forest.");
    
    set_items(( [
     "forest" : "You find yourself in the forest.",
     ({"trees","large trees"}) : "%^GREEN%^The large trees of "+
     "this forest sprout upward and some reach several hundred "+
     "feet into the sky.  They have begin thinning heavily here "+
     "and only few remain.%^RESET%^",
     ({"saplings","sapling","dead saplings"}) : "%^GREEN%^"+
     "These saplings have gnarled and withered, like their "+
     "kin in the thick of the forest.  They grow closer "+
     "to the trail and grow thicker and more frequently "+
     "here.%^RESET%^",
     ({"fog","thick fog","heavy fog","dark fog"}) : 
     "%^BOLD%^%^WHITE%^This dark and thick fog rises up from the "+
     "thick of the forest to the southwest.  It shrouds the entire "+
     "path and everything around it.%^RESET%^",
     ({"path","pathway"}) : "%^GREEN%^The pathway you now "+
     "walk on is almost entirely free of any debris.%^RESET%^",
    ] ));
    set_search("default","%^GREEN%^Nothing here really catches "+
    "your attention.%^RESET%^");
}
    