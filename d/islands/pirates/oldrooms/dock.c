//dock.c

#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(SHORE);
   set_travel(DIRT_ROAD);

   set_short("Pirate's Cove Docks");

   set_long(
@JAVAMAKER
%^BOLD%^Southern Docks%^RESET%^
You have found an open dock here that isn't being used.
The water swells along the docks and you can see the ocean
spread out to the horizon.  To the north are the docks used
by the pirate ships.  

JAVAMAKER
   );

    set_smell("default","The fresh ocean air.");
   set_listen("default","Water rushing under the docks.");
   set_items(([
      "ocean":"It looks rough, and is vast.",
      "docks":"These are old and rough hewn and worn but they seem sturdy enough.",
   ]));

   set_exits(([
      "north":CAVES"cove14",
   ]));
}


void reset(){
   ::reset();
}

void init(){
   ::init();
}
