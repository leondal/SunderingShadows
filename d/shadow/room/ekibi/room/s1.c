//Ekibi Caverns by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit EKIBIS;

void create(){
   ::create();
   set_long(::query_long()+"The cavern comes to an end here, with "+
      "the only opening to the south.\n");
   set_exits(([
      "south" : PATHEXIT"s2"
   ]));
}
