#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
   set_name("An itty bitty spider");
  setenv("MIN", "$N scampers in.");
  setenv("MOUT", "$N creeps $D.");
   set_id(({"spider","small spider","itty bitty spider","prspider"}));
   set_short("%^BOLD%^%^BLACK%^An itty bitty spider%^RESET%^");;
   set_long("%^BOLD%^%^BLACK%^This is any itty bitty black spider.  It has eight long, hairy legs and an oval shaped body with a rear that is elongated and larger that its torso.");
  set_hd(20,2);
  set_max_hp(1);
  set_hp(1);
  set_race("spider");
  set_gender("male");
  set_body_type("arachnid");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_attacks_num(1);
  set_damage(1,3);
  set_attack_limbs(({"right pincer","left pincer","mouth"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
}
