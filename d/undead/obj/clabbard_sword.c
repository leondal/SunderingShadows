//updated by Circe 11/20/04 with new desc & lore
#include <std.h>
#include "../undead.h"

inherit CWEAP"two_hand_sword.c";

void create() 
{
    ::create();
    set_name("clabbard");
    set_id(({"sword","clabbard","clabbard sword","two-handed sword","broadsword"}));
    set_short("%^BLUE%^Clabbard sword%^RESET%^");
	set_obvious_short("a massive two-handed sword");

	set_long("%^MAGENTA%^This massive sword features a blade that "+
	    "reaches over six feet in length.  The smooth cutting edge "+
        "of the blade is balanced on the opposite side with a wicked "+
        "serrated edge.  A deep, slender blood groove runs the "+
        "length of the blade, making the sword ease from a wound "+
        "with no resistence.  The hilt is sized for larger "+
        "hands, making this sword almost too large for a human to "+
        "wield.%^RESET%^");

	set_lore("The clabbard sword is said to be the legendary "+
        "blade of the mythical minotaur.  Sages agree that such "+
        "a creature does indeed exist, though number and location "+
        "of such creatures is a matter long debated.  The most "+
        "trusted lore, however, places a minotaur deep within a "+
        "maze - though none can say if that is meant as protection "+
        "for the creature...or for the rest of the world.");

    set_property("lore difficulty",7);
	set_value(1500);
	set_property("enchantment",3);
	set_hit((:TO, "extra_hit":));
	set_wield((:TO, "extra_wield":));
}

int extra_hit(object targ) 
{
    if(!objectp(targ)) return 0;
    if(!objectp(ETO)) return 0;
    
    if(random(1000) > 750)
    {
        switch(random(3))
        {
            case 0..1:          
            tell_object(ETO,"%^BOLD%^%^RED%^The sword's serrated edge plunges deep into the body "
                "of "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^RED%^The sword wielded by "+ETO->QCN+" glistens as it "
                "slices into your flesh!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^RED%^The sword wielded by "+ETO->QCN+" tears "
                "at "+targ->QCN+"'s flesh!%^RESET%^",(({ETO, targ})));
            ETO->set_property("magic",1);
            targ->do_damage(targ->return_limb(),roll_dice(2,6));
            ETO->set_property("magic",-1);
            if(random(5)) { break; }//intentionally has 2 specials approx 5% of hits        
            case 2:
            tell_object(ETO,"%^BOLD%^Your Clabbard blade rips away the tendons and flesh "
                "%^BOLD%^of "+targ->QCN+" as you pull it out of "+targ->QP+" gut!%^RESET%^");
            tell_object(targ,"%^BOLD%^The Clabbard sword wielded by "+ETO->QCN+" rips away "
                "at your flesh as it is pulled from your gut!%^RESET%^");
            tell_room(EETO,"%^BOLD%^The sword wielded by "+ETO->QCN+" spouts blood "
                "as it is withdrawen from "+targ->QCN+"'s flesh!%^RESET%^",(({ETO, targ})));
            ETO->set_property("magic",1);
            targ->do_damage(targ->return_limb(),roll_dice(3,8));
            ETO->set_property("magic",-1);
            break;
        }
    }

    return 1;
}

int extra_wield() 
{
    if((int)ETO->query_lowest_level() < 20) 
    {
        tell_object(ETO,"You may not wield such a fine weapon!");
        return 0;
    }      
    tell_object(ETO,"%^BLUE%^You wield the Clabbard sword and its strength becomes "
        "yours to command!%^RESET%^");
    tell_room(EETO,"%^BLUE%^"+ETO->query_cap_name()+" wields a giant Clabbard blade.%^RESET%^",ETO);
    return 1;
}
