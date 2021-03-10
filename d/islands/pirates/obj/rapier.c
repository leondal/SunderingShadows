#include <std.h>
inherit "/d/common/obj/weapon/light_rapier";

void create(){
   ::create();
   set_id(({"rapier","sword","foil"}));
   set_short("%^BOLD%^%^WHITE%^rapier%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^This is a fairly light and thin-bladed rapier of %^RESET%^%^WHITE%^fine "
"adamantium%^BOLD%^, sometimes referred to as a foil.  The slender blade is obviously better suited to "
"thrusting jabs than sweeping arcs, and would be better for light and nimble attacks, rather than brute "
"force.  The blade is joined at a %^BLACK%^basket hilt%^WHITE%^, which would protect the hand from potential "
"injuries throughout combat, and offer a secure grip to make the weapon hard to fumble.");
   set_property("enchantment",2);
   set_ac(1);
   set_hit((:TO,"extra_hit":));
   set_lore("%^WHITE%^%^BOLD%^This light style of weapon is commonly used by rogues, swashbucklers and "
"pirates, since such a light, easily-maintained weapon is ideal for their style of fighting.%^RESET%^\n");
   set_property("lore difficulty",9);
}

int extra_hit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(8)){
     switch(random(5)) {
       case 0..1:
       ETO->execute_attack();
       tell_object(ETO,"%^WHITE%^%^BOLD%^You lash out with lightning speed, following up your last attack "
"with another!%^RESET%^");
       tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" lashes out with lightning speed, following up "+ETO->QP+
" previous attack with another!%^RESET%^",ETO);
       return 1;
       break;

       case 2..4:
       tell_object(ETO,"%^WHITE%^%^BOLD%^You lunge forward through a gap in "+targ->QCN+"'s defenses!"
"%^RESET%^");
       tell_object(targ,"%^WHITE%^%^BOLD%^"+ETOQCN+" lunges forward through a gap in your defenses!"
"%^RESET%^");
       tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" lunges forward and catches "+targ->QCN+" with a sharp jab!"
"%^RESET%^",({ETO,targ}));
       return 2;
       break;
     }
   }
}
