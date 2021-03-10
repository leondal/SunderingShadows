#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create(){
   ::create();
   set_name("whalebone dagger");
   set_id(({"whalebone dagger","whalebone","dagger","bone dagger","long dagger","long dagger of bone"}));
   set_short("%^WHITE%^%^BOLD%^Whalebone Dagger%^RESET%^");
   set_obvious_short("a long dagger of bone");
   set_long("%^BLUE%^This is a long dagger carved from what appears to be a solid piece of%^WHITE%^ "
"bone%^BLUE%^.  It is of a particularly sturdy make, with the hilt curved to slide easily into the hand's "
"grip.  The blade is uncharacteristically long, presumably giving it a considerable reach over a normal "
"dagger, and is honed to a %^BLACK%^%^BOLD%^razor-sharp edge%^RESET%^%^BLUE%^.%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^Daggers of such length were commonly designed by rogue warriors, favoured for "
"their extended range in combat over normal daggers.  This particular dagger has been crafted from the bone "
"of a whale, and you've heard of a few such weapons being commonly used by seagoing pirates.%^RESET%^");
   set_property("lore difficulty",12);
   set_weight(3);
   set("value",600);
   set_prof_type("small blades");
   set_property("enchantment",random(2)+1);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"extra_hit":));
}

int wield_fun() {
   tell_room(EETO,"%^WHITE%^%^BOLD%^The dagger's hilt slides smoothly into "+ETOQCN+"'s hand.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^The dagger's hilt fits snugly within your grasp.%^RESET%^");
   return 1;
}

int unwield_fun() {
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" releases "+ETO->QP+" grip on the dagger.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^You release your comfortable grip on the dagger.%^RESET%^");
   return 1;
}

int extra_hit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if((roll_dice(1,20))>17){
     tell_object(ETO,"%^BOLD%^%^BLUE%^You stab "+targ->QCN+" with the force of the deep!%^RESET%^");
     tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+" stabs you with the force of the deep!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLUE%^" +ETO->QCN+ " stabs "+targ->QCN+" with the force of the deep!%^RESET%^",({ETO,targ}));
     targ->do_damage(targ->return_target_limb(),(random(5)+5));
     return 1;
   }
   else return 1;
}
