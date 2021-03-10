//pronged_claws.c - weapon for aberration thieves ~Circe~ 6/5/07

#include <std.h>
#include "../kildare.h"

inherit "/d/common/obj/weapon/claw.c";

void create(){
   ::create();
   set_name("pronged claws");
   set_id(({"claws","pronged claws","claws of the aberration","aberration claws","knuckles"}));
   set_obvious_short("%^RESET%^%^ORANGE%^a set of pronged claws%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Claws of the Aberration%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This weapon seems to have been crafted "+
      "of an assortment of %^BOLD%^%^BLACK%^claws%^RESET%^%^ORANGE%^ "+
      "and %^BOLD%^%^WHITE%^bone%^RESET%^%^ORANGE%^.  They have been "+
      "fused together to form a frightful, if simple, weapon.  "+
      "The claws stem from a %^BOLD%^%^WHITE%^length of bone%^RESET%^"+
      "%^ORANGE%^ that could be easily held in the palm of a hand.  "+
      "Each individual claw is %^BOLD%^%^BLACK%^black %^RESET%^"+
      "%^ORANGE%^as the %^BOLD%^%^BLACK%^abyss %^RESET%^%^ORANGE%^"+
      "and ends with a %^BOLD%^%^WHITE%^white tip %^RESET%^%^ORANGE%^"+
      "stained %^RED%^red%^ORANGE%^.%^RESET%^");
   set_lore("Crafted from the claws of the twisted creatures "+
      "known as peryton aberrations, this weapon is simple "+
      "in design and construction but brutal in use.  No "+
      "living person understands exactly what holds the weapon "+
      "together, but some speculate that it is a remnant of the "+
      "peryton's demonic bond.");
   set_property("lore difficulty",9);
   set_property("enchantment",1);
   set_weight(4);
   set_value(250);
   set_wield((:TO,"wield_func":));
   set_hit((:TO,"extra_hit":));
}

int wield_func(string str) {
   tell_object(ETO,"%^BOLD%^%^WHITE%^You grip the bone handle "+
      "and feel the claws between your fingers.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" seems to grow "+
      "claws as "+ETO->QS+" wields "+ETO->QP+" weapon.%^RESET%^",ETO);
   return 1;
}

int extra_hit(object victim) {
   object mylimb;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   if(!random(10)) {
      mylimb = victim->return_target_limb();
      tell_object(ETO,"%^BOLD%^%^RED%^You slash "+victim->QCN+"'s "+
         ""+mylimb+" with malice!%^RESET%^");
      tell_object(victim,"%^BOLD%^%^RED%^"+ETOQCN+" slashes your "+
         ""+mylimb+" with malice!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" slashes "+
         ""+victim->QCN+"'s "+mylimb+" with malice!%^RESET%^",({ETO,victim}));
      victim->do_damage(mylimb,random(5)+3);
      return 0;
   }
   else return random(3);
}
