#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_short(   "Road to the docks"   );

   set_long(
            "%^BOLD%^Road to the docks%^RESET%^\n"+
            "You have gone south of the town square. "+
            "This road has a few people wandering about "+
             "You can see the docks down this road, and the "+
             "two pirate ships."
"\n"
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You can hear waves crashing on shore.");

   set_items(([
     "ocean":"The ocean spreads out before you to the horizon.",
    "village":"You can now have a clear view of the village buildings. "+ 
     "They seem to have been built out of pieces of old ships.",
    "streets":"The streets are more like paths but they get the job "+
     "done.",
     "ships": "They fly the flag of the jolly rodger."
    ]));
   set_exits(([
   "south":CAVES"cove12",
   "north":CAVES"cove10"
]));
}

