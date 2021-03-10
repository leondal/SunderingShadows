//Changed to type clothing 10/21/03 by Circe.  If they are type ring, you can wear multiples
//Coded by Bane//
//Added new desc, lore, color, and raised the price a bit Cythera 3/27/05
#include <std.h>

inherit ARMOUR;

int uses;


void create(){
 	::create();
   	set_obvious_short("%^BOLD%^%^WHITE%^A jeweled bracelet%^RESET%^");
   	set_id(({"bracelet","trinket","jeweled bracelet","bracelet of protection"}));
   	set_name("bracelet of protection");
    	set_short("%^BOLD%^%^WHITE%^Bracelet of %^BOLD%^%^WHITE%^P%^RESET%^"+
		"%^MAGENTA%^r%^BOLD%^%^BLUE%^o%^GREEN%^t%^BOLD%^"+
		"%^WHITE%^e%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLUE%^t"+
		"%^GREEN%^i%^BOLD%^%^WHITE%^o%^RESET%^%^MAGENTA%^n%^RESET%^");
        set_property("repairtype",({ "jewel" }));
        set_long("%^BOLD%^%^WHITE%^Threaded on the silver linked chain"+
		" are nine small gemstones, forming the base of this bracelet."+
		"  Each round gemstone is wrapped in a silver casing and left"+
		" to dangle freely.  The most striking of the gems is the "+
		"larger %^BOLD%^%^BLUE%^st%^WHITE%^a%^BLUE%^r sapphire%^WHITE%^"+
		" set in the center.  To the left of the star sapphire four "+
		"polished orbs of %^RESET%^%^MAGENTA%^alexandrite%^BOLD%^%^WHITE%^"+
		" circle around the bracelet.  To the right of the star sapphire"+
		" are four square cut %^GREEN%^peridot%^WHITE%^ gems, spaced evenly."+
		"  The bracelet has a claw clasp that sort of resembles the claw of"+
		" a lobster.\n%^RESET%^");
   	set_lore("The Bracelets of Protection were first crafted by the Brotherhood"+
		" of the Sixteen Sigils, an order of mages specialized in "+
		"conjuration/summoning and transmutation.  The Brotherhood was"+
		" able to become very rich from the useful magical items and "+
		"trinkets that they created.  With their newfound wealth, the"+
		" Brotherhood was able to devote more energy and time to the "+
		"study of magic.  Though after one of their experiments released"+
		" a Balor in the city of Asgard, the Brotherhood was force to "+
		"disband under threat of death.");	
	set_property("lore difficulty",9);
//   	set_type("ring"); Changed to stop stacking
    	set_type("clothing");
    	set_ac(0);
    	set_property("enchantment",2);
	set_item_bonus("magic resistance",2);
	set_limbs(({"right arm","left arm"}));
    	set_weight(5);
    	set_value(3000);
    	set_wear((:TO,"wear_me":));
    	set_remove((:TO,"remove_me":));
}
int wear_me(){
    	if(uses < 11){
    		write("%^BOLD%^%^WHITE%^You feel a radiant glow bathe your body.");
    			uses += 1;
    	return 1;
    	} else {
    		write("%^MAGENTA%^The bracelet is out of magic.");
    			TO->remove();
    }
}
int remove_me(){
    	write("%^BOLD%^%^BLUE%^You feel the glow seep from your veins.");
    	return 1;
}
