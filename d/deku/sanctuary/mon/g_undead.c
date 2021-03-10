#include <std.h>
#include "../dragon.h";

inherit MONSTER;
object ob;

void create() {
   ::create();
   set_name("greater warrior");
   set_id(({"warrior","skeleton","skeleton warrior","greater skeleton warrior"}));
   set_short("Greater skeleton warrior");
   set_long(
      "This skeleton is fully armed and prepared for combat."+
      " It is suprisingly quick and agile, not just for undead,"+
      " but for anyone."
   );
   set_race("undead");
   set_wielding_limbs(({"right hand","left hand"}));
   set_gender("neuter");
   set_hd(20,8);
   set_class("fighter");
   set_mlevel("fighter",20);
   set_guild_level("fighter",20);
   set_alignment(9);
   set_max_hp(250);
   set_hp(250);
   set_overall_ac(1);
   set_mob_magic_resistance("average");
   set_property("no bows",1);
   set_property("no death",1);
   set_property("no dominate",1);
   set_property("no paralyze",1);
   set_property("no hold",1);
   set_property("full attacks",1);
   set_size(2);
   set("aggressive",30);
   set_exp(17000);
   set_stats("strength",25);
   set_stats("dexterity",12);
   ob = new(WEAP+"longsword");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   force_me("wield longsword");
   ob = new(ARMOR+"field");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   force_me("wear plate");
   ob = new(ARMOR+"helm");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   force_me("wear helm");
   ob = new(ARMOR+"mshield");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   force_me("wear shield");
   ob = new(OBJ+"warlordamulet")->move(TO);
   force_me("wear amulet");
   set_max_level(23);
}

void init() {
   ::init();
   if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"The skeleton looks right at you.");
      TO->force_me("kill "+TP->query_name()+"");
   }
}
