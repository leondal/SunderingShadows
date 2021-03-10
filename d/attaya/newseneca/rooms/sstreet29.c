//sstreet29 - Circe 11/23/07 for new Seneca
//added some guards -hades 8/10
#include <std.h>
#include "../seneca.h"

inherit VERDE;

void create(){
   ::create();
   set_long(::query_long()+"Despite the breadth of the road, this "+
      "particular stretch seems a little closed in.  To the north, "+
      "the %^BOLD%^glistening walls %^RESET%^of the cathedral tower "+
      "overhead, while to the south the %^BOLD%^town walls %^RESET%^"+
      "do the same, leaving this particular area in %^BOLD%^%^BLACK%^"+
      "shadow%^RESET%^, no matter the time of day.\n");
   set_exits(([
      "east" : ROOMS"sstreet28",
      "west" : ROOMS"sstreet30"
   ]));
}
void reset(){
  ::reset();
  if(!present("Seneca Guard 2"))
     new("/d/attaya/newseneca/mon/city_guard")->move(TO);
  if(!present("psion"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
}
