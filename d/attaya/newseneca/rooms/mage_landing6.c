//~Circe~ 1/3/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit MAGELANDING;

void create(){
   ::create();
   set_long(::query_long()+"\nA broader %^CYAN%^walkway %^RESET%^"+
      "leads eastward to an impressive set of %^BOLD%^double "+
      "doors%^RESET%^.  The spiral staircase leads up from here "+
      "through an opening in the ceiling above.\n");
   add_item("walkway","%^CYAN%^The glassteel walkway leading to the east has "+
         "no rails of any kind.  It appears extremely thin, and "+
         "it looks as though the weight of a person might cause "+
         "it to crack.  Thankfully, this particular walkway "+
         "is about twice as wide as the others - a nice trait, "+
         "given the incredible height above the floor below.%^RESET%^");
   set_exits(([
      "down" : ROOMS"mage_landing5",
      "up" : ROOMS"mage_shrine",
      "east" : ROOMS"mage_combat"
   ]));
   set_door("double doors","/d/attaya/newseneca/rooms/mage_combat","east",0,0);
   set_door_description("double doors","Double doors guard the entrance to "+
      "the eastern room.  They are quite unique in construction "+
      "and seem to have been made not of "+
      "wood but of metal, which is common enough.  The glaring "+
      "difference is that the surface of the metal shifts and "+
      "flows, giving it the appearance of %^BOLD%^m%^RESET%^o"+
      "%^BOLD%^l%^RESET%^t%^BOLD%^e%^RESET%^n %^BOLD%^m%^RESET%^i"+
      "%^BOLD%^t%^RESET%^h%^BOLD%^r%^RESET%^i%^BOLD%^l%^RESET%^.");
}