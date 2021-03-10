#include <std.h>
inherit WEAPONLESS;

void create(){
  ::create();
  set_name("dust mephit");
  setenv("MIN", "$N swirls in with a trail of %^ORANGE%^debris");
  setenv("MOUT", "$N swirls out $D leaving a trail of %^ORANGE%^debris");
  set_id(({"mephit","dust mephit"}));
  set_short("%^BOLD%^%^BLACK%^A dust mephit");;
  set_long("This unusual little creature seems made of nothing more "+
     "than swirling air and dust particles.  It is vaguely humanoid "+
     "in shape with wing-shaped appendages extending from its back.  "+
     "Two smoldering red eyes peer forth from the ever-moving cloud"+
     " of debris.");
  set_hd(35,5);
  set_max_hp(25);
  set_hp(25);
  set_race("mephit");
  set_body_type("human");
  set_ac(0);
  set_exp(1);
  set_size(1);
  set_property("magic",1);
  set_mob_magic_resistance("average");
  set_attacks_num(1);
  set_damage(3,3);
  set_attack_limbs(({"claws"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
}