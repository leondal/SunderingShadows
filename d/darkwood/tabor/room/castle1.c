#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

void create()
{
   ::create();
  set_travel(PAVED_ROAD);
  set_terrain(STONE_BUILDING);
   set_property("light",2);
  set_property("indoors", 1);
   set_property("no sticks", 1);
   set_short("Within Caer Tabor");
   set_long(
   "%^BOLD%^Within Caer Tabor%^RESET%^\n"+
   "You are standing within the walls of the magnificent Caer Tabor."+
   "  The walls are made out of thick and sturdy stone blocks which"+
   " have been smoothly polished and filled with mortar between the"+
   " cracks to keep the wind out.  Royal tapestries cover the walls."+
   "  A thick purple rug has been spread out across the floor and it"+
   " is embroidered in silver.  A large chandelier has been hung from"+
   " the ceiling.  The castle is obviously quite ancient"+
   " but still full of wealth and power.  Most of the castle is closed"+
   " off to visitors, with large doors to the north and west being"+
   " barred shut.  To the east appears to be the magistrate's office.\n\n"+
   "Mathowvy Road lies to the south.\n"
   );
   set_listen("default","The footsteps of the patrolling guards echo"+
   " in the hallway.");
   set_items(([
   "tapestries" : "Expensive royal tapestries line the walls, showing"+
   " the past rulers of Caer Tabor.",
   ({"rug","purple rug"}) : "%^MAGENTA%^A thick purple rug covers the"+
   " hallway here. It is embroidered in thick silver thread and it"+
   " does a good job at impressing you.",
   "doors" : "The large doors to the north and west are closed to the"+
   " general public. With a castle full of alert guards it would be"+
   " impossible to open them.",
   "chandelier" : "An expensive crystal chandelier is hung by a"+
   " bronze chain from the ceiling. It has over two dozen white candles"+
   " that are lit and they shed light on the castle entrance.",
   "floor" : "The floor is covered in a large purple rug.",
   "ceiling" : "A large chandelier has been hung from the ceiling,"+
   " obviously it's meant to impress visitors.",
   ]));
   set_exits(([
   "south" : ROOMDIR+"math12",
   "east" : ROOMDIR+"castle2",
   ]));
}
