//street5 - Circe 11/22/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit AZUL;

void create(){
   ::create();
   set_long(::query_long()+"The tall stucco wall of the %^BOLD%^%^MAGENTA%^"+
      "Tropical Breeze Inn%^RESET%^ lines the street to the south.  Just east "+
      "of here, you see the junction of %^BOLD%^%^BLUE%^Azul Avenue %^RESET%^"+
      "and %^YELLOW%^Sol Boulevard %^RESET%^as well as the large %^ORANGE%^"+
      "oaken gate %^RESET%^reinforced with "+
      "%^BOLD%^%^BLACK%^iron%^RESET%^ that grants entry into the city.\n");
   set_exits(([
      "west" : ROOMS"street5",
      "east" : ROOMS"street7"
   ]));
   add_item("wall","%^BOLD%^To the south, a tall cream-colored stucco wall "+
      "lines the street.  It is the northern wall of the %^MAGENTA%^Tropical "+
      "Breeze Inn%^WHITE%^.%^RESET%^");
   add_item("inn","%^BOLD%^To the south, a tall cream-colored stucco wall "+
      "lines the street.  It is the northern wall of the %^MAGENTA%^Tropical "+
      "Breeze Inn%^WHITE%^.%^RESET%^");
   add_item("junction","To the east, %^BOLD%^%^BLUE%^Azul Avenue %^RESET%^"+
      "crosses over the wide thoroughfare of %^YELLOW%^Sol Boulevard"+
      "%^RESET%^.");
   add_item("gate","%^ORANGE%^To the north and east, you see a thick "+
      "%^BOLD%^%^BLACK%^iron-bound %^RESET%^%^ORANGE%^oaken gate that "+
      "grants entry to the city.  It has a very small window with "+
      "%^BOLD%^%^BLACK%^iron bars %^RESET%^%^ORANGE%^but is otherwise "+
      "solid.%^RESET%^");
}