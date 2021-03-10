#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_short(
   "Dock Entryway"
   );

   set_long(
            "%^BOLD%^Dock Entryway%^RESET%^\n"+
            "You've traveled down the road and have almost "+
            "reached the docks. "+
            "You have a much better view of the ships now. "+
             "They are quite big and well protected."
"\n"
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You can hear waves crashing on shore and "
"people.");

   set_items(([
   "ocean":"The ocean spreads out before you to the horizon.",
    "village":"You can now have a clear view of the village buildings. "+ 
   "They seem to have been built out of pieces of old ships.",
    "streets":"The streets are more like paths but they get the job "+
     "done.",
    "ships": "Each of them has four guards watching the boarding ramp."
    ]));
   set_exits(([
"south":"/d/shadow/virtual/sea/pirate.dock",
   "east":CAVES"ship1r1",
   "west":CAVES"ship2r1",
   "north":CAVES"cove13"
]));
}
