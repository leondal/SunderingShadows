#include <std.h>
#include "../tharis.h"
inherit CROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("Grimy sewers");
    set_short("%^BOLD%^%^BLACK%^Grimy Sewers%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^The sewers unerneath Tharis suffered the "+
	"worst damage, and whole swaths of the system are unreachable. You hear work "+
	"being done though in distant caverns though who could be working in such "+
      "conditions you dont know. Water rushes through cracks, filled with refuse "+
	"and filth.%^RESET%^\n");
    set_smell("default","%^RESET%^%^ORANGE%^You smell refuse, and grime.%^RESET%^");
    set_listen("default","%^BLACK%^%^BOLD%^you hear distant sounds of work.%^RESET%^");

        set_exits(([
          "northwest" : SEWERS"slide1",
        ]));
}

void init(){
        ::init();
//        do_random_encounters(({MOBS"gcube"}),10,1);
        do_random_encounters(({"/d/shadow/mon/rat"}),30,11);
}
