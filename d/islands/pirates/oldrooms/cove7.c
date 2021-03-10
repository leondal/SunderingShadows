//cove7.c

#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);

   set_short(
@JAVAMAKER
Main Street 
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^BOLD%^Main Street Around the Bend%^RESET%^
You have moved further into the village.  You continue to feel ill
at ease, this place doesn't seem safe.  Shadows dart between
buildings and the villagers are quite creepy looking.   To the west 
you see the village cross roads.  To the northeast you see the 
weapon and armor shops.  To the north you see a tavern and to
the south you see a seafood place.
JAVAMAKER
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You can hear waves crashing on shore.");
   set_items(([
     "ocean":"The ocean spreads out before you to the horizon.",
    "village":"You can now have a clear view of the village buildings. 
They seem to have been built out of pieces of old ships.",
    "streets":"The streets are more like paths but they get the job
done.",
    ]));

   set_exits(([
   "north":CAVES"tavern",
   "south":CAVES"seafood",
"west":CAVES"cove8",
"southeast":CAVES"healer",
"northeast":CAVES"cove6"
]));

}

void reset(){
   ::reset();
   if(!present("pirate")){
	new(MON+"piratethief")->move(TO);

}
}






