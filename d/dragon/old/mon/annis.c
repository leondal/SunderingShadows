// annis.c

#include <std.h>

inherit WEAPONLESS;

create() {
  ::create();
  set_name("annis");
  set("id", ({"annis", "Annis"}) );
  set_short("Annis");
  set_long("These creatures are relatives of the night hags of the lower\n"+
           "plains.  They typically attack with their teeth inflicting\n"+
           "horrible wounds.  Her hair, teeth, and nails are glossy black\n"+
          "and eyes are dull and inflict pain just by looking at you.\n");
  set("race", "undead");
  set_gender("female");
  set_hd(10,5);
  add_limb("right leg","torso",0,0,0);
  add_limb("left leg","torso",0,0,0);
  add_limb("right arm","torso",0,0,0);
  add_limb("left arm","torso",0,0,0);
  add_limb("torso","torso",0,0,0);
  add_limb("head","torso",0,0,0);
  add_limb("right talon","right arm",0,0,0);
  add_limb("left talon","left arm",0,0,0);
  add_limb("mouth","head",0,0,0);
  set_alignment(9);
  set_overall_ac(4);
  set_size(2);
  set_damage(4,4);
  set_stats("strength", 20);
  set("aggressive", 15);
  set_attack_limbs(({"mouth","left talon","right talon"}));
  set_attacks_num(3);
  set_money("electrum",random(20));
  set_money("gold",random(100));
  set_hp(100);
}
