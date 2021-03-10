//garden2 - ~Circe~ 1/13/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"garden_inherit";

void create(){
   ::create();
   set_long(::query_long()+"\n%^RESET%^%^GREEN%^This section "+
      "of the %^BOLD%^gardens %^RESET%^%^GREEN%^is bounded on "+
      "the south and west by a %^BOLD%^%^BLACK%^wrought iron fence %^RESET%^"+
      "%^GREEN%^that separates this peaceful landscape from the "+
      "bustle of %^BOLD%^%^WHITE%^Seneca%^RESET%^%^GREEN%^.  "+
      "An incredible %^RED%^t%^ORANGE%^o%^RED%^w%^ORANGE%^e"+
      "%^RED%^r %^RESET%^%^GREEN%^rises to the west just beyond "+
      "the fence, casting its long shadow over the area.%^RESET%^\n");
   set_exits(([
      "north" : ROOMS"garden3",
      "east" : ROOMS"garden1"
   ]));
   add_item("fence","%^BOLD%^%^BLACK%^The iron picket fence has "+
      "fleur-de-lis caps and is set with %^RESET%^stone columns "+
      "%^BOLD%^%^BLACK%^at intervals.%^RESET%^");
   add_item("tower","The tower to the west is truly a wonder to behold.  "+
      "The architecture looks nothing like the rest of Seneca, and the "+
      "juxtaposition creates an image of stunning beauty.  The tower rises "+
      "approximately one hundred and fifty feet in the air, narrowing slightly "+
      "as it goes until it appears to end in a spire.  Extra care was "+
      "taken in choosing and arranging the building materials, beginning "+
      "with a band of decorative %^RED%^red stone %^RESET%^near the base "+
      "that is about twenty feet high.  Atop that is a layer of %^ORANGE%^"+
      "tan stone %^RESET%^of approximately twice that height.  This "+
      "alternating pattern continues all the way to the spire.");
   add_item("red stone","%^RED%^Each band of red stone has a wide "+
      "decorative carving featuring knots and swooping scrollwork "+
      "highlighted in places with muted %^YELLOW%^gold%^RESET%^.");
   add_item("tan stone","%^ORANGE%^Upon closer inspection, you realize the "+
      "tan stone bands are actually made up of blocks in various shades of "+
      "%^BOLD%^%^WHITE%^cream%^RESET%^%^ORANGE%^, tan, and %^RED%^pale red"+
      "%^ORANGE%^.  The smoothness of the tan stone emphasizes the "+
      "grandeur of the carved red band.%^RESET%^");
   add_item("stone","You might want to look at either the red stone or the "+
      "tan stone.");
}