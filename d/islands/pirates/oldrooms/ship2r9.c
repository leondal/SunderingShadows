#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create(){
   set_monsters(({MON"secondmate"}),({1}));
   ::create();
   set_repop(50);
   set_property("indoors",1);
   set_property("light",3);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);

set_short("Second Mate's Quarters");

set_long("%^BOLD%^Second Mate's Quarters%^RESET%^\n"+
         "You have moved east of the hallway. "+
          "These quarters are cramped with barely enough "+
          "space to move. There is a hammock and a chest, "+
          "and a few piles of clothes here and there. "+
         "A single porthole allows light in from "+
         "the outside.\n"
        );

set_smell("default","You smell stale and thick air.");
set_listen("default","You can hear the sound of water lapping against the hull.");
set_items(([
   "chest":"You find nothing of interest.",
   "clothes":"Nothing worthwhile here either.",
   "hammock":"Looks very uncomfortable.",
   "porthole":"The ocean spreads out before you.",
         ]));

  set_exits(([ "west":CAVES"ship2r7",   ]));
}

void reset() {
  ::reset();
}