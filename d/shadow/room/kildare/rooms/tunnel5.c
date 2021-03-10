#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nThe tunnel seems to bottom out here, "+
      "leading slightly upwards in both directions northward.\n");
   set_search("default","Searching around, you notice that there "+
      "seem to be some very deep shadows in the southwestern corner.");
   set_search("shadows","Searching the shadows, you find that a "+
      "narrow pathway seems to form around a bend to the southwest!");
   set_exits(([
      "northwest" : ROOMS"tunnel4",
      "northeast" : ROOMS"tunnel6",
      "southwest" : ROOMS"hiddentunnel1"
   ]));
   set_invis_exits(({"southwest"}));
}
