#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

int FLAG;
object ob;

void create() {
  	::create();
  	set_name("glenuuz");
  	set_id(({"glenuuz","prince","naga prince","naga"}));
  	set_race("naga");
  	set_gender("male");
  	set_short("%^BOLD%^%^MAGENTA%^Glenuzz, naga prince%^RESET%^");
  	set_long("%^RESET%^"+
  		"This being has the body of a huge %^GREEN%^snake %^RESET%^and the upper "+
  		"body of a man.  The naga moves very deliberately, but with a felixibility "+
  		"and fluidity that would be hard to handle in combat.  The snake "+
  		"portion of his anatomy is finely scaled and almost looks like it is "+
  		"made up of %^GREEN%^green%^RESET%^, %^YELLOW%^yellow%^RESET%^ and "+
		"%^ORANGE%^brown%^RESET%^ scales.  His human parts are well muscled and "+
		"he would be very handsome if not for the %^GREEN%^snake%^RESET%^ body, "+
		"%^YELLOW%^yellow%^RESET%^ eyes and forked tongue.\n"
        	);
 	 set_overall_ac(-4);
 	 set_mob_magic_resistance("average");
  	set_level(25);
   set_class("mage");
   set_guild_level("mage",20);
   set_mlevel("mage",20);
   set_class("ranger");
   set_mlevel("ranger",25);
   set_property("full attacks",1);
  	set_body_type("human");
  	set("aggressive",18);
  	set_alignment(9);
  	set_stats("strength",19);
  	set_stats("charisma", 16);
  	set_stats("dexterity",18);
  	set_stats("constitution",16);
  	set_stats("wisdom",15);
  	set_stats("intelligence",16);
  	set_hp(150);
  	set_exp(5000);
  	set_size(2);
	  remove_limb("right leg");
	  remove_limb("left leg");
	  add_limb("tail","tail",0,0,0);
	  set_attack_limbs(({
		"right hand",
		"left hand",
		"tail",
		}));
	 set_attacks_num(6);
	 set_damage(3,4);
  add_money("silver",random(1500)+50);
  add_money("gold",random(1000)+50);
  add_money("platinum",random(250)+50);
  add_search_path("/cmds/mage");
  add_search_path("/cmds/ranger");
  if(!random(2)){
  		ob = new("/d/deku/armours/ring_p");
  		ob->move(TO);
  		ob->set_property("enchantment",1);
  		command("wear ring");
  }
  if(!random(5)){
   	ob=new("/d/magic/scroll");
    ob->set_spell(3 + random(3));
   	ob->move(TO);
  }
    	set_emotes(3,({
		"%^MAGENTA%^Glenuuz hisses: %^RESET%^If I were you I would run away!",
		"%^MAGENTA%^Glenuuz hisses: %^RESET%^Don't worry, my venom works fast.",
		"%^MAGENTA%^Glenuuz screams: %^BOLD%^%^YELLOW%^YOU'RE MINE!!%^RESET%^",
		"%^MAGENTA%^Glenuuz hisses: %^RESET%^You seek the abyss do you?\n"+
			"%^BOLD%^%^MAGENTA%^Glenuuz licks his lips hungrily.%^RESET%^",
 		"%^MAGENTA%^Glenuuz hisses: %^RESET%^Your body will never be found.",
		"%^BOLD%^%^MAGENTA%^Glenuuz hisses.",
		"%^MAGENTA%^Glenuuz hisses: %^RESET%^Welcome to my home!",
		"%^BOLD%^%^MAGENTA%^Glenuuz twitched his tail menacingly.%^RESET%^",
		"%^BOLD%^%^MAGENTA%^Glenuuz growls menacingly.%^RESET%^",
		"%^BOLD%^%^MAGENTA%^Glenuuz smiles wickedly displaying very "+
			"sharp teeth!%^RESET%^",
		"%^MAGENTA%^Glenuuz hisses: %^RESET%^Are you lost mammal?",
		"%^BOLD%^%^MAGENTA%^Glenuuz slithers slowly about the room.%^RESET%^",
		"%^BOLD%^%^MAGENTA%^Glenuuz narrows his %^YELLOW%^yellow "+
			"%^GREEN%^reptilian %^MAGENTA%^eyes at you.%^RESET%^",
    	}),0);
    	FLAG = 0;
  	set_funcs(({"spit"}));
  	set_func_chance(30);
  	set_spell_chance(50);
  	set_spells( ({
  		"magic missile",
  		"chill touch",
  		"fireball",
  		"ice storm"
  		"sleep"
  	}));
}

void init(){
    	::init();
    	if(TP->query_true_invis()) return;
    	call_out("coverass", 2, TP);
}

void coverass(object targ){
	force_me("kill "+targ->query_name());
	if (FLAG == 1) return;
	new("/cmds/spells/d/_dispel_magic")->use_spell(TO,TP,25,10,"mage");
	// command("block west");
	FLAG = 1;
}

void spit(object targ){
	int dex;
	dex = targ->query_stats("dexterity");
	if(random(20) < dex) {
		tell_object(targ,"%^BOLD%^%^MAGENTA%^The naga spits venom into your eyes!");
		tell_room(ETO,"%^BOLD%^%^MAGENTA%^The naga spits at "+targ->query_cap_name()+""+
			" landing the venom in "+targ->query_cap_name()+"'s eyes.",targ);
		targ->force_me("emote %^BOLD%^%^RED%^screams in pain as the venom "+
			"does its work!%^RESET%^");
		targ->set_temporary_blinded(4 + random(5),"%^BOLD%^%^GREEN%^The venom has blinded you!"+
			"%^RESET%^");
	}
	else {
		tell_object(targ,"%^BOLD%^%^RED%^The naga spits venom at you, but you"+
		" manage to dodge out of the way in the nick of time.");
		tell_room(ETO,"The naga spits venom at "+targ->query_cap_name()+", but "+
		" "+targ->query_subjective()+" manages to dodge out of the way.",targ);
	}
}
void heart_beat() {
    	::heart_beat();

    	if(!objectp(TO)) return;
    	if(!objectp(ETP)) return;
    	if(present("corpse",environment(this_object()))){
      	if(!query_current_attacker() ) {
        	command("get all from corpse");
        	command("emote %^BOLD%^%^MAGENTA%^smiles with satisfaction.%^RESET%^");
        	tell_room(ETP,"%^BOLD%^%^MAGENTA%^Glenuuz decides to clean his lair up a "+
				"bit!%^RESET%^",ETO);
        command("offerall");
        command("get all");
       }
     }
     if(present("kit",TO) && query_hp() < query_max_hp()/2){
	      command("combine kit with kit");
       command("open kit");
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
   	if(query_attackers() != ({}))FLAG = 0;
	return;
}