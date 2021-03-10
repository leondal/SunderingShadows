//sstreet35 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit ROSA;

void create(){
   ::create();
   set_long(::query_long()+"A %^BOLD%^marble archway %^RESET%^to the "+
      "east leads through a hallway to a %^BOLD%^rotunda%^RESET%^.  To "+
      "the southeast, you see a grand %^RED%^t%^ORANGE%^o%^RED%^w%^ORANGE%^e%^RED%^r %^RESET%^"+
      "with scalloped sides constructed in alternating bands of %^RED%^"+
      "red %^RESET%^and %^ORANGE%^tan %^RESET%^stones rising against "+
      "the sky.\n");
   set_exits(([
      "north" : ROOMS"wstreet36",
      "south" : ROOMS"wstreet34",
      "east" : ROOMS"portal"
   ]));
   add_item("archway","The archway to the east is made of white marble "+
      "and leads into a hallway lined with columns that leads to the "+
      "rotunda.");
   add_item("rotunda","You can see the circular roof of the rotunda "+
      "rising above the archway but precious little else.");
   add_item("tower","The tower to the southeast is truly a wonder to behold.  "+
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