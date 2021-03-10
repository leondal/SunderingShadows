#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/mclub.c";

// Coral Sea Area - Created January 2009 by Ari

int tracker, trackerb;

void init(){
	::init();
		add_action("shock_them","shock");
}

void create(){
	::create();
	set_name("belaying pin"); 
	set_id(({"belay pin","pin","belaying pin","club","sailor's ace",
		"sailors ace","ace"}));
	set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^ai%^YELLOW%^l%^RESET%^"+
		"%^ORANGE%^o%^YELLOW%^r's A%^RESET%^%^ORANGE%^c%^YELLOW%^e"+
		"%^RESET%^");  
	set_obvious_short("%^RESET%^%^ORANGE%^a ship's belaying "+
		"pin%^RESET%^");
		
	set_long("%^RESET%^%^ORANGE%^Created from %^YELLOW%^brass "+
		"%^RESET%^%^ORANGE%^and %^RESET%^oak %^ORANGE%^pieces "+
		"affixed together, this belaying pin would make a fine club "+
		"for bashing the head of a ship's invader in.  Though "+
		"unadorned, the%^YELLOW%^ brass head %^RESET%^%^ORANGE%^is "+
		"smooth and rounded at the top then tapers inward creating "+
		"an upside down %^CYAN%^teardrop %^RESET%^%^ORANGE%^shape "+
		"before fanning out into a wide circular base.  It is into "+
		"this base that the handle portion, a simple wooden dowel "+
		"of smooth %^RESET%^white oak%^ORANGE%^, has been screwed.  "+
		"The word %^CYAN%^shock %^RESET%^%^ORANGE%^has been scrawled "+
		"along the underside of the head, near where the two pieces "+
		"fit together.%^RESET%^");
		
	set_value(300);
	set_property("enchantment",2);
	
	set_lore("It is common on ships to find several belaying pins. "+
		"These pins are used to secure ropes, or in case of attack "+
		"as a quick weapon that a crew member can use to defend "+
		"themselves with.  In some cases a ship will carry a few "+
		"special pins, enchanted to create an extra punch.  These "+
		"can usually be found on ships whose cargo warrents the "+
		"risk of pirate attack.");
	set_property("lore difficulty",15);
	
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	
	set_hit((:TO,"hit_function":));
}

int wieldme(){
	tell_object(ETO,"%^YELLOW%^The brass head feels heavy enough "+
		"to crack someone's skull!%^RESET%^");
	tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" looks down "+
		"contemplatively at their weapon.%^RESET%^",ETO);
	return 1;
}

int removeme(){
	tell_object(ETO,"%^YELLOW%^You slide the belaying club away "+
		"for another day.%^RESET%^");
	tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" "+
		"sets aside their weapon.%^RESET%^",ETO);
	return 1;
}

int hit_function(object targ){
	if(random(1000) < 150) {
		switch(random(3)){
		
		case 0:
			tell_object(ETO,"%^BOLD%^%^WHITE%^You bring the heavy "+
				"%^YELLOW%^brass%^WHITE%^ head of the belaying pin "+
				"down upon "+targ->QCN+"'s skull!");
			tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" brings "+
				"the solid %^YELLOW%^brass %^WHITE%^head of their "+
				"belaying pin down upon your skull! Ouch!");
			tell_room(environment(ETO),"%^BOLD%^%^WHITE%^There is "+
				"a loud CRACK as "+ETO->QCN+" attacks "+targ->QCN+"!"+
				"%^RESET%^",({targ,ETO}));
			targ->set_paralyzed(7,"%^BOLD%^%^GREEN%^You're trying to "+
				"recover your senses!%^RESET%^");
		break;	

		case 1..2:
			tell_object(ETO,"%^YELLOW%^"+targ->QCN+" yelps in pain as "+
				"the heavy brass pin strikes them!%^RESET%^");
			tell_object(targ,"%^YELLOW%^Pain bursts through your body "+
				"as "+ETO->QCN+"'s belaying pin strikes you!%^RESET%^");
			tell_room(environment(ETO),"%^YELLOW%^"+targ->QCN+" yelps "+
				"with pain as "+ETO->QCN+"'s belaying pin strikes "+
				"them soundly!%^RESET%^",({targ,ETO}));
			targ->do_damage("torso",random(6)+6);
		break;			

		return 1;
		}
	}
}

int shock_them(string str){
	if(TP->query_bound() || TP->query_unconscious()){
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(!str){
		tell_object(TP,"%^YELLOW%^You need to specfy your target."+
			"%^RESET%^");
		return 1;
	}
	if(tracker > time()){
		tell_object(TP,"%^YELLOW%^The pin appears to have run out "+
			"of energy for today.");
		return 1;
	}
	if(trackerb){
		tracker = time() + 14400;
		trackerb = 0;
	}
	else { trackerb = 1; }
		new("cmds/spells/l/_lightning_bolt")->use_spell(TP,str,20,100,"mage");
		return 1;
}
