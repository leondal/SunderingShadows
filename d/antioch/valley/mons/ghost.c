//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Minor tweaks to difficulty and XP to make trails on par with Yntala - Octothorpe 12/29/09

#include <std.h>
#include "../valley.h"
inherit F_WANDER;

void create(){
	::create();
	set_name("ghost");	
	set_id(({"ghost","undead","monster"}));
	set_short("A frightening ghost");
	set_long(
	"The ghost seems to be wearing a long robe with a hood, but"+
	" the garment is actually part of his body. This being is"+
	" slightly translucent, and his eyes seem to glow beneath"+
	" his hood. His face is twisted into an evil scowl and he"+
	" seems menacing."
	);
	set_property("undead",1);
	set_hd(15,6);
	set_max_level(22);
	set_gender("male");
	set_body_type("human");
	set_overall_ac(0);
	set_alignment(3);
	set_size(2);
	set_race("ghost");
	set_max_hp(random(50)+250);
	set_hp(query_max_hp());
	set_class("fighter");
	set_mlevel("fighter",20);
	set_level(15);
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(1,8);
    set_sight_bonus(2);
	set_hit_funcs(([
		"right hand":(:TO,"touch":),
		"left hand":(:TO,"drain":)
	]));
//        set_exp(9500);
	set_new_exp(20,"normal");
	add_money("electrum",random(5000));
	set_property("swarm",1);
	set("aggressive",25);
	set_property("weapon resistance",1);
      set_resistance("negative energy",10);
      set_resistance("positive energy",-10);
}


int touch(object targ)
{
	if(!random(5)) {
        if(!targ->query_stat_bonus("strength")) return 1;
	    if((int)targ->query_stat_bonus("strength") < -1) return 0;    	
		if(!"/daemon/saving_throw_d.c"->fort_save(targ,-12)){
			tell_object(targ,"%^BOLD%^%^CYAN%^The icy touch of the ghost drains"+
			" your strength away.");
			tell_room(ETO,"%^BOLD%^%^CYAN%^The ghost"+
			" touches "+targ->query_cap_name()+" and seems to drain"+
			" "+targ->query_objective()+" of "+targ->query_possessive()+""+
			" strength.",targ);
			targ->add_stat_bonus("strength",-1);
			return 1;
		}
		else {
			tell_object(targ,"You successfully resist the icy"+
			" touch of the ghost.");
			tell_room(ETO,"The ghost touches "+targ->query_cap_name()+","+
			" but "+targ->query_subjective()+" seems to be alright.",targ);
			return 1;
		}
		return 1;
	}
}

/*int drain(object targ)
{
	if(!random(6)) {
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^The ghost seems to drain"+
			" your life force from you!");
			tell_room(ETO,"%^BOLD%^The ghost seems"+
			" to drain "+targ->query_cap_name()+"'s life force"+
			" from "+targ->query_objective()+"!",targ);
                     targ->resetLevelForExp(-(random(500)+500));
			return 1;
		}
		else {
			tell_object(targ,"%^BOLD%^The ghost attempts to drain"+
			" away some of your life but fails.");
			tell_room(ETO,"The ghost tries to drain"+
			" away "+targ->query_cap_name()+"'s life force but"+
			" nothing seems to happen.",targ);
			return 1;
		}
		return 1;
	}
}*/
