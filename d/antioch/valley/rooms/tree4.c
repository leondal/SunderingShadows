#include "../valley.h"
inherit TREE;

void create()
{
   ::create();
   set_long(
   "From this height you can see the entire area. Almost straight"+
   " south seems to be where you came in from. To the west there"+
   " appears to be a cave of some sort. Over to the southeast there"+
   " is a camp setup in a clearing. In the far southeast the forest"+
   " seems dark and the trees are drawn together somehow. You can't"+
   " tell what exactly is happening over there. To the north there"+
   " is a valley, the trail just north of you seems to lead into it."+
   " Far to the north you can see a waterfall pouring down into a"+
   " lake, the river runs off to the east and disappears into the"+
   " woods. This is the top of the tree, the branches above you"+
   " don't look like they'd hold your weight."
   );
   set_exits( ([
   "down" : ROOMS+"tree3",
   ]) );
}
