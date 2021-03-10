//Added lore and inherit shortsword - Cythera 4-05\\
//updated some code, improved readability ~Circe~ 11/30/19
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/shortsword.c";

void create(){
   ::create();
   set_name("pearl sword");
   set_id(({"sirine sword","short sword","sword","sirine short sword","shortsword","sea sword","pearl sword","pearl shortsword","pearl short sword","pearl blade","blade"}));
   set_short("%^WHITE%^%^BOLD%^Pearl Short Sword%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A white pearl handle short sword%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^The short sword has a white pearl handle inlaid with a very large %^RESET%^%^GREEN%^green%^BOLD%^%^WHITE%^ pearl in the center of the hilt.  The blade has a white luster to it.%^RESET%^");
   set_lore("Crafted deep under the water, the White Pearl Sword is the trusted blade of the sirens.  Normally sirens have a rather neutral relationship with other fey creatures, but finding their way of life under threat by the evil of the Dark Forest and Dark Trail, the sirens have loosely allied themselves with the druids of the Moonstone Valley.  That is not to say though a siren won't revert back to her old way when feeling the urge, but for the most part they work with the nixies in protecting the waterways.");
   set_property("lore",10);
   set_value(900);
   set_weight(4);
   set_property("enchantment",(random(3))+1);
   set_hit((:TO,"hitme":));
}

int hitme(object targ){
   if(!objectp(targ)) return 1;
   if(!random(10)){
      tell_object(ETO,"%^BOLD%^The sword glows slightly and you slice through "+targ->QCN+"'s armor with ease.%^RESET%^");
      tell_object(targ,"%^BOLD%^"+ETOQCN+"'s  sword glows slightly and slices right through your armor.%^RESET%^");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+"'s sword glows slightly and seems to slice right through "+targ->QCN+"'s armor.%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",random(5)+2);
      return 1;
   }
   if(!random(20)){
      tell_object(ETO,"%^GREEN%^The green pearl glows for a moment and a warmth washes over your body.%^RESET%^");
      tell_room(EETO,"%^GREEN%^The green pearl in the hilt of "+ETOQCN+"'s sword glows briefly.%^RESET%^",ETO);
      ETO->do_damage("torso",-(random(5)+4));
      targ->do_damage("torso",random(4)+1);
      return 1;
   }
}
