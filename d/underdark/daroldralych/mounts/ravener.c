#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"ravener","raptor","lizard"}));
  set_name("ravener");
  set_short("A vicious raptor");
  set_long("This vicious-looking reptile, known to the drow as a ravener, stands upon its hind-legs to walk "
"upright, with its razor-sharp clawed forelegs held before it for balance.  Its muscular, dark-scaled body "
"moves with the grace of a predator, and its sharp green eyes show a feral intelligence unlike any animal "
"you've seen in your life.");
  set_value(125);
  set_race("lizard");
  set_body_type("reptile");
  set_max_hp(60);
  set_hd(10,10);
  set_size(2);
  set_max_distance(500);
  set_enter_room(" stalks in astride a vicious raptor.");
  set_exit_room(" stalks out astride a vicious raptor.");
  set_vehicle_short("A vicious raptor");
  set_riding_level(12);
  TO->force_me("message in slinks in.");
  TO->force_me("message out slinks out $D.");
  set_funcs(({"special"}));
  set_func_chance(10);
  set_attack_limbs(({"right forefoot","left forefoot"}));
  set_base_damage_type("slashing");
  set_attacks_num(2);
  set_damage(3,4);
  set_stats("strength",16);
  set_stats("dexterity",18);
  set_overall_ac(-4);
  set_property("knock unconscious",1);
}

void special(object target) {
   tell_room(ETO,"%^RED%^The ravener goes into a rage, slashing at anything within reach!%^RESET%^");
   TO->execute_attack();
   TO->execute_attack();
   TO->execute_attack();
   return;
}
