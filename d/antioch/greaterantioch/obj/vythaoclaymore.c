#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword.c";

create(){
   ::create();
   set_id(({"sword","claymore"}));
   set_name("claymore");
   set_obvious_short("A well-crafted claymore");
   set_short("%^BOLD%^%^RED%^Vythao's %^BOLD%^%^WHITE%^B%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^e%^RESET");
   set_long(
      "%^RESET%^%^RED%^The nearly six-foot blade has a %^BOLD%^%^RED%^blood groove %^RESET%^%^RED%^that runs"+
      "the entire length of the sword. It's hilt is fairly simple, with no engravings. The pommel"+
      "is wrapped in rough %^RESET%^%^ORANGE%^leather%^RESET%^%^RED%^ and has"+
      "%^BOLD%^%^BLUE%^fea%^BOLD%^%^RED%^th%^BOLD%^%^YELLOW%^ers%^RESET%^%^RED%^ hanging"+
      "from it. The weapon seems to be well taken care of, and precision craftsmentship"+
      " went into its creation.%^RESET%^"
   );
   set_property("enchantment",2);
   set_value(1300);
   set_wield((:TO,"wieldit":));
   set_unwield((:TO,"unwieldit":));
   set_hit((:TO,"hitit":));
}
int wieldit() {
   tell_object(ETO,"%^BOLD%^%^RED%^You heft the blade up, it's weight seemingly well-balanced.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" draws the hefty blade "+ETO->query_possessive()+" and grips it tightly.%^RESET%^",ETO);
   return 1;
}
int unwieldit() {
   tell_object(ETO,"%^BOLD%^%^RED%^You release your grip on the hefty blade.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" relaxes their grip from the blade.%^RESET%^",ETO);
   return 1;
}
int hitit(object targ){
    if(random(1000) < 200){
        if(!objectp(targ)) {
            return roll_dice(1,6);
        }
        tell_object(ETO,"%^BOLD%^%^RED%^You cut deeply into "+targ->query_cap_name()+"'s flesh with the %^BOLD%^%^WHITE%^claymore%^BOLD%^%^RED%^!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" cuts deep into your flesh with the claymore!%^RESET%^");
        tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^" +ETO->query_cap_name()+" cuts deeply into "+targ->query_cap_name()+"'s flesh with "+ETO->query_possessive()+" claymore!%^RESET%^",({ETO,targ}));
        return roll_dice(1,6)+2;
    }
}
