//Ekibi Caverns by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit EKIBI;

void create(){
   ::create();
   set_exits(([
      "northwest" : PATHEXIT"c1",
      "east" : PATHEXIT"c8"
   ]));
}
