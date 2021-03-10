#include <std.h>
#include "/realms/grendel/grendel.h"

inherit WEAPON;

void create() {
    ::create();
    set_name("Demon Fork");
    set_id( ({"fork", "demon fork", "Demon Fork", "df"}) );
    set_short("%^RED%^Demon fork%^RESET%^");
    set_obvious_short("a military fork");
    set_long(
      "This is a three pronged fork, one of the favorite weapons of the humanoid demons of the underworld.  Encrusted with ancient blood, a strange rune is inscribed where the three points connect to the handle."
    );
    set_weight(13);
    set("value", 500);
    set_wc(2,5);
    set_large_wc(2,7);
    set_size(2);
    set_type("piercing");
    set_prof_type("demonfork");
    set_property("enchantment", 3);
    set_hit((:this_object(), "extra_hit":));
    set_wield((:this_object(), "extra_wield":));
   set_unwield((:TO,"removeme":));
}

int extra_wield() {
    if((TP->query_level() < 20) && ((string)TP->query_name() != "Marlith")) {
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
    if(random(10) < 2) {
      tell_object(targ, "%^RED%^   The demon fork drives deep into your gut, and you can feel it's poision start to seep into you!");
      tell_room(environment(query_wielded()), "%^RED%^   The demonfork drives deep into "+targ->query_cap_name()+"'s gut!", targ);

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
