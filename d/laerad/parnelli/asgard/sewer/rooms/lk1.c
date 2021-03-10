#include <std.h>
#include "../lizard.h"
inherit ROOM;  // changed to use ROOM instead of VAULT to save memory (no doors)
inherit "std/pier";
void create(){
::create();
set_name("Mushroom Caves");
set("short","Dry dark cavern.");
set("long","%^ORANGE%^You find yourself in a small dry room of the cavern.  "+
   "The walls and floor look like the stone has been worked in this area. Torches line the walls "+
   "and this area is very well lit.  %^RESET%^");
set_property("indoors",1);
set_property("no teleport",1);
set_property("light",2);
set_terrain(NAT_CAVE);
set_travel(DIRT_ROAD);
set_smell("default","The room smells dusty and dry.");
set_listen("default","It is very quiet in these rooms save for the sounds you make.");
set_items(([
   "walls":"Much like what you would expect cave walls to be like, hard, dry and cool to the touch.",
   "floor":"Smooth and flat as if from some stoneworking and much usage.",
   "torches":"Sputtering and flickering the torches on the walls illuminate the room completely.",
   "torch":"Sputtering and flickering the torches on the walls illuminate the room completely."
   ]));
set_exits(([
   "south":LROOMS+"lk3"
 ]));
}
