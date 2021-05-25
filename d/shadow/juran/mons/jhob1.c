#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,timer;
object ob;

void do_check();

create() {
    	::create();
    	set_name("hobgoblin");
    	set_id(({"monster","hobgoblin"}));
    	set_short("hobgoblin");
   	set_wimpy(20);
    	set_long("This brutish humanoid is called a hobgoblin.  Wearing "+
    		"banded armor this larger cousin of the goblins looks to "+
    		"be a bit more organized and more dangerous.");
    	set_body_type("humanoid");
    	dlevel = random(5) +10;
    	set_hd(dlevel,8);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(9);
    	set_race("hobgoblin");
    	set_gender("male");
    	set_overall_ac(2);
    	set_stats("strength",18);
    	set_stats("dexterity",12);
    	set_exp(dlevel*25);
    	set_max_hp((random(120)+(dlevel*6)));
    	set_hp(query_max_hp());
    	add_money("gold",random(40));
    	add_money("silver",random(100));
    	add_money("copper",random(500));
  	set_size(2);
    	ob = new( CWEAP+"halberd.c" );
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wield halberd");
	ob = new(CARM+"banded.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear banded");
        command("speak goblin");
    	command("speech growl");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(15);
    	set_property("swarm",1);
	FLAG = 0;
	set_property("knock unconscious");
	set_monster_feats(({
	    "parry"
	}));
}
void init(){
	string mrace= TP->query_race(),srace = (string)TP->query("subrace"),mname = TP->query_name();
    	::init();
    	if(avatarp(TP) || TP->query_invis() || mname == "slave" || !interactive(TP)) return;
    	if(is_surfacerace(TP)){
		if(TP->query_bound())return 1;
		force_me("kill "+TP->query_name());
		if (!random(3))force_me("rush "+TP->query_name());
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		force_me("kill "+TP->query_name());
		if (!random(3))force_me("rush "+TP->query_name());
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
		return;
	}
	call_out("race_ck",0,TP);
}
void killem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("kill "+targ->query_name());
	if (!random(3))force_me("rush "+targ->query_name());
	if (FLAG == 1) return;
	force_me("parry");
	FLAG = 1;
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("look "+targ->query_name());
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("emote dips his head and backs away.");
	FLAG = 1;
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("emote pokes at you threateningly.");
	FLAG = 1;
}
void watchem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if(!random(3))force_me("emote watches you closely.");
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
		call_out("killem",0,TP);
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			command("emote bows before "+targ->query_cap_name());
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "goblin"|| mrace == "orc" || mrace == "hobgoblin"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("friendly",0,TP);
			return;
		}
	}else if(mrace == "drow" || mrace == "ogre" || mrace == "bugbear" || mrace == "minotaur" ||
		mrace == "gnoll" || mrace == "ogre-mage" || mrace == "half-ogre" || mrace == "troll" ||
		mrace == "firbolg" || (mrace == "dwarf" && srace == "gray dwarf")){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}else if(mrace == "kobold" || mrace == "half-orc" ||
		mrace == "half-drow"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("bullyem",0,TP);
			return;
		}
	}else if(mrace == "dwarf" || mrace == "elf" || mrace == "centaur" ||
		mrace == "half-elf" || mrace == "gnome" || mrace == "beastman" ||
		mrace == "voadkyn" || mrace == "halfling"){
		if(targ->query_bound())return 1;
		call_out("killem",0,TP);
		return;
	}else if(mrace == "wemic" || mrace == "human" || mrace == "yuan-ti"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("watchem",0,TP);
			return;
		}
	}else{
		tell_room(TO,"WHAT THE HELL ARE YOU?");
		call_out("killem",2,TP);
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
void heart_beat() {
    	object obj;
    	::heart_beat();

	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;
     	do_check();
   	if (FLAG == 0)return;
    	timer++;
    	if(timer > 100){
      	timer = 0;
		if(query_attackers() != ({}))FLAG = 0;
    		return;
    	}
}
