//cove1.c

#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
   set_short( "Cliff Face" );

   set_long(
@JAVAMAKER
%^BOLD%^Cliff Face%^RESET%^
You have descended from the cave mouth onto a cliff face.
Down below you can see people milling about a small sea
side village. There are two ships in port. Further down the
trail to the beach you can see a bridge over a water inlet.
JAVAMAKER
   );

   set_smell("default","You smell fresh ocean air.");
   set_listen("default","You can hear waves crashing on shore.");
   set_items(([
       "trail":"This is a well worn trail down the cliff face quite easy to navigate.",
   "village":"Its buildings look tiny from here. You can see people wandering about.",
       "ocean":"The ocean spreads out before you to the horizon.",
      "down":"Looking down fills you with a sense of vertigo.  You would sure hate to fall.",
   ]));

   set_exits(([
      "trail":CAVES"cove2",
      "up":CAVES"cave16",
   ]));
}


void reset(){
   ::reset();

}

void init(){
   ::init();

}







