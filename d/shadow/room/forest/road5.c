#include "forest.h"
inherit "/d/shadow/room/forest/road1";

void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("%^RESET%^%^GREEN%^On the Quiet %^BOLD%^%^GREEN%^Fo%^RESET%^%^GREEN%^r%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t %^ORANGE%^R%^BOLD%^%^ORANGE%^o%^ORANGE%^a%^ORANGE%^d%^RESET%^\n");
    set_long(::query_long()+"%^BOLD%^%^CYAN%^A magnificent temple stands here on the side of the road.%^RESET%^\n");
    set_items(([
	"road":"This dirt road cuts through a quiet forest.",
	"forest":"This is an aptly named road through a quiet forest. You hear only the occasional bird song."
      ]));

    set_exits(([
        "southeast" : FORESTDIR+"road4",
        "west" : FORESTDIR+"road6",
"temple": "/d/magic/temples/kismet/kismet"
        ]));
    set_smell("default","%^CYAN%^The fresh scent of the forest surrounds you.%^WHITE%^");
    set_listen("default","%^ORANGE%^You can hear birds singing.%^RESET%^");
    set_listen("birds","They seem to sing songs of love - or murder - depending on your mood.");
   add_item(({"temple","Tall marble structure towers over the surroundings"}));
    set_climate(CLIMATE);
}