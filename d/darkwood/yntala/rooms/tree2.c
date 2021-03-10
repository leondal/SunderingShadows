//tree2
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit ROOM;

void create(){
::create();
   set_property("indoors",1);
   set_property("light",0);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^BOLD%^%^BLACK%^Within the bowels of a dark tree");
   set_short("%^BOLD%^%^BLACK%^Within the bowels of a dark tree%^RESET%^");
   set_smell("default","The smell of earth is strong here.");
   set_long((:TO,"ldesc":));
   set_items(([
   "worms":"A few worms wiggle around in the rotting pieces of tree that litter the ground around your feet.",
   "pieces":"%^RESET%^%^ORANGE%^Pieces of this tree have fallen off from the inside and lay rotting on the ground around your feet.%^RESET%^",
]));
   set_exits((["out":INRMS+"forest236"]));
   set_climb_exits((["climb":({INRMS+"tree3",15,4,100})
]));
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^The inside of this tree is surprisingly large, much larger than one would expect"
" from looking at the tree from the outside.  It is also incredibly dark in this area, as little to no light"
" manages to get in through the small hole at the base of the tree.  A few %^RESET%^%^ORANGE%^chips"
" %^BOLD%^%^BLACK%^of %^RESET%^%^ORANGE%^rotting tree %^BOLD%^%^BLACK%^litter the floor and a few %^RESET%^worms"
" %^BOLD%^%^BLACK%^wiggle around in them.  Looking up, you can see that the inside of the tree has been"
" completely gutted, all the way to the narrow top some three hundred feet above you.%^RESET%^");
} 



