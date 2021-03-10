#include "/d/islands/dallyh/fways.h"
inherit "/std/church";

void create(){
    ::create();
    set_short("%^RESET%^%^ORANGE%^A native temple%^RESET%^");
    set_name("a native temple");    
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_long("%^RESET%^%^GREEN%^From here you can tell that this large shelter "+
    "has not been built up into the trees, but rather it is part of them. "+
    "It looks %^BOLD%^%^BLACK%^ancient%^RESET%^%^GREEN%^ and %^BOLD%^%^WHITE%^sturdy"+
    "%^RESET%^%^GREEN%^. You are not sure if it was created or simply developed, it is "+
    "impossible to tell. This particular one is set up quite obviously as a makeshift temple. "+
    "In what is probably the exact center of it rests an altar made of %^BOLD%^gnarled "+
    "oak%^RESET%^%^GREEN%^. The altar extends upward and out in all directions before "+
    "curving back toward the natural wooden floor. The top of it is completely smooth, as if "+
    "patiently awaiting some sacrifice. %^RESET%^");
    set_exits( ([
        "east" : FRPATH "road2",
    ]) );
    set_property("light", 2);
    set_property("indoors", 1);
    set_items( ([
    
        ({"shelter", "shelters", "temple", "trees"}) : "%^RESET%^%^GREEN%^This large "+
        "shelter has not been built up into the trees. It is actually a part of the trees. "+
        "It is almost as if it inside of them and the trees actually seem to be continually "+
        "growing around it, providing it with an enormous amount of protection. It seems very "+
        "sturdy and quite ancient.%^RESET%^",
        
        ({"altar", "gnarled oak altar", "gnarled altar", "oak altar"}) :"%^BOLD%^%^GREEN%^"+
        "This gnarled oak altar rests in the exact center of this shelter. It extends upward "+
        "and out in all directions before curving back toward the natural wood floor. It does not "+
        "appear to be a part of the trees of which the rest of the shelter is made of, but something "+
        "that has been added later. The top of it is completely smooth, as if patiently awaiting some "+
        "unknown sacrifice.%^RESET%^",
        
        ({"floor", "wooden floor", "natural wood floor"}) : "%^BOLD%^%^GREEN%^The floor here seems to be "+
        "composed of root material, it is bumpy and rough, but seems to almost give off a noticeable sheen."+
        "You believe it is very sturdy.%^RESET%^",
        
      ]) );
    set_smell("default","\nThe lush fragrances of the forest quell your worries.");
    set_listen("default","The sounds of forest life echo all around you.");
}
