//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>
#include <move.h>

inherit KIT;


//int uses, toggle;

void create() {
   ::create();
   set_name("brilliant prismatic potion");
   set_obvious_short("%^BOLD%^%^WHITE%^A kit of %^RED%^p%^RESET%^"+
		"%^RED%^r%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^BOLD%^%^CYAN%^"+
		"a%^BOLD%^%^BLUE%^t%^MAGENTA%^i%^RESET%^%^MAGENTA%^c"+
		"%^BOLD%^%^WHITE%^ potions");
    set_long("%^BOLD%^%^WHITE%^The glowing %^RED%^p%^RESET%^"+
		"%^RED%^r%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^BOLD%^%^CYAN%^"+
		"a%^BOLD%^%^BLUE%^t%^MAGENTA%^i%^RESET%^%^MAGENTA%^c"+
		"%^BOLD%^%^WHITE%^ liquid contained in this kit's vials is "+
		"ethereal and as sweet as ambrosia.");
   set_short("%^BOLD%^%^WHITE%^Potion of Healing%^RESET%^");
   set_id(({"prismatic","glowing prismatic","vial","potion","kit","kitxyz","potion of healing","prismatic potion","brilliant prismatic potion"}));
   set_lore("This rare potion has become a lost, mythical accomplishment, even among the best healers of the land.  "+
	    "Because of the ingredients used, such potions are very expensive."+
		"  The color of this potion suggests it might be used to cure "+
		"an near mortal deal of damage.");
   set_property("lore difficulty",32);
   set("color", "%^RED%^p%^RESET%^"+
		"%^RED%^r%^ORANGE%^i%^YELLOW%^s%^GREEN%^m%^BOLD%^%^CYAN%^"+
		"a%^BOLD%^%^BLUE%^t%^MAGENTA%^i%^RESET%^%^MAGENTA%^c"+
		"%^BOLD%^%^WHITE%^");
   set_pot_visual("glowing prismatic vial");
   set("effect_time",__COMBAT_SPEED__*2+2);
   uses = 1;
   toggle = 0;
   set_value(3000);
   set_weight(1);
}

int max_kit_size() { return 5;}

void new_do_effect(object drinker) {
  int healing;
  if(!objectp(drinker)) return 1;
    drinker->remove_property("stomached_kits");
  if(drinker->query_hp() < drinker->query_max_hp()) {
    healing = (int)drinker->query_max_hp()-(int)drinker->query_hp();
    tell_object(drinker,"Suddenly, you begin to feel better.");
    tell_object(drinker,"You have gained back "+healing+" hit points.");
    drinker->add_hp(healing);
  } else {
    tell_object(drinker,"You feel no different than before.") ;
  }
  return 1;
}
