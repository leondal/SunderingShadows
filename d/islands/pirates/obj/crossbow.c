#include <std.h>
inherit "/d/common/obj/lrweapon/hcrossbow";

void create(){
   ::create();
   set_name("crossbow");
   set_id(({"crossbow","bow","crossbow of the wyrm","wyrm crossbow","mahogony crossbow","bone crossbow"}));
   set_short("%^WHITE%^%^BOLD%^Crossbow of the %^RESET%^%^RED%^Wyrm%^RESET%^");
   set_obvious_short("%^RESET%^a crossbow of %^RED%^mahogony%^RESET%^ and %^WHITE%^%^BOLD%^bone%^RESET%^");
   set_long("This is a quite remarkable crossbow, of exquisite crafting.  The butt of the weapon is made of "
"%^RED%^deep red mahogony%^RESET%^, heavy enough to deliver a strong blow in a fight, if the user had no "
"bolts left to fire with.  %^BLACK%^%^BOLD%^Wound wire %^RESET%^forms the string of the bow, while the arms "
"are formed of %^WHITE%^%^BOLD%^polished bone%^RESET%^.  The bone must've been quite large before it was "
"carved, and now shapes the figure of a fierce dragon, each wing forming one arm of the bow, with its head "
"along the bow's line of sight, facing forward in a snarl.");
   set_weight(15);
   set_value(400);
   set_property("enchantment",2);
   set_hit((:TO,"extra_hit":));
   set_lrhit((:TO,"extra_lrhit":));
   set_lore("%^WHITE%^%^BOLD%^Very few tales ever tell of such a crossbow, though it does stand out in the "
"ones that do mention it, for its distinctive make.  The rumours tell of a pirate ship, captained by a "
"half-elf of great reknown.  It was not just because of him, however, that his vessel was so feared.  He "
"kept a great many skilled rogues by his side, one of whom was particularly competent in the use of "
"crossbow.  This particular crossbow was pillaged early in his career, and he retained it as quite an "
"exquisite memento for the rest of his days.%^RESET%^\n");
   set_property("lore difficulty",14);
}

int extra_hit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(10)){
     tell_object(ETO,"%^RED%^You bring the butt of the crossbow up in a vicious blow at "+targ->QCN+
"!%^RESET%^");
     tell_object(targ,"%^RED%^The dragon's head almost seems to snarl, as "+ETOQCN+" brings up the "
"butt of the crossbow and slams you with it!%^RESET%^");
     tell_room(EETO,"%^RED%^The dragon's head almost seems to snarl, as "+ETOQCN+" brings up the butt "
"of the crossbow and slams "+targ->QCN+" with it!%^RESET%^",({ETO,targ}));
     targ->do_damage(targ->return_target_limb(),random(6)+3);
     return 1;
   }
}

int extra_lrhit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(10)){
     tell_object(ETO,"%^WHITE%^%^BOLD%^You snap out a bolt and bring the crossbow up to sight, shooting "
+targ->QCN+" at point-blank range!%^RESET%^");
     tell_object(targ,"%^WHITE%^%^BOLD%^"+ETOQCN+" snaps out a bolt and brings "+ETO->QP+" crossbow up to "
"sight, shooting at you at point-blank range!%^RESET%^");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" snaps out a bolt and brings "+ETO->QP+" crossbow up to "
"sight, shooting "+targ->QCN+" at point-blank range!%^RESET%^",({ETO,targ}));
     targ->do_damage(targ->return_target_limb(),random(6)+6);
     return 1;
   }
}