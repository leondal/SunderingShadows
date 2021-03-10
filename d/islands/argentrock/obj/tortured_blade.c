//Based on Crystal's Diamond Cutlass
#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create(){
	::create();
	set_name("blade of the tortured soul");
	set_short("%^BOLD%^%^BLACK%^Blade of the %^BOLD%^%^BLUE%"+
		"^T%^RESET%^%^CYAN%^or%^BOLD%^t%^RESET%^%^CYAN%^"+
		"ur%^BLUE%^e%^RESET%^%^CYAN%^d Soul%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A black sapphire short sword%^RESET%^");
	set_id(({"sword","short sword","blade","blade of the tortured soul","sapphire sword"}));
	set_long("%^BOLD%^%^BLACK%^Crafted from a %^RESET%^%^BLUE%^"+
		"b%^BOLD%^%^BLACK%^la%^RESET%^%^BLUE%^c%^BOLD%^%^BLACK%^k"+
		" %^CYAN%^s%^BOLD%^a%^BLUE%^p%^RESET%^%^BLUE%^p%^CYAN%^h"+
		"%^BOLD%^i%^BLUE%^r%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^. "+
		"Its blade is slightly broader than is usual and has a "+
		"barely visible %^CYAN%^leaf curve%^BOLD%^%^BLACK%^ "+
		"coming to a sharp point. Opposing the tip is the hilt "+
		"of simple design crossguard with %^BLUE%^quillons "+
		"%^BOLD%^%^BLACK%^projecting about an inch to each side "+
		"and bending towards the blade. The grip is wrapped in a "+
		"rare %^CYAN%^s%^BLUE%^a%^RESET%^%^BLUE%^p%^CYAN%^p%^BOLD%^"+
		"h%^BLUE%^i%^RESET%^%^BLUE%^r%^CYAN%^e%^BOLD%^%^BLACK%^ "+
		"colored dragon skin. In the center of the crossguard, on "+
		"both sides of the blade, are set two oval discs of jet.");
	set_lore("Crafted from the tortured souls of the elves, these blades "+
            "epitomise the wickedness and cruelty of the fey'ri.  Entrapping "+
            "the very kin that once cast them out, the art used in forging these "+
            "cruel blades was long ago stolen from the demons they enslaved "+
            "in their subjugation of Argentrock.  Some rare blades are said to "+
		"contain the essence of demons instead of the souls of elves.  "+
		"Whatever the case, the fey'ri have come to favor this blade "+
		"above most others.");
	set_property("enchantment",4);
	set_item_bonus("caster level",1);
	set_hit((:TO, "hitme":));
	set_value(2000);set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
     if((int)ETO->query_lowest_level() < 30) {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^The sword resists your grasp!");
     	return 0;
	}
   		tell_object(ETO,"%^BOLD%^%^BLACK%^A chilling but soft moan echoes"+
		" from the blade.");
     return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^BOLD%^%^BLACK%^Another chilling but faint moan echoes"+
		" as you release the sword.");
      return 1;
}

int hitme(object targ){
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	
    if(random(1000) < 230)
    {
        switch(random(36))
        {
        case 0..20:
            tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+""+
                " grins with a wicked smirk as "+ETO->QP+" blade"+
                " slices into "+targ->QCN+".",({ETO,targ}));
            tell_object(ETO,"%^CYAN%^You grin a wicked smirk as you"+
                " slice deeply into "+targ->QCN+".");
            tell_object(targ,"%^CYAN%^"+ETO->QCN+" grins a wicked "+
                "smirk as "+ETO->QP+" blade down,"+
                " slicing deeply into your flesh.");
                    targ->do_damage("torso",random(8)+5);
            break;
        case 21..31:
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
                " gets a burst of speed and dodges under"+
                " "+targ->QCN+"'s guard, plunges "+
                " "+ETO->QP+" blade hard into "+targ->QP+""+
                " chest.",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^You get a burst of speed and dodge"+
                " under "+targ->QCN+"'s guard, plunging your "+
                "blade deep into "+targ->QP+" chest.");
            tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" speeds"+
                " up suddenly and dodges under your guard, "+
                "plunging "+ETO->QP+" sword"+
                "deep into your chest.");
                    ETO->execute_attack();
            break;
        case 32..35:
            tell_room(environment(ETO),"%^BLUE%^"+ETO->QCN+""+
                " circles behind "+targ->QCN+" and slams "+ETO->QP+" "+
                "blade into "+targ->QP+"'s back.",({ETO,targ}));
            tell_object(ETO,"%^BLUE%^You circle behind "+targ->QCN+" and "+
                "slam your blade into "+targ->QP+" back.");
            tell_object(targ,"%^BLUE%^"+ETO->QCN+""+
                " circles behind you and slams "+ETO->QP+" "+
                "blade into your back.");
                    set_property("magic",1);
                    targ->do_damage("torso",random(10)+10);
                                    targ->set_paralyzed(random(3)+1,"You are still twitching from the painful blow.");
                    remove_property("magic");
            break;
        

        default:  
            tell_object(ETO,"Well now you've done it! :) Please bug"+
                " this and include what you were doing/fighting when you got"+
                " this message.");
            break;
		}
    return 1;
	}
}
