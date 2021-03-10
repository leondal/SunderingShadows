#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("robin");
  set_id(({"robin","bird"}));
  set_short("%^RESET%^%^RED%^Robin%^RESET%^");
  set_long("  This small bird pecks away at a small worm on the ground, oblivious the dangers of these hedges.");
  set_hd(1,8);
  set_max_hp(25);
  set_hp(25);
  set_race("robin");
  set_body_type("fowl");
  set_ac(7);
  set_exp(500);
  set_attacks_num(1);
  set_damage(1,1);
  set_attack_limbs(({"beak"}));
  set_stats("strength",17);
  set_base_damage_type("slashing");
}
