/* getting rid of bottles for more realism & less spam *Styx*  12/29/05 */

#include <std.h>
#include <move.h>
#include "/d/common/common.h"
#define VALUE 20

inherit KIT;

//int uses, toggle;

/* I can't see any actual use of the toggle variable doing anything, anyone 
*  see what I'm missing or can we take it out?  *Styx*  12/29/05
*/

void create() {
  ::create();
  set_obvious_short("%^BOLD%^%^CYAN%^A kit of blue healing vials.%^RESET%^");
  set_name("blue vial");
  set_short("%^BOLD%^%^CYAN%^A kit of blue healing vials.%^RESET%^");
  set_id(({"blue","vial","potion","kit","kitxyz","blue healing vials","blue vials"}));
  set_long("%^BOLD%^%^CYAN%^The pale blue liquid contained in this kit's "
	   "vials is smooth but bitter.  ");
  set_pot_visual("blue vials");
  set("color", "blue");
  closed = 0;  // added by *Styx* to simplify use and go with adapted describe
  uses = 1;
  toggle = 0;
  set_weight(2);
  set_cointype("gold");
}

// these would be the old functions, unused now since Garrett's fix
// probably can't comment them out because they overload the super (?)
int do_effect() {
   if(!objectp(drinker)) return 1;
   tell_object(drinker, "The potion seems to cool your body.");
   drinker->add_hp(roll_dice(2,6)+4);
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
    healing = roll_dice(2,6)+4;
    tell_object(drinker,"Suddenly, you begin to feel better.");
    tell_object(drinker,"You have gained back "+healing+" hit points.");
    drinker->add_hp(healing);
  } else {
    tell_object(drinker,"You feel no different than before.") ;
  }
  return 1;
}
