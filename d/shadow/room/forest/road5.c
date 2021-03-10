#include "forest.h"
inherit "/d/shadow/room/forest/road1";

void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("%^RESET%^%^GREEN%^On the Quiet %^BOLD%^%^GREEN%^Fo%^RESET%^%^GREEN%^r%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t %^ORANGE%^R%^BOLD%^%^ORANGE%^o%^ORANGE%^a%^ORANGE%^d%^RESET%^");
    set_long(::query_long()+"
%^BOLD%^%^CYAN%^A magnificent temple stands here on the side of the road.%^RESET%^");
    set_items(([
        "road":"A new road through the forest.",
        "forest":"A quiet forest, for sure. Only the sounds of birds."
        ]));

    set_exits(([
        "southeast" : FORESTDIR+"road4",
        "west" : FORESTDIR+"road6",
"temple": "/d/magic/temples/kismet/kismet"
        ]));
    set_smell("default","You smell fresh air and the odor of
%^GREEN%^w%^BOLD%^i%^MAGENTA%^l%^RESET%^%^MAGENTA%^d%^BOLD%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^we%^RESET%^%^MAGENTA%^r%^BOLD%^s%^ORANGE%^.");
    set_listen("default","You can hear birds singing.");
    add_item(({"temple","Tall marble structure towers over the surroundings"}));
    set_climate(CLIMATE);

}
