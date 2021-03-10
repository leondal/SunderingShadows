//Ekibi Caverns by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit EKIBI;

void create(){
   ::create();
   set_long(::query_long()+"The cavern seems to open up to "+
      "the east, and you hear a stronger sound of water "+
      "from that direction.\n");
   set_exits(([
      "west" : PATHEXIT"c5",
      "east" : PATHEXIT"s2"
   ]));
}
