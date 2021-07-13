#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,timer;
object ob;

void do_check();

create() {
    	::create();
    	set_name("orc shaman");
    	set_id(({"monster","orc","shaman","orc shaman"}));
    	set_short("orc shaman");
   	set_wimpy(20);
    	set_long("The creature stands and walks like a man, but has "+
    		"the face of a pig.  His nose is like that of a pig and "+
    		"his lower teeth jut out of his lips like tusks.  This "+
               "individual looks both brutish and violent and is covered "+
    		"with rune tattoos.");
    	set_body_type("humanoid");
    	dlevel = random(6) +12;
    	set_hd(dlevel,8);
    	set_class("cleric");
    	set_mlevel("cleric", dlevel);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(6);
    	set_race("orc");
    	set_gender("male");
    	set_overall_ac(3);
    	set_stats("strength",16);
      set_stats("dexterity",12);
  	set_stats("wisdom",16);
    	set_exp(dlevel*25);
    	set_max_hp((random(120)+(dlevel*6)));
    	set_hp(query_max_hp());
    	set_achats(0,({
		"%^CYAN%^Shaman whispers: %^RESET%^You destruction coming.",
		"%^CYAN%^Shaman whispers: %^RESET%^Do we cook'em?",
		"%^CYAN%^Shaman whispers: %^RESET%^You are under me power!",
		"%^BOLD%^%^RED%^Shaman raises his arms to the sky and calls "+
			"down the wrath of his god.%^RESET%^",
		"%^CYAN%^Shaman whispers: %^BOLD%^%^RED%^TALOS AID ME NOW!%^RESET%^",
    	}),0);
    	set_emotes(0,({
    		"Shaman yawns with a bored look on his ugly face.",
		"Shaman polishes his holy symbol.",
		"Shaman glares at an orc that gets too close to him.",
		"Shaman chants a short prayer to Talos.",
		"%^CYAN%^Shaman whispers: %^RESET%^I need someone to "+
			"sacrifice.\n%^CYAN%^Shaman whispers: %^RESET%^Any "+
			"volunteers?\nShaman grins wickedly.",
    	}),0);
    	add_money("silver",random(50));
    	add_money("copper",random(250));
  	set_size(2);
    	ob = new( CWEAP+"mace.c" );
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wield mace");
	ob = new(CARM+"banded.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear banded");
    	command("speak orcish");
    	command("speech whisper");
   	set_property("full attacks",1);
    	add_search_path("/cmds/priest");
 
  	set_spells(({"flame strike",
  		"cause serious wounds",
  		"cause blindness",
  		"limb attack",
  		"hold person",
  		"storm cone"
  	}));
   	set_spell_chance(60);
    	set_max_level(15);
    	set_property("swarm",1);
	FLAG = 0;
	set_property("knock unconscious");
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
		command("say I heard bout you, yer nice.");
		force_me("kill "+TP->query_name());
		return;
	}
	call_out("race_ck",0,TP);
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("emote slaps you on the back hard.");
	FLAG = 1;
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
		force_me("kill "+targ->query_name());
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			command("bow "+targ->query_cap_name());
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "goblin"|| mrace == "orc" || mrace == "hobgoblin"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
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
			force_me("kill "+targ->query_name());
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}else if(mrace == "kobold" || mrace == "half-orc" || mrace == "half-drow"){
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
	}else if(mrace == "wemic" || mrace == "human" || mrace == "yuan-ti"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
			return;
		}else{
			call_out("watchem",0,TP);
			return;
		}
	}else{
		tell_room(TO,"WHAT THE HELL ARE YOU?");
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
	    	race_ck(person);
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
