#include <std.h>
#include <daemons.h>
#include "../juran.h"

inherit "/d/shadow/juran/mons/wonder.c";
int FLAG,dlevel,num,timer;
string time;
object ob;

void do_check();

void create(){
   	::create();
    	set_name("drow priestess");
    	set_short("drow priestess");
    	set_id( ({"monster", "priestess","drow","drow priestess"}) );
    	set_long(
      	"Wearing very light looking black chainmail and wielding a whip "+
      	"looks very menacing.  Except for skin as black as obsidian, the "+
      	"glowing red eyes, and hair as white as snow, the drow looks very similar "+
      	"to the elves from the surface.\n"
    	);
    	dlevel = random(5)+25;
    	set_body_type("humanoid");
    	set_alignment(9);
    	set_race("drow");
    	set_overall_ac(2);
    	set_hd(dlevel, 10);
    	set_class("cleric");
    	set_mlevel("cleric", dlevel);
    	set_gender("female");
      set_wielding_limbs(({"right hand","left hand"}));
    	set_emotes(0,({
		"%^CYAN%^Priestess purrs: %^RESET%^You have made a horrid mistake!",
		"%^BOLD%^%^BLUE%^Priestess screams to the heavens for aid from "+
			"her goddess!%^RESET%^",
		"%^CYAN%^Priestess purrs: %^RESET%^You will die, but you will "+
			"wish you died quickly!",
		"%^CYAN%^Priestess purrs: %^RESET%^Show this iblith what we "+
			"think of it my fighters!",
		"%^CYAN%^Priestess purrs: %^RESET%^I will reward the drow "+
			"that kills this iblith tonight!\n%^BOLD%^%^BLUE%^Priestess "+
			"blows a kiss to her patrol.%^RESET%^",
		"%^BOLD%^%^BLUE%^Priestess cackles wildly as her goddess' power "+
			"flows through her.",
		"%^CYAN%^Priestess purrs: %^BOLD%^%^RED%^NOW THE END COMES "+
			"IBLITH!!%^RESET%^",
    	}),1);
    	set_emotes(0,({
    		"Priestess makes a subtle gesture and a fighter nods.",
    		"Priestess looks you over very slowly and then smiles.",
		"Priestess grins evilly.",
		"Priestess chants a prayer to her goddess.",
		"Priestess licks her lips as she caresses one of her fighters arms.",
		"Priestess winks seductively to one of her fighters.",
    	}),0);

	num = random(10);
  	switch(random(3)){
  		case 0:
			ob = new( CWEAP+"whip.c" );
			break;
    	case 1:
			ob = new( "/d/dagger/drow/temple/obj/whip.c" );
     		break;
      case 2:
			ob = new( "/d/antioch/valley/obj/chainwhip.c" );
         break;
   }
	if(num)ob->set_property("monsterweapon", 1);
  		ob->move(TO);
    	command("wield whip");

  	ob = new("/d/newbie/rooms/drow/obj/dchain");
  		ob->set_property("monsterweapon", 1);
  		ob->move(TO);
    		force_me("wearall");
      /*ob = new("/d/common/obj/potion/healing");
    		ob->move(TO);
    		ob->set_uses(random(5)+10);*/
    set_property("add kits",10);
    	set_stats("dexterity", (random(8)+13));
    	set_stats("strength",(random(6)+12));
	set_stats("wisdom",(random(5)+14));
    	set_max_hp((random(100)+100));
    	set_hp(query_max_hp());

   	set_property("swarm",1);
     	add_search_path("/cmds/priest");
      if(!random(8)){
         new("/d/shadow/juran/weaps/jet_ring")->move(TO);
         force_me("wear ring");
      }
//added chance for jet ring that has darkness charges.  Circe 1/13/04
  	set_spells(({"flame strike",
  		"cause blindness",
  		"limb attack",
  		"hold person",
  		"darkbolt"
  	}));
   	set_spell_chance(60);
 	add_money("silver",(dlevel*15));
  	add_money("gold",(dlevel*5));
  	add_money("electrum",(dlevel*10));
    	set_mob_magic_resistance("average");
      set_exp(query_hd()*25);
      set_property("full attacks",1);
    	set_speed(35);
      set_max_level(20);
    	command("speak drow");
    	command("speech purr");
	call_out("makeem",0,TO);
      FLAG = 0;
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
		force_me("say make it dead, NOW!");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		command("emote points at "+TPQCN+" casually");
		command("say kill it my pets.");
		if(TP->query_bound())return 1;
	TP->add_follower(TO);
		force_me("kill "+TP->query_name());
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
	force_me("say make it dead, NOW!");
	FLAG = 1;
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
       force_me("say do you hunt in the night as we do?");
	force_me("emote smiles an evil smile.");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote puts her back to a wall.");
	if (FLAG == 1) return;
	force_me("emote keeps her eyes on you.");
	FLAG = 1;
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote smiles at you with the hint of steel.");
	if (FLAG == 1) return;
	force_me("say you will, of course, serve us.");
	force_me("emote gives an almost imperceptible nod and her fighters "+
		"move toward you.");
	FLAG = 1;
}
void go_home(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	command("say the night has flown and so shall we.");
	tell_room(ETO,"The drow priestess slips into the shadows.");
	targ->set_invis();
	targ->move("/d/shadowgate/void");
	targ->remove();
}
void watchem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote watches you closely.");
	if (FLAG == 1) return;
	force_me("emote makes a small hand signal to her fighters and they "+
		"all watch you closely.");
	force_me("emote looks at you considering options.");
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
			command("emote winks at "+targ->query_cap_name());
			call_out("friendly",0,TP);
			return;
		}
	}
	if(mrace == "drow" ){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			call_out("killem",0,TP);
			return;
		}else{
			call_out("friendly",0,TP);
			return;
		}
	}else if(mrace == "kobold" || mrace == "goblin"|| mrace == "orc" || mrace == "minotaur" ||
		mrace == "hobgoblin" || mrace == "ogre" || mrace == "bugbear" || mrace == "yuan-ti" ||
		mrace == "gnoll" || mrace == "ogre-mage" || mrace == "half-ogre" ||
		mrace == "firbolg" || mrace == "wemic" || mrace == "human" || mrace == "troll" ||
		mrace == "half-orc" || mrace == "half-drow" || (mrace == "dwarf" && srace == "gray dwarf")){
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
void reset(){
  	::reset();
  	time = "daemon/events_d"->query_time_of_day();
  	if(time == "dawn" || time == "day") call_out("go_home",10,TO);
}
void heart_beat() {
    	object obj;
    	::heart_beat();

	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;
    	if(obj = present("corpse",ETO)){
    		tell_room(ETO,"%^BOLD%^%^BLUE%^The priestess offers the corpse "+
    			"to the Spider Queen.%^RESET%^");
     		obj->remove();
     		command("get coins");
     		command("get kit");
  	}
   	/*if(present("kit",TO) && query_hp() < query_max_hp()/2){
		command("open kit");
		command("quaff kit");
		command("offer bottle");
   	}
    	if(present("bottle",TO)) command("offer bottle");*/
     	do_check();
   	if (FLAG == 0)return;
    	timer++;
    	if(timer > 100){
      	timer = 0;
		if(query_attackers() != ({}))FLAG = 0;
    		return;
    	}
}
