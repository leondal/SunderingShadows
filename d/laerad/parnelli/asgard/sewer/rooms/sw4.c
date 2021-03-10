#include <std.h>
#include "../lizard.h"
inherit ROOM;
void create(){
::create();
  	set_terrain(BUILT_TUNNEL);
  	set_travel(PAVED_ROAD);
set("short","Dark, dank dripping room.");
set("long","You have entered a room that is dark, dank, and wet.  "+
   "Water glistens at various points on the walls, while mold and fungus "+
   "sprout everywhere.  A small stream of fetid and foul smelling liquid "+
   "flows slowly down the middle of the passage.");
set_property("indoors",1);
set_property("light",1);
set_smell("default","The odor in here is intense and thick.  The smell of a dank sewer presses in on you.");
set_listen("default","Dripping water from the walls splashes to the floor.  Sounds of small rodents skittering float from the shadows.");
set_items(([
"stream":"The water flows slowly and thickly, are you sure you want to get your face any closer?",
"walls":"Slimy and slick, they fester with disease."
   ]));
set_exits(([
   "north":LROOMS+"sw3",
   "southeast":LROOMS+"sw5"
 ]));
}
