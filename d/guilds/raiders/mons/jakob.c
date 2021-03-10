#include <std.h>
#include <daemons.h>
inherit MONSTER;
object ob;
int FLAG;

void create(){
   	::create();
    	set_name("jakob");
    	set_short("Jakob");
    	set_id( ({"jakob","guard", "thief", "fighter"}) );
    	set_long(
      	"This is one of the ugliest looking creatures you have ever seen in "+
      	"your entire life.  Part orc, part human, he seems to have gotten the "+
      	"worst of both worlds. The hair on his head is patchy and his beard is "+
      	"all scraggly as if he can hardly grow one.  The enlarged lower teeth "+
      	"prevent his mouth from closing properly and his upturned nose makes "+
      	"him resemble a pig.  Regardless of his lack of attractiveness, however, "+
      	"you realize that this half-orc would be quite adept at fighting.  His "+
      	"physical prowess is self-evident.  On top of all that, he doesn't look "+
      	"like a very nice person either."
    	);
    	set_body_type("human");
    	set_race("half-orc");
    	set_overall_ac(5);
    	set_hd(32, 1);
    	set_class("thief");
    	set_mlevel("thief", 32);
    	set_class("fighter");
    	set_mlevel("fighter", 27);
    	set_property("no dominate",1);
      set_property("no animate",1);
      set_mob_magic_resistance("average");
      set_property("swarm",1);
    	add_search_path("/cmds/thief");
    	add_search_path("/cmds/fighter");
    	set_scrambling(1);
    	set_gender("male");
      set_property("full attacks",1);
      set_wielding_limbs(({"right hand","left hand"}));

    	ob = new("/d/attaya/obj/screamer.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    	ob = new("/d/dagger/cave2/obj/blacksword.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
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
    	ob = new("/d/islands/tonerra/obj/Lcloak");
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
    		ob->move(TO);
    		ob->set_uses(50);
    	command("put screamer in sheath");
    	command("wearall");
    	ob = new("/d/guilds/raiders/obj/earguard.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);

    	command("remove band");
    	command("wield screamer");
    	command("wield serrated");
    	set_stats("dexterity", 18);
    	set_stats("strength",18);
    	set_stats("intelligence",10);
    	set_stats("wisdom",9);
    	set_stats("charisma",7);
    	set_stats("constitution",17);
    	set_thief_skill("move silently", 95);
    	set_thief_skill("hide in shadows", 95);
    	set_invis();
    	set_max_hp(350);
    	set_hp(query_max_hp());
    	set_exp(10000);
     	set_property("swarm",1);
    	set_funcs(({"powder_em"}));
    	set_func_chance(20);
  	set_achats(20, ({
  		"%^BOLD%^%^RED%^Someone whispers: %^RESET%^What's holding dis one up?",
  		"%^BOLD%^%^RED%^Someone whispers: %^RESET%^Me help Tavares...you die!",
  		"%^BOLD%^%^RED%^Someone growls: %^RESET%^Sucks to be you eh?",
  		"%^BOLD%^%^RED%^Someone moves behind you!",
  		"%^BOLD%^%^RED%^Someone nicks you with his dagger and laughs tauntingly.",
  		"%^BOLD%^%^RED%^Someone comes at you like a raging bull."
  	}) );
}
void init(){
::init();
	add_action("pick_em","pick");
	command("watch");
    	if (TP->query_invisible() || avatarp(TP) || TP->in_guild("The Raiders in Night's Cloak") || present("raidear",TP)) return;
      if (TP->is_undetectable()) return;
       if (TP->query_bound()) {
        force_me("snicker");
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
	force_me("block north");
	force_me("rush "+targ->query_name());
	force_me("kill "+targ->query_name());
	if(FLAG == 1) return;
    	command("say %^BOLD%^%^RED%^Jakob help you!!%^RESET%^");
	command("emote grins fiercely");
	command("parry");
	FLAG = 1;
}
int pick_em(string str) {
	if(str == "lock on iron door"){
		if (TP->query_invisible() || avatarp(TP) || TP->in_guild("The Raiders in Night's Cloak") || present("raidear",TP)){
			command("say whatsa matter...loose yer key?");
			command("emote winks");
			return 0;
		}
		command("say you is more den stoopid!?!?");
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
	command("emote points behind you and looks surprised.");
	command("emote smiles with an evil glint in his eyes.");
	command("say gullible.");
	if(present("bag",TO))command("toss powder at "+targ->query_name());
}
