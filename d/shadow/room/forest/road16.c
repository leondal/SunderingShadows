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
set_long("%^BOLD%^%^GREEN%^Bridge on the Quiet Forest Road%^RESET%^\n"+
"%^RESET%^%^GREEN%^A wide %^ORANGE%^dirt trail %^GREEN%^has been "+
"cut through the forest here, and shows signs of wear from the many "+
"travelers who have ventured this way over the years. The trees are "+
"not very dense, allowing glimpses of the %^BOLD%^%^BLUE%^sky "+
"%^RESET%^%^GREEN%^overhead through the swaying treetops, and summoning "+
"dappled %^BOLD%^%^BLACK%^shadows %^RESET%^%^GREEN%^to dance across the path. "+
"The road is aptly named, as it is very quiet here beyond the pleasant songs "+
"from %^MAGENTA%^birds %^GREEN%^high overhead, and the sounds of your own passage. "+
"A bridge crosses the %^BLUE%^Sarcosta River%^GREEN%^ here, allowing travelers to continue their journey along the road.\n"
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

