#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,num,timer;
object ob;

void do_check();

create() {
    	::create();
    	set_name("ogre");
    	set_id(({"monster","ogre"}));
    	set_short("ogre");
    	set_long("This being is humanoid, at least 8 feet tall, and covered "+
    		"with lumpy skin.  The ogre's massive muscles are only slightly "+
    		"less impressive than the stench of rotted meat and body odor that "+
    		"emmanates from him.  Covered in just a loin cloth the ogre looks ready "+
    		"for business.");
    	set_body_type("humanoid");
    	dlevel = random(12) +14;
    	set_hd(dlevel,10);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(9);
    	set_race("ogre");
    	set_gender("male");
    	set_overall_ac(0);
    	set_stats("strength",20);
    	set_stats("dexterity",9);
    	set_stats("intelligence",5);
    	set_stats("wisdom",5);
    	set_stats("constitution",20);
  	set_size(3);
    	set_stats("charisma",3);
    	set_exp(dlevel*25);
    	set_max_hp((random(120)+(dlevel*10)));
    	set_hp(query_max_hp());
    	set_achats(0,({
		"Ogre grins fiercely as he swings his club at you.",
		"Ogre slams his club into the ground causing the ground to shake.",
		"Ogre grabs at you with one of his huge hands.",
		"%^BOLD%^%^RED%^Ogre bellows a war cry and lunges for you!%^RESET%^",
		"Ogre kicks a large clod of dirt at your head in an attempt to distract you.",
    	}),0);
    	set_emotes(0,({
    		"Ogre scratches his head lazily.",
    		"Ogre scratches his rear end lazily.",
		"Ogre yawns loudly.",
		"Ogre slaps his club against his palm over and over.",
		"Ogre grunts.",
		"Ogre uproots a small tree and picks his teeth with it.",
    	}),0);
    	add_money("copper",random(2500));
    	ob = new( CWEAP+"club_lg.c" );
    		ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
     		ob->set_property("enchantment",(random(3)+1));
    		command("wield large club");
	num = random(10);
	ob = new(CARM+"robe.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
  		ob->set_short("A bear skin loin cloth");
  		ob->set_long("This raggedy piece of bear skin barely "+
  			"covers the modesty of the wearer and is infested "+
  			"with fleas and other insect life.");
            ob->add_id(({"cloth","loin cloth","bear skin loin cloth"}));
    		command("wear robe");
    	command("speak giant");
    	command("speech roar");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(20);
    	set_property("swarm",1);
	FLAG = 0;
    	set_speed(35);
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
		force_me("say %^BOLD%^%^RED%^you not worth me trouble, "+
			"but me bored!!%^RESET%^");
		force_me("parry");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		if(TP->query_bound())return 1;
		command("say GOOD SMELL, MAKE ME SICK!");
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
	force_me("say %^BOLD%^%^RED%^you not worth me trouble, but me bored!!%^RESET%^");
	force_me("parry");
	FLAG = 1;
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
	force_me("emote grins a big stupid grin.");
	force_me("emote slaps you on the back hard.");
	force_me("say now gimme food.");
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
	force_me("emote waves his club menacingly at you.");
	if (FLAG == 1) return;
	force_me("say Me boss or you me squish!");
	force_me("say Wot you say?!?!");
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
		command("say GOOD SMELL, MAKE ME SICK!");
		call_out("killem",0,TP);
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			command("say food...YUM!");
			call_out("killem",0,TP);
			return;
		}else{
			command("say Me likes you.");
			command("emote thumps you on the back hard.");
			call_out("friendly",0,TP);
			return;
		}
	}
	if(mrace == "goblin" || mrace == "orc" || mrace == "kobold" || mrace == "yuan-ti" ||
		mrace == "half-orc" || mrace == "half-drow" || mrace == "troll" ||
		mrace == "hobgoblin" || mrace == "human" || mrace == "half-ogre" ||
		(mrace == "dwarf" && srace == "gray dwarf")){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("bullyem",2,TP);
			return;
		}
	}else if(mrace == "drow" || mrace == "ogre-mage" || mrace == "minotaur"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("fearem",2,TP);
			return;
		}
	}else if(mrace == "ogre" || mrace == "bugbear" || mrace == "gnoll"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			command("say him sleeping");
			call_out("friendly",0,TP);
			return;
		}else{
			call_out("friendly",2,TP);
			return;
		}
	}else if(mrace == "dwarf" || mrace == "elf" || mrace == "centaur" ||
		mrace == "half-elf" || mrace == "gnome" || mrace == "beastman" ||
		mrace == "voadkyn" || mrace == "halfling" ||
		mrace == "wemic" || mrace == "firbolg"){
		if(targ->query_bound())return 1;
		call_out("killem",0,TP);
		return;
	}else{
		command("say %^BOLD%^%^RED%^WHAT THE HELL ARE YOU?%^RESET%^");
		command("say %^BOLD%^%^RED%^no matter, me kill you me will!%^RESET%^");
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
