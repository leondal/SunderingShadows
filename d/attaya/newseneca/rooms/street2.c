//street2 - Circe 11/22/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit AZUL;

void create(){
   ::create();
   set_long(::query_long()+"Directly south of here is a small %^CYAN%^tailor "+
      "shop %^RESET%^painted a soft blue with %^BOLD%^%^BLUE%^darker blue trim"+
      "%^RESET%^.  Just to the west, you see the corner of %^BOLD%^%^BLUE%^Azul Avenue "+
      "%^RESET%^and %^BOLD%^%^MAGENTA%^Rosa Terrace%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"wstreet1",
      "east" : ROOMS"street3",
      "south" : ROOMS"tailor"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/tailor","south",0,0);
   set_door_description("door","The door to the tailor's shop is "+
      "%^ORANGE%^oaken %^RESET%^and has a curved top.  A small half-moon "+
      "%^CYAN%^window %^RESET%^is set near the top of the door.");
   add_item("shop","%^CYAN%^The tailor shop to the south is a light "+
      "blue stucco building with darker blue %^BOLD%^%^BLUE%^trim "+
      "%^RESET%^%^CYAN%^and %^BOLD%^%^BLUE%^roof%^RESET%^%^CYAN%^."+
      "%^RESET%^");
   add_item("tailor","%^CYAN%^The tailor shop to the south is a light "+
      "blue stucco building with darker blue %^BOLD%^%^BLUE%^trim "+
      "%^RESET%^%^CYAN%^and %^BOLD%^%^BLUE%^roof%^RESET%^%^CYAN%^."+
      "%^RESET%^");
   add_item("tailor shop","%^CYAN%^The tailor shop to the south is a light "+
      "blue stucco building with darker blue %^BOLD%^%^BLUE%^trim "+
      "%^RESET%^%^CYAN%^and %^BOLD%^%^BLUE%^roof%^RESET%^%^CYAN%^."+
      "%^RESET%^");
}