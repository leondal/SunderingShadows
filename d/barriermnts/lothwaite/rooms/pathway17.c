//pathway17.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  To the northeast, you can see a wooden dock leading "+
      "out into a large lake.  Back to the southwest, the path splits in two "+
      "directions, and the river runs to the west.\n");
   add_item("dock","A wide wooden dock juts into the lake to the northeast.");
   add_item("river","The river looks very deep and frigid this high up in the mountains.");
   set_exits(([
      "southwest" : PATHEXIT"pathway16",
      "northeast" : PATHEXIT"dock",
   ]));
}
