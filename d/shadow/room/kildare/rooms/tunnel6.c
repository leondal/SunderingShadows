#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThe tunnel seems to slope downwards "+
      "to the southwest, though it runs somewhat level to the northeast.\n");
   set_exits(([
      "southwest" : ROOMS"tunnel5",
      "northeast" : ROOMS"tunnel7"
   ]));
}
