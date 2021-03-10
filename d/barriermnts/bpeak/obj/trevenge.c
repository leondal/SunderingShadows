#include <std.h>

inherit "/d/common/obj/weapon/bill-guisarme.c";

void create() {
    ::create();
   set_id(({ "bill-guisarme","polearm","pole","hook","titan's revenge","revenge","Titan's revenge" }));
   set_name("%^RESET%^%^RED%^Titan's revenge%^RESET%^");
   set_short("%^RESET%^%^RED%^Titan's revenge%^RESET%^");
   set_obvious_short("%^RESET%^A wicked looking bill-guisarme");
   set_long("%^RESET%^This long pole arm has been designed with dual use in mind.  On one end sits a %^BOLD%^%^BLACK%^blackened %^RESET%^combination %^BOLD%^%^BLACK%^hammer %^RESET%^with a %^BOLD%^%^BLACK%^spiked counterweight %^RESET%^on one end, while on the other is a wickedly curved %^BOLD%^hook.  %^RESET%^The %^BOLD%^shaft %^RESET%^of the polearm is made out of some sort of %^BOLD%^shining metal, %^RESET%^with two %^ORANGE%^grips %^RESET%^made out of %^ORANGE%^leather %^RESET%^about a foot apart near the center.");
   set_value(1000);
   set_cointype("gold");
   set_property("enchantment",3);  
   set_wield((:TO,"wield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   if((int)ETO->query_level() < 15) {
      tell_object(ETO,"%^RESET%^%^RED%^You do not have the power to wield such an awesome weapon yet!%^RESET%^");
                return 0;
   }
      tell_room(environment(ETO),"%^RED%^"+ETOQCN+" grips the polearm with both hands and spins it expertly.%^RESET%^",ETO);
      tell_object(ETO,"%^RESET%^%^RED%^You grab the grips of the polearm and spin it expertly.%^RESET%^");
                return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(1000) < 100){
      switch(random(5)){
         case 0..1:
  	      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" quickly spins around and smashes "+target->query_cap_name()+" with the hammer end of the polearm!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^You spin around to knock "+target->query_cap_name()+" mercilessly with the hammer end of your weapon!%^RESET%^",target);
            tell_object(target,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" spins around to bring the hammer end of his weapon crushing into you!%^RESET%^");
          
         break ;
 	   case 2..3:
  	      tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETO->query_cap_name()+" pulls the polearm up over "+ETO->query_possessive()+" head and brings the spiked end down upon "+target->query_cap_name()+" with a savage blow!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^RED%^You pull the polearm up over your head and bring it down upon "+target->query_cap_name()+" with a savage blow!%^RESET%^");
            tell_object(target,"%^RESET%^%^RED%^"+ETO->query_cap_name()+" pulls the polearm up over "+ETO->query_possessive()+" and quickly brings it down upon you in a savage blow!%^RESET%^");
           
         case 4:
            tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" ducks down low as "+ETO->query_subjective()+" spins the polearm around to sweep the hook end of "+ETO->query_possessive()+" weapon quickly beneath "+target->query_cap_name()+"'s feet!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^CYAN%^You duck down low and spin the polearm quickly around to sweep the hook end of the weapon beneath  "+target->query_cap_name()+"'s feet!%^RESET%^",target);
            tell_object(target, "%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" ducks down low and spins the polearm around before quickly sweeping the hook end of "+ETO->query_possessive()+" weapon beneath your feet!");
            if(!"/daemon/saving_throw_d.c"->fort_save(target,-20))
              target->set_tripped(1,"You are still trying to stand up!");
           
      }
   }
   return random(5)+1;
}
