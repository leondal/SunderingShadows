#include <std.h>
inherit "/d/common/obj/weapon/whip.c";

void create() {
    ::create();
   set_id(({"vinewhip","whip"}));
   set_name("vinewhip");
   set_obvious_short("A whip");
   set_short("%^GREEN%^A vinewhip%^RESET%^");
   set_long("%^GREEN%^This whip is made out of twisted %^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^i%^ORANGE%^n%^GREEN%^e%^BOLD%^%^GREEN%^s, %^RESET%^%^GREEN%^complete with razor-sharp leaves that look like they could provide a powerful lashing.%^RESET%^");
   set("value",700);
   set_cointype("gold");
   set_property("enchantment",random(2)+1);
   set_item_bonus("attack bonus",1);
   set_item_bonus("damage bonus",1);
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   if((int)ETO->query_level() < 10) {
      tell_object(ETO,"%^GREEN%^You are not strong enough to control the wildly thrashing vines!");
                return 0;
   }
      tell_room(environment(ETO),"%^GREEN%^The vines start to come to life as "+ETOQCN+" wields their whip.%^RESET%^",ETO);
      tell_object(ETO,"%^GREEN%^The vines of the whip begin to come to life as you wield it.%^RESET%^");
                return 1;
}
int unwield_func(){
   tell_room(environment(ETO),"%^GREEN%^The whip becomes limp as "+ETOQCN+" unwields it.",ETO);
    tell_object(ETO,"The vines of the whip become limp as you unwield it.");
                return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(1000) < 215){
      switch(random(8)){
         case 0..3:
            tell_room(environment(ETO),"%^GREEN%^The whip takes on a life of its own as it lashes out at "+target->query_cap_name()+"!%^RESET%^",({target,ETO}));
            tell_object(ETO,"The whip takes on a life of its own as it lashes out at "+target->query_cap_name()+"!%^RESET%^",target);
            tell_object(target, "%^GREEN%^The whip in "+ETO->query_cap_name()+"'s hand takes on a life of its own as it lashes out at you!%^RESET%^");
		  return roll_dice(1,4)+1;
 	   case 4..6:
              tell_room(environment(ETO),"%^GREEN%^The whip in "+ETO->query_cap_name()+"'s hand hisses as it hits "+target->query_cap_name()+"!%^RESET%^",({target,ETO}));
            tell_object(ETO,"The whip hisses as it hits "+target->query_cap_name()+"!%^RESET%^");
            tell_object(target, "%^GREEN%^The whip in "+ETO->query_cap_name()+"'s hand hisses as it digs into your flesh!%^RESET%^");
		  return roll_dice(1,4)+1;
         case 7:
            tell_room(environment(ETO),"%^BOLD%^%^GREEN%^The whip wraps around "+target->query_cap_name()+"s legs and pulls "+target->query_possessive()+" off of "+target->query_possessive()+" feet!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^GREEN%^The whip wraps around "+target->query_cap_name()+"'s legs and pulls "+target->query_objective()+" off of "+target->query_possessive()+" feet!%^RESET%^",target);
            tell_object(target, "%^BOLD%^%^GREEN%^The whip held by "+ETO->query_cap_name()+" wraps around your legs and pulls you from your feet!");
//target->set_paralyzed(20,"You are trying to get to your feet.");
//changing the paralyzed based on several reports of it being too powerful Circe 11/27/07
            target->set_tripped(1+random(2),"You are trying to get to your feet.");
                 return roll_dice(1,4)+1;
      }
   }
}
//attempted to change "+ETO->query_cap_name()+" to ETOQCN, but only got errors, so I changed it back
