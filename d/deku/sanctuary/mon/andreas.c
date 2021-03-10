#include <std.h>
#include "../dragon.h";

inherit MONSTER;

void create() {
object ob;
   ::create();
   set_name("andreas");
   set_id(({"andreas","kelun","mage"}));
   set_short("Andreas Kelun");
   set_long(
      "Andreas is a young man with red hair and a muscular build."+
      " He is dressed in the typicaly garments of a mage."
   );
   set_race("human");
   set_gender("male");
   set_hd(10,2);
   set_class("mage");
   set_mlevel("mage",10);
   set_guild_level("mage",10);
   add_search_path("/cmds/wizard");
   set_alignment(3);
   set_max_hp(248);
   set_hp(248);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_property("no bows", 1);
   set_size(2);
   set("aggressive",30);
   set_exp(17000);
   set_stats("strength",14);
   set_stats("intelligence",18);
   set_stats("constitution",13);
   set_stats("wisdom",15);
   set_stats("dexterity",16);
   set_stats("charisma",17);
   ob = new("/d/common/obj/rand/mage_robes.c");
   ob->remove_property("enchantment");
   ob->set_property("enchantment",3+random(2));
   ob->move(TO);
   ob = new(OBJ+"wizardhat");
   if(random(2)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   force_me("wearall");
   force_me("wear hat");
   set_spells(({
      "lower resistance", "magic missile", "dispel magic", "magic missile"
   }));
   set_spell_chance(100);
   set_max_level(23);
}

