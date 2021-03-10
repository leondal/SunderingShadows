#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThe tunnel seems to curve downward here, "+
      "heading deeper into the mountain.\n");
   set_exits(([
      "northeast" : ROOMS"tunnel1",
      "southeast" : ROOMS"tunnel3"
   ]));
}
