//pathway16.c - Path through Lothwaite.  Circe 2/25/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  A sturdy wooden bridge leads across a swift river "+
      "to the west.\n");
   add_item("bridge","This thick wooden bridge was made of logs left in the "+
      "rough and packed with mud.  The river moving beneath it is about twenty "+
      "feet wide and moves swiftly.");
   add_item("river","The river looks very deep and frigid this high up in the mountains.");
   set_exits(([
      "west" : PATHEXIT"bridge1",
      "northeast" : PATHEXIT"pathway17",
      "southeast" : PATHEXIT"pathway18"
   ]));
}
