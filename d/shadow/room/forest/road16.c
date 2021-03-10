// revised by Styx for the river ferry dock 7/2003

#include "forest.h"
inherit ROOM;

void create()
{
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("Bridge on The Quiet Forest Road");
    set_long(
"%^BOLD%^%^GREEN%^Bridge on the Quiet Forest Road%^RESET%^
%^GREEN%^The %^ORANGE%^road%^GREEN%^ leads through the Quiet Forest. The %^ORANGE%^forest%^GREEN%^ is not very dense and the path is visible for a good distance. A bridge crosses the %^BLUE%^Sarcosta River%^GREEN%^ here, allowing travelers to continue their journey along the road. "
        );

    set_items(([
                   "road":"A new road through the forest.",
                   "forest":"A quiet forest, for sure. Only the sounds of birds.",
                   ]));
 
    set_exits(([
                   "east" : FORESTDIR+"road15",
                   "west" : FORESTDIR+"road17",
                   ]));
    set_smell("default","You smell fresh air and the odor of %^GREEN%^w%^BOLD%^i%^MAGENTA%^l%^RESET%^%^MAGENTA%^d%^BOLD%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^we%^RESET%^%^MAGENTA%^r%^BOLD%^s%^ORANGE%^.");
    set_listen("default","You can hear birds singing.");

}

