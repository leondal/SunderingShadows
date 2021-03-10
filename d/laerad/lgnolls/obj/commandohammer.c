//Essyllis: Feb 2015
#include <std.h>
#include "../lgnoll.h"
inherit "/d/common/obj/weapon/warhammer";


object targ;

void create() {
	::create();
	set_name("Commando Hammer");
	set_short("%^BOLD%^%^WHITE%^Asgard Commando Hammer%^RESET%^");
   set_obvious_short("%^BOLD%^%^ORANGE%^An Aesatri warhammer%^RESET%^");
	set_id(({"hammer","aesatri hammer","hammer asgard","commando hammer","Commando Hammer","Hammer","commando"}));
	set_long("This warhammer is, despite being very beautiful, clearly crafted with "+
			"the purpose of efficiency. The %^BOLD%^%^BLACK%^striking side %^RESET%^of "+
			"the warhammer's %^BOLD%^%^BLACK%^s%^RESET%^o%^BOLD%^%^BLACK%^l%^RESET%^i%^BOLD%^%^BLACK%^d "+
			"st%^RESET%^ee%^BOLD%^%^BLACK%^l h%^RESET%^ea%^BOLD%^%^BLACK%^d %^RESET%^narrows "+
			"until it results in a %^ORANGE%^p%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^rf%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^ct "+
			"sq%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^ar%^BOLD%^%^BLACK%^e %^RESET%^of no more than "+
			"two square-inches with %^ORANGE%^p%^BOLD%^y%^RESET%^%^ORANGE%^r%^BOLD%^a%^RESET%^%^ORANGE%^m%^BOLD%^i%^RESET%^%^ORANGE%^d-sp%^BOLD%^i%^RESET%^%^ORANGE%^kes "+
			"%^WHITE%^for added efficiency against %^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e "+
			"a%^BOLD%^%^BLACK%^rm%^RESET%^o%^BOLD%^%^BLACK%^rs%^RESET%^. The back-end of the hammer's head "+
			"widens into a almost sph%^BOLD%^e%^RESET%^r%^BOLD%^i%^RESET%^c%^BOLD%^a%^RESET%^l "+
			"sh%^BOLD%^a%^RESET%^p%^BOLD%^e %^RESET%^able to deliver truly %^BOLD%^b%^RESET%^o%^BOLD%^n%^RESET%^e%^BOLD%^-cr%^RESET%^u%^BOLD%^sh%^RESET%^i%^BOLD%^ng "+
			"%^RESET%^blows against ch%^BOLD%^%^BLACK%^ai%^RESET%^n or %^ORANGE%^leather %^WHITE%^armors. "+
			"The shaft is made from the %^ORANGE%^c%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^re of an "+
			"%^GREEN%^o%^ORANGE%^ak tr%^GREEN%^e%^ORANGE%^e %^WHITE%^and reinforced with "+
			"%^BOLD%^%^CYAN%^m%^RESET%^%^CYAN%^i%^BOLD%^thr%^RESET%^%^CYAN%^i%^BOLD%^l ba%^RESET%^%^CYAN%^n%^BOLD%^ds "+
			"%^RESET%^all the way up to the %^BOLD%^%^BLACK%^head%^RESET%^. The right side of the head "+
			"is %^BOLD%^%^CYAN%^m%^RESET%^%^CYAN%^i%^BOLD%^thr%^RESET%^%^CYAN%^i%^BOLD%^l, "+
			"%^RESET%^%^CYAN%^e%^BOLD%^ngr%^RESET%^%^CYAN%^a%^BOLD%^v%^RESET%^%^CYAN%^e%^BOLD%^d %^RESET%^with "+
			"%^YELLOW%^Aesatri %^RESET%^runes used by the %^YELLOW%^C%^WHITE%^o%^ORANGE%^mm%^WHITE%^a%^ORANGE%^nd%^WHITE%^o%^ORANGE%^ "+
			"el%^WHITE%^i%^ORANGE%^t%^WHITE%^e %^RESET%^of %^YELLOW%^Asgaard%^RESET%^. On the right side of "+
			"the head a %^MAGENTA%^gem-socket %^WHITE%^is visible. %^MAGENTA%^But the gemstone seem to be missing.%^RESET%^"
	);
	set_lore("Only given to the Elite forces of Commando in Asgard, it is considered an "+
			"honor to receive such a hammer. The citizens of Asgard were always in need "+
			"of protecting themselves, being under constant onslaught from either Trolls "+
			"or other evil forces of Laerad. These hammers were crafted by the dwarves and "+
			"were a symbol of strength and protection in Asgard.");
	set_property("lore",14);  
	set_weight(15);
	set_value(1500);
	set_property("enchantment",2);
	set_item_bonus("damage bonus",2);
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));
}

int wieldme() {
	if(ETO->query_lowest_level() < 15) {
		tell_object(ETO,"You are not powerful enough to wield this weapon.");
		return 0;
	}
	tell_object(ETO,"%^BOLD%^%^YELLOW%^You feel the strength of this weapon as you wield it.");
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->QCN+" wields this heavy looking hammer with surprising ease.",ETO);
	return 1;
}

int removeme() {
	tell_object(ETO,"%^RESET%^%^ORANGE%^The hammer seem much heavier as you set it aside.");
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->QCN+" releases the hammer with a heavy sigh.",ETO);
	return 1;
}

int hitme(object targ) {
    if(!living(ETO) || !living(targ)) return 0;
        if(random(1000) < 175) {
		tell_object(ETO,"%^BOLD%^The Aesatri runes %^YELLOW%^flare%^WHITE%^ as you smash the hammer into "+targ->QCN+"!");
		tell_object(targ,"%^BOLD%^"+ETO->QCN+"'s hammer delivers a crushing blow to you!");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" smashes the hammer with impressive force into "+targ->QCN+"!",({ETO,targ}));
		set_property("magic",1);
		targ->do_damage("torso",random(3)+5);
		remove_property("magic");
		return 1;
	}
     
}

