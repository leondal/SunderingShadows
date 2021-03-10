#include <std.h>
#include "../lizard.h"
inherit VAULT;
void create(){
::create();
set_name("Dry Caves");
set("short","Dry, well lit cavern.");
set("long","%^ORANGE%^You find yourself in a small dry cavern.  There is a door in the west wall.  "+
   "The walls and floor look like the stone has been worked in this area.  "+
   "Stalactites, stalagmites and rubble have been cleared away.  Torches line the walls "+
   "and this area is very well lit.  %^RESET%^");
set_property("indoors",1);
set_property("no teleport",1);
set_property("light",2);
set_terrain(NAT_CAVE);
set_travel(DIRT_ROAD);
set_smell("default","The cave smells dusty and dry.");
set_listen("default","It is very quiet in these caves save for the sounds you make.");
set_items(([
   "walls":"Much like what you would expect cave walls to be like, hard, dry and cool to the touch.",
   "floor":"Smooth and flat as if from some stoneworking and much usage.",
   "torches":"Sputtering and flickering the torches on the walls illuminate the room completely.",
   "torch":"Sputtering and flickering the torches on the walls illuminate the room completely."
   ]));

set_door("oak door",LROOMS+"lk8","west","green key");
set_locked("oak door",1,"lock");
     (LROOMS+"lk8")->set_locked("oak door",1,"lock");
set_door_description("oak door","Made of solid oak, it looks like it can take a hard "+
	"hit.  The keyhole winks at you in the torchlight.");
set_string("oak door","open","The door swings open.  Your hear it creak louder "+
	"than you like.\n");

set_exits(([
   "northeast":LROOMS+"w4",
   "east":LROOMS+"w11",
   "west":LROOMS+"lk8"
 ]));
}
