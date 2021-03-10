#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThe tunnel seems to curve downward here, "+
      "heading deeper into the mountain.\n");
   set_exits(([
      "west" : ROOMS"tunnel3",
      "southeast" : ROOMS"tunnel5"
   ]));
}
