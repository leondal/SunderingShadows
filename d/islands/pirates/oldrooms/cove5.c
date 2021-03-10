//cove5.c

#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_short(
@JAVAMAKER
Village Entrance
JAVAMAKER
   );

   set_long(
@JAVAMAKER
You stand at the edge of the village.  You see people milling about.
Most of them are the sort of scum you would expect to find in a
place like this.  Smugglers, thieves, and cutthroats.  This place
makes Tharis look appealing.
JAVAMAKER
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You can hear waves crashing on shore.");
   set_items(([
      "people":"You never seen this much assorted scum in your life.",
       "ocean":"The ocean spreads out before you to the horizon.",
       "village":"You now have a clear view of the village buildings.  They seem to have been built out of pieces of old ships.",
       "trail":"This is a well worn trail down the cliff face quite easy to navigate.",
      "buildings":"The buildings seem to have been built from salvaged wood.  Looks like anything goes around here.",
      "streets":"The streets are more like paths but they get the job done.",
   ]));

   set_exits(([
      "west":CAVES"cove6",
      "trail":CAVES"cove4",
   ]));
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}







