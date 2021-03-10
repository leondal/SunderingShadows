#include <std.h>
#include "../dragon.h";

inherit MONSTER;

void create() {
object ob;
   ::create();
   set_name("everardus");
   set_id(({"everardus","saidson","mage"}));
   set_short("Everardus Saidson");
   set_long(
      "Everardus is a tall standing man clad in blue robes."+
      " He moves with purpose and confidence. There is a certain aura"+
      " about him, of either confidence or power."
   );
   set_race("human");
   set_gender("male");
   set_hd(20,3);
   set_class("mage");
   set_mlevel("mage",20);
   set_guild_level("mage",20);
   add_search_path("/cmds/wizard");
   set_alignment(3);
   set_max_hp(470);
   set_hp(470);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_property("no steal", 1);
   set_property("no animate", 1);
   set_property("no bows", 1);
   set_size(2);
   set("aggressive",30);
   set_exp(40000);
   set_stats("strength",11);
   set_stats("intelligence",18);
   set_stats("constitution",15);
   set_stats("wisdom",16);
   set_stats("dexterity",16);
   set_stats("charisma",12);
   ob = new(OBJ+"serpentcoat")->move(TO);
   ob = new(OBJ+"wizardhat");
   if(random(2)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   force_me("wearall");
   force_me("wear hat");
   ob = new(OBJ+"redstone")->move(TO);
   ob = new(OBJ+"paper01")->move(TO);
   set_spells(({
      "powerword stun",
      "chain lightning",
      "hideous laughter",
      "cone of cold",
      "vampiric touch",
      "fireball",
      "meteor swarm",
      "meteor swarm",
      "chain lightning",
   }));
   set_spell_chance(100);
   set_max_level(23);
}
