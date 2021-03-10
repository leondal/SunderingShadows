#include <std.h>
#include <objects.h>
#include "../lizard.h"
inherit "std/pier";
void create(){
::create();
set_name("Mushroom Caves");
set("short","Dry dark cavern.");
set("long","%^CYAN%^You find yourself in a large dry area of a larger cavern.  "+
   "Mushrooms and other fungi grow tall here, almost to the point of making a forest.  "+
   "This area is not very well lit, but you do seem to make out the edges of a small pond of "+
   "fresh water.  %^RESET%^");
set_property("indoors",1);
set_property("no teleport",1);
set_property("light",1);
set_smell("default","The room smells dusty and dry.");
set_listen("default","It is very quiet in these rooms save for the sounds you make.");
set_items(([
   "walls":"Much like what you would expect cave walls to be like, hard, dry and cool to the touch.",
   "floor":"Smooth and flat as if from some stoneworking and much usage.",
   "mushrooms":"Tall and hard like trees, not soft as you expected.",
   "fungus":"Different colors dot the area, hopefully they are benign.",
   "fungi":"Different colors dot the area, hopefully they are benign.",
   "pond":"This is a small pond and the water looks free of floating scum, maybe you can drink it.",
   "mushroom":"Tall and hard like trees, not soft as you expected."
   ]));
set_exits(([
   "north":LROOMS+"m16",
   "northeast":LROOMS+"m17",
   "east":LROOMS+"m20",
   "southeast":LROOMS+"m23",
   "south":LROOMS+"m22",
   "southwest":LROOMS+"m21",
   "west":LROOMS+"m19",
   "northwest":LROOMS+"m15"
   ]));
}
