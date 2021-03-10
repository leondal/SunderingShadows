//Updated to inherit from hide, since it says that it's hide armor in the description, also set to lvl 20 wear to match updated enchantment requirements - Octothorpe 6/19/09
#include <std.h>
inherit "/d/common/obj/armour/hide.c";

void create(){
	::create();
	set_name("%^RESET%^%^MAGENTA%^purple hide armor%^RESET%^");
	set_id(({"purple hide","Purple Worm Hide", "leather shirt","leather","hide"}));
	set_short("%^RESET%^%^MAGENTA%^P%^BOLD%^u"+
		"%^BLUE%^r%^RESET%^%^MAGENTA%^p%^BOLD%^l%^BLUE%^e "+
		"%^RESET%^%^MAGENTA%^Worm Hide%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^A purple hide armor%^RESET%^");
	set_long("%^RESET%^%^MAGENTA%^Shaped out of a purple hide, "+
		"this armor looks thick and protective.  The supple "+
		"purple hide still retains a glossy luster to it.  "+
		"The breastplate is made more like a shirt than a "+
		"traditional leather armor with buckles.  Long, "+
		"lean sleeves made from the purple hide hug the "+
		"wearer's arms while the body of the hide molds to"+
		" the wearer's torso.  The lower edges of the purple"+
		" hide is left unfinished, creating a tattered look."+
		"  A high neckline wraps around the wearer's neck, "+
		"granting additional protection. %^RESET%^");
	set_lore("The fey'ri of Argentrock have found a use for "+
		"the purple worms that live on the island.  Scouting"+
		" parties hunt down these massive creatures just for "+
		"their hides, which the fey'ri claims grants them a "+
		"hightened immunity to magical effects.  The fey'ri "+
		"have hunted the purple worms into near extintion on "+
		"Argentrock to have robes, gloves, boots, and armor "+
		"made from the supple but tough hide.");
	set_property("lore",12);
	set_value(3000);
	set_property("enchantment",4);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme(){
     if((int)ETO->query_highest_level() < 20) {
        tell_object(ETO,"The armor doesn't fit you!");
        return 0;
     }
		tell_object(ETO,"%^MAGENTA%^You pull on the tight fitting "+
			"purple hide armor, feeling well protected from almost"+
			" any attack.");
		return 1;
}

int removeme(){
	tell_object(ETO,"%^MAGENTA%^You feel naked and vulnerable as you"+
		" pull off the purple hide.");
	return 1;
}
