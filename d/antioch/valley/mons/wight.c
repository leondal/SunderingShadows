//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Minor tweaks to difficulty and XP to make trails on par with Yntala - Octothorpe 12/26/09

#include <std.h>
#include "../valley.h"
inherit FM_WANDER;

void create(){
	::create();
	set_name("wight");
	set_id(({"wight","undead","monster"}));
	set_short("A hungry wight");
	set_long(
	"Black hair spills back from the skull of this creature,"+
	" falling down onto its tattered cape. The flesh of the"+
	" wight is mummified, an ugly brownish yellow color. His"+
	" hands end in claws that he uses to tear away the flesh"+
	" of the living. His teeth are sharp and hungry for your"+
	" meat, the lips curled back into a snarl. Yellow eyes are"+
	" glowing deep within the beasts eyesockets. Some clothing"+
	" still clings to his frame, more by accident than any"+
	" sort of modesty."
	);
	set_gender("male");
	set_race("wight");
	set_body_type("human");
	set_size(2);
	set_property("undead",1);
	set_hd(14,4);
	set_max_level(15);
	set_alignment(3);
	set_overall_ac(-3);
	set_class("fighter");
	set_mlevel("fighter",10);
	set_level(14);
	set_class("mage");
	set_mlevel("mage",10);
	set_max_hp(random(40)+140);
	set_hp(query_max_hp());
//        set_exp(9500);
	set_new_exp(10,"normal");
	set_property("weapon resistance",1);
	set_property("swarm",1);
	set("aggressive",14);
	add_money("silver",random(600));
	set_spells(({
		"magic missile"
		"hold person"
		"cone of cold"
		"fireball"
		"chain lightning"
	}));
	/*set_funcs(({"drain"}));
	set_func_chance(10);*/
      set_resistance("negative energy",10);
      set_resistance("positive energy",-10);
}

/*void drain(object targ)
{
	if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
		tell_object(targ,"%^BOLD%^%^BLUE%^The wight touches you"+
		" and you can feel your life force draining away!");
		tell_room(ETO,"%^BOLD%^%^BLUE%^The wight"+
		" touches "+targ->query_cap_name()+" and seems to drain"+
		" "+targ->query_possessive()+" life force!",targ);
        //targ->resetLevelForExp((roll_dice(1,10) * 200) * -1);
		return 1;
	}
	else {
		tell_object(targ,"%^BOLD%^%^BLUE%^The wight"+
		" makes a grab for you and you can feel a tugging"+
		" at your soul, but you have resisted its spell.");
		return 1;
	}
}*/
