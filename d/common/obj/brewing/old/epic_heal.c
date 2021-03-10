//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>
#include <move.h>

inherit KIT;


//int uses, toggle;

void create() {
   ::create();
   set_name("brilliant rose vial");
   set_obvious_short("%^BOLD%^%^MAGENTA%^A kit of brilliant rose potions%^RESET%^");
    set_long("%^BOLD%^%^MAGENTA%^The brilliant rose liquid contained in this kit's vials is sharp and cool, but fragrant.");
   set_short("%^BOLD%^%^MAGENTA%^Potion of Advanced Extra Healing%^RESET%^");
   set_id(({"rose","brilliant rose","vial","potion","kit","kitxyz","rose potions","brilliant rose potions","potion of advanced extra healing"}));
   set_lore("This potion is one crafted by many healers of the land.  "+
	    "Because of the ingredients used, such potions often have "+
	    "similar qualities, such as color and smell.  The color of "+
	    "this potion suggests it might be used to cure a extreme deal of "+
	    "damage.");
   set_property("lore difficulty",22);
   set("color", "%^MAGENTA%^brilliant rose");
   set_pot_visual("brilliant rose vial");
   set("effect_time",__COMBAT_SPEED__*2+2);
   uses = 1;
   toggle = 0;
   set_value(300);
   set_weight(2);
}

void new_do_effect(object drinker) {
  int healing;
  if(!objectp(drinker)) return 1;
    drinker->remove_property("stomached_kits");
  if(drinker->query_hp() < drinker->query_max_hp()) {
    healing = roll_dice(4,12)+6;
    tell_object(drinker,"Suddenly, you begin to feel better.");
    tell_object(drinker,"You have gained back "+healing+" hit points.");
    drinker->add_hp(healing);
  } else {
    tell_object(drinker,"You feel no different than before.") ;
  }
  return 1;
}
