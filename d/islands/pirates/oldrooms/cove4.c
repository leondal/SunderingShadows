//cove4.c

#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);

   set_short(
@JAVAMAKER
Southern Bridge Entrance
JAVAMAKER
   );

   set_long(
@JAVAMAKER
A stone bridge lies to the north that covers the gap between 
the two halves of the cliff.  The village is only a hop and a skip
away and now you can make out the flags on the ships...
...the skull and crossbones!  Here are the pirates that have
been raiding the trade routes between Shadow and Graez.
JAVAMAKER
   );

   set_smell("default","You smell fresh ocean air.");
   set_listen("default","You can hear waves crashing on shore.");
   set_items(([
      "bridge":"This is an old stone bridge, looks sturdy enough.",
       "ocean":"The ocean spreads out before you to the horizon.",
       "village":"You now have a clear view of the village buildings.  They seem to have been built out of pieces of old ships.",
       "trail":"This is a well worn trail down the cliff face quite easy to navigate.",
      "ships":"These two galleons are pirate ships....what treasures await you there?",
   ]));

   set_exits(([
      "bridge":CAVES"cove3",
      "trail":CAVES"cove5",
   ]));
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}







