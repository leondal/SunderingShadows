//Ekibi Caverns by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit EKIBI;

void create(){
   ::create();
   set_exits(([
      "northeast" : PATHEXIT"c10",
      "west" : PATHEXIT"c8",
      "southeast" : PATHEXIT"c12"
   ]));
}
