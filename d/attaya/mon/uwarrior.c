//Octothorpe (12/12/09)
//Attaya, Undead Warrior
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create() {
   object ob;
   ::create();
   set_name("undead warrior");
   set_id(({"undead warrior","undead","warrior"}));
   set_short("%^RESET%^%^RED%^r%^ORANGE%^u%^RED%^st%^ORANGE%^y %^RED%^"+
      "undead warrior%^RESET%^");
   set_long("%^RESET%^%^RED%^This undead warrior is outfitted with "+
      "completely rusted equipment.  Some vestiges of ancient armor "+
	  "cover parts of its torso, but what remains is in no condition "+
	  "to provide any semblance of protection.  The undead's leathery "+
	  "skin also follows the example of the tattered armor, with bits "+
	  "and pieces hanging to and fro over some of the bones.%^RESET%^");
   set_race("undead");
   set_gender("male");
   set_hd(35,10);
   set_size(2);
   set_overall_ac(-8);
   set_class("fighter");
   set_guild_level("fighter",35);
   set_max_hp(250+random(150));
   set_hp(query_max_hp());
   set_wielding_limbs(({"right hand"}));
   set_body_type("human");
   set_property("swarm",1);
   set_speed(30);
   set_property("full attacks",1);
   set_property("no bump",1);
   set_stats("strength",23);
   set_stats("dexterity",14);
   set_stats("constitution",9);
   set_stats("intelligence",3);
   set_stats("wisdom",3);
   set_stats("charisma",3);
   set("aggressive",25);
   set_mob_magic_resistance("average");
   set_new_exp(35,"high");
   set_alignment(9);
   ob = new(OBJ"rusts");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   command("wear shield");
   ob = new(OBJ"rustb");
   ob->set_property("monsterweapon",1);
   ob->move(TO);
   command("wield blade");
   command("message in shambles in.");
   command("message out shambles to the $D.");
   add_search_path("/cmds/feats");
   set_monster_feats(({
      "shieldbash",
	  "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void die(object ob) {
   object obx;
   tell_room(ETO,"%^BOLD%^The undead warrior collapses into a pile "+
      "of bones and crumbling armor.");
   if(!random(3)){
      obx = new("/d/common/obj/potion/advanced_heal");
      obx->set_uses(1+random(10));
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
