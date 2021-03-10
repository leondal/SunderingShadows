//bridge1.c - Path through Lothwaite.  Circe 5/10/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  You are standing on a thick wooden "+
      "bridge that travels over a wide river moving swiftly beneath.\n");
   add_item("bridge","This thick wooden bridge was made of logs left in the "+
      "rough and packed with mud.  The river moving beneath it is about twenty "+
      "feet wide and moves swiftly.");
   add_item("river","The river looks very deep and frigid this "+
      "high up in the mountains.");
   set_exits(([
      "east" : PATHEXIT"pathway16",
      "west" : PATHEXIT"pathway15"
   ]));
}
