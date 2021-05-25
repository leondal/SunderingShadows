#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,timer;
// object ob;  // moved to within create so it will be a local variable and won't stay in memory.

void do_check();

create() {
        object ob;
    	::create();
    	set_name("hobgoblin");
    	set_id(({"monster","hobgoblin"}));
    	set_short("hobgoblin");
// set_wimpy(20);   removed because they get too far if it kicks in, esp. on longer reboots.
    	set_long("This brutish humanoid is called a hobgoblin.  Wearing "+
    		"banded armor this larger cousin of the goblins looks to "+
    		"be a bit more organized and more dangerous.");
    	set_body_type("humanoid");
    	dlevel = random(6) +10;
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
        set_max_hp((random(60)+(dlevel*9)));
    	set_hp(query_max_hp());
    	set_achats(0,({
		"%^CYAN%^Hobgoblin growls: %^RESET%^Bet you cook up good!",
		"Hobgoblin swings at your wildly.",
		"%^CYAN%^Hobgoblin growls: %^RESET%^Try not mess him up "+
			"too bad! \n%^CYAN%^Hobgoblin growls: %^RESET%^Bruises taste funny.",
		"%^CYAN%^Hobgoblin growls: %^RESET%^Kill it quick!",
		"%^CYAN%^Hobgoblin growls: %^RESET%^We will taste your meat.",
		"%^CYAN%^Hobgoblin growls: %^BOLD%^%^RED%^DIE! DIE ! DIE!%^RESET%^",
    	}),0);
    	set_emotes(0,({
    		"Hobgoblin licks his lips hungrily.",
    		"Hobgoblin coughs and spits up a hairball.",
		"Hobgoblin laughs and pokes another hobgoblin.",
		"Hobgoblin glances at you.",
		"Hobgoblin checks the edge on his blade.",
		"Hobgoblin adjusts his armor.",
    	}),0);
    	add_money("gold",random(40));
    	add_money("silver",random(400));
    	add_money("copper",random(500));
  	set_size(2);
  	ob = new( CWEAP+"halberd.c" );
    		ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
     		ob->set_property("enchantment",2);
               command("wield halberd"); // added, assuming an oversight they weren't
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
        set_speed(60);
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
	TP->add_follower(TO);
		force_me("kill "+TP->query_name());
		if (!random(3))force_me("rush "+TP->query_name());
		if (FLAG == 1) return;
		force_me("say %^BOLD%^%^RED%^get 'em boys!!%^RESET%^");
		force_me("parry");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		command("say I hear you been real good!");
	TP->add_follower(TO);
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
	targ->add_follower(TO);
	force_me("kill "+targ->query_name());
	if (!random(3))force_me("rush "+targ->query_name());
	if (FLAG == 1) return;
	force_me("say %^BOLD%^%^RED%^get 'em boys!!%^RESET%^");
	force_me("parry");
	FLAG = 1;
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
	force_me("emote laughs.");
	force_me("say you got any extra food?");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote shies away from you.");
	if (FLAG == 1) return;
	force_me("say you need anything...we can get it?");
	force_me("emote dips his head and backs away.");
	FLAG = 1;
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote growls at you");
	if (FLAG == 1) return;
	force_me("say we make rules here!");
	force_me("emote pokes at you threateningly.");
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
		command("say I hear you been real good!");
		call_out("killem",0,TP);
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			command("say let 'em sleep!");
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
    	if(obj = present("corpse",ETO)){
    		command("say better cooked, but what the hell?");
    		command("emote tears a huge hunk of meat off of the "+
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
