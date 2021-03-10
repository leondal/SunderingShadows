#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThis particular area seems "+
      "to be a high point in the tunnel, with slopes leading "+
      "down to both the northwest and southwest.\n");
   set_exits(([
      "southwest" : ROOMS"tunnel12",
      "northwest" : ROOMS"tunnel14"
   ]));
}
