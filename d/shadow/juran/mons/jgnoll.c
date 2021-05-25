#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,num,timer;
object ob,obj;

void do_check();

create() {
    	::create();
    	set_name("gnoll slaver");
    	set_id(({"gnoll","monster","slaver","gnoll slaver"}));
    	set_short("gnoll slaver");
    	set_long("This is a large hyena-like humanoid.  The gnoll has "+
    		"greenish gray skin and a darker muzzle. The creature has "+
    		"a reddish gray to dull yellow mane.");
    	set_body_type("humanoid");
    	dlevel = random(11) +15;
    	set_hd(dlevel,10);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
   	set_size(3);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(9);
    	set_race("gnoll");
    	set_gender("male");
    	set_overall_ac(0);
    	set_stats("strength",19);
    	set_stats("dexterity",14);
    	set_stats("intelligence",8);
    	set_stats("wisdom",8);
    	set_stats("constitution",16);
    	set_stats("charisma",5);
    	set_exp(dlevel*25);
    	set_max_hp((random(120)+(dlevel*8)));
    	set_hp(query_max_hp());
    	set_achats(3,({
		"Gnoll growls and spits at you.",
		"Gnoll lunges at you.",
		"Gnoll feints at you then dodges left.",
		"Gnoll feints at you then dodges right.",
		"Gnoll swats at you savagely with his hammer.",
    	}),0);
    	set_emotes(3,({
    		"Gnoll barks at the slaves.",
    		"Gnoll yanks the chain attached to his slaves.",
		"Gnoll backhands a slave.",
		"Gnoll grins hungrily at a slave.",
		"Gnoll gives an evil chuckle.",
    	}),0);
    	add_money("gold",random(40));
    	add_money("silver",random(100));
    	add_money("platinum",random(25));
	num = random(15);
  	switch(random(4)){
  		case 0:
			ob = new( JWEAP+"adam_ham4.c" );
			break;
            case 1:
			ob = new( JWEAP+"adam_ham3.c" );
            	break;
            case 2:
			ob = new( JWEAP+"adam_ham2.c" );
           		break;
		case 3:
			ob = new( CWEAP+"warhammer.c" );
			break;
      }
    		if(num)ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
    		command("wield hammer");
      num = random(10);
	ob = new(CARM+"hide.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear hide");
        command("speak beast");
    	command("speech growl");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(15);
    	set_property("swarm",1);
    	set_speed(35);
	FLAG = 0;
	set_property("knock unconscious");
	set_monster_feats(({
	   "powerattack",
	   "shatter",
	   "sunder",
	   "rush"
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
		force_me("say %^BOLD%^%^RED%^I hate yer kind!!%^RESET%^");
		force_me("parry");
		FLAG = 1;
		return;
	}else	if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		command("say I smell the taint of good.");
		command("look "+mname);
		if(TP->query_bound())return 1;
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
	targ->add_follower(TO);
	force_me("kill "+targ->query_name());
	if (!random(3))force_me("rush "+targ->query_name());
	if (FLAG == 1) return;
	force_me("say %^BOLD%^%^RED%^I hate yer kind!!%^RESET%^");
	force_me("parry");
	FLAG = 1;
}
void friendly(object targ){
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
	force_me("emote makes what passes for a gnoll smile.");
	force_me("say any slaves for sale?");
	FLAG = 1;
}
void fearem(object targ){
	force_me("emote watches you out of the corner of his eye.");
	if (FLAG == 1) return;
	force_me("say I hope we're not gonna have any trouble.");
	force_me("emote never puts his back to you.");
	FLAG = 1;
}
void bullyem(object targ){
	force_me("emote pokes his hammer at you menacingly.");
	if (FLAG == 1) return;
	force_me("say maybe I add you to my goods eh?!");
	force_me("say give me money and maybe I'll leave you alone.");
	force_me("emote smacks his hammer into his hand to accentuate his point.");
	FLAG = 1;
}
void watchem(object targ){
	force_me("emote watches you closely.");
	if (FLAG == 1) return;
	force_me("say so what's it gonna be, play nice or play rough?");
	force_me("emote looks at you warily.");
	FLAG = 1;
}
void stealem(object targ){
	force_me("emote snickers to himself");
	if (FLAG == 1) return;
	force_me("strip "+targ->query_name()+" of money");
	force_me("emote chuckles again.");
	FLAG = 1;
}
void eatem(object targ){
	command("say I am hungry!");
	command("emote looks over the nearest slave.");
	command("emote grins evilly and pulls the chain slowly to him dragging "+
		"the slave to within his reach.");
	command("drool");
	force_me("kill slave");
}
void makeem(object targ){
	ob = new(JMONS+"slave");
	ob->move(ETO);
	targ->add_follower(ob);

	ob = new(JMONS+"slave");
	ob->move(ETO);
	targ->add_follower(ob);

	ob = new(JMONS+"slave");
	ob->move(ETO);
	targ->add_follower(ob);
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
		command("say I smell the taint of good.");
		command("look "+mname);
		call_out("killem",0,TP);
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			command("say bad place to sleep, good place to find my next meal.");
			call_out("killem",0,TP);
			return;
		}else{
			command("bow");
			command("say make you special deals' of me slaves?");
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "goblin" || mrace == "orc" || mrace == "kobold" ||
		mrace == "half-orc" || mrace == "half-drow"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			call_out("bullyem",0,TP);
			return;
		}
	}else if(mrace == "ogre" || mrace == "drow" || mrace == "minotaur" || mrace == "troll" ||
		mrace == "ogre-mage" || mrace == "half-ogre" || (mrace == "dwarf" && srace == "gray dwarf")){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}else if(mrace == "bugbear" || mrace == "gnoll" || mrace == "hobgoblin"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("friendly",0,TP);
			return;
		}
	}else if(mrace == "dwarf" || mrace == "elf" || mrace == "centaur" ||
		mrace == "half-elf" || mrace == "gnome" || mrace == "beastman" ||
		mrace == "voadkyn" || mrace == "halfling"){
		if(targ->query_bound())return 1;
		call_out("killem",0,TP);
		return;
	}else if(mrace == "wemic" || mrace == "firbolg" || mrace == "human" || mrace == "yuan-ti"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("watchem",0,TP);
			return;
		}
	}else{
		command("say %^BOLD%^%^RED%^WHAT THE HELL ARE YOU?%^RESET%^");
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
void reset(){
	::reset();
}
void heart_beat() {
    	object obj;
    	::heart_beat();

	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;
    	if(obj = present("corpse",ETO)){
    		command("emote %^BOLD%^%^RED%^rips an arm off the corpse "+
    			"and eats it messily.%^RESET%^");
     		obj->remove();
     		command("get coins");
  	}
     	do_check();
    	timer++;
    	if(timer > 45){
    		timer = 0;
    		if(present("slave")){
    			if(!random(10))call_out("eatem",1,TO);
    		}else call_out("makeem",0,TO);
    	   	if (FLAG == 0)return;
    		if(query_attackers() != ({}))FLAG = 0;
    		return;
    	}
}
