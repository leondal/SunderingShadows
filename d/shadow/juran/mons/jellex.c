#include <std.h>
#include <daemons.h>
#include "../juran.h"

inherit "/d/shadow/juran/mons/wonder.c";

int FLAG,num,timer;
object ob;

void create(){
::create();
	set_name("Jellex");
	set_short("Jellex, Weaponmaster");
	set_id(({"monster","Jellex","weaponmaster","jellex","drow","weapon master"}));
	set_long(
		"The drow's glowing red eyes almost seem to burn a hole through "+
		"you.  His hair is white as new snow and his skin as black as the "+
		"abyss.  He stands an average height for a drow and he moves with "+
		"surreal and deadly grace."
	);
	set_gender("male");
	set_race("drow");
	set_hd(27,10);
	set_max_hp(200+random(150));
	set_hp(query_max_hp());
	set_alignment(9);
	set_body_type("humanoid");
	set_size(2);
    	set_stats("strength",18);
    	set_stats("dexterity",20);
    	set_stats("intelligence",19);
    	set_stats("wisdom",16);
    	set_stats("constitution",17);
    	set_stats("charisma",16);
	set_overall_ac(-4);
	set_class("ranger");
	set_mlevel("ranger",30);
	set_class("thief");
	set_mlevel("thief",27);
	set_level(27);
	set_property("full attacks",1);
	set_mob_magic_resistance("average");
   	set_property("no bows",1);
    	set_exp(1000);
    	set_emotes(0,({
		"Someone looks over your belongings and hmms.",
        	"Someone grins evilly from the shadows.",
		"Someone chuckles at your clumsiness.",
		"%^BOLD%^%^RED%^Someone says: %^RESET%^you are so very "+
			"inferior, how can you live with yourself?.",
    	}),0);
    	set_thief_skill("move silently", (95));
    	set_thief_skill("hide in shadows", (95));
    	set_scrambling(1);
	set_funcs(({"trip"}));
	set_func_chance(30);
	num = random(100);
	ob = new("/d/attaya/obj/screamer.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wield screamer");
 	num = random(100);
   	ob = new("/d/dagger/cave2/obj/blacksword.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wield serrated");
	num = random(100);
    	ob = new("/d/laerad/obj/bracers6.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear bracers");
	num = random(100);
    	ob = new("/d/deku/armours/ring_p.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->set_property("enchantment",3);
    		ob->move(TO);
    		command("wear ring");
	num = random(100);
    	ob = new("/d/islands/tonerra/obj/hide.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear woven");
	num = random(100);
    	ob = new("/d/islands/tonerra/obj/Lcloak.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear cloak");
	num = random(100);
    	ob = new("/d/dagger/cave2/obj/bloodrobe.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear robe");
	ob = new("/d/common/obj/potion/healing");
    		ob->move(TO);
    		ob->set_uses(50);
	command("speech whisper");
	command("speak drow");
    	set_scrambling(1);
    	set_speed(40);
}
void init(){
	string mrace= TP->query_race(),srace = (string)TP->query("subrace"),mname = TP->query_name();
    	::init();
	command("watch");
    	if(avatarp(TP) || mname == "slave" || !interactive(TP)) return;
	if(TP->query_invis()){
		call_out("iseeu",0,TP);
		return;
	}
      if(TP->query_property("shapeshifted")) { // should react differently to beasties in shapeshift. N, 1/14
		call_out("bullyem",0,TP);
		return;
	}

	if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		command("say good?");
		command("spit");
		call_out("killem",0,TP);
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(TP->query_unconscious()){
			if(TP->query_bound())return 1;
			command("say tsk! tsk! tsk!");
			command("say very bad place to fall asleep.");
			call_out("killem",0,TP);
			return;
		}else{
			command("emote smiles and looks you over.");
			call_out("friendly",0,TP);
			return;
		}
	}
	if(mrace == "goblin" || mrace == "orc" || mrace == "kobold" ||
		mrace == "half-orc" || mrace == "half-drow" || mrace == "hobgoblin" ||
		mrace == "ogre-mage" || mrace == "bugbear" || mrace == "troll" ||
		mrace == "gnoll"  || mrace == "human" || (mrace == "dwarf" && srace == "gray dwarf")){
		call_out("bullyem",0,TP);
		return;
	}else if(mrace == "drow"){
		call_out("friendly",0,TP);
		return;
	}else if(mrace == "ogre" || mrace == "half-ogre" || mrace == "firbolg" ||
		mrace == "wemic" || mrace == "minotaur" || mrace == "yuan-ti"){
		call_out("bossem",0,TP);
		return;
	}else if(mrace == "dwarf" || mrace == "elf" || mrace == "half-elf" ||
		mrace == "gnome" || mrace == "beastman" || mrace == "voadkyn" ||
		mrace == "halfling" || mrace == "centaur"){
		call_out("killem",2,TP);
		return;
	}else{
		command("say %^BOLD%^%^BLUE%^WHAT THE HELL ARE YOU?%^RESET%^");
		command("say well momma always said %^BOLD%^%^RED%^KILL%^RESET%^ "+
			"what you don't understand!");
		call_out("killem",2,TP);
		return;
	}
}
void killem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if(TP->query_level() > 20){
		command("say we don't like your kind here");
		force_me("stab "+targ->query_name());
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		force_me("say %^BOLD%^%^RED%^this will hurt.%^RESET%^");
		force_me("say ALOT!!");
		FLAG = 1;
	}else{
		force_me("say BAH! You're not worth my time, get lost before I "+
			"change my mind!");
	}
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
	force_me("emote nods quietly and with barely any motion.");
	FLAG = 1;
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("emote looks at you with evil intent.");
	if (FLAG == 1) return;
	force_me("say I should kill you now...");
	force_me("say but maybe you will turn out to be useful.");
	force_me("grin");
	FLAG = 1;
}
void bossem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("grin menacingly.");
	if (FLAG == 1) return;
	force_me("speak wizish");
	force_me("say do what I tell you and you live.");
	force_me("smile sweetly");
	force_me("speak drow");
	FLAG = 1;
}
void trip(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
      if((int)TP->query_stats("dexterity")>random(25)){
      	tell_object(TP,"%^BOLD%^%^WHITE%^The drow kicks out at your feet "+
      		"in an effort to trip you, but you dodge the attempt!%^RESET%^");
      	tell_room(ETP,""+TPQCN+" dodges someone's attempt to trip them up.",TP);
      }else{
      	tell_object(TP,"%^BOLD%^%^RED%^The drow sweeps your feet from "+
      		"beneath you and you fall hard knocking the wind from "+
      		"you lungs!%^RESET%^");
      	tell_room(ETP,""+TPQCN+" falls to the ground hard and lies "+
      		"there stunned!",TP);
        	TP->set_paralyzed((random(10)+5),"You are busy trying to catch your breath!");
     	}
}
void iseeu(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("speak wizish");
	force_me("say I see you punk.");
	force_me("say I would find a nice place to hide if I were you.");
	force_me("emote grins evilly and checks the edge on his dagger.");
	force_me("speak drow");
	return;
}
void heart_beat() {
    	::heart_beat();
  	
  	if(!objectp(TO)) return;
  	if (!objectp(ETO)) return;
    	if(present("kit",TO) && query_hp() < ((query_max_hp()/3)*2)){
		command("open kit");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
    	}
    	if(present("bottle",TO)) command("offer bottle");
    	timer++;
    	if(timer > 25){
     		timer = 0;
      	if(!query_invis()){
      		if(query_attackers() == ({}) ) set_invis();
      	}
   		if (FLAG == 0){
   			return;
   		}else{
   			if(query_attackers() != ({})){
   				FLAG = 0;
    				return;
   			}
        	}
   	}
}
