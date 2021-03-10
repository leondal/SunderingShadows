//Mob for Spiked Gauntlet of the Burning Hell (/d/islands/argentrock/obj/diamond_fan.c")
//Cythera 9/21/05
#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("hellhound");
  setenv("MIN", "$N stalks in.");
  setenv("MOUT", "$N stalks off to the $D.");
  set_id(({"hound","hell hound","hellhound"}));
  set_short("%^RESET%^%^RED%^Hellhound%^RESET%^");
  set_long("%^RED%^This hellhounds is a rusty red to red "+
	"brown in color.  His eyes are glowing %^BOLD%^red"+
	"%^RESET%^%^RED%^ while teeth and tongues are "+
	"%^BOLD%^%^BLACK%^sooty black%^RESET%^%^RED%^.  "+
	"Flames spark out of his nostrils with every "+
	"little breath, giving him a menacing look.");
  set_hd(35,5);
  set_max_hp(25);
  set_hp(25);
  set_gender("male");
  set_race("hellhound");
  set_body_type("quadruped");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_mob_magic_resistance("insanely high");
  set_attacks_num(1);
  set_damage(3,3);
  set_attack_limbs(({"torso"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
}
