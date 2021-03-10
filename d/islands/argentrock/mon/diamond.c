//Mob for Diamond Dust Fan (/d/islands/argentrock/obj/diamond_fan.c")
//Cythera 9/21/05
#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("diamond shard");
  setenv("MIN", "$N hovers in the air.");
  setenv("MOUT", "$N floats off to the $D.");
  set_id(({"diamond shard","diamond","shard"}));
  set_short("%^BOLD%^%^WHITE%^D%^YELLOW%^i%^WHITE%^a%^BLUE%^m%^WHITE%^o"+
		"%^MAGENTA%^n%^WHITE%^d Shard%^RESET%^");
  set_long("%^BOLD%^%^WHITE%^This diamond shard is shines brilliantly in the "+
       "light.  Fused inside the crystal clear shard are specks of %^YELLOW%^"+
       "yellow%^WHITE%^, %^BLUE%^blue%^WHITE%^, and %^MAGENTA%^pink%^WHITE%^. "+
       " The shard floats in the air.");
  set_hd(35,5);
  set_max_hp(25);
  set_hp(25);
  set_gender("neuter");
  set_race("shard");
  set_body_type("snake");
  remove_limb("tail");
  remove_limb("mouth");
  remove_limb("head");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_mob_magic_resistance("extremely high");
  set_attacks_num(1);
  set_damage(3,3);
  set_attack_limbs(({"torso"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
}
