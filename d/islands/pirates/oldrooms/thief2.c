#include <std.h>
#include "../piratedefs.h"

inherit ROOM;
int opengrate;
void create(){ 
   ::create();
   set_property("indoors",1);
   set_property("light",0);
//   set_property("no teleport",1);
   set_terrain(BUILT_TUNNEL);
   set_travel(DIRT_ROAD);
   set_short("Thieves' den");

   set_long(
            "%^BOLD%^Underground%^RESET%^\n"+
            "You have entered a secret undergound "+
             "passage. The walls are damp to the touch. "+
             "You have two options: up through the grate "+
             "or south.\n"
   );

    set_smell("default","You smell stagnant water.");
    set_listen("default","You hear water dripping.");

   set_items(([
    ]));

   set_exits(([
   "south":CAVES"thief3",
   "up":CAVES"thief1"
]));

}

