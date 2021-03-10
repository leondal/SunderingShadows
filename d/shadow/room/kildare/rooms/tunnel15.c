#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThe slope of the tunnel leads "+
      "upward to the south and downward to the northeast.\n");
   set_exits(([
      "northeast" : ROOMS"tunnel16",
      "south" : ROOMS"tunnel14"
   ]));
}
