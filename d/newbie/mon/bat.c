#include <std.h>
inherit WEAPONLESS;

void create() {
  ::create();
  set_name("bat");
  set_id(({"bat","large bat"}));
  set_short("A large bat");
  set_long("%^BOLD%^%^BLACK%^The large bat is a dull black in color which makes it blend in with any dark or shadowy surface.  It's very quick as it flies around.\n");
  set_race("bat");
  set_body_type("fowl");
  set_gender("female");
  set_size(1);
  set("aggressive",25);
  set_hd(1,1);
  set_level(1);
  set_class("fighter");
  set_max_hp(15);
  set_hp(random(5)+10);
  //set_exp(20);
  set_new_exp(1,"very low");
  set_damage(1,3);
  set_attacks_num(1);
  remove_limb("beak");
  set_base_damage_type("piercing");
  set_attack_limbs(({"right claw","left claw","right wing","left wing"}));
  set_ac(10);
  set_alignment(9);
  set_stats("intelligence",2);
  set_stats("wisdom",2);
  set_stats("strength",4);
  set_stats("charisma",2);
  set_stats("dexterity",15);
  set_stats("constitution",14);
  set_new_exp(1, "very low");
}
