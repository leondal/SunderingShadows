#include <std.h>
#include <daemons.h>
inherit MONSTER;

int FLAG;
object ob;

void create(){
::create();
    	set_name("tavares");
    	set_short("Tavares");
    	set_id( ({"tavares","guard", "thief", "fighter"}) );
    	set_long(
      	"This is obviously a half-orc, but the only reason you can tell "+
      	"is the slightly enlarged lower teeth that characterize the mixing "+
      	"of orc and human.  Although his nose is slightly upturned, it is "+
      	"not so much that he could not pass for human, except for the "+
      	"teeth.  His head is shaved leaving it round and bald.  His frame is "+
      	"tight and compact and it is obvious that he works very hard to keep "+
      	"his body in the best shape.  He regards most things around him with "+
      	"a cool confidence that can only come of experience.\n"
    	);
	set_gender("male");
	set_race("half-orc");
	set_hd(32,1);
    	set_max_hp(350);
    	set_hp(query_max_hp());
    	set_exp(10000);
	set_alignment(9);
	set_body_type("humanoid");
	set_size(2);
	set_overall_ac(5);
    	set_class("thief");
    	set_mlevel("thief", 32);
    	set_class("fighter");
    	set_mlevel("fighter", 27);
    	add_search_path("/cmds/thief");
    	add_search_path("/cmds/fighter");
	set_level(32);
	set_property("full attacks",1);
	set_property("swarm",1);
	set_mob_magic_resistance("average");
    	set_property("no dominate",1);
      set_property("no animate",1);
	set_property("no paralyze",1);
   	set_property("no bows",1);
    	set_scrambling(1);
      set_wielding_limbs(({"right hand","left hand"}));
	command("speech whisper");
	ob = new("/d/attaya/obj/screamer.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	command("wield screamer");
    	ob = new("/d/dagger/cave2/obj/blacksword.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	command("wield serrated");
    	ob = new("/d/laerad/obj/bracers6.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	ob = new("/d/tharis/obj/wrist_sheath.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	ob = new("/d/attaya/obj/screamer.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	ob = new("/d/islands/tonerra/obj/hide.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	ob = new("/d/islands/tonerra/obj/Lcloak.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	ob = new("/d/dagger/cave2/obj/bloodrobe.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	ob = new("/d/deku/armours/ring_p.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	ob = new("/d/tharis/obj/bpowder.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	ob = new("/d/azha/obj/gmr_ring.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
	ob = new("/d/common/obj/potion/healing");
    		ob->set_uses(50);
    		ob->move(TO);
    	command("put screamer in sheath");
    	ob = new("/d/guilds/raiders/obj/earguard.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	command("wearall");
    	command("remove band");
    	set_stats("dexterity", 19);
    	set_stats("strength",18);
    	set_stats("intelligence",14);
    	set_stats("wisdom",10);
    	set_stats("charisma",9);
    	set_stats("constitution",17);
    	set_thief_skill("move silently", 95);
    	set_thief_skill("hide in shadows", 95);
    	FLAG = 0;
    	set_funcs(({"powder_em"}));
    	set_func_chance(20);
    	set_emotes(3,({
		"Tavares casually scratches himself.",
		"Tavares leans against the wall.",
		"Tavares stretches nonchalantly.",
		"Tavares watches the room for any movement.",
		"Tavares checks the door to make sure it is locked.",
		"Tavares scrathes his stubbly chin.",
		"Tavares idly, but agilely, flips his dagger catching it by "+
			"the handle without even looking.",
		"Tavares closes his eyes, but still seems alert for anything.",
		"Tavares yawns."
    	}),0);
  	set_achats(20, ({
  		"%^BOLD%^%^RED%^Tavares whispers: %^RESET%^Ya know we can't letcha "+
  			"leave alive don't ya?",
  		"%^BOLD%^%^RED%^Tavares whispers: %^RESET%^Nothing personal, it's "+
  			"jus' our job.",
  		"%^BOLD%^%^RED%^Tavares growls: %^RESET%^Ya a fool ta come here!",
  		"%^BOLD%^%^RED%^Tavares dodges your attacks and lunges at your throat!",
  		"%^BOLD%^%^RED%^Tavares kicks you in the stomach and laughs.",
  		"%^BOLD%^%^RED%^Tavares whirls around in a dizzying dance of death "+
  			"with his daggers."
  	}) );
   set_no_clean(1);
}
void init(){
::init();
	add_action("pick_em","pick");
	command("watch");
//	command("get all");
// I think this could be horridly abusable, so I've commented it out.
// The set_no_clean should fix him up just fine.
    	if (TP->query_invisible() || avatarp(TP) || TP->in_guild("The Raiders in Night's Cloak") || present("raidear",TP)) return;
      if (TP->is_undetectable()) return;
     if (TP->query_bound()) {
      command("say Looks like someone's already... handled you.");
       return;
     }
	command("wear band");
	force_me("stab "+TP->query_name());
	call_out("kill_em", 0, TP);
}
void kill_em(object targ){
	force_me("kill "+targ->query_name());
	call_out("hurt_em", 0, TP);
}
void hurt_em(object targ){
	force_me("block south");
	force_me("rush "+targ->query_name());
	force_me("kill "+targ->query_name());
	if(!present("jakob", ETO)){
      	ob = new("/d/guilds/raiders/mons/jakob");
      	ob->move(ETO);
	}
	if(FLAG == 1) return;
    	command("say %^BOLD%^%^RED%^You not allowed here.  I must "+
		"kill you now!!%^RESET%^");
	command("emote smiles calmly");
	command("parry");
	FLAG = 1;
}
int pick_em(string str) {
  	if(str == "lock on iron door"){
  		if (TP->query_invisible() || avatarp(TP) || TP->in_guild("The Raiders in Night's Cloak") || present("raidear",TP)){
			command("emote snickers.");
			command("say hurry up..this is embarassing.");
			return 0;
		}
		command("say You must think me blind!");
    		call_out("hurt_em", 2, TP);
      }
      return 0;
}
void heart_beat(){
    	::heart_beat();
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
 	if (FLAG == 0)return;
   	if(query_attackers() != ({})){
   		FLAG = 0;
   		command("remove band");
   	}
	return;
}
void powder_em(object targ){
	command("emote chuckles as if at a private joke.");
	command("say this will sting a bit.");
	if(present("bag",TO))command("toss powder at "+targ->query_name());
}
