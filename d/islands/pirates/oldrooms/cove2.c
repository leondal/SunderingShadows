//cove2.c

#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);

   set_short("Northern Bridge Entrance");

   set_long(
@JAVAMAKER
You have arrived at the old stone bridge.  You are much further
down the cliff now.  But the village is hard to out make due to the
tree growth that has filled this area in.  Back up the trail is the
cave mouth and ahead is the bridge over the inlet.
JAVAMAKER
   );

   set_smell("default","You smell fresh ocean air.");
   set_listen("default","You can hear waves crashing on shore.");
   set_items(([
      "bridge":"This is an old stone bridge, looks sturdy enough.",
       "ocean":"The ocean spreads out before you to the horizon.",
       "village":"You now have a clear view of the village buildings.  They seem to have been built out of pieces of old ships.",
       "trail":"This is a well worn trail down the cliff face quite easy to navigate.",
   ]));

   set_exits(([
      "bridge":CAVES"cove3",
      "trail":CAVES"cove1",
   ]));
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}







