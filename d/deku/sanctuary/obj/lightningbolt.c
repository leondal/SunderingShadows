//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
// changing to inherit from the common file and removing the redundant settings so it will stay in sync with changes *Styx*  2/20/04
// that will also make it a size 1
//changed where it inherits light rapier - cythera
inherit "/d/common/obj/weapon/light_rapier";

//added prof_type rapier Cythera 2/05\\
void create(){
	::create();
	set_name("lightning bolt rapier");
	set_id(({ "rapier", "light rapier", "lightning bolt", "sword" }));
	set_short("%^BOLD%^%^YELLOW%^Lightning Bolt Rapier%^RESET%^");
	set_obvious_short("%^YELLOW%^A yellow hued light rapier%^RESET%^");
	set_long("%^BOLD%^%^CYAN%^This rapier is crafted out of a mixture"+
		" of %^YELLOW%^gold%^CYAN%^ and %^RESET%^%^ORANGE%^brass%^BOLD%^"+
		"%^CYAN%^, twisted together.  The point on this blade, as with "+
		"all rapiers, is slim and narrow.  Though this rapier's blade is "+
		"shorter than most rapiers, suggesting that it is a light rapier.  "+
		"The hand guard of this blade is composed of twisted %^YELLOW%^gold"+
		"%^CYAN%^ that forks off in various directions, before coming to rest"+
		" at the pommel.%^RESET%^");
	set_property("lore",10);
	set_value(3000);
	set_lore("Lightning bolt, as the rapier is called by many duelist and "+
		"swashbucklers, is prized for its electrical abilities as well as"+
		" swiftness in combat.  Many noble duelists and fencers have fond "+
		"memories of a blade like this.");
/* all this would be in the /d/common file now
//	set_weight(4);
	set_type("piercing");
	set_prof_type("rapier");
	set_size(2);
	set_wc(2,3);
	set_large_wc(2,4);
*/
	set_property("enchantment",3+random(2));
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^YELLOW%^Arcs of electricity dance "+
		"across the handguard of "+ETO->QCN+"'s rapier",ETO);
	tell_object(ETO,"%^YELLOW%^Arcs of electricity dance across the"+
		" handguard of the rapier.");
	ETO->add_attack_bonus(2);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^A loud pop emits "+
		"from the rapier as "+ETO->QCN+" releases the blade",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^A loud pop emits from the "+
		"rapier as you release the blade");
	ETO->add_attack_bonus(-2);
	return 1;
}

int hit_func(object targ){
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	if(random(1000) < 200){
      	switch(random(10)){
	case 0..6:
    		tell_room(environment(query_wielded()),"%^YELLOW%^With a"+
			" loud %^CYAN%^POP%^YELLOW%^, "+ETO->QCN+"'s blade releases"+
			" an electrical charge into "+targ->QCN+"",({ETO,targ}));
		tell_object(ETO,"%^YELLOW%^From the handguard, an electrical charge"+
			" travels up the blade and into "+targ->QCN+".");
		tell_object(targ,"%^YELLOW%^With a loud %^CYAN%^POP%^YELLOW%^, "+
			""+ETO->QCN+"'s blade releases an electrical charge "+
			"into you!\nOUCH!!!");
				return roll_dice(3,4)+1;
	break;	
	case 7..9:
		tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETO->QCN+" moves "+
			"with the swiftness of lighting, landing quick jabs onto"+
			" "+targ->QCN+".",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^CYAN%^You feel a "+
			"burst of speed flow through you, speeding up your "+
			"attacks for one brief moment.");
		tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->QCN+" moves with the swiftness"+
			" of lighting, tearing into you with a series of lighting "+
			"quick strikes.");
				ETO->execute_attack();
	break;
		}
	return 1;
	}
}
