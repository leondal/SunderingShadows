//After discussion with other Imms, creating newbie-only potions
//to help out newbies ~Circe~ 6/3/07 

#include <std.h>
#include <move.h>
#include "/d/common/common.h"
#define VALUE 12

inherit KIT;

void create() {
  ::create();
  set_name("brilliant blue vial");
  set_short("%^BOLD%^%^BLUE%^A kit of brilliant blue healing vials%^RESET%^");
  set_id(({"brilliant blue","vial","potion","kit","kitabc","blue","blue vial","brilliant blue vial"}));
  set_long("%^BOLD%^%^BLUE%^The brilliant blue liquid contained in this kit's "
	   "vials is smooth but bitter.  ");
  set_pot_visual("blue vials");
  set("color", "brilliant blue");
  closed = 0;  
  uses = 1;
  toggle = 0;
  set_weight(2);
  set_cointype("gold");
  set_newbie_restricted(1);
}

// these would be the old functions, unused now since Garrett's fix
// probably can't comment them out because they overload the super (?)
int do_effect() {
   if(!objectp(drinker)) return 1;
   tell_object(drinker, "The potion seems to cool your body.");
   drinker->add_hp(roll_dice(2,4)+3);
//   if(!uses) remove();
   return 1;
}

int potion_effect() {
   int temp;
   do_effect();
   return 1;
}

void new_do_effect(object drinker) {
  int healing;
  if(!objectp(drinker)) return 1;
  drinker->remove_property("stomached_kits");
  if(drinker->query_hp() < drinker->query_max_hp()) {
    healing = roll_dice(2,4)+3;
    tell_object(drinker,"Suddenly, you begin to feel better.");
    tell_object(drinker,"You have gained back "+healing+" hit points.");
    drinker->add_hp(healing);
  } else {
    tell_object(drinker,"You feel no different than before.") ;
  }
  return 1;
}
