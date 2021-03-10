#include <std.h>
inherit "/d/common/obj/weapon/double_axe.c";

void create(){
  ::create();
  set_name("acid axe");
  set_id(({"axe","acid axe","double axe"}));
  set_obvious_short("%^RESET%^%^GREEN%^"+
    "gr%^BOLD%^ee%^RESET%^%^GREEN%^n double axe%^RESET%^");
  set_short("%^RESET%^%^GREEN%^Ac%^BOLD%^i%^RESET%^%^GREEN%^d axe%^RESET%^");
  set_long(
"This axe was built with strong metals to form a "+
"sturdy shaft between two full battle axes connected "+
"to each end of the weapon.  The weapon is "+
"completely tarnished with a %^GREEN%^green%^RESET%^ film on both "+
"axe heads.  Several %^BOLD%^%^BLACK%^black runes%^RESET%^ are etched into "+
"the two heads of the axe." );
  set_value(2000);
  set_lore("These weapons were created for dwarven"+
  " shock troops.  Dwarven smiths have mastered "+
  " a way to fuse and acidic ooze creature with "+
  " the head and cause it to drip corrosive acid.");
  set_property("lore difficulty",15);
  set_property("enchantment",2);
  set_wield((:TO,"wield_func":));
  set_unwield((:TO,"unwield_func":));
  set_hit((:TO,"hit_func":));
  set_item_bonus("acid resistance",2);
}

int wield_func(){
    if (!ETO->query_property("silent_wield")) {
        tell_room(EETO, "%^GREEN%^" + ETOQCN + " grips the double " +
            "axe and it starts dripping green fluid.", ETO);
        tell_object(ETO, "%^GREEN%^The axe heads moisten with acid.");
    }
    return 1;
}

int unwield_func(){
    if (!ETO->query_property("silent_wield")) {
        tell_room(EETO, "%^GREEN%^" + ETOQCN + " releases the axe " +
            "and the acid dries up.", ETO);
        tell_object(ETO, "%^GREEN%^" +
            "When you unwield the axe, the acid dries.");
    }
    return 1;
}

int hit_func(object targ){
     if(random(1000) < 250){
        tell_room(ETO, "%^GREEN%^"+ETOQCN+"'s "+
         "hacks deep into "+targ->QCN+" the wound"+
		 " hisses from acid.",({ETO,targ}));
        tell_object(ETO,"%^GREEN%^You hack "+
           targ->QCN+" and acid burns the wound further.");
        tell_object(targ,"%^GREEN%^"+
           "Acid from "+ETOQCN+"'s axe burns your flesh.");  
        targ->cause_typed_damage(targ,0,roll_dice(3,4),"acid");		 
				return 1;}
 
   return 0;
}
