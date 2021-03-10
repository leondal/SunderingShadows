#include <std.h>
#include "../defs.h"
#include <daemons.h>
inherit WEAPONLESS;

// Coral Sea Area - Created January 2009 by Ari

create(){
	::create();
		set_name("electric eel");
		set_id(({"eel","monster","electric eel","Cyrserox",
			"cyrserox","guardian"}));
		set_short("%^YELLOW%^C%^RESET%^%^ORANGE%^y%^BLACK%^"+
			"%^BOLD%^r%^RESET%^%^ORANGE%^s%^YELLOW%^er%^BLACK%^"+
			"o%^YELLOW%^x%^BLACK%^, Treasure's Guardian"+
			"%^RESET%^");
		set_long("%^BOLD%^%^BLACK%^With its sleek black skin, this "+
			"monstrous eel has learned to hide itself well amongst the "+
			"%^BLUE%^dark waters %^BOLD%^%^BLACK%^at the bottom of "+
			"the Saakrune Sea.  Long and slender, the body begins "+
			"with a blunt nosed face filled with rows of %^WHITE%^"+
			"needle-sharp teeth %^BLACK%^and tapers back to an "+
			"elongated tip.  Flickers of %^YELLOW%^light %^BOLD%^"+
			"%^BLACK%^pass through the creature's body at times, "+
			"illuminating the darkness of its skin with an %^BLUE%^"+
			"e%^YELLOW%^t%^BLACK%^h%^YELLOW%^e%^BLUE%^r%^YELLOW%^e"+
			"%^BLACK%^a%^BLUE%^l l%^YELLOW%^u%^BLACK%^m%^YELLOW%^i"+
			"%^BLUE%^n%^BLACK%^e%^BLUE%^s%^YELLOW%^c%^BLACK%^e"+
			"%^YELLOW%^n%^BLUE%^ce %^BLACK%^and setting the %^YELLOW%^"+
			"yellow eyes %^BOLD%^%^BLACK%^ablaze with %^WHITE%^energy"+
			"%^BLACK%^.  No limbs mar the sleek beauty of the creature "+
			"though the mouth looks dangerous enough to be cautious "+
			"of such a creature.%^RESET%^");
		set_race("eel");
		set_body_type("snake");
		set_gender("female");
		set_alignment(5);
		set_size(3);
		set_exp(20000);
		set("aggressive","agg_func");
		
		add_limb("mouth","head",0,0,0);
		add_limb("tail","torso",0,0,0);
		set_attack_limbs(({"mouth"}));
		set_attacks_num(4);
		set_base_damage_type("piercing");
		set_damage(2,8);
		set_hd(40,10);
		set_class("fighter");
		set_mlevel("fighter",30);
		set_guild_level("fighter",30);
		set_max_hp(random(240)+2000);
		set_hp(query_max_hp());
		set_overall_ac(-12);
				
		set_stats("strength",18);
		set_stats("intelligence",15);
		set_stats("wisdom",15);
		set_stats("dexterity",20);
		set_stats("constitution",15);
		set_stats("charisma",15);
		
		set_mob_magic_resistance("average");
		set_property("no animate",1);
		set_property("no death",1);
		set_property("no steal",1);
		set_property("no dominate",1);
		set_property("no bows",1);
		set_property("water breather",1);
				
		set_funcs(({"bite_them","zap_them","chew_them","squeeze_them"}));
		set_func_chance(25);
} 

void agg_func(){
	if(TP->query_invis()){return;}
		force_me("emote %^YELLOW%^bursts%^RESET%^ from the rubble "+
			"in a burst of sleek %^BLACK%^%^BOLD%^black death"+
			"%^RESET%^!");
		force_me("kill "+TP->query_name());
	return;
}

int bite_them(object target){
	tell_object(target,"%^BOLD%^%^WHITE%^The eel rushes forward with "+
		"rows of sharp teeth glinting as they snap down around your "+
		"limb!%^RESET%^");
	tell_room(ETO,"%^BOLD%^%^WHITE%^The eel rushes forward swiftly, its "+
			"teeth snapping down upon "+target->QCN+"'s limb!"+
			"%^RESET%^",target);
				set_property("magic",1);
				target->do_damage("torso",random(15)+25);
				remove_property("magic");
	return 1;
}

int chew_them(object target){
	tell_object(target,"%^BOLD%^%^CYAN%^You scream as the eel tears away "+
		"at your tender flesh, realizing only too late that you're "+
		"under water!%^RESET%^");
	tell_room(ETO,"%^BOLD%^%^CYAN%^A burst of bubbles explode from "+
		""+target->QCN+" as they open their mouth to scream!%^RESET%^",target);
				set_property("magic",1);
				target->do_damage("torso",random(20)+25);
				remove_property("magic");
	return 1;
}

int squeeze_them(object target){
	tell_object(target,"%^YELLOW%^You feel the electricity burn through "+
		"you as the eel brushes up against you!%^RESET%^");
	tell_room(ETO,"%^YELLOW%^The eel brushes against "+target->QCN+"!"+
		"%^RESET%^",target);
		target->set_paralyzed(15,"%^YELLOW%^Your muscles are twitching "+
			"from the electric shock!%^RESET%^");
	return 1;
}

int zap_them(object target){
	tell_object(target,"%^BOLD%^%^BLUE%^The eel wraps itself around your "+
		"body and squeezes!%^RESET%^");
	tell_room(ETO,"%^BOLD%^%^BLUE%^The eel wraps itself around "+target->QCN+" "+
		"and squeezes the life out of them!%^RESET%^",target);
		set_property("magic",1);
		target->do_damage("torso",random(30)+15);
		remove_property("magic");
	return 1;
}

void die(object target){
        object *pplz;
        int i,freeze;
        pplz = all_living(ETO);
        TO->set_property("magic",1);
        tell_room(ETO,"%^YELLOW%^A burst of electrical energy pulses "+
			"outward from the eel, momentarily electrifying the water!"+
			"%^RESET%^");
                        new(OBJ"coral_goodchest")->move(TO);
						new(OBJ"coral_earring")->move(TO);
						
		if(!sizeof(pplz)) return;
       
		for(i=0;i<sizeof(pplz);i++) {
			if(avatarp(pplz[i])) continue;
			pplz[i]->set_paralyzed(15);
		}
		
        ::die(TO);
        return 1;
}
