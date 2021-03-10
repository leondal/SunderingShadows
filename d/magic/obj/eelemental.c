//eelemental.c

#include <std.h>

inherit WEAPONLESS;

void create(){
   int num;

   ::create();
   set_name("earth elemental");
   set_id(({"elemental","earth elemental","eelemental"}));
   set_short("Earth Elemental");
   set_long(
@PEG
    The massive mound of clay seems to be vaguely molded into
a semi human form. It has no feet and two log like appendages for arms. A
round bulge swells in the middle of the top of the creature. These earth
elementals are truly fearsome. You heard that castle walls fall to their blows.
PEG
   );
   num = random(100);
   switch (num) {
   case 0..59:
      set_hd(12,1);
      break;
   case 60..94:
      set_hd(16,1);
      break;
   case 95..99:
      set_hd(21+random(4),1);
      break;
   default:
      set_hd(12,1);
   }
   set_hp(query_hd()*8);
   set_exp(1);
   set_stats("strength",18);
   set_stats("intelligence",7);
   set_stats("dexterity",4);
   set_race("elemental");
   add_limb("torso","torso",50,0,2);
   add_limb("right appendage","torso",50,0,2);
   add_limb("left appendage","torso",50,0,2);
   add_limb("base","torso",50,0,2);
   set_attack_limbs(({"left appendage", "right appendage"}));
   set_damage(4,8);
   set_attacks_num(1);
   set_base_damage_type("bludgeoning");
   set_overall_ac(0);
}


