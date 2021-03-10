#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){
::create();

set_property("indoors",1);
set_property("light",3);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);

set_short("First Mate's Quarters");

set_long("%^BOLD%^First Mate's Quarters%^RESET%^\n"+
         "You have moved west of the hallway. "+
         "These quarters are cramped with barely enough "+
         "space to move. There is a hammock and a chest, "+
         "and a few piles of clothes here and there."
"\n"
        );

set_smell("default","You smell stale and thick air.");
 set_listen("default","You can hear the sound of water lapping against the hull.");
set_items(([
         "chest":"You find nothing of interest.",
         "clothes":"Nothing worthwhile here either.",
         "hammock":"Looks very uncomfortable.",
         ]));

set_exits(([
           "east":CAVES"ship2r7",
          ]));

}
