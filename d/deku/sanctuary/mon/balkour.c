#include <std.h>
#include "../dragon.h";

inherit MONSTER;

void create() {
   object ob;
   ::create();
   set_name("balkour");
   set_id(({"balkour","skeleton","hero"}));
   set_short("Balkour, Fallen Hero");
   set_long(
      "This skeleton possesses an inner vigor not seen in most undead."+
      " Placed in the eye sockets are red lights that burn with desire."+
      " It is still wielding the sword and wearing the armor it was buried"+
      " with and appears to still be able to use them. It is fully equipped"+
      " with sword, shield, armor, and helm."
   );
//   set_race("undead");
//"undead" is not a valid race.  Changing it ~Circe~ 3/26/05
   set_race("human");
//   set_wielding_limbs(({"right hand","left hand"}));
//not needed with a valid race
   set_property("undead",1);
   set_gender("neuter");
   set_hd(20,8);
   set_class("fighter");
   set_mlevel("fighter",20);
   set_guild_level("fighter",20);
   set_alignment(9);
   set_max_hp(250);
   set_hp(250);
   set_overall_ac(0);
   set_mob_magic_resistance("average");
   set_property("no bows",1);
   set_property("no death",1);
   set_property("no dominate",1);
   set_property("no paralyze",1);
   set_property("no hold",1);
   set_property("full attacks",1);
   set_size(2);
   set("aggressive",30);
   set_exp(28000);
   set_stats("strength",25);
   set_stats("dexterity",12);
   ob = new(WEAP+"longsword");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   force_me("wield longsword");
   ob = new(OBJ+"banded");
   if(random(2)) ob->set_property("monsterweapon",1);
   ob->move(TO);
//   force_me("wear banded");
   ob = new(ARMOR+"helm");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
//   force_me("wear helm");
   ob = new(ARMOR+"mshield");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
//   force_me("wear shield");
   force_me("wearall");
   set_max_level(23);
}

void init() {
   ::init();
   if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"The skeleton looks right at you.");
      TO->force_me("kill "+TP->query_name()+"");
   }
}
