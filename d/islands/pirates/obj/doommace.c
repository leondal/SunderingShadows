#include <std.h>
inherit "/d/common/obj/weapon/mace";

void create(){
   ::create();
   set_id(({"mace of doom","doom","mace"}));
   set_name("%^RESET%^%^BLUE%^Mace of Doom%^RESET%^");
   set_short("%^RESET%^%^BLUE%^Mace of Doom%^RESET%^");
   set_obvious_short("A black mace");
   set_long("%^BLUE%^This mace is made from the very stuff of blackness.  Your skin feels frigid while it "
"touches this %^BOLD%^%^BLACK%^weapon%^RESET%^%^BLUE%^.  You can it feel willing you to commit acts of such "
"hatred that Xvim will take heed and recognize you as one of his own.%^RESET%^");
   set_property("enchantment",2);
   set("value",500);
   set_wield((:TO,"wield_fun":));
   set_hit((: TO,"extra_hit" :));
}

int wield_fun(string str){
   if(ALIGN->is_good(ETO)){
     tell_object(ETO,"You would never wield that evil thing!");
     return 0;
   }

   if(!ETO->query_diety() || (string)ETO->query_diety()=="xvim"){
     tell_object(ETO,"%^BLUE%^You feel your soul wrench as you wield the evil mace.%^RESET%^");
     tell_room(EETO,"%^BLUE%^"+TPQCN+"'s eyes begin to %^RED%^glow%^BLUE%^ as "+TP->QS+" wields the black "
"mace.%^RESET%^",ETO);
     return 1;
   }
   tell_object(ETO,"Your diety would not approve of that!");
   return 0;
}

int extra_hit(object targ){
   targ = ETO->query_current_attacker();
   if(!random(4)) {
     if(ALIGN->is_good(targ)) {
       tell_object(ETO,"%^BLUE%^Your mace %^BOLD%^glows%^RESET%^%^BLUE%^ as you smite the forces of good!"
"%^RESET%^");
	 tell_object(targ,"%^BLUE%^Your soul cries out as you are stuck by "+ETOQCN+"'s black mace!");
       tell_room(EETO,"%^BLUE%^"+targ->QCN+" cries out in agony as "+ETOQCN+" stikes "+targ->QS+" with the "
"black mace!%^RESET%^",(({ETO,targ})));
       return(roll_dice(2,4));
     }
     return 0;
   }
}
