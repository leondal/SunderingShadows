#include "/d/islands/dallyh/fways.h"

inherit CROOM;

void create()
{
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_short("%^RESET%^%^ORANGE%^A path through a small village%^RESET%^");
    set_name("A path through a small village");
    set_long("%^RESET%^%^ORANGE%^You find yourself within a vast and %^BOLD%^%^WHITE%^"+
    "beautiful%^RESET%^%^ORANGE%^ forest. Some of the %^RESET%^%^ORANGE%^trees%^RESET%^"+
    "%^ORANGE%^ around you travel skyward for hundreds of feet and are as thick as "+
    "a wagon while others are much thinner and reach only a few dozen feet into the air. "+
    "They blend together harmoniously, as if each is supporting the other and each "+
    "type lends it %^RESET%^%^GREEN%^branches%^RESET%^%^ORANGE%^ to the impressive "+
    "%^BOLD%^%^MAGENTA%^canopy%^RESET%^%^ORANGE%^ formation which heavily blankets this "+
    "ancient forest. You realize that there are shelters attached to and built up into a "+
    "large number of them. Each %^BOLD%^%^GREEN%^bl"+
    "%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^nds%^RESET%^%^ORANGE%^ in so well with the forest that "+
    "it is difficult to find any openings. You realize that this is a well hidden native village and "+
    "you suspect that the natives prefer it this "+
    "way. All of the bushes present in the rest of the forest have been cleared away here which "+
    "serves to make this portion of the forest even more breathtakingly beautiful.%^RESET%^");
    set_property("indoors",0);
    set_light(2);
    
    set_items(([

    ({"forest", "vast forest", "beautiful forest"}) : "%^RESET%^%^GREEN%^This ancient forest "+
    "is quite beautiful. Some of the trees here are several hundred feet high and as thick as "+
    "a wagon while others are much thinner and only reach a few dozen feet into the air. Shelters have "+
    "been attached to and built up in a large number of the bigger ones here.%^RESET%^",

    ({"branches", "canopy", "trees", "tree",
    "impressive canopy"}) : "%^RESET%^%^ORANGE%^The trees intertwine together "+
    "and their branches form an impressive, majestic canopy which heavily blankets the entire "+
    "forest.%^RESET%^",

    ({"floor", "undergrowth", "forest floor"}) : "%^RESET%^%^GREEN%^The forest is remarkably "+
    "free of undergrowth. It is as if someone or something has "+
    "went through much painstaking effort to keep it beautiful.%^RESET%^",
    
    ({"shelter", "shelters"}) : "%^RESET%^%^ORANGE%^These wooden shelters blend in so well with the "+
    "forest here that it is difficult to find any openings. They look quite elaborate from the outside but "+
    "you have no way of knowing what the insides might look like.%^RESET%^",
    ]));
   
    
    set_smell("default","\nThe lush fragrances of the forest quell your worries.");
    set_listen("default","The sounds of forest life echo all around you.");
}
