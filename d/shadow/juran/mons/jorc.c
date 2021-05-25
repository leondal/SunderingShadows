#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,dlevel,num,timer;
object ob;

void do_check();

create() {
    	::create();
    	set_name("orc chieftain");
    	set_id(({"chieftain","monster","orc","orc chieftain"}));
    	set_short("orc chieftain");
   	set_wimpy(20);
    	set_long("The creature stands and walks like a man, but has "+
    		"the face of a pig.  His nose is like that of a pig and "+
    		"his lower teeth jut out of his lips like tusks.  This "+
    		"individual look both brutish and violent and is covered "+
    		"with rune tattoos.");
    	set_body_type("humanoid");
    	dlevel = random(8) +12;
    	set_hd(dlevel,8);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_alignment(9);
    	set_race("orc");
    	set_gender("male");
    	set_overall_ac(2);
    	set_stats("strength",18);
    	set_stats("dexterity",12);
    	set_exp(dlevel*25);
    	set_max_hp((random(120)+(dlevel*6)));
    	set_hp(query_max_hp());
    	set_achats(0,({
		"%^CYAN%^Chieftain grunts loudly: %^RESET%^Now we are gonna hurt you!",
		"Chieftain howls for his tribe.",
		"%^CYAN%^Chieftain grunts loundly: %^RESET%^You die now, stand still!",
		"%^CYAN%^Chieftain grunts loudly: %^RESET%^I will make a hat out of your skull!",
		"%^CYAN%^Chieftain grunts loudly: %^RESET%^I will give your weapons to my kids.",
		"%^CYAN%^Chieftain grunts loudly: %^BOLD%^%^RED%^THAT HADTA HURT!!%^RESET%^",
    	}),0);
    	set_emotes(0,({
    		"Chieftain licks his lips hungrily.",
    		"Chieftain coughs and spits.",
		"Chieftain yells at a smaller orc.",
		"Chieftain glances slyly at you.",
		"Chieftain flexes his impressive muscles.",
		"Chieftain waves his axe at another orc menacingly.",
		"Chieftain pulls a severed delicate hand from his pocket "+
			"and begins to chew on the fingers hungrily.",
    	}),0);
    	add_money("gold",random(40));
    	add_money("silver",random(100));
    	add_money("copper",random(500));
  	set_size(2);
	num = random(20);
  	ob = new( CWEAP+"battle_axe.c" );
     		if(num)ob->set_property("monsterweapon", 1);
 	    	ob->move(TO);
            command("wield battle axe");
     		ob->set_property("enchantment",(random(3)+1));    		
	ob = new(CARM+"splint.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear splint");
    	command("speak orcish");
    	command("speech grunt loudly");
   	set_property("full attacks",1);
    	add_search_path("/cmds/fighter");
    	set_max_level(15);
    	set_property("swarm",1);
    	set_speed(35);
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
		force_me("say %^BOLD%^%^RED%^supper boys, let's get at it!!%^RESET%^");
		force_me("parry");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		command("say I heard bout you, yer nice.");
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
	force_me("say %^BOLD%^%^RED%^supper boys, let's get at it!!%^RESET%^");
	force_me("parry");
	FLAG = 1;
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
	force_me("emote slaps you on the back hard.");
	force_me("say what tribe you from?");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	force_me("say orc's can be big help, you ask, you see?");
	force_me("emote dips his head and backs away.");
	FLAG = 1;
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote growls at you");
	if (FLAG == 1) return;
	force_me("say best you listen up punk!");
	force_me("say Me da boss here!");
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
		command("say I heard bout you, yer nice.");
		call_out("killem",0,TP);
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			command("say Don't they look so peaceful?");
			command("say try not ta wake 'em when you take they money.");
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
	}else if(mrace == "kobold" || mrace == "half-orc" || mrace == "half-drow"){
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
