//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>
#include <move.h>

inherit KIT;


//int uses, toggle;

void create() {
   ::create();
   set_name("glowing golden vial");
   set_obvious_short("%^BOLD%^%^YELLOW%^A kit of glowing golden potions%^RESET%^");
    set_long("%^BOLD%^%^YELLOW%^The glowing golden liquid contained in this kit's vials is sweet and honeylike.");
   set_short("%^BOLD%^%^YELLOW%^Potion of Legendary Healing%^RESET%^");
   set_id(({"golden","glowing golden","vial","potion","kit","kitxyz","golden potions","glowing golden potions","potion of legendary healing"}));
   set_lore("This potion is one crafted by many healers of the land.  "+
	    "Because of the ingredients used, such potions often have "+
	    "similar qualities, such as color and smell.  The color of "+
	    "this potion suggests it might be used to cure a awesome deal of "+
	    "damage.");
   set_property("lore difficulty",32);
   set("color", "%^YELLOW%^glowing golden");
   set_pot_visual("glowing golden vial");
   set("effect_time",__COMBAT_SPEED__*2+2);
   uses = 1;
   toggle = 0;
   set_value(200);
   set_weight(1);
}

void new_do_effect(object drinker) {
  int healing;
  if(!objectp(drinker)) return 1;
    drinker->remove_property("stomached_kits");
  if(drinker->query_hp() < drinker->query_max_hp()) {
    healing = roll_dice(3,20)+20;
    tell_object(drinker,"Suddenly, you begin to feel better.");
    tell_object(drinker,"You have gained back "+healing+" hit points.");
    drinker->add_hp(healing);
  } else {
    tell_object(drinker,"You feel no different than before.") ;
  }
  return 1;
}
