//limbs changed by Circe to help stop bugging.  3/19/05
#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
   set_name("raven");
  setenv("MIN", "$N flys in and circles the room.");
  setenv("MOUT", "$N flys silently off to the $D.");
   set_id(({"bird","raven"}));
   set_short("%^BOLD%^%^BLACK%^Raven%^RESET%^");;
   set_long("%^BOLD%^%^BLACK%^A large dark black bird with a stout beak. It has long claws for slashing and makes for a very effective predator.");
  set_hd(35,5);
  set_max_hp(25);
  set_hp(25);
   set_race("raven");
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
