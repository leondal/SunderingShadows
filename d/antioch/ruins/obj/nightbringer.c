//Added lore and changed to inherit mace - Cythera 4/05
#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/weapon/mace.c";

int FLAG;

void create()
{
	::create();
   set_obvious_short("%^BOLD%^%^BLACK%^A black mace%^RESET%^");
	set_name("Nightbringer");
	set_short("%^BOLD%^%^BLACK%^Nightbringer%^RESET%^");
	set_id(({"nightbringer","Nightbringer","mace","shar mace","mace of shar","shar's mace"}));
	set_long(
	"%^BOLD%^%^BLACK%^This is a rather wicked looking mace, with barbed points at the end of"+
	" it. It is a solid black in color, and made of a hefty metal that also"+
	" appears to be quite durable. Just looking at the mace sends a shiver"+
	" down your spine, it seems to have a presence about it.%^RESET%^"
	);
	set_lore("The bane of any Selunite, Nightbringer is an unholy mace "+
		"sanctified in the darkness that is Shar.  Due to the secretive"+
		" nature of The Lady of Loss' faith, the origins of the mace are"+
		" unclear and cloudy at best.  It is my belief that the mace is "+
		"actually a divine artifact (not to be confused with a magical "+
		"artifact) of the Church of the Mistress of the Night.  While "+
		"anyone of a dark heart can wield the mace, it is said that the "+
		"true power and might of the mace only is felt by those who have "+
		"pledge their souls to Shar.  The Nightbringer is a favored weapon"+
		" of the Sharran clerics of bashing in heads and limbs of "+
		"Selunites. - The Way of the Night: The Eternal Battle of Selune"+
		" and Shar - Therdorick Renegard");
	set_property("lore",13);
	//set_weight(10);
	//set_size(2);
	//set_type("bludgeoning");
	//set_prof_type("mace");
	//set_wc(1,8);
	//set_large_wc(1,8);
	set_property("enchantment",3);
	set_item_bonus("attack bonus",2);
	set_item_bonus("sight bonus",2);
	//set_weapon_speed(7);
	set_value(100);
	set_hit((:TO,"hitme":));
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
}

int wieldme()
{
	if(ETO->query_lowest_level() < 20) {
		tell_object(ETO,"%^BOLD%^%^RED%^Nightbringer tells you: %^RESET%^I will"+
		" never let someone as pitiful as you wield me!");
		if(!"daemon/saving_d"->saving_throw(ETO,"spell",-3)) {
			tell_object(ETO,"%^BLUE%^You feel the sight slowly drain from your"+
			" eyes.");
			set_property("magic",1);
			ETO->do_damage("torso",random(5)+10);
			ETO->add_attacker(TO);
			ETO->continue_attack();
			ETO->remove_attacker(TO);
			remove_property("magic");
			ETO->set_blind(1);
		}
		return 0;
	}
	if((string)ETO->query_diety() == "selune") {
		tell_object(ETO,"%^BLUE%^The mace burns your hand as you try to grasp the handle.");
		tell_object(ETO,"%^BOLD%^%^RED%^Nightbringer tells you: %^RESET%^I will"+
		" never let one of Selune's flea ridden dogs wield me!");
		tell_room(environment(ETO),""+ETO->QCN+" draws "+ETO->QP+""+
		" hand back as if in pain from trying to grasp the handle of the mace.",ETO);
		set_property("magic",1);
		ETO->do_damage("torso",random(10)+30);
		ETO->add_attacker(TO);
		ETO->continue_attack();
		ETO->remove_attacker(TO);
		remove_property("magic");
		return 0;
	}
	if(ALIGN->is_good(ETO)) {
		tell_object(ETO,"%^BOLD%^%^RED%^Nightbringer tells you: %^RESET%^If you"+
		" wish to wield me, you must give up your goodly ways. Together we might"+
		" be powerful allies some day....");
		return 0;
	}
   if(ETO->query_property("good item")) {
       tell_object(ETO,"The nightbringer refuses to be wielded while you're using such goodly items!");
       return 0;
   }
	if(ALIGN->is_evil(ETO)) {
		if((string)ETO->query_diety() == "shar") {
			tell_object(ETO,"%^BOLD%^%^BLACK%^Sweet darkness overcomes you as you grasp Nightbringer,"+
			" you can feel Shar's strength flowing through you.");
			tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The room seems to darken"+
			" as "+ETO->QCN+" wields Nightbringer.",ETO);
			FLAG = 1;
         ETO->set_property("evil item",1);
			return 1;
		}
		tell_object(ETO,"%^BOLD%^%^BLACK%^Darkness overcomes you as you grasp"+
		" the mace.");
		tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The room seems to darken"+
		" as "+ETO->QCN+" wields "+ETO->QP+" mace.",ETO);
      ETO->set_property("evil item",1);
		return 1;
	}
	else {
		tell_object(ETO,"%^BOLD%^%^RED%^Nightbringer tells you: %^RESET%^You"+
		" will do for now, and I shall add to the darkness already in your soul.");
      ETO->set_property("evil item",1);
		return 1;
	}
}

int removeme()
{
	if(FLAG == 1) {
		tell_object(ETO,"%^BOLD%^%^BLACK%^Your fingers ache as you release Nightbringer"+
		" and already you can't wait to wield it again.");
		tell_room(environment(ETO),"The light seems to return to the room as"+
		" "+ETO->QCN+" releases Nightbringer.",ETO);
      ETO->set_property("evil item",-1);
		return 1;
	}
	if(ALIGN->is_evil(ETO)) {
		tell_object(ETO,"%^BOLD%^%^BLUE%^You feel the rush of power leave you,"+
		" and you already crave to have it back.");
		tell_room(environment(ETO),"The light seems to return to the room as"+
		" "+ETO->QCN+" releases "+ETO->QP+" mace.",ETO);
      ETO->set_property("evil item",-1);
		return 1;
	}
	else {
		tell_object(ETO,"%^BOLD%^%^RED%^Nightbringer tells you: %^RESET%^I knew"+
		" you did not have the endurance to wield me for long.");
      ETO->set_property("evil item",-1);
		return 1;
	}
}

int hitme(object targ)
{
	if(FLAG != 1 && (string)targ->query_diety() == "shar") {
		return -3;
	}
	if(!random(5)) {
		tell_object(ETO,"You smash the %^BOLD%^%^BLACK%^Nightbringer%^RESET%^ into "+targ->QCN+"'s"+
		" skull!");
		tell_object(targ,""+ETO->QCN+" smashes "+ETO->QP+""+
		" mace into your skull!");
		tell_room(environment(ETO),""+ETO->QCN+" smashes "+ETO->QP+""+
		" mace into "+targ->QCN+"'s skull!",({ETO,targ}));
		targ->do_damage("torso",random(3)+2);
		return 1;
	}
	if(!random(12)) {
		if(!"daemon/saving_d"->saving_throw(targ,"spell",-3)) {
			tell_object(ETO,"%^BOLD%^%^BLACK%^Your Nightbringer drains the light"+
			" from "+targ->QCN+"'s eyes.");
			tell_object(targ,"%^YELLOW%^"+ETO->QCN+"'s Nightbringer"+
			" seems to drain the light from your eyes!");
			tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s"+
			" Nightbringer drains the light from "+targ->QCN+"'s eyes.",({ETO,targ}));
                        targ->set_temporary_blinded(roll_dice(1,4));
			return 1;
		}
		tell_object(ETO,"%^BOLD%^%^BLUE%^Your Nightbringer tries to drain "+targ->QCN+""+
		" of "+targ->QP+" sight, but "+targ->QS+""+
		" resists.\n"+
		"%^BOLD%^%^RED%^Nightbringer tells you: %^RESET%^This one must be"+
		" powerful to be able to resist MY powers.");
		tell_object(targ,"%^BOLD%^"+ETO->QCN+"'s Nightbringer"+
		" tries to cast a spell over you, but you resist its powers.");
		return 1;
	}
	if(!random(18)) {
		tell_object(ETO,"%^RED%^%^BOLD%^Your %^BLACK%^Nightbringer%^RED%^"+
		" %^RESET%^%^RED%^darkens%^BOLD%^ as it slams into "+targ->QCN+", draining "+targ->QO+""+
		" of "+targ->QP+" strength.");
		if(FLAG == 1) {
			tell_object(ETO,"%^RED%^Strength flows into you through the Nightbringer.");
                        ETO->do_damage("torso",(-1)*(random(4)+2));
		}
		tell_object(targ,"%^BOLD%^%^RED%^"+ETO->QCN+"'s %^BLACK%^Nightbringer%^RED%^"+
		" slams into you, draining you of your strength.");
		tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+"'s"+
		" %^BLACK%^Nightbringer%^RED%^ slams into "+targ->QCN+","+
		" who seems to weaken.",({ETO,targ}));
		targ->do_damage("torso",random(5)+3);
		return 1;
	}
	if(FLAG == 1) {
		targ->do_damage("torso",random(3)+1);
		return 1;
	}
}
