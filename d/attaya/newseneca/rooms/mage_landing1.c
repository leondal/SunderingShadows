//~Circe~ 1/2/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit MAGELANDING;

void create(){
   ::create();
   set_long(::query_long()+"\nTo the east here is a room with "+
      "a %^BOLD%^%^WHITE%^large door %^RESET%^set within the "+
      "%^BOLD%^%^BLACK%^gray stone walls%^RESET%^.  The room "+
      "looks quite strange, as the floor seems to be hovering "+
      "in mid-air twenty feet above the floor of the chamber below.\n");
   set_exits(([
      "down" : ROOMS"mage_entry",
      "up" : ROOMS"mage_landing2",
      "east" : ROOMS"mage_meeting"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/mage_meeting","east",0,0);
   set_door_description("door","The door in the eastern wall is "+
      "unique in construction.  It seems to have been made not of "+
      "wood but of metal, which is common enough.  The glaring "+
      "difference is that the surface of the metal shifts and "+
      "flows, giving it the appearance of %^BOLD%^m%^RESET%^o"+
      "%^BOLD%^l%^RESET%^t%^BOLD%^e%^RESET%^n %^BOLD%^m%^RESET%^i"+
      "%^BOLD%^t%^RESET%^h%^BOLD%^r%^RESET%^i%^BOLD%^l%^RESET%^.");
}