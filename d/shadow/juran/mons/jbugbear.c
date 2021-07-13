#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,num,timer;
object ob;

void do_check();

create() {
    	::create();
    	set_name("bugbear");
    	set_id(({ "monster","bugbear" }));
    	set_short("bugbear");
    	set_long("This being is a giant cousin of the goblins.  The "+
    		"bugbear stands 7 feet tall and is very muscular.  His "+
    		"hide ranges from yellow to dark brown and his hair is "+
    		"coarse and brown.  Eyes of greenish white with red pupil "+
    		"look you over.  His ears are wedge shaped and atop his "+
    		"head while his mouth if full of sharp fangs.");
    	set_body_type("humanoid");
    	dlevel = random(6) +10;
    	set_hd(dlevel,8);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
   	set_size(3);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(9);
    	set_race("bugbear");
    	set_gender("male");
    	set_overall_ac(3);
    	set_stats("strength",19);
    	set_stats("dexterity",17);
    	set_stats("intelligence",8);
    	set_stats("wisdom",5);
    	set_stats("constitution",16);
    	set_stats("charisma",5);
    	set_exp(dlevel*25);
    	set_max_hp((random(120)+(dlevel*8)));
    	set_hp(query_max_hp());
    	set_achats(0,({
		"Bugbear grins fiercely as he thrusts his spearb at you.",
		"Bugbear feints at you with his spear.",
		"Bugbear swipes at you with his free claw.",
		"%^BOLD%^%^RED%^Bugbear screams loudly for reinforcements and "+
			"then lunges for you!%^RESET%^",
		"Bugbear swings his spear like a club toward your head.",
    	}),0);
    	set_emotes(0,({
    		"Bugbear grunts.",
    		"Bugbear scratches his rear end lazily.",
		"Bugbear yawns loudly.",
		"Bugbear slaps his spear against his palm over and over.",
		"Bugbear drools hungrily.",
		"Bugbear swats a a fly buzzing his head.",
    	}),0);
    	add_money("gold",random(40));
    	add_money("silver",random(100));
    	add_money("copper",random(500));
    	ob = new( CWEAP+"spear_lg.c" );
    		ob->set_property("monsterweapon", 1);
  	 	ob->move(TO);
     		ob->set_property("enchantment",(random(2)+1));
   		command("wield spear");
	num = random(10);
	ob = new(CARM+"banded.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear banded");
        command("speak goblin");
    	command("speech grunt");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(20);
    	set_property("swarm",1);
	FLAG = 0;
	set_speed(35);
	set_property("knock unconscious");
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
		force_me("say %^BOLD%^%^RED%^wonder if you meat stringy?!%^RESET%^");
		force_me("say %^BOLD%^%^RED%^we find out soon 'nuff!%^RESET%^");
		force_me("parry");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		command("say BAH! KILL GOODIES!");
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
	force_me("say %^BOLD%^%^RED%^wonder if you meat stringy?!%^RESET%^");
	force_me("say %^BOLD%^%^RED%^we find out soon 'nuff!%^RESET%^");
	force_me("parry");
	FLAG = 1;
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
	force_me("emote makes what passes for a bugbear smile.");
	force_me("emote turns the point of his spear away from you.");
	force_me("say anything to eat you gots?");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote watches you all the time");
	if (FLAG == 1) return;
	force_me("say be good yes?");
	force_me("emote backs away slowly.");
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
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote pokes his spear at you menacingly.");
	if (FLAG == 1) return;
	force_me("say What you want pipsqueak!");
	force_me("say Say fast now?!?!");
	force_me("emote looms over you threateningly.");
	FLAG = 1;
}
void watchem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote watches you closely.");
	if (FLAG == 1) return;
	force_me("say hmmm, be ye friend or foe?");
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
		command("say BAH! KILL GOODIES!");
		call_out("killem",0,TP);
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			command("say awwwww, look, it sleepin'.");
			command("emote chuckle gruffly.");
			call_out("stealem",0,TP);
			return;
		}else{
			command("say welcome evil master.");
			command("bows awkwardly");
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "goblin" || mrace == "orc" || mrace == "kobold" ||
		mrace == "half-orc" || mrace == "half-drow"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("bullyem",0,TP);
			return;
		}
	}else if(mrace == "drow" || mrace == "ogre" || mrace == "minotaur" || mrace == "troll" ||
		mrace == "ogre-mage" || mrace == "half-ogre" || (mrace == "dwarf" && srace == "gray dwarf")){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}else if(mrace == "bugbear" || mrace == "gnoll" || mrace == "hobgoblin"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
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
			call_out("stealem",0,TP);
			return;
		}else{
			call_out("watchem",0,TP);
			return;
		}
	}else{
		command("say %^BOLD%^%^RED%^WHAT THE HELL ARE YOU?%^RESET%^");
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
      if(!objectp(TO)) return;
      if(!objectp(ETO)) return;
    	if(obj = present("corpse",ETO)){
    		command("emote %^BOLD%^%^RED%^rips an arm off the corpse "+
    			"and eats it messily.%^RESET%^");
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
