#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

create(){
   ::create();
   set_id(({"dagger","quickdagger"}));
   set_name("platinum dagger");
   set_obvious_short("%^BOLD%^%^WHITE%^A beautiful platinum dagger%^RESET%^");
   set_short("%^BOLD%^%^CYAN%^Whir%^BOLD%^%^BLUE%^l%^BOLD%^%^CYAN%^wind%^RESET%^");
   set_long(
      "%^BOLD%^%^CYAN%^This exquisite blade is a %^BOLD%^%^YELLOW%^long %^BOLD%^%^CYAN%^dagger"+
      " which is elegantly simple in appearance. The pommel of the dagger has a small %^BOLD%^%^WHITE%^skull"+
      " %^BOLD%^%^CYAN%^which has %^BOLD%^%^RED%^fiery %^BOLD%^%^CYAN%^red eyes. The handle is wrapped in"+
      " %^RESET%^%^BLUE%^cold iron %^BOLD%^%^CYAN%^which fits tightly. The blade is plain with a narrow"+
      " blood groove along the lower portion. Well-balanced, this blade would be %^BOLD%^%^RED%^lethal"+
      " %^BOLD%^%^CYAN%^in combat.%^RESET%^");
   set_property("enchantment",2);
   set_value(1300);
   set_wield((:TO,"wieldit":));
   set_unwield((:TO,"unwieldit":));
   set_hit((:TO,"hitit":));
}
int wieldit() {
   tell_object(ETO,"%^BOLD%^%^CYAN%^You feel light-headed for a moment as you wield the blade.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" wields the "+ETO->query_possessive()+" and looks %^BOLD%^%^YELLOW%^dizzy %^BOLD%^%^CYAN%^for a moment.%^RESET%^",ETO);
   return 1;
}
int unwieldit() {
   tell_object(ETO,"%^BOLD%^%^YELLOW%^You lose your orientation for a moment as you unwield the blade.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+" unwield the blade and stumbles slightly, as if disorientated.%^RESET%^",ETO);
   return 1;
}
int hitit(object targ){
    if(random(1000) < 200){
        if(!objectp(targ)) {
            return roll_dice(1,6)+2;
        }
//            ETO->execute_attack();
// removed one, this weapon was sick overpowered even wielding just one. N, 7/12.
	    ETO->execute_attack();
        tell_object(ETO,"%^BOLD%^%^CYAN%^Suddenly you feel the world slow down around you as you quickly slice at "+targ->query_cap_name()+" with unnatural speed!");
        tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" %^BOLD%^%^YELLOW%^blurs %^BOLD%^%^WHITE%^for a moment as they strike you with unnatural speed!%^RESET%^");
        tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^" +ETO->query_cap_name()+" turns into a %^BOLD%^%^YELLOW%^blur %^BOLD%^%^CYAN%^for a moment as they slash "+targ->query_cap_name()+" with unnatural speed!%^RESET%^",({ETO,targ}));
        return roll_dice(1,6)+2;
    }
}
