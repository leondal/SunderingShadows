//tree.c

#include <std.h>

inherit WEAPONLESS;

void make_me();
void set_caller(object ob);

object caller;

void create(){
	::create();
	
	set_name("tree");
	set_id(({"tree"}));
	set("short","An old tree");
	set("long",
@OLI
	This is a grand old oak tree. forced to up root itself by the call
of a treant to protect the forest. Fierce in a fight this tree shows the 
signs of having been in a few.
OLI
	);
	set_overall_ac(0);
	set_race("tree");
	add_limb("trunk","trunk",0,0,0);
	add_limb("right limb","trunk",0,0,0);
	add_limb("foliage","trunk",0,0,0);
	add_limb("root","trunk",0,0,0);
	add_limb("left limb","trunk",0,0,0);
	make_me();
	set_attack_limbs(({"right limb","left limb"}));
	set_attacks_num(2);
	}
	
void make_me(){
	int i;
	i = random(5);
	set_hd(i+10,8);
	set_exp(2000 + 1000*i);
	set_hp(query_hd()*8);
	switch (query_hd()){
		case 10:
		case 11:
			set_damage(2,8);
			break;
		case 12:
		case 13:
			set_damage(3,6);
			break;
		case 14:
		case 15:
			set_damage(4,6);
			break;
		default:
			set_damage(2,8);
	}
}

void heart_beat(){
	if((object *)caller->query_attackers() == ({})){
		caller->remove_summoned(TO);
		caller->set_func_chance(80);
		tell_room(ETO,"%^BOLD%^%^GREEN%^The battle over the tree reroots and returns to peace!");
		TO->remove();
	}
	if(!objectp(TO)) return;
	::heart_beat();
}

void set_caller(object ob){
	caller = ob;
	}
