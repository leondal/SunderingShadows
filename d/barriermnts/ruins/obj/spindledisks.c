#include <std.h>
#include "../inherit/ruins.h"
#include <magic.h>
inherit "/d/common/obj/weapon/scourge";

create(){
   ::create();
   set_id(({"spindle discs","discs","disks","spindlediscs","spindle disks","spindledisks"}));
   set_name("spindle disks");
   set_obvious_short("%^CYAN%^%^BOLD%^string-suspended crystal disks%^RESET%^");
   set_short("%^CYAN%^%^BOLD%^s%^WHITE%^pi%^CYAN%^nd%^WHITE%^le %^CYAN%^di%^WHITE%^sk%^CYAN%^s%^RESET%^");
   set_long("%^GREEN%^The strange device consists of two circular disks of %^CYAN%^%^BOLD%^crystalline "
"stone%^RESET%^%^GREEN%^, each half an inch wide and two inches across.  A small, thick bar joins the "
"two disks across the centre, through which a small hole is tied with twined %^ORANGE%^string%^GREEN%^.  "
"The string extends for several feet, tied at the end into a small loop.%^RESET%^");
   set_property("enchantment",random(2)+2);
   set_item_bonus("attack bonus",3);
   set_value(80);
   set_cointype("gold");
   set_lore("%^WHITE%^%^BOLD%^This particularly unorthodox weapon was one of many that the halfling "
"rogue Kaali Thistlefoot was known to carry, and that she utilized equally in battle and for amusement.  "
"It often caused many laughs at the weapon's expense, though this quickly changed when the weapon was "
"seen in combat.%^RESET%^");
   set_property("lore difficulty",18);
   set_size(1);
   set_wc(1,3);
   set_large_wc(1,3);
   set_weapon_speed(3);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun() {
   tell_object(ETO,"%^GREEN%^You slip a finger through the string's loop, closing your hand over the "
"disks.%^RESET%^");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" slips a finger through the string's loop, closing "+ETO->QP+
" hand over the disks.%^RESET%^",ETO);
   return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^GREEN%^You remove your finger from the string's loop.%^RESET%^");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" removes "+ETO->QP+" finger from the string's loop.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object target){
   int flag,i;
   object *inven;
   flag = -1;
   if(random(1000) < 175){
     inven=all_inventory(target);
     for (i=0;i<sizeof(inven);i++) {
       if(inven[i]->query_wielded()) {
         if (inven[i]->query_property("enchantment") && inven[i]->query_property("enchantment") >= 0) {
           flag = i; }
         if (!inven[i]->query_property("enchantment")) { flag = i; }
       }
     }
     switch(random(4)){
       case 0:
       if (flag != -1) {
         tell_object(ETO,"%^RED%^%^BOLD%^You lash out with the spindledisks, hitting them painfully "
"against the back of "+target->QCN+"'s hand and forcing "+target->QO+" to drop "+target->QP+
" weapon!%^RESET%^");
         tell_object(target,"%^RED%^%^BOLD%^"+ETO->QCN+" lashes out at your hand with the spindledisks, "
"hitting them so painfully you lose hold of your weapon!%^RESET%^");
         tell_room(EETO,"%^RED%^%^BOLD%^"+ETO->QCN+" lashes out with the spindledisks, hitting them "
"painfully against the back of "+target->QCN+"'s hand and forcing "+target->QO+" to lose hold of "
+target->QP+" weapon!%^RESET%^",({ETO,target}));
         inven[flag]->__ActuallyUnwield();
		 target->remove_property("disarm time");
		 target->set_property("disarm time",time()+(ROUND_LENGTH*roll_dice(1,4)));
       }
       else {
         tell_object(ETO,"%^RED%^%^BOLD%^You lash out with the spindledisks, hitting them painfully "
"against the back of "+target->QCN+"'s hand!%^RESET%^");
         tell_object(target,"%^RED%^%^BOLD%^"+ETO->QCN+" lashes out at your hand with the spindledisks, "
"hitting them painfully!%^RESET%^");
         tell_room(EETO,"%^RED%^%^BOLD%^"+ETO->QCN+" lashes out with the spindledisks, hitting them "
"painfully against the back of "+target->QCN+"'s hand!%^RESET%^",({ETO,target}));
       }
       return 1;
       break;

       case 1..3:
       tell_object(ETO,"%^ORANGE%^You snap the spindledisks out to the length of the string, cracking "
"them against the side of "+target->QCN+"'s head!%^RESET%^");
       tell_object(target,"%^ORANGE%^"+ETO->QCN+" snaps the spindledisks out to full length, cracking "
"them against the side of your head!%^RESET%^");
       tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" snaps the spindledisks out to the length of the string, "
"cracking them against the side of "+target->QCN+"'s head!%^RESET%^",({ETO,target}));
       target->do_damage("head",roll_dice(2,3));
       target->set_paralyzed((random(10)+10),"You are still trying to blink the stars from your vision!");
       target->set_temporary_blinded(2,"You are still trying to blink the stars from your vision!");
       break;
     }
     return 1;
   }
}
