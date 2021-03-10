//pathway21.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  To the north, a large field opens up, "+
      "with a tall wooden silo in the distance.\n");
   add_item("field","To the north, the path gives way to a large green "+
      "field where a vegetable garden has been sown.  A tall silo stands "+
      "just on the other side of the field.");
   set_exits(([
      "north" : PATHEXIT"veggarden",
      "southwest" : PATHEXIT"pathway20"
   ]));
}