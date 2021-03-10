#include "../valley.h"
inherit TREE;

void create()
{
   ::create();
   set_long(
   "Higher in the tree you are now level with the tops of the"+
   " other trees. You can see that this forest stretches out quite"+
   " a ways. There seems to be a very tall tower to the southwest"+
   " and you think there might be a break in the trees to the northeast."
   );
   set_exits( ([
   "down" : ROOMS+"tree1",
   "up" : ROOMS+"tree3",
   ]) );
}
