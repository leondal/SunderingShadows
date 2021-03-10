//Added fighter feats - Octothorpe 7/7/10

#include <std.h>
#include "../drownew.h"

inherit MONSTER;
int FLAG;

void create(){
   object ob;
   int dlevel;
   ::create();
   set_name("drow guard");
   set_short("Drow Guard");
   set_id( ({"fighter","drow","elf","guard","drow guard","drowf"}) );
   set_long(
     	"Wearing very light looking black chainmail and wielding a whip and a "+
     	"shortsword this drow looks very menacing.  Except for skin as "+
     	"black as obsidian and hair as white as snow, the drow looks very similar "+
     	"to the elves from the surface.\n"
   );
   dlevel = random(3)+4;
   set_body_type("human");
   set_race("drow");
   set_overall_ac(8);
   set_hd(dlevel,8);
   set_class("fighter");
   set_mlevel("fighter", dlevel);
   set_gender(random(2)?"male":"female");
   set_wielding_limbs(({"right hand","left hand"}));

  	ob = new(DNOBJ+"dchain");
    	ob->set_property("monsterweapon",1);
  		ob->move(TO);
    	command("wear chain");
  	ob = new(DNOBJ+"dwhip");
  	  	ob->move(TO);
		command("wield whip");
   ob = new(DNOBJ+"ossword");
  		ob->move(TO);
    	ob->set_property("monsterweapon",1);
		command("wield sword");
//   ob = new("/d/common/obj/potion/healing");
//   	ob->move(TO);
//        ob->set_uses(random(4)+2);
//removed kits to stop fencing abuse and make the area a little more manageable.  Circe 1/4/04
   ob = new(DNOBJ+"i_key");
   	ob->move(TO);
        ob = new("/d/common/obj/misc/pouch.c");
  		ob->move(TO);
  		command("wear pouch");
  		command("put key in pouch");

   set_stats("dexterity", (random(6)+13));
   set_stats("strength",(random(5)+14));
   set_max_hp((random(60)+55));
   set_hp(query_max_hp());

   set_property("swarm",1);
   add_search_path("/cmds/fighter");
  	add_money("silver",(dlevel*30));
  	add_money("gold",(dlevel*10));
  	add_money("copper",(dlevel*50));
  	add_money("electrum",(dlevel*20));
   set_mob_magic_resistance("average");
   set_exp(query_hd()*200);
   set_property("full attacks",1);
   set_max_level(6);
   FLAG = 0;
 	ob = new(DNOBJ+"dcoif");
  		ob->move(TO);
    	ob->set_property("monsterweapon",1);
    	command("wear coif");
	set_monster_feats(({
	   "parry",
       "powerattack",
	   "shatter",
	   "sunder",
	   "rush"
	}));		
}

void init(){
	string mrace=TP->query_race();
    	::init();
    	if(wizardp(TP) || TP->query_invis() || mrace == "drow") return;
    	call_out("whupass", 10, TP);
}

void whupass(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	command("kill "+targ->query_name());
	if(!random(10)) command("rush "+targ->query_name());
	if(FLAG == 1) return;
    	command("speak common");
    	command("say %^BOLD%^%^BLUE%^surface scum prepare to DIE!");
	command("parry");
	FLAG = 1;
}
void heart_beat() {
    	::heart_beat();
//   	if(present("kit") && query_hp() < query_max_hp()/2){
//		command("open kit");
//		command("quaff kit");
//		command("offer bottle");
//   	}
//   	if(present("bottle")) command("offer bottle");
   	if (FLAG == 0)return;
   	if(query_attackers() != ({}))FLAG = 0;
    	return;
}
