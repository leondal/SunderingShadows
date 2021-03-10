//Octothorpe (1/30/09)
//Underdark Mining Caverns, Mangled Corpse
//Based on Loki's corpses in Ogre Caverns
///d/dagger/ogres/obj/corpse.c

#include <std.h>
#include "../defs.h"
inherit BAG;

void create(){
   ::create();
   set_name("decayed remains");
   set_id(({"remains","decayed remains"}));
   set_short("%^RED%^decayed remains%^RESET%^");
   set_long("%^RED%^It is difficult to precisely determine which race "+
      "this person belonged to in life. The skin and muscle have been "+
      "picked away, leaving behind only a bloody mess.%^RESET%^\n");
   set_property("no_animate",1);
   set_weight(5000);
   set_value(0);
   set_max_internal_encumbrance(50);
   switch(random(3)){
      case 0: new(OBJ"gnochain")->move(TO);
         break;
      case 1: new(OBJ"gnojack")->move(TO);
         break;
      case 2: new(OBJ"kobstudded")->move(TO);
         break;
      default: new(OBJ"gnochain")->move(TO);
         break;
   }
}