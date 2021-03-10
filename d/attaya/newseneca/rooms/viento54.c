//viento54 - Circe 11/12/07 for new Seneca
// added a couple guards -hades 8/10
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
   set_long(::query_long()+"This stretch of road leads to the %^BOLD%^"+
      "town square %^RESET%^to the west.  North and south of here are "+
      "%^GREEN%^gardens %^RESET%^with grand monuments set among stone "+
      "benches.\n");
   set_exits(([
      "west" : ROOMS"square",
      "east" : ROOMS"viento55",
      "north" : ROOMS"monument2",
      "south" : ROOMS"monument3"
   ]));
}
void reset(){
  ::reset();
 
  if(!present("Seneca Guard"))
     new("/d/attaya/newseneca/mon/city_guard")->move(TO);
  if(!present("psion"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);

}
