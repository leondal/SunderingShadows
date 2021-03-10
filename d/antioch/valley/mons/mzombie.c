//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Minor tweaks to difficulty and XP to make trails on par with Yntala - Octothorpe 12/26/09

#include <std.h>
#include "../valley.h"
inherit F_WANDER;

void create(){
	::create();
	set_name("monster zombie");
	set_id(({"monster","monster zombie","zombie","undead","bugbear"}));
	set_short("A filthy monster zombie");
	set_long(
	"This disgusting figure is that of a bugbear who has been turned"+
	" into a zombie through use of magic and forced to obey the will"+
	" of his master. Dirt still clings to the creature's furr from"+
	" the time he spent in the grave, and large patches of his"+
	" hide are missing. Several of his teeth are gone and one of"+
	" his eyes is sunken in and useless. There are numerous cuts all"+
	" over the beast from past battles, cuts that will not heal"+
	" and do not bleed. This poor creature should be resting in his"+
	" grave."
	);
	set_property("undead",1);
	set_hd(15,3);
	set_max_level(15);
	set_gender("male");
	set_body_type("bugbear");
	set_race("zombie");
	set_size(3);
	set_alignment(6);
	set_overall_ac(-2);
	set("aggressive",25);
	set_property("swarm",1);
//        set_exp(9500);
	set_new_exp(15,"normal");
	set_level(15);
	set_class("fighter");
	set_mlevel("fighter",15);
	set_stats("dexterity",12);
	set_stats("charisma",1);
	set_max_hp(random(60)+190);
	set_hp(query_max_hp());
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(1,20);
      set_resistance("negative energy",10);
      set_resistance("positive energy",-10);
}

	
