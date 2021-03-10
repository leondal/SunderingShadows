#include <std.h>
#include "../tharis.h"
inherit CROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",1);
    set_name("Grimy sewers");
    set_short("%^BOLD%^%^BLACK%^Grimy sewers%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^The sewers underneath Tharis has suffered considerable "
"damage, and whole swathes of the system are unreachable. You hear work being done in distant "
"caverns, though who could be working in such conditions, you couldn't guess. Water rushes "
"through cracks, filled with refuse and filth.");
    set_smell("default","%^RESET%^%^ORANGE%^You smell refuse, and grime.%^RESET%^");
    set_listen("default","%^BLACK%^%^BOLD%^You hear distant sounds of work.%^RESET%^");
}

void init(){
   ::init();
   if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
//   do_random_encounters(({MOBS"gcube"}),10,1);
// sorry, these cubes gotta go til they can be rewrit
   do_random_encounters(({"/d/shadow/mon/rat"}),30,11);
}
