//Hmm - this thing was using weapons and is WEAPONLESS?? - I'll change it to be straight 
//weaponless
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

int FLAG,stuff;
object ob;

void create() {
  	::create();
  	set_name("naga fighter");
  	set_id(({"naga"}));
  	set_race("naga");
   set_gender(random(2)?"male":"female");
  	set_short("%^BOLD%^%^GREEN%^Naga fighter%^RESET%^");
  	set_long("%^RESET%^"+
  		"This being has the body of a huge %^GREEN%^snake %^RESET%^and the upper "+
  		"body of a human.  The naga moves very deliberately, but with a felixibility "+
  		"and fluidity that would be hard to handle in combat.  The snake "+
  		"portion of it's anatomy is finely scaled and almost looks like it is "+
  		"made up of %^GREEN%^green%^RESET%^, %^YELLOW%^yellow%^RESET%^ and "+
		"%^ORANGE%^brown%^RESET%^ scales.  The human parts are well muscled and "+
		"it would be very comely if not for the %^GREEN%^snake%^RESET%^ body, "+
		"%^YELLOW%^yellow%^RESET%^ eyes and forked tongue.\n"
  );
  set_overall_ac(-4);
	 set_mob_magic_resistance("average");
  set_level(25);
  set_class("ranger");
  set_mlevel("ranger",20);
		set_guild_level("ranger",20);
  set_property("full attacks",1);
  set_body_type("human");
  set("aggressive",18);
  set_alignment(9);
  set_hd(25,1);
  set_stats("strength",19);
  set_stats("charisma", 17);
  set_stats("dexterity",18);
  set_stats("constitution",18);
  set_stats("wisdom",13);
  set_stats("intelligence",12);
  set_hp(200);
  set_exp(3000);
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
	 set_damage(2,4);
  add_money("silver",random(1500)+50);
  add_money("gold",random(500)+50);
  add_money("platinum",random(100)+50);
  add_search_path("/cmds/ranger");
  if(!random(2)){
  		stuff = (random(4)+1);
  		ob = new(("/d/laerad/obj/bracers"+stuff));
  		ob->move(TO);
   	command("wear bracers");
   }
  set_emotes(3,({
		"%^MAGENTA%^Naga hisses: %^RESET%^Run away, run away FAST!",
		"%^MAGENTA%^Naga hisses: %^RESET%^I see you like my venom.",
		"%^MAGENTA%^Naga screams: %^BOLD%^%^YELLOW%^YOU'RE MINE!!%^RESET%^",
 		"%^MAGENTA%^Naga hisses: %^RESET%^Your body will never be found.",
		"%^BOLD%^%^MAGENTA%^Naga hisses.",
		"%^MAGENTA%^Naga hisses: %^RESET%^YOU ARE NOT WELCOME!",
		"%^BOLD%^%^MAGENTA%^Naga twitches it's tail menacingly.%^RESET%^",
		"%^BOLD%^%^MAGENTA%^Naga growls menacingly.%^RESET%^",
		"%^BOLD%^%^MAGENTA%^Naga smiles wickedly displaying very "+
			"sharp teeth!%^RESET%^",
		"%^MAGENTA%^Naga hisses: %^RESET%^Are you lost mammal?",
		"%^BOLD%^%^MAGENTA%^Naga slithers slowly about the room.%^RESET%^",
		"%^BOLD%^%^MAGENTA%^Naga narrows his %^YELLOW%^yellow "+
			"%^GREEN%^reptilian %^MAGENTA%^eyes at you.%^RESET%^",
    	}),0);
  FLAG = 0;
  set_funcs(({"spit"}));
  set_func_chance(30);
}
void init(){
    	::init();
    	if(TP->query_true_invis()) return;
    	call_out("coverass", 2, TP);
}

void coverass(object targ){
	force_me("kill "+targ->query_name());
	if (FLAG == 1) return;
	new("/cmds/spells/d/_dispel_magic")->use_spell(TO,TP,20,10,"cleric");
	command("block northeast");
	FLAG = 1;
}

void spit(object targ){
	int dex;
	dex = targ->query_stats("dexterity");
	if(random(20) < dex) {
		tell_object(targ,"%^BOLD%^%^MAGENTA%^The naga spits venom into your eyes!");
		tell_room(ETO,"%^BOLD%^%^MAGENTA%^The naga spits at "+targ->QCN+""+
			" landing the venom in "+targ->QCN+"'s eyes.",targ);
		targ->force_me("emote %^BOLD%^%^RED%^screams in pain as the venom "+
			"does its work!%^RESET%^");
		targ->set_temporary_blinded(4 + random(5),"%^BOLD%^%^GREEN%^The venom has blinded you!"+
			"%^RESET%^");
	}
	else {
		tell_object(targ,"%^BOLD%^%^RED%^The naga spits venom at you, but you"+
		" manage to dodge out of the way in the nick of time.");
		tell_room(ETO,"The naga spits venom at "+targ->query_cap_name()+", but "+
		" "+targ->QS+" manages to dodge out of the way.",targ);
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
    	tell_room(ETP,"%^BOLD%^%^MAGENTA%^Naga decides to clean it's lair up a "+
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