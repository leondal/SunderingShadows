// changed to +1 with new enchantment settings, nienne 05/07
#include <std.h>
#include "../elfisland1.h"
inherit "/d/common/obj/weapon/claw.c";

create(){
   ::create();
   set_id(({"claw","gauntlet","clawed gauntlet"}));
   set_name("clawed gauntlet");
   set_obvious_short("A clawed gauntlet");
   set_short("%^RESET%^%^RED%^G%^BOLD%^%^WHITE%^o%^RESET%^%^RED%^re's %^RESET%^%^RED%^cl%^BOLD%^%^WHITE%^a%^RESET%^%^RED%^w%^RESET%^");
   set_long(
      "%^RESET%^%^RED%^The two eight inch %^BOLD%^%^WHITE%^blades %^RESET%^%^RED%^protrude ominously from an %^BOLD%^%^RED%^adamantine %^RESET%^%^RED%^"+
      "gauntlet. The %^BOLD%^%^WHITE%^blades %^RESET%^%^RED%^are sharpened to a magical keeness."+
      " The inner lining is made out of soft sheep skin,"+
      " making the fit snug but comfortable. The fingers of the"+
      " gauntlet allow for easy movement, making almost no"+
      " hindrance to the wearer's flexibility or combat potential."+
      " The %^BOLD%^%^RED%^adamantine %^RESET%^%^RED%^is dyed with a strange red substance, hueing"+
      " it to almost a blood red color. Small runes cover the gauntlet"+
      " that shift randomly. %^RESET%^"
   );
   set_property("enchantment",1);
   set_value(900);
   set_ac(1);
   set_wield((:TO,"wieldit":));
   set_unwield((:TO,"unwieldit":));
   set_hit((:TO,"hitit":));
}
int wieldit() {
   tell_object(ETO,"%^BOLD%^%^RED%^You slide the gauntlet on and clench your fist in anticipation.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" slides the gauntlet on and clenches "+ETO->query_possessive()+" fist in anticipation.%^RESET%^",ETO);
   return 1;
}
int unwieldit() {
   tell_object(ETO,"%^BOLD%^%^RED%^You let out a relieved sigh as you remove the gauntlet.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" removes the gauntlet and seems much more relaxed.%^RESET%^",ETO);
   return 1;
}
int hitit(object targ){
    if(random(1000) < 200){
        if(!objectp(targ)) {
            return roll_dice(1,6);
        }
        tell_object(ETO,"%^BOLD%^%^RED%^You slash deeply across "+targ->query_cap_name()+"'s flesh with the %^BOLD%^%^WHITE%^claws %^BOLD%^%^RED%^of the gauntlet!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" cuts deep into your flesh with the claws of a gauntlet!%^RESET%^");
        tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^" +ETO->query_cap_name()+" deeply slashes into "+targ->query_cap_name()+"'s flesh with "+ETO->query_possessive()+" clawed gauntlet!%^RESET%^",({ETO,targ}));
        return roll_dice(1,6)+2;
    }
}
