#include <std.h>
inherit WEAPONLESS;

int flag;

void create(){
	object obj;

	::create();
	set_name("gargoyle");
	set_short("a gargoyle");
	set_id(({"gargoyle"}));
	set_long(
		"This creature is a grotesque caricture of a large dog-like beast "+
		"with horns and a barbed tail.  Winged and with exaggerated "+
		"features, this stone creature looks just like the sculptures "+
		"you have seen sitting idly as waterspouts on the roofs of castles.  "+
		"This being's teeth, claws, and horns look like they could do much damage."
	);
	set_gender("neuter");
	set_race("gargoyle");
	set_body_type("quadraped");
	set_hd(20,10);
	set_max_hp(300 + random(100));
	set_hp(query_max_hp());
	set_alignment(9);
	set_overall_ac(-8);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_level(20);
	set_property("full attacks",1);
	set_max_level(20);
	set_exp(8500);
	set_stats("strength",19);
	set_stats("intelligence",6);
	set_stats("wisdom",7);
	set_stats("dexterity",12 + random(7));
	set_stats("constitution",18);
	set_stats("charisma",random(5));
	set_property("swarm",1);
	set("aggressive",25);
	set_mob_magic_resistance("average");
	set_property("weapon resistance",2);
	remove_limb("right hand");
	remove_limb("left hand");
	add_limb("right claw","right foreleg",0,0,0);
	add_limb("left claw","left foreleg",0,0,0);
	add_limb("teeth","mouth",0,0,0);
	add_limb("horns","head",0,0,0);
	set_attack_limbs(({"right claw","left claw","teeth","horns"}));
	set_attacks_num(4);
	set_damage(3,8);
	set_base_damage_type("slashing");
	set_funcs(({"whip"}));
    	set_func_chance(20);
    	flag = 0;
}
void init(){
	string mrace = TP->query_race();
	::init();
	force_me("watch");
	if(avatarp(TP) || mrace == "gargoyle" || mrace == "golem") return;
	TO->force_me("kill "+TP->query_name()+"");
	if(!(flag == 1)){
		flag = 1;
		tell_room(ETO,"%^RED%^The gargoyle giggles malifically and then attacks!");
	}
}
void whip(object targ){
	int dex,para;
	dex = targ->query_stats("dexterity");
	if(!random(20) > dex) {
		tell_object(targ,"%^RED%^The gargoyle whips it's barbed tail "+
			"at you striking you painfully!%^RESET%^");
		tell_room(ETO,"%^RED%^The gargoyle strikes with it's tail "+
			"at "+targ->query_cap_name()+" slashing "+targ->query_possessive()+""+
			"with it's  barbs painfully.%^RESET%^",targ);
		targ->do_damage("torso", roll_dice(1,10));
		targ->add_attacker(TO);
		targ->continue_attack();
	}else {
		tell_object(targ,"%^CYAN%^The gargoyle's tail lashes out and "+
			"entangles your limbs.");
		tell_room(ETO,"%^CYAN%^The gargoyle's tail lashes out and "+
			"entangles "+targ->query_cap_name()+"'s limbs.",targ);
		para = random(8) + 3;
	     	targ->set_paralyzed(para,"%^CYAN%^You are entangled in the gargoyles tail!");
	}
}
void heart_beat(){
  	object atkr;

  	if(!objectp(TO)) return;
  	::heart_beat();
  	atkr = query_current_attacker();
  	if(!atkr) {
    		flag = 0;
    		return;
  	}
}