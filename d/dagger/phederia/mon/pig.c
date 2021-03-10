#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("pig");
  set_id(({"pig","sickly looking pig"}));
  set_short("Sickly looking pig");
  set_long("  This patetic looking pig is crusted with dried mud and seems to wander about weakly.   Its been wandering through the fields  in search of food after nearly starving in its pen.");
  set_hd(3,8);
  set_max_hp(25);
  set_hp(25);
  set_race("pig");
  set_body_type("equine");
  set_ac(7);
  set_exp(100);
  set_gender("female");
  set_attacks_num(1);
  set_damage(1,6);
  set_attack_limbs(({"head","hoof"}));
  set_stats("strength",17);
  set_moving(1);
  set_speed(20);
  set_base_damage_type("blunt");
}
