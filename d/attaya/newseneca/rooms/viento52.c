//viento52 - Circe 11/10/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
   set_long(::query_long()+"Rising above the busy Seneca streets to the "+
      "north is an impressive %^BOLD%^%^BLACK%^tower%^RESET%^ rising above the "+
      "tall inn in the background.  The shop to the south features wide "+
      "%^CYAN%^windows %^RESET%^painted with images of happy, playful "+
         "%^RESET%^%^ORANGE%^animals %^RESET%^cavorting on a "+
         "%^GREEN%^grassy field%^WHITE%^ with the shop's name written "+
         "in %^BOLD%^%^BLUE%^blue print%^RESET%^.  %^YELLOW%^S%^WHITE%^t"+
         "%^YELLOW%^r%^WHITE%^i%^YELLOW%^p%^WHITE%^e%^YELLOW%^d "+
         "%^WHITE%^a%^YELLOW%^w%^WHITE%^n%^YELLOW%^i%^WHITE%^n"+
         "%^YELLOW%^g%^WHITE%^s %^RESET%^cover the windows, allowing "+
         "occasional glimpses of the store within.\n");
   set_exits(([
      "west" : ROOMS"viento51",
      "east" : ROOMS"viento53",
      "north" : ROOMS"mage_entry",
      "south" : ROOMS"toystore"
   ]));
   set_door("tower door","/d/attaya/newseneca/rooms/mage_entry","north",0,0);
   set_door_description("tower door","The smooth %^BOLD%^%^BLACK%^gray stone "+
      "walls %^RESET%^of the tower are broken by these arched %^ORANGE%^"+
      "double doors%^RESET%^.  Carved along the edges of the deep brown "+
      "wood are %^BOLD%^%^CYAN%^mystical runes %^RESET%^filled with "+
      "molten %^BOLD%^silver%^RESET%^.  Matching %^BOLD%^silver handles "+
      "%^RESET%^are mounted side-by-side to allow entry, but the tower seems "+
      "almost to have a will of its own.");
   set_door("door","/d/attaya/newseneca/rooms/toystore","south",0);
   set_door_description("door","%^YELLOW%^The door to the south is painted "+
      "a soft, sunny yellow but is without further adornments.%^RESET%^");
   add_item("tower","%^BOLD%^%^BLACK%^Soaring high above the streets of "+
      "%^WHITE%^Seneca%^BLACK%^, the tower to the north nevertheless blends "+
      "in thanks to the multi-story inn just behind it.  A few small windows "+
      "can be seen along the tower as it climbs towards the sky.%^RESET%^");
   add_item("shop","%^ORANGE%^The small wooden shop to the south is clearly "+
      "a cheerful place, evidenced by the colorful windows depicting "+
      "happy animals dancing about in a field.  Above the image is the name "+
      "of the shop, %^BOLD%^%^BLUE%^Dolly's Treasures%^RESET%^%^ORANGE%^.%^RESET%^");
   add_item("toys","Visible through the %^CYAN%^windows %^RESET%^are a wide "+
      "variety of toys, from stuffed animals and toy wands to beautiful "+
      "music boxes.");
}