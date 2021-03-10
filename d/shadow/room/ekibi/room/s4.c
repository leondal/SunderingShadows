//Ekibi Caverns by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit EKIBIS;

void create(){
   ::create();
   set_long(::query_long()+"The cavern comes to an end here, with "+
      "narrow openings to the southwest and southeast.\n");
   set_exits(([
      "north" : PATHEXIT"c13",
      "southwest" : PATHEXIT"s5",
      "southeast" : PATHEXIT"s6"
   ]));
}
