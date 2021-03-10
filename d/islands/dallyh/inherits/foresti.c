#include <std.h>
#include "area_info.h"
#include "../fways.h"
inherit CROOM;

void place_my_mobs()
{
    if(base_name(TO) != DFOREST && !random(2)) 
    {
        switch(random(10))
        {
            case 0..2:
                set_monsters(({FMPATH "pixie", FMPATH "nymph"}), ({2 + random(3), random(2) + random(3)})); 
                break;
            case 3..5:
                set_monsters(({FMPATH "battle_briar", FMPATH "bearhound"}), ({2 + random(3), 3 + random(2)}));
                break;
            case 6..7:
                set_monsters(({FMPATH "night_twist"}), ({1 + random(2)}));
                break;
            case 8..9:
                set_monsters(({FMPATH "hunter"}), ({3 + random(3)}));
                break;
        }        
        set_repop(55);
    }
}



void create()
{
// object ob;

    place_my_mobs();
    ::create();
    set_name("within the vast forest");
    set_short("%^RESET%^%^GREEN%^Within the vast forest%^RESET%^");
    set_property("indoors", 0);
    set_property("light", 1);
    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);

    set_long("%^RESET%^%^GREEN%^You find yourself within a vast and %^BOLD%^%^WHITE%^"+
    "beautiful%^RESET%^%^GREEN%^ forest. Some of the %^RESET%^%^ORANGE%^trees%^RESET%^"+
    "%^GREEN%^ around you travel skyward for hundreds of feet and are as thick as "+
    "a wagon while others are much thinner and reach only a few dozen feet into the air. "+
    "They blend together harmoniously, as if each is supporting the other and each "+
    "type lends it %^RESET%^%^ORANGE%^branches%^RESET%^%^GREEN%^ to the impressive "+
    "%^BOLD%^%^MAGENTA%^canopy%^RESET%^%^GREEN%^ formation which heavily blankets this "+
    "ancient forest. There are thick, thorny %^BOLD%^%^BLACK%^bushes%^RESET%^%^GREEN%^ "+
    "growing up near and around many of trees, which serve to make traveling slightly "+
    "arduous. Except for the bushes the floor of the forest is mostly free of "+
    "%^BOLD%^undergrowth%^RESET%^%^GREEN%^, as if someone or something has went through "+
    "much painstaking effort to keep it beautiful.%^RESET%^");


    set_items(([

    ({"forest", "vast forest", "beautiful forest"}) : "%^RESET%^%^GREEN%^This ancient forest "+
    "is quite beautiful. Some of the trees here are several hundred feet high and as thick as "+
    "a wagon while others are much thinner and only reach a few dozen feet into the air.%^RESET%^",

    ({"branches", "canopy", "trees", "tree",
    "impressive canopy"}) : "%^RESET%^%^ORANGE%^The trees intertwine together "+
    "and their branches form an impressive, majestic canopy which heavily blankets the entire "+
    "forest.%^RESET%^",

    ({"bushes", "bush", "thorny bushes", "thorny bush"}) : "%^BOLD%^%^BLACK%^These thorny bushes "+
    "grow up near and around many of the trees. They make travel here slightly arduous.%^RESET%^",

    ({"floor", "undergrowth", "forest floor"}) : "%^RESET%^%^GREEN%^The forest is remarkably "+
    "free of undergrowth, save for the thorny bushes. It is as if someone or something has "+
    "went through much painstaking effort to keep it beautiful.%^RESET%^",

    ]));

    set_smell("default","\nThe lush fragrances of the forest quell your worries.");
    set_listen("default","The sounds of forest life echo all around you.");
}

void reset()
{
    ::reset();
    //place_mobs();
}


