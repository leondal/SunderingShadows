#include <std.h>
inherit "/d/common/obj/weapon/club_lg.c";



void create() {
    ::create();
   set_id(({"club","club of the giants"}));
   set_name("%^BOLD%^%^BLACK%^Club %^RESET%^of the %^ORANGE%^G%^BOLD%^%^WHITE%^i%^RESET%^a%^BOLD%^%^BLACK%^n%^RESET%^t%^ORANGE%^s%^RESET%^");
   set_obvious_short("A very large club");
   set_short("%^BOLD%^%^BLACK%^Club %^RESET%^of the %^ORANGE%^G%^BOLD%^%^WHITE%^i%^RESET%^a%^BOLD%^%^BLACK%^n%^RESET%^t%^ORANGE%^s%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is a very large club exquistely crafted from a"
" %^RESET%^g%^BOLD%^%^WHITE%^le%^RESET%^ami%^BOLD%^%^WHITE%^n%^RESET%^g"
" %^BOLD%^%^BLACK%^obsidian metal that %^WHITE%^shines %^BLACK%^in the light. Large"
" %^BOLD%^%^WHITE%^di%^CYAN%^a%^WHITE%^mo%^CYAN%^n%^WHITE%^d-studded spikes"
" %^BLACK%^catch your eye as they %^WHITE%^sp%^CYAN%^a%^WHITE%^r%^CYAN%^k%^WHITE%^le"
" %^BLACK%^from the head of the club and contrast the darkened metal.  The handle"
" of the club curves into a slender grip for easy handling and is engraved with"
" %^RESET%^%^CYAN%^ancient runes %^BOLD%^%^BLACK%^that shift in form and"
" %^RESET%^%^CYAN%^gl%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^w %^BOLD%^%^BLACK%^with"
" their own inner %^RESET%^%^CYAN%^magic.%^RESET%^");
   set("value",1500);
   set_cointype("gold");
   set_property("enchantment",3);  
   set_item_bonus("attack bonus",1);
   set_item_bonus("damage bonus",1);
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   if((int)ETO->query_level() < 20 && !ETO->id("hill giant")) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The club refuses to let you hold it and bonks you instead%^RESET%^!");
      ETO->do_damage("torso",random(25)+25);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
   return 0;
   }
      tell_room(environment(ETO),"%^RESET%^%^CYAN%^The runes on the club begin to %^BOLD%^%^CYAN%^glow %^RESET%^%^CYAN%^as "+ETOQCN+" wields the club.%^RESET%^",ETO);
      tell_object(ETO,"%^RESET%^%^CYAN%^The runes on the club begin to %^BOLD%^%^CYAN%^glow %^RESET%^%^CYAN%^as you wield it.%^RESET%^");
                return 1;
}
int unwield_func(){
   tell_room(environment(ETO),"%^RESET%^%^CYAN%^%^The runes on the club begin to fade as "+ETOQCN+" unwields it.%^RESET%^",ETO);
    tell_object(ETO,"%^RESET%^%^CYAN%^The runes on the club begin to fade as you unwield it%^RESET%^.");
                return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(10) < 1){
      switch(random(5)){
         case 0..1:
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The club smacks "+target->query_cap_name()+" with tremendous force!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^The club smacks "+target->query_cap_name()+" with tremendous force!%^RESET%^",target);
            tell_object(target, "%^BOLD%^%^BLACK%^The club wielded by "+ETO->query_cap_name()+" smacks you hard!%^RESET%^");
		  return roll_dice(2,8)+2;
 	   case 2..3:
  	      tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The diamond spikes of the club %^WHITE%^flash %^CYAN%^as they find their mark!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^CYAN%^The diamond edges of the club %^WHITE%^flash %^CYAN%^as they hit "+target->query_cap_name()+"!%^RESET%^");
            tell_object(target, "%^BOLD%^%^CYAN%^The diamond edges on the club %^WHITE%^flash %^CYAN%^as they dig into your flesh!%^RESET%^");
		  return roll_dice(2,8)+2;
         case 4:
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The club cackles as it hits "+target->query_cap_name()+" squarely, sending bits of "+target->query_possessive()+" %^RESET%^%^RED%^flesh %^BOLD%^%^BLACK%^flying in all directions!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^The club cackles and shakes violently in your hands as it hits "+target->query_cap_name()+" sqaurely, sending bits of "+target->query_possessive()+" %^RESET%^%^RED%^flesh %^BOLD%^%^BLACK%^flying in several directions!%^RESET%^",target);
            tell_object(target, "%^BOLD%^%^BLACK%^The club held by "+ETO->query_cap_name()+" cackles insanely as it hits you hard, sending pieces of your %^RESET%^%^RED%^flesh %^BOLD%^%^BLACK%^flying in all directions, leaving you in a daze!");
            target->set_paralyzed(30,"You still can't see straight!");
            return roll_dice(2,10)+4;
      }
   }
}


