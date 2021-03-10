#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nTo the southwest, the tunnel "+
      "has a relatively sharp drop off.\n");
   set_exits(([
      "southwest" : ROOMS"tunnel10",
      "east" : ROOMS"tunnel12"
   ]));
}
