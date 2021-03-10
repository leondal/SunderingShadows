//pathway29.c - Path through Lothwaite.  Circe 3/19/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  The pathway to the northwest seems to be "+
      "the main path through town,  while there is a bridge to the "+
      "southeast.  The bridge has been raised, possibly to increase "+
      "security.  It does not seem you can go any further that way.\n");
/*   add_item("bridge","This thick wooden bridge was made of logs left in the "+
      "rough and packed with mud.  The river moving beneath it is about twenty "+
      "feet wide and moves swiftly.");
*/
   add_item(({"bridge","wooden bridge"}), "The wooden bridge has been "+
      "lifted, providing an effective barrier across the pathway.  There "+
      "seems to be no way across until the bridge is lowered.");
   add_item("river","The river looks very deep and frigid this high up in the mountains.");
   set_exits(([
      "northwest" : PATHEXIT"pathway28",
//      "southeast" : PATHEXIT"bridge2",
   ]));
}