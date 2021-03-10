//estreet22 - Circe 11/23/07 for new Seneca
//added some guards - hades 8/10
#include <std.h>
#include "../seneca.h"

inherit LILA;

void create(){
   ::create();
   set_long(::query_long()+"This corner is the %^ORANGE%^junction "+
      "%^RESET%^of %^MAGENTA%^Lila Way %^RESET%^and %^GREEN%^Verde "+
      "Esplanade%^RESET%^.  To the northwest is a large %^ORANGE%^"+
      "wooden building %^RESET%^housing a %^ORANGE%^stable%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"estreet21",
      "west" : ROOMS"sstreet23"
   ]));
   add_item("building","%^ORANGE%^The wooden building to the northwest "+
      "must be a stable.  It features a wide sliding door that stands "+
      "open most of the time, and you can see the individual stalls "+
      "closest to the door just inside.%^RESET%^");
}
void reset(){
  ::reset();
  if(!present("Seneca Guard 2"))
     new("/d/attaya/newseneca/mon/city_guard")->move(TO);
  if(!present("psion"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
}
