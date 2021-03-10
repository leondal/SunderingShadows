#include <std.h>
inherit "/d/common/obj/weapon/shortsword";

int attacked;

void create(){
   ::create();
   set_id(({"sword of doom","doom","sword","short sword"}));
   set_name("%^RESET%^%^BLUE%^Sword of Doom%^RESET%^");
   set_short("%^RESET%^%^BLUE%^Sword of Doom%^RESET%^");
   set_obvious_short("A black short sword");
   set_long("%^BLUE%^This sword is made from the very stuff of blackness.  Your skin feels frigid while it "
"touches this %^BOLD%^%^BLACK%^weapon%^RESET%^%^BLUE%^.  You can it feel willing you to commit acts of such "
"hatred that Xvim will take heed and recognize you as one of his own.%^RESET%^");
   set_property("enchantment",2);
   set("value",500);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((: TO,"extra_hit" :));
}

int wield_fun(string str){
   if(ALIGN->is_good(ETO)){
     tell_object(ETO,"You would never wield that evil thing!");
     return 0;
   }

   if(!ETO->query_diety() || (string)ETO->query_diety()=="bane"){
     tell_object(ETO,"%^BLUE%^You feel your soul wrench as you wield the evil shortsword.%^RESET%^");
     tell_room(EETO,"%^BLUE%^"+TPQCN+"'s eyes begin to %^RED%^glow%^BLUE%^ as "+TP->QS+" wields the black "
"shortsword.%^RESET%^",ETO);
     return 1;
   }
   tell_object(ETO,"Your diety would not approve of that!");
   return 0;
}

int unwield_func(string str){
   if(attacked==0){
     tell_object(ETO,"%^BOLD%^%^RED%^You cannot, you are too consumed with hatred to let your weapon go!"
"%^RESET%^");
     tell_room(EETO,"%^RED%^"+ETOQCN+" tries to release "+ETO->QP+" sword but cannot.%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^BLUE%^You release your sword, its bloodlust sated");
   return 1;
}

int extra_hit(object targ){
   targ = ETO->query_current_attacker();
   if(!random(4)) {
     if(ALIGN->is_good(targ)){
       attacked=1;
       tell_object(ETO,"%^BLUE%^Your sword %^BOLD%^glows%^RESET%^%^BLUE%^ as you smite the forces of good!"
"%^RESET%^");
       tell_object(targ,"%^BLUE%^Your soul cries out as you are stuck by "+ETOQCN+"'s black shortsword!");
       tell_room(EETO,"%^BLUE%^"+targ->QCN+" cries out in agony as "+ETOQCN+" stikes "+targ->QS+" with the "
"black shortsword!%^RESET%^",(({ETO,targ})));
       return(roll_dice(1,8));
     }
     return 0;
   }
}
