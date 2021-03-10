#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg.c";

create() {
   ::create();
   set_id(({"warhammer","hammer","large hammer","large war hammer","forge","Forge"}));
   set_name("forge");
   set_obvious_short("A large war hammer");
//   set_short("%^BOLD%^%^BLACK%^Hammer of the %^RESET%^F%^CYAN%^o%^BOLD%^%^BLACK%^r%^RESET%^g%^CYAN%^e%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Forge%^RESET%^");
//This hammer was intentionally named Forge (see lore), so changing it back :) ~Circe~ 4/30/08
   set_long(
      "This heavy hammer has a solid iron head tapered on both sides, "+
      "much like a hammer used by blacksmiths rather than those "+
      "typically used in battle.  A long chestnut handle has been "+
      "wrapped with leather strips to provide a better grip.  Obviously "+
      "made to be wielded with both hands, this hammer would probably "+
      "be very useful in the forge or in battle.  The flat of the hammer "+
      "head has been engraved in a block script."
   );
   set_lore(
      "The heavy hammers known simply as the Forge were originally made "+
      "by a prominent blacksmith in the fief of Drogheda.  Meant to be "+
      "used in the blacksmith's forge, they were eventually used instead "+
      "in the war on the lord.  Legend says that these hammers still find "+
      "their true potential in the hands of a warrior."
   );
   set_property("lore difficulty",10);
   set("read",
@CIRCE
%^BOLD%^%^BLUE%^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

%^BOLD%^%^BLACK%^   Under a spreading chestnut tree
      The village smithy stands;
    The smith, a mighty man is he,
     With large and sinewy hands;
 And the muscles of his brawny arms
      are strong as iron bands.

%^BOLD%^%^BLUE%^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
CIRCE
   );
   set_value(750);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((: TO,"extra_hit" :));
   set_property("enchantment",1);
   set_item_bonus("armor bonus",1);
}

int wield_func(string str) {
    if((int)ETO->query_level() < 10) {
        tell_object(ETO,"You may not wield such a fine weapon!");
        return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLUE%^You can feel the strength of your arms "+
       "as you heft the hammer.%^RESET%^");
    return 1;
}
int unwield_func(string str) {
    tell_object(ETO,"%^BLUE%^You slowly release your grip on the hammer!%^RESET%^");
    return 1;
}
int extra_hit(object vic) {
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(vic)) return 1;
    if(!random(10)) {
        tell_object(ETO,"%^RED%^You turn the hammer in mid-air, "+
           "striking quickly with both sides!%^RESET%^");
        tell_object(vic,"%^RED%^"+ETO->query_cap_name()+" turns the hammer "+
           "quickly in mid-air, striking you with both sides!%^RESET%^");
        tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+" turns "+
           ""+ETO->query_possessive()+" hammer in mid-air striking "+vic->query_cap_name()+" "+
           "stoutly with both sides!%^RESET%^", ({ETO,vic}));
        vic->set_tripped(1,"You feel dazed from the hammer blow!");
        vic->do_damage("torso",random(4)+4);
        return 1;
    }
    if(!random(30)) {
        tell_object(ETO,"%^YELLOW%^Sparks fly from the end of your hammer as "+
           "you whirl with amazing quickness!%^RESET%^");
        tell_object(vic,"%^YELLOW%^Sparks fly from "+ETO->query_cap_name()+"'s "+
           "hammer as he whirls and smashes it into you!%^RESET%^");
        tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+" spins "+
           "madly, causing a whirlwind of sparks to fly into "+vic->query_cap_name()+"!"+
           "%^RESET%^", ({ETO,vic}));
        ETO->execute_attack();
        return 1;
    }
    else return 1;
}
