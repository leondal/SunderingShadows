//Added fighter feats - Octothorpe 7/7/10

#include <std.h>
#include "../drownew.h"

inherit MONSTER;
int FLAG;

void create(){
   object ob;
   int dlevel;
   	::create();
    	set_name("drow fighter");
    	set_short("Drow Fighter");
    	set_id( ({"fighter","drow","elf","drowf"}) );
    	set_long(
      	"Wearing very light-looking black chainmail and wielding a "+
      	"shortsword balanced by a matching longsword, this drow looks very menacing.  Except for skin as "+
      	"black as obsidian and hair as white as snow, the drow looks very similar "+
      	"to the elves from the surface.\n"
    	);
    	dlevel = random(5)+3;
    	set_body_type("human");
    	set_race("drow");
    	set_overall_ac(8);
    	set_hd(dlevel, 8);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
    	set_gender(random(2)?"male":"female");
      set_wielding_limbs(({"right hand","left hand"}));
// moved strength setting here - they couldn't carry the gear with base str so it was getting stranded with no environment  *Styx*

        set_stats("strength",(random(6)+10));

  	ob = new(DNOBJ+"olsword");
  	    	ob->move(TO);
		command("wield sword");
   	ob = new(DNOBJ+"ossword");
  		ob->move(TO);
    		ob->set_property("monsterweapon",1);
		command("wield sword");
        if(!random(3)) {
   	   ob = new(DNOBJ+"dcoif");
  		ob->move(TO);
    		command("wear coif");
        }
  	ob = new(DNOBJ+"dchain");
  		ob->move(TO);
    		command("wear chain");
//        ob = new("/d/common/obj/potion/healing");
//    		ob->move(TO);
//                ob->set_uses(random(3)+2);
//removing kits to make area more managable and stop fencing abuse.  Circe 1/4/04
    	set_stats("dexterity", (random(6)+13));
    	set_max_hp((random(30)+60));
    	set_hp(query_max_hp());

     	set_speed(25);
   	set_property("swarm",1);
   	add_search_path("/cmds/fighter");
  	add_money("silver",(dlevel*30));
  	add_money("gold",(dlevel*10));
  	add_money("copper",(dlevel*50));
  	add_money("electrum",(dlevel*20));
    	set_mob_magic_resistance("average");
      set_exp(query_hd()*150);
      set_property("full attacks",1);
      set_max_level(6);
      FLAG = 0;
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
    	command("yell %^BOLD%^%^RED%^INVADERS, TO ARMS!!");
   	command("say %^BOLD%^%^BLUE%^to hell with them, I'll take care of you myself!");
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
