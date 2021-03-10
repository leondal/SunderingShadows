#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

void create() {
   ::create();
   set_name("twisted blacksteel blade");
   set_id(({"blade","blacksteel blade","twisted blade","grakrath","Grak'rath"}));
   set_short("%^BOLD%^%^BLACK%^Grak'rath - the blade of%^RESET%^ %^BOLD%^%^GREEN%^Chaos%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A twisted blacksteel blade%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This long twisted blade is made from a black, "
"unknown metal, both light-weight and durable. The double-edged blade "
"is%^RESET%^ %^RED%^razor-sharp%^BOLD%^%^BLACK%^, barbed and serrated in some "
"parts, smooth and fine edged in others - a blade of "
"%^BOLD%^%^GREEN%^chaos%^BOLD%^%^BLACK%^. A deep%^RESET%^ %^RED%^blood "
"%^BOLD%^%^BLACK%^groove travels along the length of the blade, flanked on "
"either side by jagged%^BOLD%^%^CYAN%^ runes%^BOLD%^%^BLACK%^. There is a "
"sense of wrongness about the %^BOLD%^%^CYAN%^runes%^BOLD%^%^BLACK%^, to look "
"on them is to feel uneasy. The hilt is carved from soft black stone, wrapped "
"in supple leather of some unknown beast. A thick %^BOLD%^%^RED%^blood-ruby "
"%^BOLD%^%^BLACK%^has been set into the end of the hilt, seccured firmly by a "
"set of black claws.%^RESET%^\n");
   set_value(2050);
   while((int)TO->query_property("enchantment") < 4) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",4);
   }
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You feel a battle take place within you "
"as you wield the %^BOLD%^%^GREEN%^chaos blade%^BOLD%^%^BLACK%^, but "
"eventually your will triumphs and you feel stronger for it.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" looks%^RESET%^ %^WHITE%^pale "
"%^BOLD%^%^BLACK%^as "+ETO->QS+" wield a twisted blacksteel "
"blade.%^RESET%^",ETO);
   ETO->do_damage("torso",random(4)+2);
   return 1;
}

int unwield_fun(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You feel whole once more, if not a "
"little weaker.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" releases a twisted "
"blacksteel blade, the%^RESET%^ %^MAGENTA%^color %^BOLD%^%^BLACK%^returning "
"to "+ETO->QP+" skin.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object targ){
   int dam;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(10)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^You sink your blade deep into "
+targ->QCN+"'s%^RESET%^ %^RED%^flesh%^BOLD%^%^BLACK%^, the sword "
"turning%^RESET%^ %^CYAN%^icy%^RESET%^ %^BOLD%^%^BLACK%^in your "
"hand.%^RESET%^");

      tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" sinks "+ETO->QP+" blade deep into your%^RESET%^ %^RED%^flesh%^BOLD%^%^BLACK%^, a wave of%^RESET%^ %^CYAN%^numbness %^BOLD%^%^BLACK%^overwhelming you.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" sinks "+ETO->QP+" blade "
"deep into "+targ->QCN+"'s%^RESET%^ %^RED%^flesh%^BOLD%^%^BLACK%^, causing "+targ->QO+" to%^RESET%^ "
"%^CYAN%^shiver%^BOLD%^%^BLACK%^.%^RESET%^",({ETO,targ}));
      targ->set_paralyzed(7,"Your body is entirely numb!");
      return 1;
   }

   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The %^BOLD%^%^CYAN%^runes "
"%^BOLD%^%^BLACK%^on your blade come to life, the smell of%^RESET%^ "
"%^RED%^blood %^BOLD%^%^BLACK%^overwhelms your senses!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^BLACK%^The %^BOLD%^%^CYAN%^runes "
"%^BOLD%^%^BLACK%^on "+ETO->QCN+"'s blade come to %^BOLD%^%^GREEN%^life "
"%^BOLD%^%^BLACK%^and you feel your very %^BOLD%^%^CYAN%^soul "
"%^BOLD%^%^BLACK%^being assaulted!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLACK%^The %^BOLD%^%^CYAN%^runes "
"%^BOLD%^%^BLACK%^on "+ETO->QCN+"'s blade %^BOLD%^%^GREEN%^flare "
"%^BOLD%^%^BLACK%^with a sickening "
"%^BOLD%^%^CYAN%^glow%^BOLD%^%^BLACK%^,%^RESET%^ %^RED%^fire blazing "
"%^BOLD%^%^BLACK%^in "+ETO->QP+" eyes!%^RESET%^",({ETO,targ}));
      ETO->add_hp(random(8));
      return 1;
   }

   if(!random(10)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^You thrust your blade through "
+targ->QCN+", feeling %^BOLD%^%^RED%^fury %^BOLD%^%^BLACK%^overwhelm "
"you!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" %^BOLD%^%^RED%^impales "
"%^BOLD%^%^BLACK%^you to the hilt with their twisted blade, howling with "
"%^BOLD%^%^RED%^fury%^BOLD%^%^BLACK%^!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" gives a cry of "
"%^BOLD%^%^RED%^fury%^BOLD%^%^BLACK%^, thrusting the blade through "
+targ->QCN+" in a spray of %^RESET%^%^RED%^gore!%^RESET%^",({ETO,targ}));
      targ->do_damage(targ->return_target_limb(),random(8)+8);
      return 1;
   }
}
