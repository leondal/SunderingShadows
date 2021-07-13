#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,num,timer;
object ob;

void do_check();

create() {
    	::create();
    	set_name("goblin fighter");
    	set_id(({"monster","goblin","fighter","goblin fighter"}));
    	set_short("goblin fighter");
   	set_wimpy(15);
    	set_long("This foul and ugly little creature is a goblin fighter. "+
    		"They are tough little guys and are fiercely loyal to the "+
    		"boss, unless, of course, the boss shows weakness. ");
    	set_body_type("humanoid");
    	dlevel = random(6) + 7;
    	set_hd(dlevel,6);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
    	add_search_path("/cmds/fighter");
      set_wielding_limbs(({"right hand","left hand"}));
    	set_size(1);
   	set_stats("intelligence",8);
    	set_stats("wisdom",8);
    	set_stats("strength",16);
    	set_stats("charisma",3);
    	set_stats("dexterity",18);
    	set_stats("constitution",13);
    	set_alignment(9);
    	set_race("goblin");
    	set_overall_ac(4);
    	set_exp(dlevel*20);
    	set_max_hp((random(90)+(dlevel*6)));
    	set_hp(query_max_hp());
    	add_money("gold",random(10));
    	add_money("silver",random(25));
    	add_money("copper",random(750));
    	set_property("swarm",1);
    	set_property("full attacks",1);
      ob = new(CARM+"chain.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear chain");
      ob = new(CWEAP+"dagger.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wield dagger");
     	ob = new(CARM+"buckler.c");
     		ob->set_property("monsterweapon", 1);
   		ob->move(TO);
    		command("wear buckler");
    	set_max_level(12);
    	command("speak goblin");
    	command("speech spit");
    	FLAG = 0;
	set_property("knock unconscious");
	set_monster_feats(({"parry"}));
}
void init(){
	string mrace= TP->query_race(),srace = (string)TP->query("subrace"),mname = TP->query_name();
    	::init();
    	if(avatarp(TP) || TP->query_invis() || mname == "slave" || !interactive(TP)) return;
    	if(is_surfacerace(TP)){
		if(TP->query_bound())return 1;
		force_me("kill "+TP->query_name());
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		if(TP->query_bound())return 1;
		force_me("kill "+TP->query_name());
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
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
	if(!random(3))force_me("emote grins a big toothy grin");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("quiver");
	FLAG = 1;
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("emote pokes you threateningly.");
	FLAG = 1;
}
void watchem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("emote looks at you warily.");
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
		if(targ->query_bound())return 1;
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			if(!random(3))command("emote %^BOLD%^%^RED%^nods lots and lots!");
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			force_me("parry");
			FLAG = 1;
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "goblin"|| mrace == "orc" || mrace == "hobgoblin"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			force_me("parry");
			FLAG = 1;
			return;
		}else{
			call_out("friendly",0,TP);
			return;
		}
	}else if(mrace == "drow" || mrace == "ogre" || mrace == "bugbear" || mrace == "minotaur" ||
		mrace == "gnoll" || mrace == "ogre-mage" || mrace == "troll" || mrace == "half-ogre" || mrace == "yuan-ti" ||
		mrace == "firbolg" || (mrace == "dwarf" && srace == "gray dwarf")){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			force_me("parry");
			FLAG = 1;
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}else if(mrace == "kobold" || mrace == "half-orc" ||
		mrace == "half-drow"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			force_me("parry");
			FLAG = 1;
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
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
		return;
	}else if(mrace == "wemic"|| mrace == "human" ){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			force_me("parry");
			FLAG = 1;
			return;
		}else{
			call_out("watchem",0,TP);
			return;
		}
	}else{
		tell_room(TO,"WHAT THE HELL ARE YOU?");
		if(targ->query_bound())return 1;
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
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
	    	call_out("race_ck",0,TP);
	}
	return 1;
}
void heart_beat() {
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
