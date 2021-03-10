#include <std.h>
#include "../dragon.h";

inherit MONSTER;
object ob;

void create(){
   ::create();
   set_name("toris");
   set_id(({"toris","tiefling"}));
   set_short("Toris, Planetouched Tiefling");
   set_long(
      "Toris is a tall bronze skinned tiefling with pointy ears and fiery red eyes."+
      " He has large bat like wings extending from his back and a long sharp tail hanging"+
      " to the floor."
   );
   set_class("fighter");
   set_guild_level("fighter",20);
   set_race("tiefling");
   set_hd(20,6);
   set_alignment(6);
   set_max_hp(400);
   set_hp(400);
   set_overall_ac(-30);
   set_property("weapon resistance", 10);
   set_property("no dominate", 1);
   set_property("no hold", 1);
   set_property("no bows", 1);
   set_property("no paralyze", 1);
   set_property("no poison", 1);
   set_size(2);
   set("aggressive",30);
   set_exp(24000);
   set_wielding_limbs(({"right hand","left hand"}));
   set_stats("strength",19);
   set_stats("dexterity",25);
   ob = new(OBJ+"lightningbolt")->move(TO);
   force_me("wield rapier");
   set_max_level(23);
   set_max_level(23);
}

void init() {
   ::init();
   if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"Toris looks right at you.");
      TO->force_me("kill "+TP->query_name()+"");
   }
}