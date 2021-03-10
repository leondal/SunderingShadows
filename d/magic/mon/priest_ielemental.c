//ielemental.c. Nienne, 07/05.

#include "summoned_monster.h"
inherit WEAPONLESS;

void create(){
   int num;

   ::create();
   set_name("ice elemental");
   set_id(({"elemental","ice elemental","ielemental","summoned monster"}));
   set_short("Ice Elemental");
   set_long("%^BOLD%^%^CYAN%^This massive creature appears to have a vaguely humanoid sape, just like a "
"statue.  However its whole body is crystalline and semi-transparent, made entirely of ice!  Its limbs are "
"thick and look impressively heavy, and two %^BOLD%^%^WHITE%^glowing white orbs %^BOLD%^%^CYAN%^seem to serve "
"as its eyes.  An icy aura of cold radiates out from the creature, chilling the air around it.%^RESET%^");
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
   add_limb("right crest","right fist",50,0,2);
   add_limb("left crest","left fist",50,0,2);
   add_limb("head","head",50,0,2);
   add_limb("base","base",50,0,2);
   set_race("elemental");
   set_gender("sexless");
   set_attack_limbs(({"right fist","left fist"}));
   set_damage(5,6);
   set_base_damage_type("bludgeoning");
   set_attacks_num(1);
   set_overall_ac(0);
}
