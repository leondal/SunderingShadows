#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/rapier.c";
int hit_func;
int wield_func;
int unwield_func;
int elec;

void create() {
   ::create();
   set_id(({ "rapier","sword","lightning rapier","storm sword","storm rapier","lightning sword"}));
   set_name("%^BOLD%^%^BLACK%^St%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^rm r%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^p%^RESET%^i%^BOLD%^%^BLACK%^er%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^St%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^rm r%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^p%^RESET%^i%^BOLD%^%^BLACK%^er%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A %^BLACK%^darkened rapier%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This small blade is dull grey in color but is exquisitely made. Lightweight and perfectly balanced, the weapon appears as though it would compliment almost any wielder, but will be deadly within the right hands.  Small barbs run the length of the blade, and small little flecks of %^YELLOW%^energy %^BLACK%^dance along the surface between them as if a constant %^RESET%^%^CYAN%^st%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^rm %^BOLD%^%^BLACK%^were brewing within the darkened steel itself.");
   set_value(0);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
   set_hit((:TO,"hit_func":));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   elec = 0;
   set_overallStatus(220);
   set_property("no disenchant",1);
}
int wield_func(){
   tell_object(ETO,"%^YELLOW%^The energy of the elements surge through you as the blade in your hand comes to life!%^RESET%^");
   tell_room(environment(ETO),"%^CYAN%^"+ETO->query_cap_name()+"'s blade seems to surge with life as "+ETO->query_subjective()+" takes hold of the weapon!%^RESET%^",ETO);
   return 1;
}
int unwield_func(){
   if(elec == 1){  
      tell_object(ETO,"%^YELLOW%^The surge of electrical energy within the blade dies down as you unwield it.%^RESET%^");
      tell_room(environment(ETO),"%^YELLOW%^The surge of energy within "+ETO->query_cap_name()+"'s blade dies down as "+ETO->query_subjective()+" unwields it.%^RESET%^",ETO);
      elec = 0;
   return 1;
   }
   else{
      tell_object(ETO,"%^CYAN%^You feel a sense of disappointment as you unwield the blade and feel the absence of energy it gave you.%^RESET%^");
      tell_room(environment(ETO),"%^CYAN%^The bouncing energy of "+ETO->query_cap_name()+"'s blade finally dies down as "+ETO->query_subjective()+" unwields the weapon.%^RESET%^",ETO);
      return 1;
   }
}
int hit_func(object target) 
{
   object ob;
   if(!objectp(target)) return 0;
   if(!objectp(ETO)) { return 0; }
   if(!living(ETO)) { return 0; }
   if(random(1000) < 400){
      switch(random(15)){
         case 0..4:
             tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^"+ETOQCN+" deftly thrusts "+ETO->query_possessive()+" rapier into "+target->QCN+"!",({ETO,target}));
             tell_object(ETO,"%^BOLD%^%^GREEN%^You deftly thrust your rapier into "+target->QCN+"!");
             tell_object(target,"%^BOLD%^%^GREEN%^"+ETOQCN+" deftly thrusts "+ETO->query_possessive()+" rapier into you!");
             if(!objectp(target)) return roll_dice(1,6);
             ob = new("/d/token_hunt/obj/low/rapierdam.c");
             ob->set_target(target);
             ob->move(target);
             return roll_dice(1,6);
         case 5..11:
  	        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" seems to catch the fury of the %^RESET%^%^CYAN%^st%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^rms %^BOLD%^%^BLACK%^as "+ETO->query_subjective()+" picks up the speed of the winds and whirls the weapon quickly around to thrust at "+target->query_cap_name()+" again!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^Your blade seems to lend you the %^RESET%^%^RED%^fury %^BOLD%^%^BLACK%^of the %^RESET%^%^CYAN%^st%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^rms %^BOLD%^%^BLACK%^as you pick up the speed of the winds and whirl the blade around to hit "+target->query_cap_name()+" again!%^RESET%^",({environment(ETO),target}));
            tell_object(target, "%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" seems to gain the %^RESET%^%^RED%^fury %^BOLD%^%^BLACK%^of the %^RESET%^%^CYAN%^st%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^rms %^BOLD%^%^BLACK%^as "+ETO->query_subjective()+" spins the blade quickly around to thrust at you again!%^RESET%^",({environment(ETO),ETO}));
            ETO->execute_attack();
		    return roll_dice(1,8)+1;
 	   case 12..14:
            if (environment(ETO)->query_property("indoors")&& elec == 0) 
            {
  	            tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+"'s rapier seems to suck up the energy from around it before firing it violently towards "+target->query_cap_name()+"!",({target,ETO}));
                tell_object(ETO,"%^YELLOW%^Your rapier seems to suck up the energy from around it before firing it violently towards "+target->query_cap_name()+"!%^RESET%^",({environment(ETO),target}));
                tell_object(target, "%^YELLOW%^"+ETO->query_cap_name()+"'s rapier seems to suck up the energy around it before firing it violently towards you!%^RESET%^",({environment(ETO),ETO}));
		        return roll_dice(1,10)+1;
            }
            else if (!environment(ETO)->query_property("indoors")&& elec == 0) 
            {
  	            tell_room(environment(ETO),"%^RESET%^CYAN%^The energy of "+ETO->query_cap_name()+"'s rapier begins to shift and dance around as the %^BOLD%^%^BLACK%^clouds %^RESET%^%^CYAN%^above begin to swirl and take form, sending a %^YELLOW%^bolt of lightning %^RESET%^%^CYAN%^down into the blade, %^YELLOW%^electrifying %^RESET%^%^CYAN%^it!",ETO);
                tell_object(ETO,"%^RESET%^%^CYAN%^The energy of your rapier begins to shift and dance around as the %^BOLD%^%^BLACK%^clouds %^RESET%^%^CYAN%^above begin to swirl and take form, sending a %^YELLOW%^bolt of lightning %^RESET%^%^CYAN%^into the blade, %^YELLOW%^electrifying %^RESET%^it!",({environment(ETO),target}));
		        elec = 1;
            }
            else
            {
               switch(random(3)){
                  case 0:
  	               tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+"'s sword crackles with electrical energy as it strikes "+target->query_cap_name()+"!",({target,ETO}));
                     tell_object(ETO,"%^YELLOW%^Your sword crackles with electrical energy as it hits "+target->query_cap_name()+"!%^RESET%^",({environment(ETO),target}));
                      tell_object(target, "%^YELLOW%^"+ETO->query_cap_name()+"'s sword crackles with electrical energy as it strikes you!%^RESET%^",({environment(ETO),ETO}));
		          return roll_dice(1,10)+1;
                   case 1:
  	                tell_room(environment(ETO),"%^YELLOW%^A loud %^WHITE%^POP %^YELLOW%^can be heard as "+ETO->query_cap_name()+"'s weapon strikes "+target->query_cap_name()+", causing small surges of electrical energy to dance along the blade!",({target,ETO}));
                      tell_object(ETO,"%^YELLOW%^A loud %^WHITE%^POP %^YELLOW%^can be heard as you strike "+target->query_cap_name()+" with the rapier, causing small surges of electrical energy to dance along the length of the blade!%^RESET%^",({environment(ETO),target}));
                       tell_object(target, "%^YELLOW%^A loud %^WHITE%^POP %^YELLOW%^ can be heard coming from "+ETO->query_cap_name()+"'s weapon as it strikes you, causing small surges of electrical energy to dance along the length of the blade!%^RESET%^",({environment(ETO),ETO}));
		           return roll_dice(1,10)+1;
                   case 2:
  	                tell_room(environment(ETO),"%^YELLOW%^The pent up energy in "+ETO->query_cap_name()+"'s sword comes to a crest at the tip of the blade before shooting out at "+target->query_cap_name()+" in a forceful explosion of power before the sword once again goes quiet!",({target,ETO}));
                      tell_object(ETO,"%^YELLOW%^The pent up energy in the weapon seems to gather at the tip of the blade and suddenly shoots out at "+target->query_cap_name()+" in a forceful explosion of power before the rapier once again goes quiet!%^RESET%^",({environment(ETO),target}));
                       tell_object(target, "%^YELLOW%^The pent up energy of "+ETO->query_cap_name()+"'s weapon seems to crest at the tip of the blade before shooting out towards you in a forceful explosion of power before the rapier once again goes quiet!%^RESET%^",({environment(ETO),ETO}));
                       elec = 0;
		           return roll_dice(2,10)+1;
            }
         return 1;
         } 
      }
   }
}
