//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword.c";

void create(){
	::create();
	set_name("coral sword");
	set_id(({ "coral sword", "sword", "weapon", "coral" }));
	set_short("%^RESET%^%^ORANGE%^C%^BOLD%^%^MAGENTA%^o"+
		"%^RESET%^%^ORANGE%^r%^BOLD%^%^MAGENTA%^a%^RESET%^"+
		"%^ORANGE%^l %^YELLOW%^Sword%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A large sword made"+
		" of c%^BOLD%^%^MAGENTA%^o%^RESET%^%^ORANGE%^r"+
		"%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^l%^RESET%^");
	set_long("%^ORANGE%^C%^BOLD%^%^MAGENTA%^o%^RESET%^%^ORANGE%^r"+
		"%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^l has been shaped "+
		"and twisted to form this great blade. The blade, hilt and all,"+
		" is about five feet in length. Everything from the hilt to the "+
		"blade to the pommel is made out of coral. It almost seems as if"+
		" the blade was shaped out of the material instead of being crafted"+
		" from it. The double blade has been sharpened to a fine edge.\n%^RESET%^");
	set_value(1500);
	set_lore(
@AVATAR
The Coral Sword was first said to have come from the creatures that inhabit the lands below the seas. Where and who first brought it to the lands it is hard to say. The clergy of Istishia claim one of their own found the item though so do many numerous pirates and fishermen.

AVATAR
	);
	set_property("lore",8);
	set_property("enchantment",3+random(2));
      set_item_bonus("attack bonus",1);
      set_item_bonus("damage bonus",1);
      set_item_bonus("armor class",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BOLD%^%^MAGENTA%^"+ETO->QCN+" gives a few practice swings of "+ETO->QP+" large coral sword.",TP);
	tell_object(TP,"%^BOLD%^%^MAGENTA%^You heft up the blade and marvel at how well balanced it is.");
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^ORANGE%^"+ETO->QCN+" unwields the large sword made from coral.",TP);
	tell_object(TP,"%^ORANGE%^You release your hold of the coral sword.");
	return 1;
}
int hit_func(object targ){
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	if(random(1000) < 300){
      	switch(random(10)){
	case 0..6:
		tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^A mist suddenly "+
			"envelopes "+ETO->QCN+"'s blade just meer moments before"+
			" slashing into "+targ->QCN+"",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^MAGENTA%^Steam rises from within the coral,"+
			" cloaking the blade in a steaming mist just before you slash"+
			" into "+targ->QCN+"");
		tell_object(targ,"%^BOLD%^%^MAGENTA%^A mist suddenly envelopes "+
			""+ETO->QCN+"'s blade just meer moments before slashing "+
			"into you!");
				return roll_dice(2,4)+2;
	break;
	case 7..9:
		tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+" hacks into"+
			" "+targ->QCN+", the coral blade cutting cleanly and"+
			" smoothly into "+targ->QO+"",({ETO,targ}));
		tell_object(ETO,"%^ORANGE%^You hack into "+targ->QCN+" with a clean and smooth blow.");
		tell_object(targ,"%^ORANGE%^"+ETO->QCN+" hacks into you, the coral"+
			" blade slicing cleanly and smoothly through your flesh!");
				return roll_dice(3,3)+5;
	break;
		}
	return 1;
	}
}