//pathway15.c - Path through Lothwaite.  Circe 5/10/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  The path continues here, leading "+
      "southwest toward the ramparts or east over a bridge into the "+
      "village.  A smooth, grassy dip in the valley to the west "+
      "leads to two tall buildings.\n");
   add_item("bridge","This thick wooden bridge was made of logs left in the "+
      "rough and packed with mud.  The river moving beneath it is about twenty "+
      "feet wide and moves swiftly.");
   add_item("river","The river looks very deep and frigid this "+
      "high up in the mountains.");
   set_exits(([
      "southwest" : PATHEXIT"pathway14",
      "east" : PATHEXIT"bridge1",
      "west" : PATHEXIT"grass1"
   ]));
}
