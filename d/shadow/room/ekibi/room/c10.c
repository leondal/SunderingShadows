//Ekibi Caverns by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit EKIBI;

void create(){
   ::create();
   set_exits(([
      "northeast" : PATHEXIT"c11",
      "southwest" : PATHEXIT"c9"
   ]));
}
