#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"canine","dog","cavvekan"}));
  set_name("cavvekan");
  set_short("A small bat-faced dog");
  set_long("This is definitely one of the stranger creatures you've seen, referred to by the drow as a "
"cavvekan. From a distance, it seems like some kind of large slender hound, covered in dark, unfurred skin "
"with the smoothness of velvet. However, at a closer look their faces are quite unique, resembling more that "
"of a bat. It has large, upright ears, small eyes, and long fangs like those of its canine relatives.");
  set_value(65);
  set_race("cavvekan");
  set_body_type("quadruped");
  set_max_hp(40);
  set_hd(8,10);
  set_size(1);
  set_max_distance(300);
  set_enter_room(" bounds in upon a small black canine.");
  set_exit_room(" bounds out upon a small black canine.");
  set_vehicle_short("A small bat-faced dog");
  set_riding_level(6);
  TO->force_me("message in bounds in.");
  TO->force_me("message out bounds out $D.");
  set_funcs(({"special"}));
  set_func_chance(10);
  set_attack_limbs(({"right forefoot","left forefoot","teeth"}));
  set_base_damage_type("piercing");
  set_attacks_num(1);
  set_damage(3,4);
  set_stats("strength",12);
  set_stats("dexterity",18);
  set_overall_ac(-2);
  set_property("knock unconscious",1);
}

void special(object target) {
   if (!objectp(target)) return;
   tell_object(target,"%^BOLD%^%^BLACK%^The cavvekan snarls and sinks its sharp fangs into your "
"skin!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^BLACK%^The cavvekan snarls and sinks its sharp fangs into "+target->QCN+"'s "
"skin!%^RESET%^",target);
  target->do_damage("torso",random(8)+5);
   return;
}
