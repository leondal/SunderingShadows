#include "../valley.h"
inherit TREE;

void create()
{
   ::create();
   set_long(
   "Further up in the tree you have a better view of the area."+
   " From this vantage you can see that the trees definitely do give"+
   " way up to the north, it must be some sort of clearing or valley."+
   " You can see that the trail system extends further to the east"+
   " but seems to disappear into the woods. You believe that you"+
   " could climb up a little higher, but you're nearing the top."
   );
   set_exits( ([
   "down" : ROOMS+"tree2",
   "up" : ROOMS+"tree4",
   ]) );
}
