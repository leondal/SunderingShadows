//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>
#include <move.h>

inherit KIT;


//int uses, toggle;

void create() {
   ::create();
   set_name("bright white vial");
   set_obvious_short("%^BOLD%^%^WHITE%^A kit of bright white potions%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Potion of Extra Healing%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^The bright white liquid contained in this kit's vials is minty and refreshing.");
   set_id(({"white","bright white","vial","potion","kit","kitxyz","white potions","bright white potions","potion of extra healing"}));
   set_lore("This potion is one crafted by many healers of the land.  "+
	    "Because of the ingredients used, such potions often have "+
	    "similar qualities, such as color and smell.  The color of "+
	    "this potion suggests it might be used to cure a good deal of "+
	    "damage.");
   set_property("lore difficulty",12);
   set("color", "%^WHITE%^bright white");
   set_pot_visual("bright white vial");
   set("effect_time",__COMBAT_SPEED__*2+2);
   uses = 1;
   toggle = 0;
   set_value(100);
   set_weight(2);
}

void new_do_effect(object drinker) {
  int healing;
  if(!objectp(drinker)) return 1;
    drinker->remove_property("stomached_kits");
  if(drinker->query_hp() < drinker->query_max_hp()) {
    healing = roll_dice(3,10)+5;
    tell_object(drinker,"Suddenly, you begin to feel better.");
    tell_object(drinker,"You have gained back "+healing+" hit points.");
    drinker->add_hp(healing);
  } else {
    tell_object(drinker,"You feel no different than before.") ;
  }
  return 1;
}
