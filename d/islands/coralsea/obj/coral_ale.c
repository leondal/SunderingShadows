#include <std.h>
inherit "/d/common/obj/weapon/mclub.c";

// Coral Sea Area - Created January 2009 by Ari
// Monsterweapon only, should never be on a player.

void create(){
	::create();
	set_name("mug of ale");
	set_id(({"mug","mug of ale","ale"}));
	set_short("mug of ale");
	set_long("This looks like a mug filled with ale.");
	set_value(0);
	set_type("bludgeoning");
	set_property("enchantment",3);
	set_hit((:TO,"hit_function":));
}

int hit_function(object targ){
	if(random(1000) < 200) {
		switch(random(10)){
		
		case 0..1:
			tell_room(EETO,"%^YELLOW%^Grizon's mug smashes upside "+
				""+targ->QCN+"'s head!%^RESET%^");
			set_property("magic",1);
				targ->set_paralyzed(5,"%^BOLD%^%^ORANGE%^You're "+
				"recovering your senses!%^RESET%^");
			remove_property("magic");	
		break;
		
		case 2..4:
			tell_room(EETO,"RESET%^%^ORANGE%^Grizon splashes some "+
				"of the ale into "+targ->QCN+"'s face, blinding them!");
			set_property("magic",1);
			targ->set_paralyzed(5,"%^BOLD%^%^ORANGE%^You're trying to "+
				"clear your eyes of ale!%^RESET%^");
			remove_property("magic");
		break;
		
		case 5..8:
			tell_room(EETO,"%^YELLOW%^A chip of Grizon's mug breaks "+
				"off and jabs into "+targ->QCN+"'s arm. %^RED%^Blood "+
				"sprays everywhere!%^RESET%^");
			set_property("magic",1);
			targ->do_damage("torso",random(6)+8);
			remove_property("magic");	
		break;
		
		case 9:
			tell_room(EETO,"%^BOLD%^%^RED%^Angry at spilling his beer "+
				"Grizon screams in rage, breaking the mug on a counter "+
				"top and jabbing it into "+targ->QCN+"'s tender flesh!");
			set_property("magic",1);
			targ->do_damage("torso",random(5)+20);
			remove_property("magic");
		break;
		
		return 1;
		}
	}
}