//estreet14 - Circe 11/23/07 for new Seneca
//added some guard -hades 8/10
#include <std.h>
#include "../seneca.h"

inherit LILA;

void create(){
   ::create();
   set_long(::query_long()+"This corner is the junction of %^BOLD%^"+
      "%^BLUE%^Azul Avenue %^RESET%^and %^MAGENTA%^Lila Way%^RESET%^.  "+
      "To the southwest is the corner of a tall %^RED%^brick wall%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"street12",
      "south" : ROOMS"estreet14"
   ]));
   add_item("wall","The wall to the southwest is %^RED%^red brick %^RESET%^"+
      "with gray mortar.  It rises three stories, but you cannot tell "+
      "what the building might be from here.");
}
void reset(){
  ::reset();
  if(!present("Seneca Guard 2"))
     new("/d/attaya/newseneca/mon/city_guard")->move(TO);
  if(!present("psion"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
}
