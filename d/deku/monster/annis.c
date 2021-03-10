#include <std.h>

inherit WEAPONLESS;

create() {
  ::create();
  set_name("annis");
  set_id(({"annis", "Annis"}));
  set_short("Annis");
  set_long("These creatures are relatives of the night hags of the lower\n"+
           "plains.  They typically attack with their teeth inflicting\n"+
           "horrible wounds.  Her hair, teeth, and nails are glossy black\n"+
          "and eyes are dull and inflict pain just by looking at you.\n");
  set_race("undead");
  set_gender("female");
  set_hd(10,5);
  set_body_type("humanoid");
  add_limb("right talon","right arm",0,0,0);
  add_limb("left talon","left arm",0,0,0);
  add_limb("mouth","head",0,0,0);
  set_alignment(9);
  set_overall_ac(4);
  set_size(2);
  set_stats("strength",17);
  set_stats("dexterity",12);
  set_stats("constitution",9);
  set_stats("wisdom",12);
  set_stats("intelligence",12);
  set_stats("charisma",8);
  set_damage(3,4);
  set("aggressive", 15);
  set_attack_limbs(({"mouth","left talon","right talon"}));
  set_attacks_num(3);
  set_money("electrum",random(20));
  set_money("gold",random(100));
  set_hp(80 + random(41));
  set_exp(query_max_hp() * 10);
}
