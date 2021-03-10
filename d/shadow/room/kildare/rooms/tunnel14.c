#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThis part of the tunnel is on a "+
      "steep slope leading upwards to the southeast.\n");
   set_exits(([
      "north" : ROOMS"tunnel15",
      "southeast" : ROOMS"tunnel13"
   ]));
}
