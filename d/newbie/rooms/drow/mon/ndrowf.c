//Added fighter feats - Octothorpe 7/7/10

#include <std.h>
#include "../drownew.h"

inherit MONSTER;

int FLAG;

void create(){
   object ob;
   	::create();
    	set_name("patrol leader");
    	set_short("Patrol leader");
    	set_id( ({"fighter","drow","elf","leader","patrol leader","drowf"}) );
    	set_long(
      	"Wearing very light looking black chainmail and wielding two "+
      	"shortswords this drow looks very menacing.  Except for skin as "+
      	"black as obsidian and hair as white as snow, the drow looks very similar "+
      	"to the elves from the surface.\n"
    	);
    	set_body_type("human");
    	set_race("drow");
    	set_overall_ac(8);
    	set_hd(7, 8);
    	set_class("fighter");
    	set_mlevel("fighter", 7);
        set_wielding_limbs(({"right hand","left hand"}));
    	set_gender(random(2)?"male":"female");

  	ob = new(DNOBJ+"ossword");
  	    	ob->move(TO);
		command("wield sword");
   	ob = new(DNOBJ+"ossword");
  		ob->move(TO);
    		ob->set_property("monsterweapon",1);
		command("wield sword");
 	ob = new(DNOBJ+"dcoif");
  		ob->move(TO);
    		command("wear coif");
  	ob = new(DNOBJ+"dchain");
  		ob->move(TO);
    		command("wear chain");
      if(!random(3)){
         ob = new("/d/common/obj/potion/healing");
       		ob->move(TO);
                  ob->set_uses(random(4)+2);
      }
    	ob = new(DNOBJ+"b_key");
    		ob->move(TO);
        ob = new("/d/common/obj/misc/pouch.c");
  		ob->move(TO);
  		command("wear pouch");
  		command("put key in pouch");

    	set_stats("dexterity", (random(6)+13));
    	set_stats("strength",(random(6)+12));

     	set_property("swarm",1);
     	set_max_hp((random(40)+45));
    	set_hp(query_max_hp());
    	add_search_path("/cmds/fighter");
    	add_money("silver",random(180));
  	    add_money("gold",random(60));
  	    add_money("copper",random(300));
     	add_money("electrum",random(120));
    	set_mob_magic_resistance("average");
       set_exp(800);
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
    	call_out("whupass", 5, TP);
}

void whupass(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	command("kill "+targ->query_name());
	if(!random(10)) command("rush "+targ->query_name());
	if(FLAG == 1) return;
    	command("say %^BOLD%^%^BLUE%^you trespass.  You must now be PUNISHED!!");
	command("say %^BOLD%^%^BLUE%^maybe you will bring a nice price at the market!!");
	command("parry");
	FLAG = 1;
}
void heart_beat() {
    	::heart_beat();
   	if(present("kit") && query_hp() < query_max_hp()/2){
		command("open kit");
		command("quaff kit");
		command("offer bottle");
   	}
    	if(present("bottle")) command("offer bottle");
   	if (FLAG == 0)return;
   	if(query_attackers() != ({}))FLAG = 0;
    	return;
}
