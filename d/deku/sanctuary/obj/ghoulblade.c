//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create(){
	::create();
	set_name("Vampire's Fang");
	set_id(({ "dagger", "blade", "weapon", "vampire's fang", "fang" }));
	set_short("%^BOLD%^%^BLACK%^Vampire's Fang%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A dark dagger%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This dagger is wrought from a "+
		"mysterious dark metal. The blade is somewhat %^RED%^"+
		"%^BOLD%^%^BLACK%^stained and %^RESET%^%^ORANGE%^corroded"+
		"%^BOLD%^%^BLACK%^ as if it has not been taken cared of "+
		"very well for some unknown length of time. The %^WHITE%^"+
		"bone %^BOLD%^%^BLACK%^hilt, carved in the likeness of "+
		"skeletal fingers, has now aged to a dull %^YELLOW%^yellow"+
		" %^BLACK%^color.\n");
//        set_weight(3);  // let the inherit set it now
	set_value(233);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^'Forged from the fang of a giant vampire and enchanted with the spirits of the wandering ghouls are all words that describe these daggers of shadows. 
AVATAR
	);
	set_property("lore",9);
/* let the base file set these now too per bug reports of such a high discern
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
        set_wc(2,4);
        set_large_wc(2,4);
*/
        set_property("enchantment",3+random(2));  // increase to offset lowering the discern
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" grabs the dagger "+
		"and blinks a few times.%^RESET%^",TP);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You grab the dagger by the hilt and"+
		" feel something briefly intrude into your consciousness.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" releases the dagger and "+
		"blinks a few times.%^RESET%^",TP);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You release the dagger and the "+
		"presence in your mind disappears.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	if(random(1000) < 300){
      	switch(random(10)){
	case 0..4:
		tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" "+
			"stabs the dagger deeply into "+ETO->QP+" victim.%^RESET%^",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^BLACK%^You stab the dagger deeply into"+
			" your victim.%^RESET%^");
		tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" stabs the dagger deeply"+
			" into you.%^RESET%^");
				return roll_dice(2,3)+2;
	break;
	case 5..7:
		tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Crackling bands of negative"+
			" energy surround "+ETO->QCN+"'s dagger.",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^BLACK%^Crackling bands of negative energy "+
			"surround your dagger for one brief moment.%^RESET%^");
		tell_object(targ,"%^BOLD%^%^BLACK%^The negative energy around "+
			""+ETO->QCN+"'s dagger chills strikes out at your lifeforce!%^RESET%^");
				return roll_dice(2,4)+2;
	break;
	case 8..9:
		tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" jams "+ETO->QP+" dagger"+
			" deep into "+targ->QCN+"'s neck, laughing wildly as the dagger "+
			"feeds on the blood.",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^BLACK%^You jam the dagger deep into"+
			" "+targ->QCN+"'s neck, laughing gleefully as the blade feasts"+
			" on the blood.%^RESET%^");
		tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" jams "+ETO->QP+" dagger"+
			" into your neck, laughing wildly as the blade feasts on your "+
			"blood!%^RESET%^");
				return roll_dice(4,3)+3;
	break;
		}
	return 1;
      }
}