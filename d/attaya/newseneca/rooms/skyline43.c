//skyline43
// updated by hades 11/15/2009 added guards
#include <std.h>
#include "../seneca.h"

inherit SKYLINE;

void create(){
   ::create();
   set_long(::query_long()+"To both the east and west lie %^GREEN%^"+
      "gardens %^RESET%^with monuments set among stone benches.  "+
      "South of here is the wide %^BOLD%^town square %^RESET%^"+
      "at the juncture of two major roadways.\n");
   set_exits(([
      "west" : ROOMS"monument1",
      "east" : ROOMS"monument2",
      "north" : ROOMS"skyline42",
      "south" : ROOMS"square"
   ]));
}
void reset(){
   ::reset();
 
   if(!present("Seneca Guard"))new("/d/attaya/newseneca/mon/city_guard")->move(TO);
   if(!present("Seneca Guard 2"))
      new("/d/attaya/newseneca/mon/city_guard")->move(TO);
   if(!present("psion"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
   if(!present("psion 2"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
}
