#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThe tunnel is relatively level "+
      "here but slopes downward to the southeast.\n");
   set_exits(([
      "southwest" : ROOMS"tunnel6",
      "southeast" : ROOMS"tunnel8"
   ]));
}
