//Changed by Circe 6/4/07 to appear during combat
#include <std.h>
#include "../drownew.h"

inherit MONSTER;
int FLAG;

void create(){
   object ob;
   int dlevel;
   	::create();
    	set_name("drow thief");
    	set_short("Drow Thief");
    	set_id( ({"thief","drow","elf","drowt"}) );
    	set_long(
      	"Wearing only darkened leather and a sword and a "+
      	"dagger this drow looks very stealthy.  Except for skin as "+
      	"black as obsidian and hair as white as snow, the drow looks very similar "+
      	"to the elves from the surface.\n"
    	);

    	if(!random(5)){
    		dlevel = random(3)+4;
    	}else {
    		dlevel = random(5)+2;
    		}
    	set_body_type("human");
    	set_race("drow");
    	set_overall_ac(8);
    	set_hd(dlevel, 8);
	set_class("thief");
    	set_mlevel("thief", dlevel);
    	set_gender(random(2)?"male":"female");
      set_wielding_limbs(({"right hand","left hand"}));
// moved strength setting here - they couldn't carry the gear with base str so it was getting stranded with no environment  *Styx*
        set_stats("strength",(random(6)+10));
        ob=new("/d/common/obj/armour/bracers.c");
        if(random(4)){
        ob->set_property("monsterweapon",1);
        }
               ob->move(TO);
               command("wear bracers");
        ob = new(DNOBJ+"olsword");
  	    	ob->move(TO);
		command("wield sword");
   	ob = new(DNOBJ+"odagger");
  		ob->move(TO);
		command("wield dagger");
	ob = new(DNOBJ+"dstudded");
  		ob->move(TO);
    		command("wear studded");
//      ob = new("/d/common/obj/potion/healing");
//    		ob->move(TO);
//    		ob->set_uses(random(4)+3);
//removing kits to make area more manageable and stop fencing abuse.  Circe 1/4/04
    	add_search_path("/cmds/thief");
    	set_stats("dexterity", (random(6)+13));
    	set_max_hp((random(35)+60));
    	set_hp(query_max_hp());
    	set_thief_skill("move silently", (dlevel*5 + 45));
    	set_thief_skill("hide in shadows", (dlevel*5 + 45));
    	set_scrambling(1);

    	set_speed(15);
    	set_property("swarm",1);
  	add_money("silver",(dlevel*30));
  	add_money("gold",(dlevel*10));
  	add_money("copper",(dlevel*50));
  	add_money("electrum",(dlevel*20));
    	set_mob_magic_resistance("average");
      set_exp(query_hd()*150);
      set_property("full attacks",1);
      if (dlevel > 4) set_invis();
      set_max_level(6);
      FLAG = 0;
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
    	command("stab "+targ->query_name());
	command("kill "+targ->query_name());
    	command("scramble");
	if(FLAG == 1) return;
    	command("speak common");
    	command("say %^BOLD%^%^BLUE%^drop your coins and run.  Maybe I let you live!!");
    	command("say %^BOLD%^%^BLUE%^ok, we do this the hard way!!");
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
//invis stuff added by Circe 6/4/07 to make them appear during combat
      if(query_invis() && query_attackers() != ({})){
         set_invis();
      }
      if(!query_invis() && query_attackers() == ({})){
         set_invis();
      }
   	if (FLAG == 0)return;
   	if(query_attackers() != ({}))FLAG = 0;
    	return;
}