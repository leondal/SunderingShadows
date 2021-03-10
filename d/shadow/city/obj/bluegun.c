#include <std.h>
inherit "/d/common/obj/lrweapon/pistol";
create() {
   ::create();
   set_id(({ "pistol", "gun"}));
   set_name("pistol","flintlock pistol");
   set_short("%^BLUE%^a "+
   "%^BOLD%^fl%^RESET%^%^BLUE%^i%^CYAN%^n%^BLUE%^t%^BOLD%^lo%^RESET%^%^BLUE%^c%^CYAN%^k "+ 
   "%^BLUE%^p%^BOLD%^is%^RESET%^%^BLUE%^t%^CYAN%^o%^BLUE%^l%^WHITE%^");
   set_long("%^ORANGE%^This handheld flintlock would be easy to conceal. The barrel "+
   "is a %^BOLD%^%^BLUE%^r%^RESET%^%^CYAN%^i%^BLUE%^c%^BOLD%^h c%^RESET%^%^BLUE%^o%^BOLD%^b%^RESET%^%^BLUE%^a%^CYAN%^l%^BOLD%^%^BLUE%^t "+ 
   "h%^RESET%^%^CYAN%^u%^BOLD%^%^BLUE%^e%^RESET%^%^ORANGE%^, inlaid with delicate %^BOLD%^gold scrollwork%^RESET%^%^ORANGE%^, "+ 
   "and the %^BOLD%^%^BLACK%^walnut %^RESET%^%^ORANGE%^stock is comfortable and worn. A %^BOLD%^golden %^RESET%^serrated bayonet "+ 
   "%^ORANGE%^has been affixed to the underside of the barrel, ready for close combat.%^WHITE%^");
   set_weight(4);
   set_size(1);
   set_value(1000);
   set_property("enchantment",2);
   set_wc(1,6);
   set_critical_hit_multiplier(4);
   set_type("bludgeoning");
   set_lr_prof_type("gun");
   set_weapon_prof("exotic");
   set_rate_of_fire(4);
   set_range(2,4,6);
   set_ammo("cartridge");
   set_decay_rate(100);
   set_weapon_speed(1);
   set_damage_type("piercing");
   set_lrhit((:TO,"extra_lrhit":));
   set_hit((:TO,"extra_hit":));
   set_lore("%^WHITE%^%^BOLD%^Because pistols like this tend to be somewhat rare in the world, the ones that do show up "+
   "have a deep and fascinating history as to its origins. This one, however, has no search history. If there is one thing "+
   "to be said about it, is that there's nothing to be said about it. At least nothing that anyone is willing to speak about, "+
   "leaving it shrouded in mystery.%^RESET%^\n");
   set_property("lore difficulty",9);
}
int extra_lrhit(object targ){
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 0;
   if(random(1000) < 300){
     switch(random(36)){
     case 0..15:
     tell_object(ETO,"%^BOLD%^%^WHITE%^You shift your grip on the pistol to stab it fiercely into "+targ->QCN+"!%^RESET%^");
     tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s bayonet stabs savagely into your flesh!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s bayonet stabs savagely into "+targ->QCN+"!%^RESET%^",({ETO,targ}));
     targ->do_damage(targ->return_target_limb(),random(6)+3);
     break;
     case 16..31:
     tell_object(ETO,"%^CYAN%^%^BOLD%^You raise your pistol and pull the trigger, shooting "+
	 ""+targ->QCN+" at point-blank range!%^RESET%^");
     tell_object(targ,"%^CYAN%^%^BOLD%^"+ETOQCN+" points "+ETO->QP+" at you and pulls the trigger, "+
	 "shooting you at point-blank range!%^RESET%^");
     tell_room(EETO,"%^CYAN%^%^BOLD%^"+ETOQCN+" raises "+ETO->QP+" pistol and pulls the trigger, "+
	 "shooting "+targ->QCN+" at point-blank range!%^RESET%^",({ETO,targ}));
     targ->do_damage(targ->return_target_limb(),random(6)+6);
	 break;
     return 1;
   }
}
}