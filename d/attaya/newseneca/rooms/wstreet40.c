//sstreet40 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit ROSA;

void create(){
   ::create();
   set_long(::query_long()+"A building just to the east has %^CYAN%^light "+
      "blue stucco walls %^RESET%^with %^BOLD%^%^BLUE%^darker trim%^RESET%^.  "+
      "The roof is finished in %^BOLD%^%^BLUE%^dark blue tile%^RESET%^ as "+
      "well.  North of here you see the corner where %^BOLD%^%^MAGENTA%^Rosa "+
      "Terrace %^RESET%^meets %^BOLD%^%^BLUE%^Azul Avenue%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"wstreet1",
      "south" : ROOMS"wstreet39"
   ]));
   add_item("building","Likely a shop of some kind, the building to the "+
      "east has very %^CYAN%^soft blue stucco %^RESET%^and is well-kept.  "+
      "A %^ORANGE%^window basket %^RESET%^on this side has been filled "+
      "with %^BOLD%^coir fibers %^RESET%^to support the %^ORANGE%^ora"+
      "%^YELLOW%^n%^RESET%^%^ORANGE%^ge bou%^YELLOW%^g%^RESET%^%^ORANGE%^"+
      "ain%^YELLOW%^v%^RESET%^%^ORANGE%^ill%^YELLOW%^e%^RESET%^%^ORANGE%^"+
      "a%^RESET%^ growing within.");
}