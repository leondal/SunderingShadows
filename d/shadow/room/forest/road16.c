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
	"road":"This dirt road cuts through a quiet forest.",
	"forest":"This is an aptly named road through a quiet forest. You hear only the occasional bird song."
                  ]));
 
    set_exits(([
                   "east" : FORESTDIR+"road15",
                   "west" : FORESTDIR+"road17",
                   ]));
    set_smell("default","%^CYAN%^The fresh scent of the forest surrounds you.%^WHITE%^");
    set_listen("default","%^ORANGE%^You can hear birds singing.%^RESET%^");
    set_listen("birds","They seem to sing songs of love - or murder - depending on your mood.");

}

