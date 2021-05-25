#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,num,timer;
object ob;

void do_check();

create() {
    	::create();
    	set_name("kobold");
    	set_id(({"monster","kobold"}));
    	set_short("kobold");
   	set_wimpy(15);
    	set_long("This creature stands no more than three feet tall and "+
    		"has scaly skin that ranges from dark, rusty brown to a rusty "+
    		"black.  The kobold's eyes glow with a red spark, two small "+
    		"horns protrude from his forehead and he has a rat-like tail.");
    	set_body_type("humanoid");
    	dlevel = random(4) + 3;
    	set_hd(dlevel,6);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
    	add_search_path("/cmds/fighter");
      set_wielding_limbs(({"right hand","left hand"}));
    	set_stats("intelligence",9);
    	set_stats("wisdom",9);
    	set_stats("strength",14);
    	set_stats("charisma",3);
    	set_stats("dexterity",18);
    	set_stats("constitution",12);
    	set_alignment(9);
    	set_race("kobold");
    	set_overall_ac(5);
    	set_exp(dlevel*20);
    	set_max_hp((random(40)+(dlevel*6)));
    	set_hp(query_max_hp());
    	set_achats(3,({
		"Kobold snarls and spits at you.",
		"Kobold circles you warily looking for an opening.",
		"Kobold tries to bite your ankle.",
		"Kobold gets behind you and tries to stick you with his sword.",
		"Kobold dodges your swing.",
    	}),0);
    	set_emotes(3,({
		"Kobold watches everything closely.",
        	"Kobold keeps his eye on you.",
		"Kobold barks something you cannot understand.",
		"Kobold's rat-like tail twitches.",
    	}),0);
    	add_money("silver",random(25));
    	add_money("copper",random(500));
    	set_property("swarm",1);
    	set_property("full attacks",1);
	num = random(10);
      ob = new(CARM+"hide.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear hide");
      ob = new(CWEAP+"shortsword.c");
     		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wield sword");
    	set_max_level(8);
    	command("speak draconic");
    	command("speech yip");
    	set_speed(20);
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
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
		return;
	}else	if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		command("say you goodies makin' me puke.");
	TP->add_follower(TO);
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
	force_me("emote nods at you.");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("quiver");
	if (FLAG == 1) return;
	force_me("emote trembles with fear");
	FLAG = 1;
}
void bullyem(object targ){
	if(!objectp(TO)) return 1;
	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	force_me("emote looks at you threateningly.");
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
void stealem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote snickers to himself");
	if (FLAG == 1) return;
	force_me("strip "+targ->query_name()+" of money");
	force_me("emote chuckles again.");
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
		command("say you goodies makin' me puke.");
	targ->add_follower(TO);
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			command("say us borrows shinies...sleep good.");
			command("emote giggles wickedly");
			call_out("stealem",0,TP);
			return;
		}else{
			command("say we hearda you...don't hurts us pleazes!");
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "goblin"|| mrace == "orc"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			call_out("friendly",0,TP);
			return;
		}
	}else if(mrace == "drow" || mrace == "ogre" || mrace == "bugbear" || mrace == "troll" ||
		mrace == "gnoll" || mrace == "ogre-mage" || mrace == "hobgoblin" ||
		mrace == "wemic" || mrace == "firbolg" || mrace == "minotaur" || mrace == "yuan-ti" ||
		mrace == "half-ogre" || mrace == "human" || mrace == "half-orc" || mrace == "centaur" ||
		mrace == "half-drow" || (mrace == "dwarf" && srace == "gray dwarf")){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}else if(mrace == "kobold"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			call_out("bullyem",0,TP);
			return;
		}
	}else if(mrace == "dwarf" || mrace == "elf" ||mrace == "half-elf" ||
		mrace == "gnome" || mrace == "beastman" || mrace == "voadkyn" ||
		mrace == "halfling"){
		if(targ->query_bound())return 1;
	targ->add_follower(TO);
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
	}else{
		command("say %^BOLD%^%^RED%^WHAT THE HELL ARE YOU?%^RESET%^");
	targ->add_follower(TO);
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
