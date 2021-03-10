//felemental.c

#include <std.h>

inherit WEAPONLESS;

void create(){
   int num;

   ::create();
   set_name("fire elemental");
   set_id(({"fire","fire elemental","elemental","felemental"}));
   set_short("Fire Elemental");
   set_long(
@PEG
    %^BOLD%^%^YELLOW%^You look into this inferno. It has almost what
look like arms, maybe even a face. You hastily look for water or
anything to hide in. This creature is truly fearsome you think of the
pain that could be caused by all this fire.
PEG
   );
   num = random(100);
   switch (num) {
   case 0..74:
      set_hd(12,1);
      break;
   case 75..98:
      set_hd(16,1);
      break;
   case 99:
      set_hd(21+random(4),1);
      break;
   default:
      set_hd(12,1);
      break;
   }
   set_hp(query_hd()*8);
   set_exp(1);
   set_stats("strength",18);
   set_stats("intelligence",7);
   set_stats("dexterity",4);
   set_race("elemental");
   add_limb("torso","torso",50,0,2);
   add_limb("right flame","torso",50,0,2);
   add_limb("left flame","torso",50,0,2);
   add_limb("base","torso",50,0,2);
   set_attack_limbs(({"left flame", "right flame"}));
   set_damage(3,8);
   set_attacks_num(1);
   set_base_damage_type("bludgeoning");
   set_gender("sexless");
   set_overall_ac(0);
}


