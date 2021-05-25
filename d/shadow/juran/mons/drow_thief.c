#include <std.h>
#include <daemons.h>
#include "../juran.h"

inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,num,timer;
string time;
object ob;

void do_check();

void create(){
   	::create();
    	set_name("drow thief");
    	set_short("drow thief");
    	set_id( ({"monster", "thief","drow","elf"}) );
    	set_long(
      	"Wearing only darkened leather and wielding two "+
      	"daggers this drow looks very stealthy.  Except for skin as "+
      	"black as obsidian and hair as white as snow, the drow looks very similar "+
      	"to the elves from the surface.\n"
    	);

    	if(!random(5)){
    		dlevel = random(6)+13;
    	}else {
    		dlevel = random(6)+9;
    		}
    	set_body_type("humanoid");
    	set_race("drow");
    	set_alignment(9);
    	set_overall_ac(6);
    	set_hd(dlevel, 6);
	set_class("thief");
    	set_mlevel("thief", dlevel);
    	set_gender(random(2)?"male":"female");
      set_wielding_limbs(({"right hand","left hand"}));

	num = random(10);
    	ob = new("/d/newbie/rooms/drow/obj/olsword");
    		if(num)ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
		command("wield sword");
	num = random(10);
   	ob = new("/d/newbie/rooms/drow/obj/odagger");
     		if(num)ob->set_property("monsterweapon", 1);
 		ob->move(TO);
		command("wield dagger");
	num = random(10);
	ob = new("/d/newbie/rooms/drow/obj/dstudded");
     		if(num)ob->set_property("monsterweapon", 1);
 		ob->move(TO);
    		command("wear studded");
      /*ob = new("/d/common/obj/potion/healing");
    		ob->move(TO);
    		ob->set_uses(random(5)+10);*/
			set_property("add kits",10);
      if(!random(10)){
         new("/d/shadow/juran/weaps/jet_ring")->move(TO);
         force_me("wear ring");
      }
//added chance for jet ring that has darkness charges.  Circe 1/13/04

    	add_search_path("/cmds/thief");
    	set_stats("dexterity", (random(8)+13));
    	set_stats("strength",(random(6)+12));
    	set_max_hp((random(50)+50));
    	set_hp(query_max_hp());
    	set_thief_skill("move silently", 95);
    	set_thief_skill("hide in shadows", 95);
    	set_scrambling(1);
    	set_property("swarm",1);
  	add_money("silver",(dlevel*15));
  	add_money("gold",(dlevel*5));
  	add_money("electrum",(dlevel*10));
    	set_mob_magic_resistance("average");
      set_exp(query_hd()*25);
      set_property("full attacks",1);
      set_max_level(15);
    	command("speak drow");
    	command("speech speak quietly");
      FLAG = 0;
	  set_scrambling(1);
	     set_monster_feats(({
		     "ambidexterity",
			 "two weapon fighting",
			 "improved two weapon fighting",
			 "greater two weapon fighting",
			 "two weapon defense",
			 "dodge",
			 "evasion",
			 "mobility",
			 "scramble",
			 "spring attack",
			 "knockdown",
			 "parry"
			 }));
}


void init(){
	string mrace= TP->query_race(),srace = (string)TP->query("subrace"),mname = TP->query_name();
    	::init();
    	if(avatarp(TP) || TP->query_invis() || mname == "slave" || !interactive(TP)) return;
    	if(is_surfacerace(TP)){
		if(TP->query_bound())return 1;
		force_me("stab "+TP->query_name());
		force_me("kill "+TP->query_name());
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		force_me("stab "+TP->query_name());
		force_me("kill "+TP->query_name());
		return;
	}
	call_out("race_ck",0,TP);
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
	if(!random(3))force_me("emote smiles an evil smile.");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("emote keeps his eyes on you.");
	FLAG = 1;
}
void go_home(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	tell_room(ETO,"The drow thief slips into the shadows.");
	targ->set_invis();
	targ->move("/d/shadowgate/void");
	targ->remove();
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("emote circles you taking your measure.");
	FLAG = 1;
}
void watchem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("emote looks at you considering options.");
	FLAG = 1;
}
void race_ck(object targ){
	string mrace, srace, mname;

    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
      if(targ->query_property("shapeshifted")) { // should react differently to beasties in shapeshift. N, 1/14
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			call_out("watchem",0,TP);
			return;
		}
	}

	mrace = targ->query_race();
      srace = (string)targ->query("subrace");
	mname = targ->query_name();
	if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		force_me("stab "+targ->query_name());
		force_me("kill "+targ->query_name());
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			if(!random(3))command("emote bows to "+targ->query_cap_name());
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "drow" ){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("stab "+targ->query_name());
			force_me("kill "+targ->query_name());
			return;
		}else{
			call_out("friendly",0,TP);
			return;
		}
	}else if(mrace == "kobold" || mrace == "goblin"|| mrace == "orc" || mrace == "minotaur" ||
		mrace == "hobgoblin" || mrace == "ogre" || mrace == "bugbear" || mrace == "yuan-ti" ||
		mrace == "gnoll" || mrace == "ogre-mage" || mrace == "half-ogre"||
		mrace == "firbolg" || mrace == "wemic" || mrace == "human" || mrace == "troll" ||
		mrace == "half-orc" || mrace == "half-drow" || (mrace == "dwarf" && srace == "gray dwarf")){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("stab "+targ->query_name());
			force_me("kill "+targ->query_name());
			return;
		}else{
			call_out("bullyem",0,TP);
			return;
		}
	}else if(mrace == "dwarf" || mrace == "elf" || mrace == "half-elf" ||
		mrace == "gnome" || mrace == "beastman" || mrace == "voadkyn" ||
		mrace == "halfling" || mrace == "centaur"){
		if(targ->query_bound())return 1;
		force_me("stab "+targ->query_name());
		force_me("kill "+targ->query_name());
		return;
	}else{
		tell_room(TO,"WHAT THE HELL ARE YOU?");
		force_me("stab "+targ->query_name());
		force_me("kill "+targ->query_name());
		return;
	}
}
int do_check(){
    	int i;
    	object *people, *list, person;
	string mrace;
     	people = ({});
    	list = ({});

    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(TO->query_current_attacker()) return 1;

    	people = all_living(environment(this_object()));

    	for(i=0;i<sizeof(people);i++){
		if(!((people[i] == TO) || (wizardp(people[i]))))
	  		list += ({people[i]});
      }
	if(!list || !sizeof(list)) return 2;

	person = list[random(sizeof(list))];

	if(!present(person, ETO)) return 1;

	if(person->query_unconscious()){
		if(person->query_bound())return 1;
	    	call_out("race_ck",0,person);
	}
	return 1;
}
void reset(){
  	::reset();
  	time = "daemon/events_d"->query_time_of_day();
  	if(time == "dawn"|| time == "day")call_out("go_home",10,TO);
}
void heart_beat() {
    	::heart_beat();

	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;
   	/*if(present("kit",TO) && query_hp() < query_max_hp()/2){
		command("open kit");
		command("quaff kit");
		command("offer bottle");
   	}
    	if(present("bottle",TO)) command("offer bottle");*/
     	do_check();
    	timer++;
    	if(timer > 25){
         	timer = 0;
         	if(!query_invis()){
        		if(query_attackers() == ({}) ){
      			if (dlevel > 14) set_invis();
      		}
      	}
   		if (FLAG == 0){
   			return;
   		}else{
   			if(query_attackers() != ({})){
   				FLAG = 0;
    				return;
   			}
        	}
   	}
}
