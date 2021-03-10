//sstreet34 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit ROSA;

void create(){
   ::create();
   set_long(::query_long()+"Rising high in the sky to the east is a "+
      "beautiful %^RED%^t%^ORANGE%^o%^RED%^w%^ORANGE%^e%^RED%^r %^RESET%^"+
      "with scalloped sides constructed in alternating bands of %^RED%^"+
      "red %^RESET%^and %^ORANGE%^tan %^RESET%^stones.  An %^BOLD%^archway "+
      "%^RESET%^in the bottom %^RED%^red band %^RESET%^grants entry into "+
      "the tower from this side.\n");
   set_exits(([
      "north" : ROOMS"wstreet35",
      "south" : ROOMS"wstreet33",
      "east" : ROOMS"psi_entry"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/psi_entry","east",0,0);
   set_door_description("door","The door to the tower has a unique shape - "+
      "instead of being simply rounded, it has an onion-shaped top that perfectly "+
      "matches the archway around it.  It is crafted of thick %^ORANGE%^pale "+
      "wood %^RESET%^that perfectly matches the %^ORANGE%^tan bands %^RESET%^"+
      "of the tower.  A thick %^ORANGE%^brass ring %^RESET%^serves as the "+
      "door handle.");
   add_item("archway","%^RED%^The archway at the base of the tower is onion-"+
      "shaped and is fitted with a %^ORANGE%^tan wooden door%^RED%^ to "+
      "grant entry to the tower.%^RESET%^");
   add_item("tower","The tower to the east is truly a wonder to behold.  "+
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