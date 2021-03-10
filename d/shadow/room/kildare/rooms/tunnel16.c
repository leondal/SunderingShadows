#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThis particular area seems to be a "+
      "low point in the tunnel, with slopes rising to both the "+
      "north and southwest.\n");
   set_exits(([
      "north" : ROOMS"tunnel17",
      "southwest" : ROOMS"tunnel15"
   ]));
}
