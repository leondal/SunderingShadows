//~Circe~ 1/2/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit MAGELANDING;

void create(){
   ::create();
   set_long(::query_long()+"\nDelicious smells of cooking food "+
      "linger lightly in the air, emanating from the %^BOLD%^"+
      "doorway %^RESET%^to the east.\n");
   set_exits(([
      "down" : ROOMS"mage_landing4",
      "up" : ROOMS"mage_landing6",
      "east" : ROOMS"mage_kitchen"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/mage_kitchen","east",0,0);
   set_door_description("door","The door in the eastern wall is "+
      "unique in construction.  It seems to have been made not of "+
      "wood but of metal, which is common enough.  The glaring "+
      "difference is that the surface of the metal shifts and "+
      "flows, giving it the appearance of %^BOLD%^m%^RESET%^o"+
      "%^BOLD%^l%^RESET%^t%^BOLD%^e%^RESET%^n %^BOLD%^m%^RESET%^i"+
      "%^BOLD%^t%^RESET%^h%^BOLD%^r%^RESET%^i%^BOLD%^l%^RESET%^.");
}