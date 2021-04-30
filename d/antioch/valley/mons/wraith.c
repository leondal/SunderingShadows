//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Minor tweaks to difficulty and XP to make trails on par with Yntala - Octothorpe 12/26/09

#include <std.h>
#include "../valley.h"
inherit F_WANDER;

void create(){
	::create();
	set_name("wraith");
	set_id(({"wraith","undead","monster","shadow","evil shadow"}));
	set_short("An evil shadow");
	set_long(
	"%^BOLD%^%^BLACK%^The wraith is a deep black color,"+
	" seemingly made of almost pure evil. It has assumed a"+
	" man-like shape with arms, a torso and head. The skull"+
	" contains glowing %^RED%^red%^BOLD%^%^BLACK%^ eyes."
	);
	set_property("undead",1);
	set_hd(13,4);
	set_max_level(15);
	set_race("wraith");
	set_gender("male");
	set_body_type("human");
	set_size(2);
	set_alignment(3);
	set_property("weapon resistance",1);
	set_overall_ac(4);
	set_class("fighter");
	set_mlevel("fighter",10);
	set_level(13);
	set_max_hp(random(75)+170);
	set_hp(query_max_hp());
//        set_exp(9500);
	set_new_exp(10,"normal");
	add_money("electrum",random(200));
	set_property("swarm",1);
	set("aggressive",25);
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(1,12);
    set_sight_bonus(2);
	/*set_funcs(({"drain"}));
	set_func_chance(10);*/
      set_resistance("negative energy",10);
      set_resistance("positive energy",-10);
}


/*void drain(object targ)
{
     // updated September 30 2005, by Lujke, to make the xp drain a % of current experience, as agreed
     // by Garrett
     // these are disgustingly high numbers, so I'm changing them
     int texp, tlevel, percent;  // percent added by Lujke 30/09/05
     tlevel = targ->query_highest_level();
     texp = targ->query_exp();
     percent = 0;

	if(!random(6)) {
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^%^BLACK%^The wraith seems to drain"+
			" your life force from you!");
			tell_room(ETO,"%^BOLD%^%^BLACK%^The wraith seems"+
			" to drain "+targ->query_cap_name()+"'s life force"+
			" from "+targ->query_objective()+"!",targ);
                     switch(tlevel) {
                        case 0..15:
                           // changed by Lujke September 30 2005
                           percent = random(5) + 1;
//                             targ->resetLevelForExp(-(random(1000)+3000));
                           break;
                        case 16..20:
                           // changed by Lujke September 30 2005
                           percent  = random(4)+ 1;
//                             targ->resetLevelForExp(-(random(3000)+8000));
                           break;
                          case 21..25:
                           // changed by Lujke September 30 2005
                           percent = random(3)+1;
//                             targ->resetLevelForExp(-(random(10000)+50000));
                           break;
                        case 26..100:
                           // changed by Lujke September 30 2005
                           percent = random(2)+1;   
//                             targ->resetLevelForExp(-(random(40000)+1000000));
                           break;
                     }
                        // next line added by Lujke September 30 2005
                        texp = texp * percent;
                        texp = texp / 100;
                        resetLevelForExp(texp * -1);
			return 1;
		}
		else {
			tell_object(targ,"%^BOLD%^%^BLACK%^The wraith attempts to drain"+
			" away some of your life but fails.");
			tell_room(ETO,"The wraith tries to drain"+
			" away "+targ->query_cap_name()+"'s life force but"+
			" nothing seems to happen.",targ);
			return 1;
		}
		return 1;
	}
}*/
