//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
#include "../dragon.h"

inherit "/d/common/obj/weapon/dagger.c";
void create(){
   ::create();
   set_id(({"dagger","dagger of returning","returning dagger","throwing dagger"}));
   set_name("dagger");
   set_obvious_short("%^BOLD%^%^BLUE%^A sapphire hilted dagger%^RESET%^");
   set_short("%^BOLD%^%^BLUE%^Dagger %^BOLD%^%^WHITE%^of %^RESET%^re%^BOLD%^%^WHITE%^t%^BOLD%^%^BLUE%^u%^RESET%^rn%^BOLD%^%^WHITE%^in%^BOLD%^%^BLUE%^g%^RESET%^");
   set_long(
      "%^RESET%^This is a small dagger with tiny %^BOLD%^%^BLUE%^sapphires %^RESET%^embedded into"+
      " the hilt. The blade is sharpened to a %^BOLD%^%^WHITE%^keen edge %^RESET%^on both sides and the point"+
      " honed to a %^RESET%^%^MAGENTA%^deadly tip%^RESET%^."
   );
   set_lore(
      "This dagger was made by Leica Kelun, a mage of the Arcane Brotherhood."+
      " Leica was an accomplished mage as well as a expert knife thrower. She"+
      " made this dagger to make practicing easier."
   );
   set_property("lore",9);
  // set_type("piercing");
  // set_prof_type("small blades");
  // set_weight(4);
  // set_size(1);
  // set_wc(1,6);
  // set_weapon_speed(1);
 //  set_large_wc(1,6);
   set_property("enchantment",3+random(2));
   set_value(1900);
   set_wield((:TO,"wieldit":));
   set_unwield((:TO,"unwieldit":));
   set_hit((:TO,"hitit":));
}
int wieldit() {
   tell_object(ETO,"%^BOLD%^%^BLUE%^You grip the hilt of the small dagger.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+" firmly grips the hilt of the small dagger.%^RESET%^",ETO);
   return 1;
}
int unwieldit() {
   tell_object(ETO,"%^BOLD%^%^BLUE%^You reluctantly release the dagger.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" unwraps "+ETO->query_possessive()+" fingers from the hilt of the small dagger.%^RESET%^",ETO);
   return 1;
}
int hitit(object targ){
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	if(random(1000) < 200){
      		tell_object(ETO,"%^BOLD%^%^BLUE%^In the midst of combat you"+
			" flip the dagger, hilt side up, and throw it at"+
			" "+targ->QCN+"! The dagger then reappears in your "+
			"hand after making contact!%^RESET%^");
   		tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+" suddenly throws"+
			" "+ETO->QP+" dagger at you, but it magically reappears "+
			"in "+ETO->QP+" hand after making contact!%^RESET%^");
   		tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+" "+
			"suddenly throws "+ETO->QP+" dagger at "+targ->QCN+", "+
			"but the dagger reappears in "+ETO->QP+" hand after "+
			"making contact!%^RESET%^",({ETO,targ}));
   				return roll_dice(2,6)+2;   
	 }
}
