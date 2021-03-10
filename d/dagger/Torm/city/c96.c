#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create()
  {
  ::create();
  set_property("smithy",1); 
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_door("door",TCITY+"c80","south");  // took out key on this side so people don't get locked in *Styx*  4/18/03
  set_property("indoors",1);
  set_property("light",2);
    set_short("Torm's finest weapons smith");
  set_long(
    "Torm's finest weapons smith.\n"
  "  You feel awed by the multitude of shining weapons that line the walls of this weaponsmith."
    "  It seems no king's treasure trove ever gleamed brighter than the polish on many of these simple but exceedingly well made items."
    "  A forge stands to the back with a constant glow coming from it, surrounded by metal-working implements."
  );
   set_smell("default","The room smells of oils used to polish swords.");
   set_listen("default","There is the steady pound of a hammer on the anvil coming from the back.");
   set_items(([
   ({"walls","weapons"}) : "There are a multitude of brightly shining weapons lining the walls.",
   "forge" : "There is a forge in the back of the room that is always lit, helping to light the room and keep it warm, sometimes a bit uncomfortably so.",
   ]));
  set_exits(([
  "south":TCITY+"c80",
  ]));
  set_open("door",1);
}
void init(){
  ::init();
  if(!present("angel",TO)){
  new(MON+"weaponer1.c")->move(TO);
 }
}
