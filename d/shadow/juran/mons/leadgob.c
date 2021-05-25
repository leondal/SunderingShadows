#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,num,timer;
object ob;

void do_check();

create() {
    	::create();
    	set_name("goblin boss");
    	set_id(({"monster","goblin","goblin leader","goblin boss","boss"}));
    	set_short("goblin boss");
   	set_wimpy(20);
    	set_long("This stout and ugly little creature is bigger than the rest of "+
    		"the goblins.  He is short, green, and covered with tribal tattoos.  "+
    		"Fierce looking and aggressive, this goblin seems to be a leader "+
    		"among his kind.");
    	set_body_type("humanoid");
    	dlevel = random(8) +10;
    	set_hd(dlevel,6);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(9);
    	set_race("goblin");
    	set_gender("male");
    	set_overall_ac(3);
    	set_stats("strength",18);
    	set_stats("dexterity",17);
    	set_exp(dlevel*25);
    	set_max_hp((random(120)+(dlevel*6)));
    	set_hp(query_max_hp());
    	set_achats(0,({
		"%^CYAN%^Goblin grunts: %^RESET%^You make mistake, bad mistake!",
		"Goblin boss screams for reinforcements.",
		"Goblin boss shrugs.\n%^CYAN%^Goblin grunts: %^RESET%^You die now, yup yup!",
		"%^CYAN%^Goblin grunts: %^RESET%^King sez you die!",
		"%^CYAN%^Goblin whispers: Give me shinies and go, mebbe me let "+
			"you live.%^RESET%^",
		"%^CYAN%^Goblin yells: %^BOLD%^%^RED%^LEAVE NOW!!%^RESET%^",
    	}),0);
    	set_emotes(0,({
    		"Goblin boss wipes his snotty nose on his hairy arm.",
    		"Goblin boss coughs and spits.",
		"Goblin boss barks orders at the others.",
		"Goblin boss glances slyly at you.",
		"Goblin boss flexes his impressive, but diminutive muscles.",
		"Goblin boss smacks a smaller goblin in the back of the head.",
		"Goblin boss yanks what look to be a gory elven leg from a smaller "+
			"goblin and starts gnawing on it hungrily.",
    	}),0);
    	add_money("gold",random(40));
    	add_money("silver",random(100));
    	add_money("copper",random(500));
    	ob = new( CWEAP+"longsword.c" );
     		ob->set_property("monsterweapon", 1);
   		ob->move(TO);
    		command("wield sword in right hand and left hand");
	num = random(20);
	ob = new(CARM+"sfullplate.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear plate");
    	command("speak goblin");
    	command("speech grunt");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(20);
  	set_size(1);
    	set_property("swarm",1);
    	set_speed(30);
	FLAG = 0;
	set_property("knock unconscious");
	set_monster_feats(({
	   "blade block",
	   "impale",
	   "light weapon",
	   "strength of arm",
	   "sweepingblow"
	}));
	set_funcs(({
	   "impaleit",
	   "sweepit"
	}));
	set_func_chance(30);
}
void init(){
	string mrace= TP->query_race(),srace = (string)TP->query("subrace"),mname = TP->query_name();
    	::init();
    	if(avatarp(TP) || TP->query_invis() || mname == "slave" || !interactive(TP)) return;
    	if(is_surfacerace(TP)){
		if(TP->query_bound())return 1;
	TP->add_follower(TO);
		force_me("kill "+TP->query_name());
		if (FLAG == 1) return;
		force_me("say %^BOLD%^%^RED%^you make good meals me tinkin'!!%^RESET%^");
		force_me("parry");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
			command("say you good, we hate good!");
	TP->add_follower(TO);
			force_me("kill "+TP->query_name());
			if (FLAG == 1) return;
			force_me("say %^BOLD%^%^RED%^you make good meals me tinkin'!!%^RESET%^");
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
	force_me("emote grins a big toothy grin");
	force_me("say what tribe you?");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("quiver");
	if (FLAG == 1) return;
	force_me("say you no hurt us please?");
	force_me("emote scurries around covering his head and ducking.");
	FLAG = 1;
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote growls at you");
	if (FLAG == 1) return;
	force_me("say you do wot me say...you be ok!");
	force_me("say ME da boss of you!");
	force_me("emote pokes you threateningly.");
	FLAG = 1;
}
void watchem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote watches you closely.");
	if (FLAG == 1) return;
	force_me("say you belong or no?");
	force_me("emote looks at you warily.");
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
		command("say you good, we hate good!");
	targ->add_follower(TO);
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		force_me("say %^BOLD%^%^RED%^you make good meals me tinkin'!!%^RESET%^");
		force_me("parry");
		FLAG = 1;
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			command("say SHHHHHH!  Sleeping");
			command("emote giggles wickedly");
	targ->add_follower(TO);
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			force_me("say %^BOLD%^%^RED%^you make good meals me tinkin'!!%^RESET%^");
			force_me("parry");
			FLAG = 1;
			return;
		}else{
			command("say you BAAAAAAD!");
			command("emote smiles uneasily");
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "goblin"|| mrace == "orc" || mrace == "hobgoblin"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
	targ->add_follower(TO);
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			force_me("say %^BOLD%^%^RED%^you make good meals me tinkin'!!%^RESET%^");
			force_me("parry");
			FLAG = 1;
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
	targ->add_follower(TO);
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			force_me("say %^BOLD%^%^RED%^you make good meals me tinkin'!!%^RESET%^");
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
	targ->add_follower(TO);
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			force_me("say %^BOLD%^%^RED%^you make good meals me tinkin'!!%^RESET%^");
			force_me("parry");
			FLAG = 1;
			return;
		}else{
			call_out("bullyem",0,TP);
			return;
		}
	}else if(mrace == "dwarf" || mrace == "elf" || mrace == "centaur" ||
		mrace == "half-elf" || mrace == "gnome" || mrace == "beastman" ||
		mrace == "voadkyn" || mrace == "halfling"){
		if(targ->query_bound())return 1;
	targ->add_follower(TO);
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		force_me("say %^BOLD%^%^RED%^you make good meals me tinkin'!!%^RESET%^");
		force_me("parry");
		FLAG = 1;
		return;
	}else if(mrace == "wemic" || mrace == "human" || mrace == "yuan-ti"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
	targ->add_follower(TO);
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			force_me("say %^BOLD%^%^RED%^you make good meals me tinkin'!!%^RESET%^");
			force_me("parry");
			FLAG = 1;
			return;
		}else{
			call_out("watchem",0,TP);
			return;
		}
	}else{
		tell_room(TO,"WHAT THE HELL ARE YOU?");
	targ->add_follower(TO);
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		force_me("say %^BOLD%^%^RED%^you make good meals me tinkin'!!%^RESET%^");
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
	    	call_out("race_ck",0,person);
	}
	return 1;
}
void heart_beat() {
    	object obj;
    	::heart_beat();

	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;
    	if(obj = present("corpse",ETO)){
    		command("emote tears a hug hunk of meat off of the "+
    			"corpse and starts eating greedily.");
     		obj->remove();
     		command("get coins");
  	}
     	do_check();
   	if (FLAG == 0)return;
    	timer++;
    	if(timer > 100){
      	timer = 0;
		if(query_attackers() != ({}))FLAG = 0;
    		return;
    	}
}

void imapleit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("impale "+targ->query_name());
}

void sweepit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("sweepingblow "+targ->query_name());
}