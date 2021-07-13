#include <std.h>
#include <daemons.h>
#include "../juran.h"

inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,FACE,STUFF,num,timer;
object ob;

create() {
    	::create();
    	set_name("doppleganger");
    	set_id(({"monster","doppleganger"}));
    	set_short("doppleganger");
    	set_long("Generally humanoid in appearance this bipedal creature "+
    		"is covered in a thick gray hide."
    	);
    	set_hd(5, 6);
    	set_level(5);
   	set_size(2);
    	set_body_type("humanoid");
    	set_alignment(9);
    	set_race("doppleganger");
    	set_gender("neuter");
    	set_ac(5);
    	set_stats("strength",18);
    	set_stats("dexterity",18);
    	set_stats("wisdom",18);
    	set_stats("intelligence",18);
    	set_exp(1500);
    	set_hp(query_max_hp());
    	set_achats(3,({
		"Ducks under your blow and comes up ready to fight.",
		"Sweeps out a leg trying to trip you.",
		"Leaps high into the air aiming a kick at your head.",
		"Hisses at you.",
 		"Anticipates your next move and counters it.",
   	}),0);
    	set_emotes(1,({
		"Nods to you.",
		"Looks you over slowly and smiles.",
		"Watches you secretly.",
		"Smiles at you confidently.",
		"Chuckles at some private joke.",
		"Stands completely still.",
    	}),0);
    	add_search_path("/cmds/fighter");
    	add_search_path("/cmds/thief");
    	add_search_path("/cmds/mage");
    	add_search_path("/cmds/bard");
    	add_search_path("/cmds/priest");
    	add_search_path("/cmds/assassin");
    	add_search_path("/cmds/ranger");
    	set_property("swarm",1);
    	set_property("full attacks",1);
    	command("speak wizish");
    	set_speed(30);
    	set_mob_magic_resistance("average");
	FLAG = 0;
	FACE = 0;
	STUFF = 0;
	set_property("knock unconscious");
}
void init(){
	string mrace= TP->query_race(),srace = (string)TP->query("subrace"),mname = TP->query_name();
    	::init();
    	if(avatarp(TP) || TP->query_invis() || mname == "slave" || !interactive(TP)) return;
    	if(FACE==0){
		tell_object(TP,"%^BOLD%^Another mind bores into your brain and all "+
			"your secrets are laid bare.%^RESET%^");
		TP->set_paralyzed(5000,"%^BOLD%^%^MAGENTA%^Another mind is probing yours!");
		tell_room(ETP,"%^BOLD%^"+TPQCN+" stops dead "+
			"in "+TP->query_possessive()+" tracks "+
			"with a blank look on "+TP->query_possessive()+" face.%^RESET%^",TP);
    		call_out("make_face",0,TP);
	   	TP->set_paralyzed(0);
    		force_me("kill "+TPQCN);
    		return;
    	}
	if((mrace == "dwarf" && srace != "gray dwarf") || mrace == "elf" || mrace == "half-elf" ||
		mrace == "gnome" || mrace == "beastman" || mrace == "voadkyn" ||
		mrace == "halfling" || mrace == "half-drow"){
		if(TP->query_bound())return 1;
		force_me("kill "+TP->query_name());
		if (FLAG == 1) return;
		force_me("say time to die morsel!");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		command("emote licks its lips.");
		command("say yummy.");
		if(TP->query_bound())return 1;
		force_me("kill "+TP->query_name());
		return;
	}
	call_out("race_ck",0,TP);
}
void killem(object targ){
	force_me("kill "+targ->query_name());
	if (FLAG == 1) return;
	force_me("say time to die tasty morsel!");
	FLAG = 1;
}
void friendly(object targ){
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
	force_me("say I am you, you are me.");
	force_me("emote smiles an evil smile.");
	FLAG = 1;
}
void fearem(object targ){
	force_me("emote looks for an exit.");
	if (FLAG == 1) return;
	force_me("emote never lets you get behind it.");
	FLAG = 1;
}
void bullyem(object targ){
	force_me("emote grins at you showing more teeth that you prefer.");
	if (FLAG == 1) return;
	force_me("say leave.");
	force_me("say now.");
	FLAG = 1;
}
void watchem(object targ){
	force_me("emote watches you closely.");
	if (FLAG == 1) return;
	force_me("emote looks at you and ponders.");
	FLAG = 1;
}
void race_ck(object targ){
	string mrace= targ->query_race(),srace = (string)targ->query("subrace"),mname = targ->query_name();

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
	if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		command("say kill it my pets.");
		call_out("killem",0,TP);
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			command("say let us see what they have.");
			call_out("stealem",0,TP);
			return;
		}else{
			command("wink "+targ->query_cap_name());
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "drow" ){
			call_out("fearem",0,TP);
			return;
	}else if(mrace == "kobold" || mrace == "goblin"|| mrace == "orc" || mrace == "yuan-ti" ||
		mrace == "hobgoblin" || mrace == "ogre" || mrace == "bugbear" || mrace == "minotaur" ||
		mrace == "gnoll" || mrace == "ogre-mage" || mrace == "half-ogre" || mrace == "troll" ||
		mrace == "firbolg" || mrace == "wemic" || mrace == "human" || mrace == "half-drow" ||
		mrace == "half-orc" || (mrace == "dwarf" && srace == "gray dwarf")){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("bullyem",0,TP);
			return;
		}
	}else if(mrace == "dwarf" || mrace == "elf" || mrace == "half-elf" ||
		mrace == "gnome" || mrace == "beastman" || mrace == "voadkyn" ||
		mrace == "halfling" || mrace == "centaur"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("killem",2,TP);
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
void make_face(object targ){
	string mclass= TO->query_class();

	FACE = 1;
    	set_name(targ->query_cap_name());
    	set_id(({targ->query_cap_name()+"'s evil twin", "doppleganger","monster"}));
    	set_short(targ->query_cap_name());
    	set_long("This looks very much like a "+targ->query_gender()+" "+
    		""+targ->query_race()+", maybe it is.\n");
    	set_race(targ->query_race());
    	set_gender(targ->query_gender());
    	set_body_type(targ->query_body_type());
    	set_hd(targ->query_hd()+5,8);
    	set_class(targ->query_class());
    	set_level(targ->query_level()+5);
    	set_mlevel(targ->query_class(),targ->query_level()+5);
    	set_size(targ->query_size());
    	set_wielding_limbs(targ->query_wielding_limbs());
    	set_max_hp(targ->query_max_hp()+50);
    	set_hp(targ->query_max_hp()+50);
    	set_max_sp(targ->query_max_sp());
    	set_sp(targ->query_max_sp());
    	set_stats("strength", targ->query_stats("strength"));
    	set_stats("dexterity", targ->query_stats("dexterity"));
    	set_stats("constitution", targ->query_stats("constitution"));
    	set_stats("charisma", targ->query_stats("charisma"));
    	set_stats("intelligence", targ->query_stats("intelligence"));
    	set_stats("wisdom", targ->query_stats("wisdom"));
    	set_overall_ac(targ->query_ac());
    	set_spell_chance(targ->query_spell_chance());
    	set_spells(targ->query_spells());
    	if(STUFF == 0){
    	   STUFF = 1;
	   ob = new(CARM+"robe.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	   ob = new("/d/deku/armours/ring_p.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	   if(mclass == "fighter" || mclass == "cavalier" || mclass == "paladin" || 		mclass == "antipaladin"){
    		num = random(15);
		ob = new( "/d/laerad/parnelli/asgard/sewer/weapons/flamesword.c" );
		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
		command("wield flame");
		ob = new(CARM+"field.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
		ob = new(CARM+"shield.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
		ob = new(CARM+"helm.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wearall");
		return 1;
    	   }else if(mclass == "cleric"){
   		num = random(15);
		ob = new( "/d/laerad/parnelli/asgard/sewer/weapons/flamemace.c" );
    		if(num)ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
    		command("wield flame");
    		ob = new(CARM+"field.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
		ob = new(CARM+"shield.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
		ob = new(CARM+"helm.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wearall");
		return 1;
	   }else if(mclass == "ranger"){
    		num = random(15);
		ob = new( "/d/laerad/parnelli/asgard/sewer/weapons/flamesword.c" );
    		if(num)ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
    		command("wield flame");
    		num = random(15);
		ob = new( "/d/laerad/parnelli/asgard/sewer/weapons/flamesword.c" );
    		if(num)ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
    		command("wield flame");
    		ob = new(CARM+"studded.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
		ob = new("/d/laerad/obj/bracers2.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wearall");
		return 1;
    	   }else if(mclass == "thief"){
	    	num = random(15);
		ob = new( "/d/laerad/parnelli/asgard/sewer/weapons/flamesword.c" );
    		if(num)ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
    		command("wield flame");
    		ob = new(CARM+"hide.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		ob = new("/d/tharis/obj/wrist_sheath.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
		ob = new("/d/laerad/obj/bracers2.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wearall");
		ob = new( CWEAP+"dagger" );
    		ob->set_property("monsterweapon", 1);
      	ob->set_property("enchantment",2);
 	    	ob->move(TO);
  	    	command("put dagger in sheath");
    		set_scrambling(1);
    		set_thief_skill("move silently", 95);
    		set_thief_skill("hide in shadows", 95);
		return 1;
    	   }else if(mclass == "bard" || mclass == "assassin"){
	    	num = random(15);
		ob = new( "/d/laerad/parnelli/asgard/sewer/weapons/flamessword.c" );
    		if(num)ob->set_property("monsterweapon", 1);
  	    	ob->move(TO);
    		command("wield flame");
    		ob = new(CARM+"hide.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
		ob = new("/d/laerad/obj/bracers2.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wearall");
		return 1;
    	   }else{
		ob = new("/d/laerad/obj/bracers2.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wearall");
    		return 1;
         }
	}
}
void heart_beat() {
    	object obj;
    	::heart_beat();

	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;
    	if(obj = present("corpse",ETO)){
    		tell_room(ETO,"%^BOLD%^%^CYAN%^Rifles through the corpse's belongings.%^RESET%^");
     		obj->remove();
     		command("get coins");
     		command("get kit");
  	}
   	if(present("kit",TO) && query_hp() < query_max_hp()/2){
		command("open kit");
		command("quaff kit");
		command("offer bottle");
   	}
    	if(present("bottle",TO)) command("offer bottle");
     	do_check();
   	if (FLAG == 0)return;
    	timer++;
    	if(timer > 100){
      	timer = 0;
		if(query_attackers() != ({}))FLAG = 0;
    		return;
    	}
}
