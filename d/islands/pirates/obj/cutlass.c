#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
   ::create();
   set_name("cutlass");
   set_id(({"cutlass","gold-hilted cutlass","ornate cutlass","claw","golden claw","eyris' golden claw"}));
   set_short("%^WHITE%^%^BOLD%^Eyris' %^RESET%^%^ORANGE%^Go%^YELLOW%^l%^RESET%^%^ORANGE%^den Cl%^YELLOW%^a%^RESET%^%^ORANGE%^w%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^ornate %^YELLOW%^gold-hilted %^WHITE%^cutlass%^RESET%^");
   set_long("%^BLUE%^%^BOLD%^This cutlass consists of a long, slender blade, upturned slightly at the end.  "
"Fine %^WHITE%^adamantium %^BLUE%^forms the blade, which holds a keen edge and a perfect, bright sheen.  It "
"is attached to a %^YELLOW%^golden hilt%^BLUE%^, with a smooth grip and a half-basket cover, to protect the "
"hand during combat.  The basket cover is engraved with the image of a %^RESET%^%^ORANGE%^snarling tiger"
"%^BLUE%^%^BOLD%^, in quite elaborate style.  The entire weapon looks quite exquisite, and is probably worth "
"a fair amount.%^RESET%^");
   set_weight(7);
   set_value(800);  // discern 8/10 on a standard longsword. Check?
   set_weapon_speed(4);
//   if(random(3)) set_property("enchantment",1);
   set_property("enchantment",2);
   set_hit((:TO,"extra_hit":));
   set_lore("%^WHITE%^%^BOLD%^This cutlass was known to be the trademark weapon of the pirate captain Eyris.  "
"He was quite fond of the emblem of the tiger for himself, and is often referred to by pirates as 'The Tiger "
"of the Sea' because of this.  It's said that he had quite expensive tastes, possibly why he would have such "
"an exquisite weapon.  After his demise at the hands of the pirate Rolon, the weapon was passed to his mate as "
"a sign of good faith from his new captain.%^RESET%^\n");
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_fun":));
}

int wield_fun() {
   int ench;
   ench = (int)TO->query_property("enchantment");
   ench = ench+1;
   ench = ench*5;
   if(ETO->query_highest_level() < ench) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^You can't get a proper grip on the blade's hilt!%^RESET%^");
     return 0;
   }
   return 1;
}

int extra_hit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(10)){
     switch(random(10)) {
       case 0..1:
       ETO->execute_attack();
       tell_object(ETO,"%^YELLOW%^You glide forward, weaving your curved blade in an elegant display of "
"swordcraft!%^RESET%^");
       tell_room(EETO,"%^YELLOW%^"+ETOQCN+" glides forward, weaving "+ETO->QP+" curved blade in an elegant "
"display of swordcraft!%^RESET%^",ETO);
       return 1;
       break;

       case 2..5:
       tell_object(ETO,"%^GREEN%^You twist the blade of your cutlass back, slamming the pommel between "
+targ->QCN+"'s eyes!%^RESET%^");
       tell_object(targ,"%^GREEN%^"+ETOQCN+" twists the blade of "+ETO->QP+" cutlass back, slamming the "
"pommel between your eyes!%^RESET%^");
       tell_room(EETO,"%^GREEN%^"+ETOQCN+" twists the blade of "+ETO->QP+" cutlass back, slamming the pommel "
"between "+targ->QCN+"'s eyes to daze "+targ->QO+"!%^RESET%^",({ETO,targ}));
       targ->set_paralyzed(7,"You're still seeing stars!");
       break;

       case 6..9:
       tell_object(ETO,"%^BLUE%^%^BOLD%^You feint at "+targ->QCN+"'s head and duck to the right, rising "
"quickly to slice at "+targ->QP+" unprotected side with a backhand blow!%^RESET%^");
       tell_object(targ,"%^BLUE%^%^BOLD%^"+ETOQCN+" feints at your head and ducks to the right, rising "
"quickly to slice at your unprotected side with a backhand blow!%^RESET%^");
       tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETOQCN+" feints at "+targ->QCN+"'s head and ducks to the right, "
"rising quickly to slice at "+targ->QP+" unprotected side with a backhand blow!%^RESET%^",({ETO,targ}));
       targ->do_damage(targ->return_target_limb(),roll_dice(3,4));       
       break;
     }
   }
}

