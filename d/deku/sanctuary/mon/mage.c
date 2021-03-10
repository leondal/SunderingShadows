#include <std.h>
#include "../dragon.h";

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("zombie");
   set_id(({"zombie","sanctmob"}));
   set_short("Decaying zombie");
   set_long(
      "This is a decrepit walking corpse. It is garbed in an old tattered robe"+
      " and smells of corrosion and death. Its lifeless eyes glaze over the"+
      " scene with no apparent interest in anything except the living."
   );
   set_race("undead");
   set_gender("neuter");
   set_hd(15,8);
   set_class("mage");
   set_guild_level("mage",15);
   set_alignment(9);
   set_max_hp(189);
   set_hp(189);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_size(2);
   set("aggressive",30);
   set_exp(14000);
   set_attacks_num(2);
   add_limb("right fist", "right arm", 0, 0, 0);
   add_limb("left fist", "left arm", 0, 0, 0);
   set_attack_limbs(({"right fist","left fist"}));
   set_base_damage_type("bludgeoning");
   set_damage(1,12);
   set_stats("strength",14);
   set_stats("dexterity",15);
   set_spells(({
      "fireball",
      "lightning bolt",
      "cone of cold",
      "scorcher",
   }));
   set_spell_chance(90);
  set_max_level(23);
}

void init() {
   ::init();
   if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"The zombie looks right at you.");
      TO->force_me("kill "+TP->query_name()+"");
   }
}
