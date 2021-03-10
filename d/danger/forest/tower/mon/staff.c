#include <std.h>

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("staff");
   set_id(({"mage staff","staff"}));
   set_short("A Floating Staff");
   set_long("If this staff was not floating, it would"+
   " be just another staff.");
   set_class("mage");
   set_mlevel("mage", 50);
   set_guild_level("mage", 50);
   set_max_hp(2000);
   set_hp(2000);
   set_exp(100000);
   set_overall_ac(-4);
   set_property("weapon resistance", 4);
   set_attack_limbs(({"blunt end"}));
   set_base_damage_type("blunt");
   set_attacks_num(1);
   set_damage(1,6);
   set_gender("neuter");
   set_race("staff");
   set_property("spell penetration",100);
   set_property("swarm", 1);
   set_stats("strength", 8);
   set_stats("dexterity", 14);
   set_stats("constitution", 20);
   set_stats("wisdom", 1);
   set_stats("intelligence", 25);
   set_stats("charisma", 1);
   set_spells(({
      "lightning orb",
      "prismatic spray",
      "hideous laughter",
	 "powerword stun",
	 "cone of cold",
	 "fireball",
	 "meteor swarm",
 	 "disintegrate"
   }));
   set_spell_chance(100);
}

void heart_beat(){
   ::heart_beat();
   if(!objectp(TO)) return;
   if(!query_stoneSkinned()) {
      new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,TO,40,100,"mage");
   }
}