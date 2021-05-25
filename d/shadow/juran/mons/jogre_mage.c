#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,num,timer;
object ob,obj;

void do_check();

create() {
    	object ob;
    	::create();
    	set_name("ogre-mage");
    	set_id(({"monster","ogre-mage","mage"}));
    	set_short("ogre-mage");
    	set_long("The ogre-mage looms over you.  Slightly taller than its "+
      "denser cousin, the ogre, this beast looks ready for anything.  "+
      "Wearing robes that are covered in complicated runes the "+
    		"ogre-mage seems to be bristling with magical energy.");
    	set_body_type("humanoid");
    	dlevel = random(9) + 15;
    	set_hd(dlevel, 8);
    	set_level(dlevel);
    	set_class("mage");
    	set_guild_level("mage",dlevel);
    	set_mlevel("mage",dlevel);
    	set_class("fighter");
    	set_mlevel("fighter",dlevel);
    	set_alignment(9);
    	set_race("ogre-mage");
    	set_gender("male");
    	set_ac(1);
   	set_size(3);
   	set_stats("strength",19);
    	set_stats("dexterity",17);
    	set_stats("wisdom",14);
    	set_stats("intelligence",18);
    	set_exp(dlevel*25);
    	set_max_hp((random(100)+(dlevel*8)));
    	set_hp(query_max_hp());
    	set_achats(0,({
		"%^CYAN%^Ogre-mage intones: %^RESET%^I love the smell of "+
			"burnt flesh in the morning!",
		"%^CYAN%^Ogre-mage intones: %^RESET%^Did that "+
			"sting?\n%^CYAN%^Ogre-mage intones: %^RESET%^GOOD!",
		"%^CYAN%^Ogre-mage intones: %^BOLD%^%^RED%^I shall turn you "+
			"into a TOAD!!",
		"%^CYAN%^Ogre-mage intones: %^RESET%^Hop little toady!",
 		"%^CYAN%^Ogre-mage intones: %^RESET%^Ok, time to go to sleep "+
 			"little morsel.",
   	}),0);
    	set_emotes(0,({
		"Ogre-mage mutters an incantation.",
		"Ogre-mage traces arcane runes in the air.",
		"Ogre-mage looks you over then chuckles to himself.",
		"Ogre-mage taps his forehead thoughtfully.",
		"Ogre-mage grins evilly.",
    	}),0);
    	add_money("gold",random(100));
    	add_money("silver",random(200));
    	add_money("copper",random(500));
    	set_spell_chance(65);
    	set_spells( ({"magic missile",
    		"chill touch",
    		"hideous laughter",
    		"fireball",
    		"vampiric touch",
    		"lightning bolt",
    		"monster summoning i"
    	}));
	new("/d/azha/obj/mr_ring")->move(TO);
    		command("wear ring");
     	ob = new( CARM+"robe.c" );
    		ob->set_property("monsterweapon", 1);
     		ob->move(TO);
   		command("wear robe");
    	add_search_path("/cmds/fighter");
    	add_search_path("/cmds/mage");
    	set_max_level(15);
    	set_property("swarm",1);
    	set_property("full attacks",1);
        command("speak giant");
    	command("speech intone");
    	set_speed(40);
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
		if (FLAG == 1) return;
		force_me("say %^BOLD%^%^RED%^Your kind is not welcome here!!%^RESET%^");
		force_me("cast dispel magic");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		command("say You goodies think you know all!");
	TP->add_follower(TO);
		force_me("kill "+TP->query_name());
		if (FLAG == 1) return;
		force_me("cast dispel magic");
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
	if (FLAG == 1) return;
	force_me("cast dispel magic");
	force_me("say %^BOLD%^%^RED%^Your kind is not welcome here!!%^RESET%^");
	FLAG = 1;
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
	force_me("emote makes what passes for an ogre-mage smile.");
	force_me("say nice day for carnage eh?");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote watches you out of the corner of his eye.");
	if (FLAG == 1) return;
	force_me("say We're not gonna have any trouble are we?");
	FLAG = 1;
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote glares at you.");
	if (FLAG == 1) return;
	force_me("say you'd better do as I say and everything will be ok?!");
	force_me("say give me your scrolls and we will get along.");
	FLAG = 1;
}
void watchem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote watches you closely.");
	if (FLAG == 1) return;
	force_me("say so what's it gonna be, play nice or be cooked?");
	force_me("emote watches you closely.");
	FLAG = 1;
}
void stealem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote snickers to himself");
	if (FLAG == 1) return;
	force_me("strip "+targ->query_name()+" of money");
	force_me("strip "+targ->query_name()+" of bag");
	force_me("strip "+targ->query_name()+" of bag");
	force_me("strip "+targ->query_name()+" of robe");
	force_me("strip "+targ->query_name()+" of book");
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
		command("say You goodies think you know all!");
		call_out("killem",0,TP);
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			command("say hmmm, don't you look comfortable!");
			call_out("stealem",0,TP);
			return;
		}else{
			command("say how may I serve you.");
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "goblin" || mrace == "orc" || mrace == "kobold" || mrace == "troll" ||
		mrace == "half-orc" || mrace == "half-drow" || mrace == "half-ogre" ||
		(mrace == "dwarf" && srace == "gray dwarf")){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("stealem",0,TP);
			return;
		}else{
			call_out("bullyem",0,TP);
			return;
		}
	}else if(mrace == "drow" || mrace == "minotaur"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}else if(mrace == "ogre" || mrace == "bugbear" ||
		mrace == "gnoll" || mrace == "hobgoblin" || mrace == "ogre-mage"){
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
     		command("get bag");
     		command("get bag");
     		command("get robe");
     		command("get scroll");
     		command("get scroll");
     		command("get book");
  	}
     	do_check();
    	timer++;
    	if(timer > 45){
    		timer = 0;
    	   	if (FLAG == 0)return;
    		if(query_attackers() != ({}))FLAG = 0;
    		return;
    	}
}
