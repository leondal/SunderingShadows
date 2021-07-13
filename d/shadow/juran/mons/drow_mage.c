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
    	set_name("drow mage");
    	set_short("drow mage");
    	set_id( ({"monster", "mage","drow","drow mage"}) );
    	set_long(
      	"Wearing only a robe this drow still looks lethal.  Except for "+
      	"skin as black as obsidian, the "+
      	"glowing red eyes, and hair as white as snow, the drow looks very similar "+
      	"to the elves from the surface.\n"
    	);
    	dlevel = random(10)+15;
    	set_body_type("humanoid");
    	set_alignment(9);
    	set_race("drow");
    	set_overall_ac(6);
    	set_hd(dlevel, 4);
    	set_class("mage");
    	set_guild_level("mage",dlevel);
    	set_mlevel("mage", dlevel);
    	set_gender("male");
      set_wielding_limbs(({"right hand","left hand"}));

	num = random(10);
	ob = new(CARM+"robe.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
  		ob->set_short("A black robe");
  		ob->set_long("This is a black robe is very light and seems "+
  			"to shimmer.  No dweomer can be detected.");
    		command("wear robe");
      /*ob = new("/d/common/obj/potion/healing");
    		ob->move(TO);
    		ob->set_uses(random(5)+10);*/
			set_property("add kits",10);
      if(!random(8)){
         new("/d/shadow/juran/weaps/jet_ring")->move(TO);
         force_me("wear ring");
      }
//added chance for jet ring that has darkness charges.  Circe 1/13/04

    	set_stats("dexterity", (random(8)+13));
    	set_stats("strength",(random(6)+12));
	set_stats("intelligence",(random(5)+16));
    	set_max_hp((random(100)+100));
    	set_hp(query_max_hp());

   	set_property("swarm",1);
     	add_search_path("/cmds/mage");
  	set_spells(({"color spray",
  		"hideous laughter",
  		"magic missile",
  		"fireball",
  		"monster summoning i",
  		"vampiric touch",
  		"darkness",
  		"lightning bolt",
  		"web"
  	}));
   	set_spell_chance(60);
 	add_money("silver",(dlevel*15));
  	add_money("gold",(dlevel*5));
  	add_money("electrum",(dlevel*10));
    	set_mob_magic_resistance("average");
      set_exp(query_hd()*25);
      set_property("full attacks",1);
      set_max_level(20);
    	command("speak drow");
    	command("speech whisper");
      FLAG = 0;
}
void init(){
	string mrace= TP->query_race(),srace = (string)TP->query("subrace"),mname = TP->query_name();
    	::init();
    	if(avatarp(TP) || TP->query_invis() || mname == "slave" || !interactive(TP)) return;
    	if(is_surfacerace(TP)){
		if(TP->query_bound())return 1;
		force_me("kill "+TP->query_name());
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
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
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if(!random(3))force_me("emote ignores you completely.");
}
void go_home(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	tell_room(ETO,"The drow mage slips into the shadows.");
	targ->set_invis();
	targ->move("/d/shadowgate/void");
	targ->remove();
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
		force_me("kill "+targ->query_name());
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			command("emote bows to "+targ->query_cap_name());
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "drow" ){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
			return;
		}else{
			call_out("friendly",0,TP);
			return;
		}
	}else if(mrace == "kobold" || mrace == "goblin"|| mrace == "orc" || mrace == "minotaur" ||
		mrace == "hobgoblin" || mrace == "ogre" || mrace == "bugbear" || mrace == "yuan-ti" ||
		mrace == "gnoll" || mrace == "ogre-mage" || mrace == "half-ogre" ||
		mrace == "firbolg" || mrace == "wemic" || mrace == "human" || mrace == "troll" ||
		mrace == "half-orc" || mrace == "half-drow" || (mrace == "dwarf" && srace == "gray dwarf")){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
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
		force_me("kill "+targ->query_name());
		return;
	}else{
		tell_room(TO,"WHAT THE HELL ARE YOU?");
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
   	if (FLAG == 0)return;
    	timer++;
    	if(timer > 100){
      	timer = 0;
		if(query_attackers() != ({}))FLAG = 0;
    		return;
    	}
}
