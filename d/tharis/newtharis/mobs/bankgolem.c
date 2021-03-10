#include <std.h>
#include "../tharis.h"
inherit "/std/trainer";

// Based on /d/avatars/nienne/golem.c
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Bank Remodle - Created in February 2009 by Ari

void create(){
	::create();
	set_name("stone golem");
	set_id(({"golem","stone golem","bankgolem"}));
	set_short("A large stone golem");
	
	set_long("%^BOLD%^%^WHITE%^This large marble golem has been "+
		"carefully carved in order to make it look very human in "+
		"appearance.  Though its white skin has the opaque luster "+
		"of the stone it is created from, it has been dressed in "+
		"expensively tailored garments so that only the neck, face "+
		"and hands can be seen.  The face is carved into a passive "+
		"watchful demenor, while the fingers show every crease and "+
		"ridge of a proper hand. More then one person has mistaken "+
		"this tall creature for a member of the stone giant race."+
		"%^RESET%^");
	
	set_alignment(5);
	set_race("golem");
	set_gender("neuter");
	set_body_type("humanoid");
	set_hd(30,12);
	set_stats("strength",20);
	set_stats("constitution",20);
	set_stats("dexterity",6);
	set_max_hp(1000);
	set_hp(1000);
	set_overall_ac(-16);
	set_exp(0);
	set_attacks_num(2);
	set_damage(2,6);
	set_size(3);
	set_weight(10000);
	set_property("swarm",1);
	set_property("magic resistance",25);
	set_property("no steal",1);
	set_property("knock unconscious",1);
	
	set_funcs(({"smash_them","maul_them"}));
	set_func_chance(20);
	
	TO->force_me("pose standing beside the great vault door");
}

int maul_them(object target){
	tell_object(target,"%^BOLD%^%^WHITE%^The stone golem brings both of "+
		"it's large fists together and smashes them into your tender "+
		"body!");
	tell_room(ETO,"%^BOLD%^%^WHITE%^"+target->QCN+" screams as the "+
		"golem's twin fists make contact!%^RESET%^",target);
		target->do_damage("torso",random(15)+30);
	return 1;
}

int smash_them(object target){
	tell_object(target,"%^BOLD%^%^BLACK%^Blinding pain stuns you as "+
		"the golem brings his huge fist down on the top of your "+
		"head!%^RESET%^");
	tell_room(ETO,"%^BOLD%^%^BLACK%^The stone golem brings its large "+
		"fist down on "+target->QCN+"'s head!%^RESET%^",target);
		target->set_paralyzed(15,"%^BOLD%^%^BLACK%^You're stunned "+
			"from the blow to the head!%^RESET%^");
	return 1;
}
