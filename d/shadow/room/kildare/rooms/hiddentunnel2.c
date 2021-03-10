#include "../kildare.h"

inherit HIDDENTUNNEL;

void create(){
   ::create();
   set_long(::query_long()+"\nThis narrow tunnel grows covered "+
      "with a light film of dust as it continues into the "+
      "%^RESET%^gloom %^BOLD%^%^BLACK%^to the southwest.  "+
      "The sounds of the fowl inhabitants can be heard toward "+
      "the east.\n");
   set_exits(([
      "southwest" : ROOMS"hiddentunnel3",
      "east" : ROOMS"hiddentunnel1"
   ]));
}