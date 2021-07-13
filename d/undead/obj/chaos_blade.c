#include <std.h>
#include "../undead.h"

inherit CWEAP"bastard.c";

void create() 
{
    ::create();
    set_id(({"sword","bastard sword","black sword","chaos blade","blade"}));
    set_name("Chaos Blade");    
    set_obvious_short("%^BOLD%^%^BLACK%^a shimmering black bladed sword%^RESET%^");
    set_short("%^RESET%^%^BOLD%^%^GREEN%^Ch%^BLACK%^a%^GREEN%^os %^BLUE%^B%^GREEN%^lade%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^The blade of this sword seems to be made "
        "of nothing at all, or even the absence of anything.  It looks like "
        "a shimmering rift in the planes themselves, a small shard of "
        "nothingness that shimmers as its shape constantly undergoes subtle "
        "changes.  The rift that serves as a blade is almost four inches wide "
        "and about three feet in length, but not as heavy as a metal blade "
        "of the same size would be.%^RESET%^");

    set_lore("%^BOLD%^%^WHITE%^Rumors tell of a ancient warrior who long "
        "ago traveled to the plane of limbo in search of a blade which "
        "was capable of defeating the death knight that had killed his "
        "father in battle.  The warrior was chaotic of heart, unable to "
        "control and focus his thoughts, and the plane of limbo itself "
        "is known to meld itself to what is in the mind of those who are "
        "on it.  So chaotic was the warrior's heart, that a great rift "
        "opened on the plane of limbo, a tear in the fabric of the world "
        "that lead through to the plane of chaos.  The warrior saw that "
        "rift as the weapon he was looking for, and his mind tore a fragment "
        "of it away.  That fragment was said to be forged into a powerful "
        "sword, the %^RESET%^%^GREEN%^Chaos Blade%^RESET%^%^BOLD%^%^WHITE%^");
    
    set_property("lore difficulty",25);
    set_value(2500);
    set_property("enchantment",3);
    set_weight(3);
    set_type("slashing");

    set_hit((:TO,"hitme":));
    set_wield((:TO,"wieldme":));
    set_unwield((:TO,"unwieldme":));

}

int wieldme()
{

    if(!random(1000)) 
    {
        tell_object(ETO,"The sword decides that it has served you "
            "for long enough and disappears!");
        TO->remove();
        return 0;
    }

	switch(TP->query_alignment())
    {
	    case 1: 
        case 2: 
        case 3:
		    tell_object(ETO,"%^RED%^The sword refuses your hand and collapses "
                "in on itself with a violent implosion!");
		    tell_room(EETO,"The sword carried by "+ETO->QCN+" suddenly collapses "
                "in on itself with a voilent implosion!",ETO);
		    TO->set_property("magic",1);
            ETO->do_damage("left hand",roll_dice(3,6));
            TO->set_property("magic",-1);
            TO->remove();
		    return 0;	        
	    case 4: 
        case 5: 
        case 6:
		    tell_object(ETO,"%^YELLOW%^You feel drained as you grip the handle "
                "to the blade.");
		    tell_room(EETO,""+ETO->QCN+" looks tired as "+ETO->QP+" grips "
                "the shimmering weapon.",ETO);
		    TO->set_property("magic",1);
            ETO->do_damage("left hand",roll_dice(1,4));
            TO->set_property("magic",-1);
   		    TO->set_wc(1,3);
   		    TO->set_large_wc(1,2);
		    return 1;
	
	    case 7: 
        case 8: 
        case 9:		
		    tell_object(ETO,"%^BOLD%^%^GREEN%^You can feel the chaos in the "
                "blade feeding your own soul, making you stronger!");
		    tell_room(EETO,""+ETO->QCN+"'s eyes flash a sudden wild green color "
                "as "+ETO->QS+" grips the blade!",ETO);
   		    TO->set_wc(2,6);
   		    TO->set_large_wc(3,6);
		    return 1;
	    
        default: 
            return 1;
	}

	return 1;
}

int unwieldme()
{
    if(!objectp(ETO) || !interactive(ETO)) { return 1; }

	switch((int)TP->query_alignment())
    {
	    case 1: 
        case 2: 
        case 3:

            return 1;
            
	    case 4: 
        case 5: 
        case 6:
		    tell_object(ETO,"%^YELLOW%^You breathe a sigh of relief after "
                "you release the blade");
		    tell_room(EETO,""+ETO->QCN+" breathes a sigh of relief as "+ETO->QP+" "
                "releases the weapon.",ETO);
   		    TO->set_wc(1,8);
   		    TO->set_large_wc(1,12);
		    return 1;
	
	    case 7: 
        case 8: 
        case 9:		
		    tell_object(ETO,"%^BOLD%^%^GREEN%^You long for the comforting presense "
                "of the blade almost as soon as it leaves your grasp!");
		    tell_room(EETO,""+ETO->QCN+" releases the blade with a wistful sigh",ETO);
   		    TO->set_wc(1,8);
   		    TO->set_large_wc(1,12);
		    return 1;
	    
        default: 
            return 1;
	}

	return 1;
}


int hitme(object targ)
{
    if(!objectp(targ)) return 0;
    if(!objectp(ETO)) return 0;

    if(random(1000) > 750)
    {

	    switch(ETO->query_alignment())
        {
	        case 1: 
            case 2: 
            case 3:

                return 0;
            
	        case 4: 
            case 5: 
            case 6:

                tell_object(ETO,"%^BOLD%^You can feel a sudden surge of "
                    "energy as your blade slips between "+targ->QCN+"'s ribs.\n"
                    "%^RED%^A wrenching pain twists your own insides as the blade "
                    "transfers the pain of the wound back into you!%^RESET%^");
                tell_object(targ,"%^BOLD%^You feel a sudden pain as "+ETO->QCN+" jabs "
                    ""+ETO->QP+" sword between your ribs!\n%^RES%^Suddenly "+ETO->QCN+" screams "
                    "in pain as if the attack hurt "+ETO->QS+" too!%^RESET%^");
                tell_room(EETO,"%^BOLD%^"+ETO->QCN+" quickly slips "+ETO->QP+" sword "
                    "between "+targ->QCN+"'s ribs and they both suddenly cry out in "
                    "pain!%^RESET%^",({ETO,targ}));
                TO->set_property("magic", 1);
                targ->do_damage("torso",roll_dice(2,6));
                ETO->do_damage("torso",roll_dice(2,6));
                TO->set_property("magic", -1);
                return 0;
	
	        case 7: 
            case 8: 
            case 9:		

	            switch(targ->query_alignment())
                {
	                case 1: 
                    case 2: 
                    case 3:

                        tell_object(ETO,"%^BOLD%^%^GREEN%^The sword gleams with an angry light "
                            "as you strike "+targ->QCN+"!%^RESET%^");
                        tell_object(targ,"%^BOLD%^%^GREEN%^The sword wielded by "+ETO->QCN+" "
                            "gleams with an angry light as it strikes you!%^RESET%^");                    
                        tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+"'s sword gleams with an "
                            "angry light as "+ETO->QS+" strikes "+targ->QCN+"!%^RESET%^",({ETO,targ}));                    
                        TO->set_property("magic", 1);
                        targ->do_damage(targ->return_limb(),roll_dice(3,8));
                        TO->set_property("magic", -1);
                        return 1;

	                case 4: 
                    case 5: 
                    case 6:

                        tell_object(ETO,"%^CYAN%^You send a lightning strike quickly through "
                            ""+targ->QCN+"'s defences and strike a vulnerable spot!%^RESET%^");                    
                        tell_object(targ,"%^CYAN%^"+ETO->QCN+" sends a lightly strike in towards "
                            "you, slipping through your defences and scoring a painful "
                            "hit!%^RESET%^");                    
                        tell_room(EETO,"%^CYAN%^"+ETO->QCN+" sends a lightning strike towards "
                            ""+targ->QCN+", slipping through "+targ->QP+" defences and "
                            "scoring a painful hit!%^RESET%^",({ETO,targ}));                    
                        TO->set_property("magic", 1);
                        targ->do_damage(targ->return_limb(),roll_dice(2,6));
                        TO->set_property("magic", -1);
                        return 1;

	                case 7: 
                    case 8: 
                    case 9:	

                        tell_object(ETO,"%^BOLD%^You can feel a sudden surge of "
                            "energy as your blade slips between "+targ->QCN+"'s ribs.\n"
                            "%^RED%^A wrenching pain twists your own insides as the blade "
                            "transfers the pain of the wound back into you!%^RESET%^");
                        tell_object(targ,"%^BOLD%^You feel a sudden pain as "+ETO->QCN+" jabs "
                            ""+ETO->QP+" sword between your ribs!\n%^RES%^Suddenly "+ETO->QCN+" screams "
                            "in pain as if the attack hurt "+ETO->QS+" too!%^RESET%^");
                        tell_room(EETO,"%^BOLD%^"+ETO->QCN+" quickly slips "+ETO->QP+" sword "
                            "between "+targ->QCN+"'s ribs and they both suddenly cry out in "
                            "pain!%^RESET%^",({ETO,targ}));
                        TO->set_property("magic", 1);
                        targ->do_damage("torso",roll_dice(2,6));
                        ETO->do_damage("torso",roll_dice(2,6));
                        TO->set_property("magic", -1);
                        return 1;
                    default:
                        return 1;
                }
	    

            default: 
                return 1;
        }

    }

return 1;

}
