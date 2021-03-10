//limbs changed by Circe to help stop bugging.  3/19/05
#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("white owl");
  setenv("MIN", "$N flys in and circles the room.");
  setenv("MOUT", "$N flys silently off to the $D.");
  set_id(({"owl","white owl","bird"}));
  set_short("%^BOLD%^%^WHITE%^White owl%^RESET%^");;
  set_long("A massive, ferocious looking white owl.   Long claws and beak made for slashing makes it an effective predator of the night.");
  set_hd(35,5);
  set_max_hp(25);
  set_hp(25);
  set_race("owl");
  set_body_type("fowl");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_mob_magic_resistance("average");
  set_attacks_num(1);
  set_damage(3,3);
//  set_attack_limbs(({"razored claws","slashing beak"}));
  set_attack_limbs(({"right claw","left claw","beak"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
}
