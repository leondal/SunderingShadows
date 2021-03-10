#include <std.h>
#include "../tharis.h"
inherit TOWNSMAN;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Healer Remodle - Created in February 2009 by Ari

void create() {
	::create();
		set_name("Hersh");
                set_id(({"The Healer","hersh","healer"}));
		set_property("no attack",1);
		set_short("Hersh the quiet healer of Tharis");
		set("aggressive", 0);
		set_level(19);
		set_long("%^RESET%^%^CYAN%^An older gentleman with "+
			"stark white hair, Hersh is dressed in simple, "+
			"utilitarian garments that allow him to move "+
			"about the shop easily and free from obstacles "+
			"such as snagged cuffs or hems that trip.  "+
			"A leather tool belt is secured about his waist "+
			"with several slots for vials and a couple pouches "+
			"that likely hold bandages or other tools of the "+
			"trade.  Though elderly, he still seems spry and his "+
			"dark gray eyes are bright and watchful, taking in "+
			"the condition of those who enter in a quick and "+
			"effective manner.%^RESET%^");
		set_gender("male");
		set_alignment(8);
		set("race", "human");
		add_money("gold", random(500));
		set_body_type("human");
		set_property("no attack", 1);
		set_hd(19,3);
		set_max_hp(query_hp());
		set_max_sp(query_hp());
		set_sp(query_max_sp());
		set_mp(random(500));
		set_max_mp(query_mp());
		set_exp(10);
}
