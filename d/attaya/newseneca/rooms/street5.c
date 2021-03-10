//street5 - Circe 11/22/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit AZUL;

void create(){
   ::create();
   set_long(::query_long()+"The tall stucco wall of the %^BOLD%^%^MAGENTA%^"+
      "Tropical Breeze Inn%^RESET%^ lines the street to the south.\n");
   set_exits(([
      "west" : ROOMS"street4",
      "east" : ROOMS"street6"
   ]));
   add_item("wall","%^BOLD%^To the south, a tall cream-colored stucco wall "+
      "lines the street.  It is the northern wall of the %^MAGENTA%^Tropical "+
      "Breeze Inn%^WHITE%^.%^RESET%^");
   add_item("inn","%^BOLD%^To the south, a tall cream-colored stucco wall "+
      "lines the street.  It is the northern wall of the %^MAGENTA%^Tropical "+
      "Breeze Inn%^WHITE%^.%^RESET%^");
}