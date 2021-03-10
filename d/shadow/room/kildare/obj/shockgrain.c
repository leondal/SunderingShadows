#include <std.h>
inherit "/d/common/obj/weapon/awlpike";

void create(){
   ::create();
   set_id(({"shock","shock of grain","pole arm","polearm"}));
   set_name("shock of grain");
   set_obvious_short("A wooden polearm");
   set_short("%^YELLOW%^Shock of Grain%^RESET%^");
   set_long(
      "%^ORANGE%^This wooden polearm has been fashioned to look like a "+
      "sheaf of grain bound together with leather cording.  The "+
      "detail is fantastic, with the individual lengths of grain "+
      "carved in relief.  Wider strips of darkened leather form "+
      "sturdy grips to keep the wielder's hands from slipping, and "+
      "the head of the grain is worked into a fine point, perfect "+
      "for piercing through armor."
    );
    set_lore(
      "The Shock of Grain was a cleverly-designed weapon made to "+
      "escape detection centuries ago.  Afraid of a peasant uprising, "+
      "the domineering lord of Drogheda, a fief just north of Echoes "+
      "Mountains, forbade his serfs to possess weapons of any kind.  "+
      "A weaponsmith of great cunning forged these Shocks in secret, and "+
      "armed with the new weapons which looked like nothing but grain "+
      "from afar, the peasants fooled their lord and won their freedom."
    );
    set_property("lore difficulty",8);
    set_value(50);
    set_property("enchantment",1);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"extra_hit":));

}
int wield_func(string str) {
   tell_object(ETO,"%^ORANGE%^You wrap your hands around the shock of "+
      "grain and feel the power of the earth flowing through you.%^RESET%^");
   return 1;
}
int unwield_func(string str) {
   tell_object(ETO,"%^ORANGE%^You feel a weight on your shoulders lighten as you "+
      "release the shock of grain.%^RESET%^");
   return 1;
}
int extra_hit(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   if(!random(30)) {
      tell_object(ETO,"%^YELLOW%^With your feet planted firmly on the earth, "+
         "you thrust the end of the polearm deeply into your opponent!%^RESET%^");
      tell_object(victim,"%^YELLOW%^"+ETO->query_cap_name()+" plants "+
         ""+ETO->query_possessive()+" feet firmly on the ground before impaling "+
         "you!%^RESET%^");
      tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+" plants "+
         ""+ETO->query_possessive()+" feet firmly on the ground before impaling "+
         ""+victim->query_cap_name()+" visciously!%^RESET%^", ({ETO,victim}));
      victim->do_damage("torso",random(10)+5);
      return 0;
   }
   if(!random(30)){
      set_property("magic",1);
      tell_object(ETO,"%^GREEN%^You feel the power of the earth flow through "+
         "your body, healing some of your wounds.%^RESET%^");
      tell_room(environment(ETO),"%^GREEN%^A strange look of peace comes over "+
         ""+ETO->query_cap_name()+", leaving "+ETO->query_objective()+" looking "+
         "refreshed.%^RESET%^",(ETO));
      ETO->do_damage("torso",(-1)*(random(5)+5));
      remove_property("magic");
      return 1;
   }
   else return 0;
}
