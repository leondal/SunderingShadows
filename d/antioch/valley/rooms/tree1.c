#include "../valley.h"
inherit TREE;

void create()
{
   ::create();
   set_long(
   "As you begin to climb up the tree you can see more of the"+
   " world around you. There are still dark and sinister"+
   " trees on all sides of you, but now you can see the sky."
   );
   set_exits( ([
   "down" : ROOMS+"dtree",
   "up" : ROOMS+"tree2",
   ]) );
}
