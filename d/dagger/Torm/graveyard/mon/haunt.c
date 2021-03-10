#include <std.h>
#include "/d/antioch/valley/valley.h"
inherit F_WANDER;

void create()
{
	::create();
	set_name("haunt");
	set_id(({"haunt","monster","undead","spirit","tormented spirit"}));
	set_short("A tormented spirit");
	set_long(
	"A nebulous figure stands before you, the visage of the"+
	" haunt's former body. It's translucent and eerie looking,"+
	" a tormented spirit. Some unfinished business causes this"+
	" poor soul to wonder the realms after death."
	);
	set_gender("male");
	set_race("spirit");
	set_body_type("human");
	set_size(2);
	set_property("undead",1);
	set_hd(15,4);
	set_max_level(20);
  set_overall_ac(3);
	set_alignment(random(9)+1);
	set_class("fighter");
	set_mlevel("fighter",10);
	set_level(15);
	set_max_hp(random(40)+120);
	set_hp(query_max_hp());
	set("aggressive",15);
	set_property("swarm",1);
	set_exp(1500);
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(1);
	set_base_damage_type("slashing");
	set_damage(1,6);
	set_hit_funcs((["right hand":(:TO,"dex_drain":)]));
}

int dex_drain(object targ)
{
	if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
		tell_object(targ,"%^YELLOW%^The haunt sucks away some of"+
		" your agility.");
		tell_room(ETO,"%^YELLOW%^The haunt touches"+
		" "+targ->query_cap_name()+", and "+targ->query_subjective()+""+
		" seems a little groggy.",targ);
		targ->add_stat_bonus("dexterity",-1);
		return 1;
	}
	else {
		return 1;
	}
}
