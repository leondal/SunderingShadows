#include <std.h>
inherit "/d/common/obj/weapon/trident.c";

void create(){
	::create();
	set_name("trident");
	set_id(({ "hurricane", "trident", "trident of the hurricane","electrum trident" }));
	set_short("%^BOLD%^%^CYAN%^Trident of the %^RESET%^%^BLUE%^H%^CYAN%^"+
		"u%^BLUE%^r%^BOLD%^%^BLACK%^r%^RESET%^i%^BLUE%^c%^CYAN%^a"+
		"%^BLUE%^n%^CYAN%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^A blue electrum trident%^RESET%^");
	set_long("%^BLUE%^The sharp %^BOLD%^electrum%^RESET%^%^BLUE%^ prongs"+
		" of this trident are decorated with wicked looking %^BOLD%^"+
		"%^BLACK%^b%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^b%^BOLD%^%^BLACK%^s"+
		"%^RESET%^%^BLUE%^.  Engraved into the metal are images of fierce "+
		" forked bolts of %^BOLD%^%^CYAN%^lightning%^RESET%^%^BLUE%^.  "+
		"The prongs join together at an electrum base that extends out "+
		"about five feet.  %^BOLD%^%^BLACK%^Black coral%^RESET%^%^BLUE%^ "+
		"has been grafted to the metal, creating a rough texture grip.  "+
		"A metal forked %^BOLD%^spike%^RESET%^%^BLUE%^ extends off the base "+
		"of the trident, adding it's deadly appearance.%^RESET%^");
	set_value(1750);
	set_lore("Crafted by Patram the Storm Mage, a follower of Talos, the "+
		"Trident of the Hurricane was to be a gift.  Patram had fallen for"+
		" a pirate known as Captain Hawkings.  Patram served on Captain "+
		"Hawking's ship, The Shattered Spear, for several years.  Under "+
		"Captain Hawking's rule, the pirates developed a fearsome reputation"+
		" from the Dagger Sea all the way down to Attaya.  Patram became a "+
		"close confident of Captain Hawking's for his ability to unleash "+
		"fearsome spells to stop ships from escaping.  The two were hardly "+
		"ever seen apart, even on land.  This trident was enchanted by "+
		"Patram as a gift to the pirate he loved.  Some sailors claim that"+
		" with Patram's magic, he and Captain Hawking have become liches "+
		"that sail the seas to this day.");
	set_property("enchantment",2);
	set_item_bonus("attack bonus",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
   if((int)ETO->query_level() < 14) {
       write("You are not skilled enough to use this weapon!");
    	return 0;
   }
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The prongs on the trident cackle "+
		"with energy as "+ETO->QCN+" %^BOLD%^%^CYAN%^wields the weapon.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The prongs on the trident "+
		"crackle with energy.");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" releases the trident with reluctance.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You unwield the trident with reluctance.");
	return 1;
}

int hit_func(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   if(random(1000) < 150){
   	switch(random(40))
	{	
		default:
  		tell_object(ETO,"%^BOLD%^%^BLUE%^Lightning crackles across the"+
			" prongs of the trident, shocking "+victim->QCN+".");
      	tell_object(victim,"%^BOLD%^%^BLUE%^Lightning crackles across "+
			"the prongs of "+ETO->QCN+"'s trident, shocking you.");
      	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^Lightning crackles "+
			"across the prongs of "+ETO->QCN+"'s trident,"+
       		" shocking "+victim->QCN+".",({ETO,victim}));
       		victim->do_damage(victim->return_target_limb(),random(4)+3);
	 	break;
		case 37..39:
      	tell_object(ETO,"%^BOLD%^%^CYAN%^You recoil back as you unleash "+
			"a cone of whirling water and wind at "+victim->QCN+".");
      	tell_object(victim,"%^BOLD%^%^CYAN%^"+ETO->QCN+" recoils back"+
			" as "+ETO->QS+" unleashes a cone of whirling water and wind at you!");
      	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^%^BOLD%^%^CYAN%^"+ETO->QCN+" "+
			"recoils back as "+ETO->QS+" unleashes a cone of whirling"+
			" water and wind at"+victim->QCN+".",({ETO,victim}));
        		victim->do_damage(victim->return_target_limb(),random(6)+6);
		break;
	}
   	
    return 1;
   }
}
