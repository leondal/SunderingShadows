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
    	dlevel = random(11) +12;
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
    	add_money("copper",random(2500));
    	ob = new( CWEAP+"club_lg.c" );
    		ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
     		ob->set_property("enchantment",(random(3)+1));
    		command("wield club");
	ob = new(CARM+"robe.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
  		ob->set_short("A bear skin loin cloth");
  		ob->set_long("This raggedy piece of bear skin barely "+
  			"covers the modesty of the wearer and is infested "+
  			"with fleas and other insect life.");
            ob->add_id(({"cloth","loin cloth","bear skin loin cloth"}));
    		command("wear robe");
    	command("speak giant");
    	command("speech bellow");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(20);
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
		force_me("rush "+TP->query_name());
		if (FLAG == 1) return;
		force_me("parry");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		if(TP->query_bound())return 1;
		force_me("kill "+TP->query_name());
		force_me("rush "+TP->query_name());
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
	force_me("rush "+targ->query_name());
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
	if(!random(3))force_me("emote backs away slowly.");
	FLAG = 1;
}
void stealem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("strip "+targ->query_name()+" of money");
	if(!random(3))force_me("emote chuckles again.");
	FLAG = 1;
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("emote waves his club menacingly at you.");
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
		call_out("killem",0,TP);
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "goblin" || mrace == "orc" || mrace == "kobold" || mrace == "troll" ||
		mrace == "half-orc" || mrace == "half-drow" || mrace == "yuan-ti" ||
		mrace == "hobgoblin" || mrace == "human" || mrace == "half-ogre"  ||
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
			call_out("friendly",0,TP);
			command("say him sleeping");
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
     	do_check();
   	if (FLAG == 0)return;
    	timer++;
    	if(timer > 100){
      	timer = 0;
		if(query_attackers() != ({}))FLAG = 0;
    		return;
    	}
}
