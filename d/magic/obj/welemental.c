//welemental.c

#include <std.h>

inherit WEAPONLESS;

void create(){
   int num;

   ::create();
   set_name("water elemental");
   set_id(({"elemental","water elemental","welemental"}));
   set_short("Water Elemental");
   set_long(
@PEG
    %^BOLD%^%^BLUE%^This large creature appears as a large wave with a vaguely
humanoid shape. The arms are merely smaller waves. From deep inside the
wavelike body you see two green orbs that serve as eyes. You can see
the ebbing and flowing in the monster.
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
   set_stats("dexterity",10);
   add_limb("torso","torso",50,0,2);
   add_limb("right crest","right crest",50,0,2);
   add_limb("left crest","left crest",50,0,2);
   add_limb("upper crest","upper crest",50,0,2);
   add_limb("base","base",50,0,2);
   set_race("elemental");
   set_gender("sexless");
   set_attack_limbs(({"right crest","left crest"}));
   set_damage(5,6);
   set_base_damage_type("bludgeoning");
   set_attacks_num(1);
   set_overall_ac(0);
}

