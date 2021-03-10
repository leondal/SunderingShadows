//Ekibi Caverns by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit EKIBIS;

void create(){
   ::create();
   set_long(::query_long()+"The cavern comes to an end here, with "+
      "openings to the north and southwest.\n");
   set_exits(([
      "north" : PATHEXIT"s2",
      "southwest" : PATHEXIT"c11"
   ]));
}
