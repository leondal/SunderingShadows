//Changed over to inherit /claw.c - Cythera 4/05
#include <std.h>

inherit "/d/common/obj/weapon/claw.c";

void create(){
   	::create();
	set_name("jade claws");
   	set_id(({"jade claws","claws","weapon","tiger claws","brace","claw"}));
   	set_obvious_short("%^YELLOW%^A pair of %^GREEN%^jade"+
		"%^YELLOW%^ claws%^RESET%^");
   	set_short("%^RESET%^%^GREEN%^J%^BOLD%^ade %^YELLOW%^"+
		"Tiger %^RESET%^%^GREEN%^Cl%^BOLD%^aw%^RESET%^%^GREEN%^s%^RESET%^");
   	set_long("%^GREEN%^Three long sharp claws made from "+
		"%^BOLD%^jade %^RESET%^%^GREEN%^jut out of a %^YELLOW%^yellow"+
		" gold%^RESET%^%^GREEN%^ brace.  The %^YELLOW%^gold brace"+
		"%^RESET%^%^GREEN%^ covers the back of the hand and wrist of"+
		" the wearer, with golden leather straps used to tighten the fit."+	
		"  Engraved into the gold metal is the image of a %^YELLOW%^tiger"+
		"%^RESET%^%^GREEN%^ looking ready to strike.  Flecks of %^BOLD%^"+
		"jade%^RESET%^%^GREEN%^ are used for the tiger's eyes giving "+
		"the great cat a lifelike appearance.  The %^BOLD%^jade claws"+
		"%^RESET%^%^GREEN%^ rise out six inches, tapering to a fine "+
		"point.  The inside of the claws have been sharpened, "+
		"allowing the wielder to either pierce or slash their target.%^RESET%^\n");
   	set_lore("In The Two Faced Rakshasa, Rjarek must fight between his"+
		" past life and the future that he desires."+
		" In an act of redemption, Rjarek offered his life to save a "+
		"priestess of Mielikki.  The Goddess was so pleased"+
		" with his selfless act that she transformed the claws on his hands"+
		" to pure jade claws.  The play was a critical"+
		" and professional failure because to many people found it hard to "+
		"be sympathetic to a monstrous creature like"+
		" Rjarek.  That and lines that could have been better written by a"+
		" drunk child. -  Lemons and Limes - A History"+
		" of Failed Plays - Devin Igarn");
   	set_property("lore difficulty",13);
     set_property("enchantment",2);
	set_item_bonus("sight bonus",1);
        set_value(800);
   	set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
   	set_hit((:TO,"hit_func":));
}
int wield_func(string str) {
     if((int)ETO->query_lowest_level() < 14) {
      	tell_object(ETO,"%^BOLD%^%^GREEN%^You fumble with the claws"+
			" but can't figure out how to use them.%^RESET%^");
      		return 0;
}
   	tell_object(ETO,"%^BOLD%^%^GREEN%^You strap the gold brace"+
		" onto your forearm.  The jade claws start to"+
		"%^YELLOW%^ g%^GREEN%^l%^YELLOW%^o%^GREEN%^w. %^RESET%^");
   	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" straps"+
		" on a gold brace to "+ETO->QP+" forearm, the jade"+
		" claws start to %^YELLOW%^g%^GREEN%^l%^YELLOW%^o%^GREEN%^w."+
		"%^RESET%^",ETO);
    		return 1;
}
int unwield_func(string str) {
  	tell_object(ETO,"%^GREEN%^The jade claws cease to glow as"+
		" you unbuckle the brace");
   	tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+"'s "+
      	"claws cease to glow as "+ETO->QS+" unbuckle the gold brace.",ETO);
    		return 1;
}

int hit_func(object victim) 
{
   	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(victim)) return 1;
    	
    if(random(1000) < 150)
    {
        switch(random(15))
        {

        case 0..12:
            tell_object(ETO,"%^BOLD%^%^GREEN%^The jade claws glow brightly"+
                ", allowing you to slice"+
                " through "+victim->QCN+"'s defenses with ease.");
            tell_object(victim,"%^BOLD%^%^GREEN%^"+ETO->QCN+" slices through "+
                    "your defenses, "+ETO->QP+" jade claws glowing brightly!",);
            tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+" slices"+
                " through "+victim->QCN+"'s defenses, "+ETO->QP+" jade claws "+
                "glowing brightly.",({ETO,victim}));
                  return roll_dice(2,4)+2;
            break;
        
        case 13..14:
            tell_object(ETO,"%^BOLD%^%^GREEN%^You swipe at "+
                ""+victim->QCN+" ripping into them with the ferocity of a tiger.");
            tell_object(victim,"%^BOLD%^%^GREEN%^"+ETO->QCN+" swipes at "+
                    "you, "+ETO->QP+" claws sinking deep into your flesh before"+
                " they jerk them out.",);
            tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+" swipes at "+
                ""+victim->QCN+", striking with the ferocity of a"+
                " tiger.",({ETO,victim}));
                  return roll_dice(3,4)+3;
            break;

        default:  
            break;
		}
    return 1;
	}
}
