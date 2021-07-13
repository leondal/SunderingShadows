#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit "/d/shadow/juran/mons/wonder.c";

int xx,dlevel,FLAG,timer;

void do_check();

create() {
    	object ob;
    	::create();
    	set_name("goblin mage");
    	set_id(({"monster","goblin","mage","goblin mage"}));
    	set_short("goblin mage");
    	set_long("The Goblin before you is what passes for a mage of the goblin race. "+
    		"He practices the black arts and is feared by all "+
    		"the goblins including the boss himself.");
    	set_body_type("humanoid");
    	dlevel = random(6) + 9;
    	set_hd(dlevel, 4);
    	set_level(dlevel);
    	set_class("mage");
    	set_guild_level("mage",dlevel);
    	set_mlevel("mage",dlevel);
    	set_class("fighter");
    	set_mlevel("fighter",dlevel);
    	set_alignment(9);
    	set_race("goblin");
    	set_gender("male");
    	set_ac(2);
   	set_size(1);
   	set_stats("strength",16);
    	set_stats("dexterity",17);
    	set_stats("wisdom",18);
    	set_stats("intelligence",18);
    	set_exp(dlevel*25);
    	set_max_hp((random(100)+(dlevel*6)));
    	set_hp(query_max_hp());
    	set_achats(0,({
		"%^CYAN%^Mage squeaks: %^RESET%^No trifle wit me!",
		"%^CYAN%^Mage squeaks: %^RESET%^Me burn you agin soon.",
		"%^CYAN%^Mage yells: %^BOLD%^%^RED%^GET GONE!!",
		"%^CYAN%^Mage whines: %^RESET%^ACK! WHY YOU STILL BE HERE?!?!",
 		"%^CYAN%^Mage giggles: %^RESET%^It hurts don't it?!?!",
   	}),0);
    	set_emotes(0,({
		"Mage mutters an incantation.",
		"Mage traces arcane runes in the air.",
		"Mage chuckles to himself.",
		"Mage raises an eyebrow.",
		"Mage burps in the middle of an incantation ruining the spell.",
    	}),0);
    	add_money("gold",random(50));
    	add_money("silver",random(100));
    	add_money("copper",random(600));
    	set_spell_chance(50);
    	set_func_chance(35);
    	set_spells( ({"magic missile","scorcher","chill touch","darkness"}));
    	set_funcs(({"special_spell"}));
	new("/d/azha/obj/mr_ring")->move(TO);
    		command("wear ring");
     	ob = new( CARM+"robe.c" );
    		ob->set_property("monsterweapon", 1);
     		ob->move(TO);
   		command("wear robe");
    	add_search_path("/cmds/fighter");
    	add_search_path("/cmds/mage");
    	set_max_level(8);
    	set_property("swarm",1);
    	set_property("full attacks",1);
    	command("speak goblin");
    	command("speech squeak");
    	set_max_level(15);
	set_property("knock unconscious");
}
int special_spell() {
	object me = TO;
	object vic = me->query_current_attacker();
    	xx=random(5)+1;
    	switch(xx) {
    		case 1:
			if(me->query_hp() < 10) {
	    			me->add_hp(random(5)+3);
	    			tell_room(ETO,"%^MAGENTA%^Sorceror's robe glows with "+
	    				"an inner light.");
	    		return 1;
  			}
        		me->force_me("cackle");
        		me->force_me("cast color spray at "+vic->query_name());
        		return 1;
    		case 2:
			if(me->query_hp() < 10) {
	    			me->add_hp(random(5)+3);
	    			tell_room(ETO,"%^MAGENTA%^Sorceror's robe glows "+
	    				"with an inner light.");
	    			return 1;
  			}
        		me->force_me("grin");
        		me->force_me("cast lightning bolt at "+vic->query_name());
        		return 1;
    		case 3:
			if(me->query_hp() < 10) {
	    			me->add_hp(random(5)+3);
	    			tell_room(ETO,"%^MAGENTA%^Sorceror's robe glows "+
	    				"with an inner light.");
	    			return 1;
  			}
        		me->force_me("howl");
        		tell_object(vic,"%^BOLD%^%^RED%^Sorceror hurls a bolt of pure "+
        			"evil at you!");
        		tell_room(ETO,"%^BOLD%^%^RED%^Sorceror hurls a bolt of pure "+
        			"evil at "+vic->query_cap_name()+"!",vic);
        		vic->do_damage("torso",random(20)+3);
        		return 1;
    		case 4:
			if(me->query_hp() < 10) {
	    			me->add_hp(random(5)+3);
	    			tell_room(ETO,"%^MAGENTA%^Sorceror's robe glows with "+
	    				"an inner light.");
	    			return 1;
  			}
        		me->force_me("scream");
        		me->force_me("cast fireball at "+vic->query_name());
        		return 1;
    		case 5:
       		tell_room(ETO,"%^MAGENTA%^Sorceror's robe glows with an inner light.");
       		me->add_hp(5);
       	return 1;
    	}
}
void init(){
	string mrace= TP->query_race(),srace = (string)TP->query("subrace"),mname = TP->query_name();
    	::init();
    	if(avatarp(TP) || TP->query_invis() || mname == "slave" || !interactive(TP)) return;
    	if(is_surfacerace(TP)){
		if(TP->query_bound())return 1;
		force_me("kill "+TP->query_name());
		if (FLAG == 1) return;
		if(!random(3))force_me("say %^BOLD%^%^RED%^you make good meals "+
			"me tinkin'!!%^RESET%^");
		FLAG = 1;
		return;
	}else if(member_array(mname,KILLING_D->query_good_bounties()) !=-1){
		force_me("kill "+TP->query_name());
		if (FLAG == 1) return;
		if(!random(3))force_me("say %^BOLD%^%^RED%^you make good meals "+
			"me tinkin'!!%^RESET%^");
		FLAG = 1;
		return;
	}
	call_out("race_ck",0,TP);
}
void friendly(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	force_me("look "+targ->query_name());
	if (FLAG == 1) return;
	if(!random(3))force_me("emote grins a big toothy grin");
	FLAG = 1;
}
void fearem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("quiver");
	FLAG = 1;
}
void bullyem(object targ){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(targ)) return 1;
	if (FLAG == 1) return;
	if(!random(3))force_me("emote pokes at you threateningly.");
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
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		if(!random(3))force_me("say %^BOLD%^%^RED%^you make good meals "+
			"me tinkin'!!%^RESET%^");
		FLAG = 1;
		return;
	}
	if(member_array(mname,KILLING_D->query_evil_bounties()) !=-1){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			if(!random(3))force_me("say %^BOLD%^%^RED%^you make good meals "+
				"me tinkin'!!%^RESET%^");
			FLAG = 1;
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}
	if(mrace == "goblin"|| mrace == "orc" || mrace == "hobgoblin"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			if(!random(3))force_me("say %^BOLD%^%^RED%^you make good meals "+
				"me tinkin'!!%^RESET%^");
			FLAG = 1;
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
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			if(!random(3))force_me("say %^BOLD%^%^RED%^you make good meals "+
				"me tinkin'!!%^RESET%^");
			FLAG = 1;
			return;
		}else{
			call_out("fearem",0,TP);
			return;
		}
	}else if(mrace == "kobold" || mrace == "half-orc" ||
		mrace == "half-drow"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			if(!random(3))force_me("say %^BOLD%^%^RED%^you make good meals "+
				"me tinkin'!!%^RESET%^");
			FLAG = 1;
			return;
		}else{
			call_out("bullyem",0,TP);
			return;
		}
	}else if(mrace == "dwarf" || mrace == "elf" || mrace == "half-elf" ||
		mrace == "gnome" || mrace == "beastman" || mrace == "voadkyn" ||
		mrace == "halfling" || mrace == "centaur"){
		if(targ->query_bound())return 1;
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		if(!random(3))force_me("say %^BOLD%^%^RED%^you make good meals "+
			"me tinkin'!!%^RESET%^");
		FLAG = 1;
		return;
	}else if(mrace == "wemic" || mrace == "human" || mrace == "yuan-ti"){
		if(targ->query_unconscious()){
			if(targ->query_bound())return 1;
			force_me("kill "+targ->query_name());
			if (FLAG == 1) return;
			if(!random(3))force_me("say %^BOLD%^%^RED%^you make good meals "+
				"me tinkin'!!%^RESET%^");
			FLAG = 1;
			return;
		}else{
			call_out("watchem",0,TP);
			return;
		}
	}else{
		if(targ->query_bound())return 1;
		tell_room(TO,"WHAT THE HELL ARE YOU?");
		force_me("kill "+targ->query_name());
		if (FLAG == 1) return;
		if(!random(3))force_me("say %^BOLD%^%^RED%^you make good meals "+
			"me tinkin'!!%^RESET%^");
		FLAG = 1;
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
	    	call_out("race_ck",0,TP);
	}
	return 1;
}
void heart_beat() {
    	::heart_beat();

	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;
     	do_check();
   	if (FLAG == 0)return;
    	timer++;
    	if(timer > 200){
      	timer = 0;
		if(query_attackers() != ({}))FLAG = 0;
    		return;
    	}
}
