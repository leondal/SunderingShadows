//Octothorpe (2/21/10)
//Attaya, Bishimon
//Original by Thundercracker

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit MONSTER;

object ob;
int MERCY;

void create(){
   ::create();
   set_name("bishimon");
   set_id(({"bishimon","champion","champion of the black dawn"}));
   set_short("%^BOLD%^%^BLACK%^Bishimon, Champion of the "+
      "Black D%^RESET%^a%^BOLD%^%^BLACK%^wn%^RESET%^");
   set_long("Before you is an armored mess of metallic horns, blades, "+
      "and spikes.  It is impossible to ascertain the race or gender "+
	  "of this being since it encased in ebon metal. Even though this "+
	  "armored foe appears anonymous, certainly this can only be "+
	  "Bishimon, the first guardian of the Crystalline Tower of the "+
	  "Black Dawn.");
   set_race("undead");
   set_hd(40,1);
   set_level(40);
   set_gender("male");
   set_size(2);
   set_overall_ac(-8);
   set_class("fighter");
   set_guild_level("fighter",40);
   set_guild_level("mage",40);
   set_hp(5000);
   set_max_hp(query_hp());
   set_wielding_limbs(({"right hand","left hand"}));
   set_body_type("human");
   ob=new(OBJ"cursed")->move(TO);
   command("wield sword in right hand");
   ob=new(OBJ"cursed")->move(TO);
   command("wield sword in left hand");
   set_mob_magic_resistance("average");
   set_property("weapon resistance",3);
   set_property("full attacks",1);
   set_property("no paralyze", 1);
   set_property("no knockdown", 1);
   set_property("no death",1);
   set_property("no dominate",1);
   set_property("no bows",1);
   set_property("no hold", 1);
   set_property("no tripped", 1);
   set_property("swarm",1);
   set_skill("perception",30);
   set_property("magic", 1);
   set_stats("strength",22);
   set_stats("dexterity",16);
   set_stats("constitution",25);
   set_stats("intelligence",15);
   set_stats("wisdom",14);
   set_stats("charisma",9);
   set("aggressive",25);
   set_property("no death",1);
   set_property("cast and attack",1);
   set_exp(50000);
   set_alignment(9);
   add_search_path("/cmds/fighter");
   set_monster_feats(({
      "ambidexterity",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "greater two weapon fighting",
	  "two weapon defense",
	  "expertise",
	  "knockdown",
	  "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
   set_spells(({
               "fear",
                   "bestow curse",
                   "waves of exhaustion"
                   }));
   set_spell_chance(50);
   set_funcs(({
      "rushit",
	  "flashit",
	  "kdit"
   }));
   set_func_chance(50);
   force_me("speak wizish");
   force_me("speech %^MAGENTA%^grumble hoarsely%^RESET%^");
   new(OBJ"bish_gauntlets")->move(TO);
   new(OBJ"bish_helm")->move(TO);
   new(OBJ"bish_plate")->move(TO);
   command("wearall");
   MERCY = 0;
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void die(object ob){
   object *attackers;
   int i;
   attackers = TO->query_attackers();
   attackers = filter_array(attackers,"is_non_immortal_player",FILTERS_D);
//   if(sizeof(TO->query_attackers()) < 1) return; // this breaks bishimon- Uriel
   tell_room(ETO,"%^BOLD%^Bishimon stumbles back and turns around "+
      "towards the mirror, but falls short and drops to the ground "+
	  "mere inches from it.\n"+
	  "%^RESET%^%^RED%^You...are...powerful...avenge the fallen.  "+
	  "Jarmila...forgive me...%^RESET%^",TP);
   for(i=0;i<sizeof(attackers);i++){
      if(!objectp(attackers[i])) { continue; }
	  if(member_array("Gained entry to the Crystal Tower, Defeated Bishimon",attackers[i]->query_mini_quests()) == -1){
	     attackers[i]->set_mini_quest("Gained entry to the Crystal Tower, Defeated Bishimon",3100000,"%^BOLD%^%^BLACK%^Gained entry to the Crystal Tower, Defeated Bishimon%^RESET%^");
      }
   }
   force_me("open gates");
   ::die(ob);
}

int aggfunc(){
    string mrace=TP->query_race();
    if (mrace == "undead") return 1;
	if(TP->query_true_invis()) return 1;
	if(wizardp(TP)) return 1;
	if(MERCY < 1){
	   force_me("say %^RED%^I will show you no mercy.  I SHALL DESTROY YOU!!!");
	   TO->force_me("rush "+TPQN);
	   MERCY = 1;
	}
   TO->force_me("rush "+TPQN);
}

void set_paralyzed(int time,string message){return 1;}

void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("knockdown "+targ->query_name());
}

void flashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("flash "+targ->query_name());
}

void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("rush "+targ->query_name());
}
