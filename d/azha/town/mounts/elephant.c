// elephant: exotic mount for azha, by Nienne, 10/04 //
#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"elephant"}));
  set_name("elephant");
  set_short("%^BLACK%^%^BOLD%^A huge gray elephant%^RESET%^");
  set_long("This creature is enormous!  It has drab gray skin, a long trunk, and a pair of ivory tusks at either side of its mouth.");
  set_value(10500);
  set_race("elephant");
  set_body_type("quadruped");
  set_size(3);
  set_max_hp(100);
  set_hp(100);
  set_hd(10,8);
  set_max_distance(300);
  set_enter_room(" stomps in on a great elephant.");
  set_exit_room(" stomps out on a great elephant.");
  set_vehicle_short("%^BLACK%^%^BOLD%^A huge gray elephant%^RESET%^");
  set_riding_level(10);
  set_attack_limbs(({"right forefoot","left forefoot","tusks"}));
  set_attacks_num(2);
  set_damage(3,4);
  set_stats("strength",19);
  set_overall_ac(-2);
  TO->force_me("message in stomps in.");
  TO->force_me("message out stomps out $D.");
}
