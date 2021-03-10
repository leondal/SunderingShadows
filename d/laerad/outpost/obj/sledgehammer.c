#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg.c";

create() {
   ::create();
   set_id(({"warhammer","hammer","large hammer","sledgehammer","sledge","sledge hammer"}));
   set_name("sledgehammer");
   set_obvious_short("A sledgehammer");
   set_short("%^BOLD%^%^BLACK%^sledgehammer%^RESET%^");

   set_long(
      "This is a large sledgehammer. There isn't anything extraordinary "+
	  "about this one, besides it is made of dwarven steel and in remarkable "+
	  "good quality. It is a weapon which could really pack a punch if used as a weapon."
   );
 
   set_value(250);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((: TO,"extra_hit" :));
   set_property("enchantment",2);
   set_item_bonus("damage bonus",1);
}

int wield_func(string str) {
    if((int)ETO->query_level() < 10) {
        tell_object(ETO,"This hammer is simply too heavy for you!");
        return 0;
    }
    
    return 1;
}

int extra_hit(object vic) {
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(vic)) return 1;
    if(!random(10)) {
        tell_object(ETO,"%^RED%^You deliver a massive blow with the heavy sledgehammer!%^RESET%^");
        tell_object(vic,"%^RED%^"+ETO->query_cap_name()+"%^RED%^ hits you with a massive blow from "+ETO->QP+"%^RED%^ sledgehammer%^RESET%^");
        tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+" deals "+vic->QCN+" a massive blow with "+ETO->QP+" sledgehammer!%^RESET%^", ({ETO,vic}));
        vic->set_tripped(1,"You feel dazed from the hammer blow!");
        vic->do_damage("torso",random(10)+4);
        return 1;
    }
    
}
