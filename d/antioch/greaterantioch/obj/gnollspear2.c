#include <std.h>
inherit "/d/common/obj/weapon/mspear.c";

create(){
   ::create();
   set_id(({"spear"}));
   set_name("gnollspear");
   set_obvious_short("A finely-crafted tribal decorated spear");
   set_short("%^BOLD%^%^BLUE%^Tr%^BOLD%^%^CYAN%^ib%^BOLD%^%^BLUE%^al %^BOLD%^%^RED%^Sp%^BOLD%^%^BLACK%^ea%^BOLD%^%^BLUE%^r%^RESET%^");
   set_long(
      "%^RESET%^%^RED%^This long, %^BOLD%^%^CYAN%^steel%^RESET%^%^RED%^-tipped spear"+
      " looks well crafted. A %^BOLD%^%^WHITE%^worn cloth %^RESET%^%^RED%^covers a large"+
      " portion of the shaft. Two long pieces of %^RESET%^%^ORANGE%^leather %^RESET%^%^RED%^"+
      " hang down, with %^BOLD%^%^YELLOW%^feathers %^RESET%^%^RED%^hanging from it. The spear"+
      " is obviously tribally made, though looks quite vicious.%^RESET%^"
   );
   set_property("enchantment",2);
   set_item_bonus("armor bonus",1);
   set_value(1300);
   set_wield((:TO,"wieldit":));
   set_unwield((:TO,"unwieldit":));
   set_hit((:TO,"hitit":));
}
int wieldit() {
   tell_object(ETO,"%^BOLD%^%^YELLOW%^You grasp the spear tightly, prepared for battle.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+" lifs the spear "+ETO->query_possessive()+" and prepares for battle.%^RESET%^",ETO);
   return 1;
}
int unwieldit() {
   tell_object(ETO,"%^BOLD%^%^YELLOW%^You relax your grip on the spear.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+" relaxes their grip from the spear.%^RESET%^",ETO);
   return 1;
}
int hitit(object targ){
    if(random(1000) < 200){
        if(!objectp(targ)) {
            return roll_dice(1,6);
        }
        tell_object(ETO,"%^BOLD%^%^WHITE%^You stab deeply into "+targ->query_cap_name()+"'s flesh with the tip of %^BOLD%^%^RED%^spear%^BOLD%^%^WHITE%^!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" stabs deep into your flesh with the spear!%^RESET%^");
        tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^" +ETO->query_cap_name()+" stabs deeply into "+targ->query_cap_name()+"'s flesh with "+ETO->query_possessive()+" spear!%^RESET%^",({ETO,targ}));
        return roll_dice(2,6)+2;
    }
}
