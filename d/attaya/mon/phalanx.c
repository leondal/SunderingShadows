//Octothorpe (12/12/09)
//Attaya, Skeletal Phalanx
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create(){
   object ob;
   ::create();
   set_name("skeletal legionary");
   set_id(({"phalanx","skeleton","skeletal legionary","shield-toting","legionary"}));
   set_short("%^RESET%^%^ORANGE%^shield%^YELLOW%^-%^RESET%^%^ORANGE%^"+
      "toting %^BOLD%^%^WHITE%^skeleton%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This skeleton is the survivor, albeit "+
      "an undead one, of an ancient Kinnesarudan legion.  The gear of "+
	  "this skeleton is not rusted out, as is found on most of the "+
	  "other undead warriors populating the Attayan jungle.  The torso "+
	  "is devoid of any armor, presumably having disintegrated decades "+
	  "ago, yet a flawless, %^RESET%^%^ORANGE%^bronze %^BOLD%^%^WHITE%^"+
	  "shield is humerusly mounted on the skeleton.  Wielded in the "+
	  "skeleton's in left hand is a barbarous longsword that appears "+
	  "as new as the day it was forged in the Cauldron below Crystal "+
	  "Mountain.%^RESET%^");
   set_race("undead");
   set_gender("male");
   set_hd(40,10);
   set_size(2);
   set_overall_ac(-13);
   set_class("fighter");
   set_guild_level("fighter",40);
   set_max_hp(300+random(150));
   set_hp(query_max_hp());
   set_wielding_limbs(({"right hand","left hand"}));
   set_body_type("human");
   set_property("swarm",1);
   set_property("full attacks",1);
   set_property("no bump",1);
   set_stats("strength",22);
   set_stats("dexterity",16);
   set_stats("constitution",17);
   set_stats("intelligence",3);
   set_stats("wisdom",3);
   set_stats("charisma",3);
   set("aggressive",25);
   set_mob_magic_resistance("low");
   set_new_exp(35,"very high");
   set_alignment(9);
   set_damage_bonus(1+random(8));
   ob = new(OBJ"pshield");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   command("wear shield");
   ob = new(OBJ"cursed");
   if(random(3))  ob->set_property("monsterweapon", 1);
   ob->move(TO);
   command("wield sword");
   add_search_path("/cmds/feats");
   set_monster_feats(({
      "shieldbash",
	  "toughness",
	  "improved toughness",
	  "damage resistance",
	  "knockdown",
	  "expertise",
	  "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
   add_search_path("/cmds/fighter");
   set_fighter_style("soldier");
   set_func_chance(15);
   set_funcs(({"rushit","flashit","bashit","kdit"}));
   command("message in marches in stiffly.");
   command("message out marches stiffly to the $D.");
   set_speed(70);
   set_moving(1);
   set_resistance("negative energy",20);
   set_resistance("positive energy",-20);
}

void init(){
   string mrace=TP->query_race();
   ::init();
   if(mrace == "undead" || mrace == "necrophidius" || mrace == "snake" || mrace == "demonic entity" || mrace == "wyvern" || mrace == "influence" || mrace == "king scorpion" || mrace == "will-o-wisp" || mrace == "toc'lahar" || mrace == "elemental") return;
   if(TP->query_invis() && !TP->query_true_invis()){
      tell_object(TP,"%^BOLD%^The skeletal legionary senses your approach...");
	  TO->force_me("rush "+TPQN);
   }
}

void bashit(object targ){
   TO->force_me("shieldbash "+targ->query_name());
}

void kdit(object targ){
   TO->force_me("knockdown "+targ->query_name());
}

void rushit(object targ){
   TO->force_me("rush "+targ->query_name());
}

void flashit(object targ){
   TO->force_me("flash "+targ->query_name());
}

void die(object ob){
   object obx;
   tell_room(ETO,"%^BOLD%^The skeletal legionary collapses into a pile "+
      "of bones and crumbling armor.");
   if(!random(3)){
      obx = new(OBJ"pshield");
      obx->move(ETO);
   }
   if(!random(3)){
      obx = new(OBJ"cursed");
      obx->move(ETO);
   }
   if(!random(3)){
      obx = new("/d/common/obj/potion/legendary_heal");
      obx->set_uses(1+random(4));
      obx->move(ETO);
   }
   if(!random(20)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(ETO);
   }
   TO->move("/d/shadowgate/void");
   TO->remove();
}
