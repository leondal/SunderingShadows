#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThe tunnel has a sharp slope "+
     "here, with the high point to the northwest and a fairly "+
     "steep drop to the southeast.\n");
   set_exits(([
      "northwest" : ROOMS"tunnel7",
      "southeast" : ROOMS"tunnel9"
   ]));
}
