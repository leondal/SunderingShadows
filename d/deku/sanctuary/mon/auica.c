#include <std.h>
#include "../dragon.h";

inherit MONSTER;

void create() {
object ob;
   ::create();
   set_name("auica");
   set_id(({"auica","kelun","mage"}));
   set_short("Auica Kelun");
   set_long(
      "Auica is a beautiful female human with long golden blonde hair"+
      " and cyan eyes. She is elegantly garbed in long flowing red mage"+
      " robes and is in charge of the day to day affairs of this tower."
   );
   set_race("human");
   set_gender("female");
   set_hd(20,2);
   set_class("mage");
   set_mlevel("mage",20);
   set_guild_level("mage",20);
   add_search_path("/cmds/wizard");
   set_alignment(3);
   set_max_hp(560);
   set_hp(560);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_property("no bows", 1);
   set_size(2);
   set("aggressive",30);
   set_exp(30000);
   set_stats("strength",14);
   set_stats("intelligence",18);
   set_stats("constitution",13);
   set_stats("wisdom",16);
   set_stats("dexterity",15);
   set_stats("charisma",20);
   ob = new("/d/common/obj/rand/randrobe.c")->move(TO);
   ob = new(OBJ+"paper04")->move(TO);
   ob = new(OBJ+"wizardhat");
   if(random(2)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   force_me("wearall");
   force_me("wear hat");
   set_spells(({
      "lightning orb",
      "scorcher",
      "prismatic spray",
      "hideous laughter"
   }));
   set_spell_chance(100);
   set_max_level(23);
}

void init() {
   ::init();
   if(TP->query_invis() && !avatarp(TP)) {
      TO->force_me("say You did not really think you could sneak up on me in my own tower did you?");
      TO->force_me("kill "+TP->query_name()+"");
   }
}
