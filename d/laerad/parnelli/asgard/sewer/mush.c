
#include <std.h>
#include <objects.h>
inherit ROOM;

void create(){
::create();
  	set_terrain(NAT_CAVE);
  	set_travel(RUTTED_TRACK);
set("short","Dry dark cavern.");
set("long","%^CYAN%^You find yourself in a large dry area of a larger cavern.  "+
   "Mushrooms and other fungi grow tall here, almost to the point of making a forest.  "+
   "This area is not very well lit.  %^RESET%^");
set_property("indoors",1);
set_property("no teleport",1);
set_property("no sticks",1);
set_property("light",1);
set_smell("default","The room smells dusty and dry.");
set_listen("default","It is very quiet in these rooms save for the sounds you make.");
set_items(([
   ({"walls","wall"}):"Much like what you would expect cave walls to be like, hard, dry and cool to the touch.",
   "floor":"Smooth and flat as if from some stoneworking and much usage.",
   ({"mushrooms","mushroom"}):"Tall and hard like trees, not soft as you expected.",
   ({"fungus","fungi"}):"Different colors dot the area, hopefully they are benign."
   ]));
 }
