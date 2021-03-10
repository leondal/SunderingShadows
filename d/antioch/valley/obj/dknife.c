//updated by Circe 6/15/04 with desc, lore, etc by Shar
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/sickle";

void create()
{
	::create();
	set_name("dryad kama");
	set_id(({"kama","dryad kama","aventurine kama"}));
      set_obvious_short("a small kama");
	set_short("%^RESET%^%^GREEN%^Aventurine Kama%^RESET%^");
	set_long(
@CIRCE
A foot long piece of %^YELLOW%^golden chestnut wood %^RESET%^makes up the base of this weapon.  Jutting out perpendicular to the wooden base is a %^GREEN%^deep green blade%^RESET%^.  The blade is actually made out of %^GREEN%^aventurine%^RESET%^, a green semi-precious stone.  The thick blade tapers to a fine, sharp, point.  The %^GREEN%^aventurine %^RESET%^is veined with %^BOLD%^%^GREEN%^lighter green f%^RESET%^%^GREEN%^le%^BOLD%^cks %^RESET%^against the %^GREEN%^deeper green %^RESET%^base color, giving a vibrant quality to the stone.  Wrapped around the shaft of the weapon is a length of %^YELLOW%^b%^RESET%^%^RED%^r%^ORANGE%^a%^YELLOW%^i%^RESET%^%^RED%^d%^ORANGE%^e%^YELLOW%^d blonde%^RESET%^, %^RED%^auburn%^RESET%^, and %^ORANGE%^brunette %^RESET%^hairs woven with sprigs of %^GREEN%^mistletoe%^RESET%^.
CIRCE
	);
      set_lore(
@CIRCE
The kama is one of those strange weapons that came about from a harvest tool.  The kama is much like a sickle in many ways, though without the sharp curve the sickle posses.  The kama is used to harvest grains.  Many druids have come to adopt the kama as one of their favored weapons, mainly due to its small size.  The aventurine used in this kamas blade is a sacred stone to the followers of Mielikki.  A curious story surrounds the braided length of hair that wraps around the kama.  Some sages believe it to be actually dryad hair, and if unbraided one will find a single white strand in the center of the braid-given by a unicorn.  Though the braid seems resistant to anyone attempting to unbraid it, tangling about itself as if living.
CIRCE
      );
      set_property("lore difficulty",14);
	set_value(150);
	set_property("enchantment",3);
      set_wield((:TO,"wieldme":));
      set_unwield("%^GREEN%^The green flecks fade as you unwield the blade.");
      set_hit((:TO,"hitme":));
}

int wieldme(){
   if((int)ETO->query_lowest_level() < 17){
      tell_object(ETO,"The kama refuses to be wielded by one so "+
         "unexperienced in the world.");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^GREEN%^The flecks of green in the blade "+
      "flash in response to your touch.");
   tell_room(EETO,"%^BOLD%^%^GREEN%^The ribbons of green in the blade "+
      "flash in response to "+ETOQCN+"'s touch.",ETO);
   return 1;
}

int hitme(object targ){
   if(!objectp(ETO)) return 0;
   if(!objectp(targ)) return 0;
   if(random(10) < 3){
      tell_object(ETO,"%^GREEN%^You sink the kama deep into "+
         ""+targ->QCN+"s flesh!");
      tell_object(targ,"%^GREEN%^"+ETOQCN+" sinks "+ETO->QP+" "+
         "kama deep into your flesh!");
      tell_room(EETO,"%^GREEN%^"+ETOQCN+" sinks "+ETO->QP+" "+
         "kama deep into "+targ->QCN+"'s flesh!",({ETO,targ}));
      targ->do_damage("torso",random(5)+2);
      return 1;
   }
   if(random(100) < 15){
      tell_object(ETO,"%^BOLD%^%^GREEN%^You unwrap the braided "+
         "length of hair from around the shaft and whip the kama "+
         "about, tearing into "+targ->QCN+"!");
      tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+" unwraps a "+
         "length of braided hair from around "+ETO->QP+" kama and "+
         "whips the weapon into you!");
      tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETOQCN+" unwraps a "+
         "length of braided hair from around "+ETO->QP+" kama and "+
         "whips the weapon into "+targ->QCN+"!",({ETO,targ}));
      targ->do_damage("torso",random(13)+4);
      return random(2);
   }
   return 0;
}
