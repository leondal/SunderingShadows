// tiger: exotic mount for azha, by Nienne, 10/04 //
#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"tiger"}));
  set_name("tiger");
  set_short("%^RESET%^%^RED%^A large, fierce tiger%^RESET%^");
  set_long("This feline moves with stealth and grace, though it's quite apparent from the size of its claws and teeth that it has the potential to be -very- dangerous.");
  set_value(2800);
  set_race("tiger");
  set_body_type("quadruped");
  set_max_hp(150);
  set_hd(3,1);
  set_max_distance(400);
  set_enter_room(" stalks in on a great tiger.");
  set_exit_room(" stalks out on a great tiger.");
  set_vehicle_short("%^RESET%^%^RED%^A large, fierce tiger%^RESET%^");
  set_riding_level(15);
  set_attack_limbs(({"right forepaw","left forepaw","teeth"}));
  set_attacks_num(3);
  set_damage(1,6);
  set_stats("strength",17);
  set_stats("dexterity",19);
  set_overall_ac(2);
  TO->force_me("message in slinks in gracefully.");
  TO->force_me("message out stalks out $D.");
}
