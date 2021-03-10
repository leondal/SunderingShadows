//weapon

#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_short("Shawologon's Weapons");

   set_long(
@JAVAMAKER
%^BOLD%^%^WHITE%^Shawologon's Weapons.%^RESET%^
You have wondered into a shop full of weapons.  The counter to 
the east holds a wide variety of daggers.  Seems to be what
Shawologon specializes in.  The exit is to the south.
JAVAMAKER
   );

   set_smell("default","You smell weapon oil.");
   set_listen("default","It's pretty quiet here.");
   set_items(([
       "counter":"This beaten old counter looks like it was made from the captain's desk of an old ship.",
  "daggers":"There are a large varitey of daggers arrayed on the counter.",
   ]));

   set_exits(([
      "south":CAVES"cove6",
   ]));
}

void reset(){
   ::reset();
if(!present("shawologon")){
new(MON+"shawologon")->move(TO);
}
}

void init(){
   ::init();

}