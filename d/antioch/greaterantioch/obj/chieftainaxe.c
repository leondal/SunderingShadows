#include <std.h>
inherit "/d/common/obj/weapon/large_battle_axe.c";

create(){
   ::create();
   set_id(({"axe","battle axe"}));
   set_name("chieftainaxe");
   set_obvious_short("%^BOLD%^%^RED%^An orn%^BOLD%^%^WHITE%^a%^BOLD%^%^RED%^tely decorated large %^BOLD%^%^YELLOW%^battleaxe%^RESET%^");
   set_short("%^BOLD%^%^GREEN%^Lil' Choppa%^RESET%^");
   set_long(
      "%^RESET%^%^ORANGE%^The nearly five-foot long battle axe has a long ornately carven"+
      " shaft which has %^RESET%^%^RED%^tribal %^RESET%^%^ORANGE%^drawings covering its length."+
      " The massive %^BOLD%^%^WHITE%^double-headed %^RESET%^%^ORANGE%^axehead has permanently"+
      " dried %^RESET%^%^RED%^blood %^RESET%^%^ORANGE%^covering its head. %^RESET%^");
   set_property("enchantment",3);
   set_item_bonus("armor bonus",1);
   set_value(1300);
   set_wield((:TO,"wieldit":));
   set_unwield((:TO,"unwieldit":));
   set_hit((:TO,"hitit":));
}
int wieldit() {
   tell_object(ETO,"%^BOLD%^%^GREEN%^You wield the massive axe, in awe at it's powerful look.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->query_cap_name()+" wields the "+ETO->query_possessive()+" and grips it tightly.%^RESET%^",ETO);
   return 1;
}
int unwieldit() {
   tell_object(ETO,"%^BOLD%^%^GREEN%^You release your grip on the hefty axe.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->query_cap_name()+" relaxes their grip from the axe.%^RESET%^",ETO);
   return 1;
}
int hitit(object targ){
    if(random(1000) < 5){
        if(!objectp(targ)) {
            return roll_dice(50,6);
        }
        tell_object(ETO,"%^BOLD%^%^RED%^Power flows through your body as you swing violently at "+targ->query_cap_name()+"'s neck and strike it with a critical blow!");
        tell_object(targ,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" swings back and the axe strikes you squarely in your neck - LUCKY BASTARD!%^RESET%^");
        tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^" +ETO->query_cap_name()+" swings back and violently strikes "+targ->query_cap_name()+"'s neck with a critical strike of "+ETO->query_possessive()+" battleaxe!%^RESET%^",({ETO,targ}));
        return roll_dice(1,6)+2;
    }
}
