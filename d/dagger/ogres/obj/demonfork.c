#include <std.h>
#include "/realms/grendel/grendel.h"

inherit "/d/common/obj/weapon/mspear.c";

void create() {
    ::create();
    set_name("Demon Fork");
    set_id( ({"fork", "military fork", "tanar'ri Barb", "barb"}) );
    set_short("%^RESET%^%^RED%^T%^RESET%^%^BOLD%^%^RED%^a%^RESET%^%^RED%^"+
"nar'ri B%^RESET%^%^BOLD%^%^BLACK%^arb%^RESET%^");
    set_obvious_short("%^RESET%^%^RED%^blood e%^RESET%^%^BOLD%^%^BLACK%^"+
"n%^RESET%^%^RED%^crusted m%^RESET%^%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^"+
"litary fo%^RESET%^%^BOLD%^%^BLACK%^rk%^RESET%^");
    set_long(
      "%^RESET%^%^RED%^This short fork has a %^RESET%^%^ORANGE%^haft of "+
"unknown material %^RESET%^%^RED%^that is cool to the touch. It is almost "+
"three feet long, easily wieldable in one hand. The fork ends in three half "+
"foot prongs made of %^RESET%^%^BOLD%^%^BLACK%^obsidion%^RESET%^%^RED%^. Each"+
" prong is wickedly sharp, and encrusted with several layers of %^RESET%^%^BOLD%^"+
"%^RED%^blood%^RESET%^"
    );
   set_lore("%^BLACK%^%^BOLD%^Each one of the forks favored by the Tanar'ri are "+
"forged in the Abyss, brought to the material plane by only the strongest of the "+
"horde of demons. Each soul taken by the fork seems to feed it, and the power within"+
" it can become enough to do physical harm to those of good heart who even touch "+
"them.\n%^RESET%^");
    set("value", 5000);
    set_property("enchantment", 4);
    set_hit((:this_object(), "extra_hit":));
    set_wield((:this_object(), "extra_wield":));
   set_unwield((:TO,"removeme":));
}

int extra_wield() {
    if((TP->query_level() < 20) && ((string)TP->query_name() != "Maurezhi Demon")) {
      tell_object(TP, "%^RED%^You are not strong enough to handle this weapon.");
      return 0;
    } else {
      tell_object(TP, "%^RED%^You feel the demonic power in the fork flow into you.");
      tell_room(ETP, TPQCN+" cackles insanely as the power of the fork flows into them.", TP);
      if(is_good(TP)){
        TP->do_damage("torso", roll_dice(5,5));
        TP->add_attacker(TO);
        TP->continue_attack();
        TP->remove_attacker(TO);
      }
   ETO->set_property("evil item",1);
      return 1;
    }
}

int removeme() {
   ETO->set_property("evil item",-1);
   return 1;
}

int extra_hit(object targ) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   targ = ETO->query_current_attacker();
    if(random(10) < 2) {
      tell_object(targ, "%^RED%^   The fork drives deep into your gut, and you can feel it's poision start to seep into you!");
      tell_room(environment(query_wielded()), "%^RED%^   The fork drives deep into "+targ->query_cap_name()+"'s gut!", targ);

      if(is_good(query_wielded())){
        tell_object(query_wielded(), "%^RED%^You feel a sharp pain in your hands as the fork feels the joy of drawing blood!%^RESET%^");
        query_wielded()->do_damage("torso", roll_dice(2,5));

        return random(5);
      } else {
        targ->add_poisoning(15);
        return (random(5)+3);
      }
    }
}
