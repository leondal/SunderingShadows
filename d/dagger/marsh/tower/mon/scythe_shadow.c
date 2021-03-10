#include <std.h>
inherit WEAPONLESS;

void create(){
  ::create();
  set_name("looming shadow");
  setenv("MIN", "$N flickers in.");
  setenv("MOUT", "$N flickers silently off to the $D.");
  set_id(({"shadow","looming shadow","daggershadow0"}));
  set_short("%^BOLD%^%^BLACK%^A looming shadow%^RESET%^");;
  set_long("Difficult to see, this creature seems to be made of "+
     "shadow itself.  It seems to flicker in and out of existence, "+
     "leaving only the impression of an indistinct humanoid shape.");
  set_hd(35,5);
  set_max_hp(25);
  set_hp(25);
  set_race("shadow");
  set_body_type("human");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_mob_magic_resistance("average");
  set_attacks_num(1);
  set_damage(3,3);
  set_attack_limbs(({"claws"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
}
