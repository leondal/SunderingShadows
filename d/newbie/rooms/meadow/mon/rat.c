#include <std.h>
inherit WEAPONLESS;

void create() {
  ::create();
  set_name("rat");
  set_id(({"rat","scrawny rat"}));
  set_short("A scrawny rat");
  set_long("%^ORANGE%^The scrawny brown rat has a scruffy coat and looks hungry.");
  set_race("rat");
  set_body_type("quadruped");
  set_gender("female");
  set_size(1);
  set("aggressive",25);
  set_hd(1,1);
  set_level(1);
  set_class("fighter");
  set_mlevel("fighter",1);
  set_max_hp(15);
  set_hp(random(5)+10);
  set_exp(20);
  set_damage(1,3);
  set_attacks_num(1);
  set_base_damage_type("piercing");
  add_limb("teeth", "head", 0, 0, 0);
  set_attack_limbs(({"right forepaw","left forepaw","teeth"}));
  set_ac(10);
  set_alignment(9);
  add_money("gold",random(10)+2);
  add_money("silver",random(10));
  set_stats("intelligence",2);
  set_stats("wisdom",2);
  set_stats("strength",5);
  set_stats("charisma",2);
  set_stats("dexterity",8);
  set_stats("constitution",12);
  set_new_exp(1, "very low");
}
