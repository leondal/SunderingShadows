#include <std.h>
inherit "/d/common/obj/weapon/scimitar";


void create() 
{
    ::create();
    set_name("gleaming scimitar");

    set_id(({"scimitar", "gleaming scimitar", "vanity"}));
	
    set_obvious_short("%^BOLD%^%^WHITE%^A gleaming "+
    "bone scimitar%^RESET%^");
		
    set_short("%^BOLD%^%^YELLOW%^V%^RESET%^%^ORANGE%^"+
    "a%^BOLD%^%^YELLOW%^n%^RESET%^%^ORANGE%^i"+
    "%^BOLD%^%^YELLOW%^t%^RESET%^%^ORANGE%^y%^RESET%^");
	
    set_long("%^BOLD%^%^WHITE%^The blade of this scimitar "+
    "is made from a wide, thick bone %^BOLD%^%^RED%^"+
    "fragment%^BOLD%^%^WHITE%^. The fragment has been "+
    "carved so that the end of it curves backward "+
    "dramatically. It has been polished to the point "+
    "that it reflects all visible light and "+
    "upon gazing into it your reflection looks "+
    "%^BOLD%^%^CYAN%^flawless%^BOLD%^%^WHITE%^"+
    "! The hilt is in the shape of a "+
    "%^BOLD%^%^BLACK%^s%^BOLD%^%^RED%^p"+
    "%^BOLD%^%^BLACK%^i%^BOLD%^%^RED%^d"+
    "%^BOLD%^%^BLACK%^e%^BOLD%^%^RED%^r "+
    "%^BOLD%^%^WHITE%^with all eight legs bent so that they "+
    "are extended toward the handle. "+
    "The handle is larger than normal and "+
    "made from %^RESET%^%^ORANGE%^leather "+
    "%^BOLD%^%^WHITE%^wrapped tightly "+
    "around the end of the bone fragment, which "+
    "juts out from the bottom of the handle. "+
    "The entire weapon is light and almost "+
    "feels as if it is hollow. It is exceptionally "+
    "strong and durable despite the material "+
    "from which is crafted.%^RESET%^");

    set_weight(2);
    set_value(3000);
    set_property("lore difficulty", 15);

    set_lore("%^BOLD%^%^WHITE%^The smith who "+
    "forged this scimitar has been long forgotten. "+
    "It was thought to have been a gift to the spider "+
    "queen Ahyriquel in an attempt to appease her mighty "+
    "vanity. It is unknown whether or not the "+
    "attempt was successful as the weapon and the "+
    "queen have not been seen in a long time. "+
    "It is said to increase not only the vanity "+
    "of whoever might hold it but to cast a "+
    "favorable light on the way others view "+
    "them as well.%^RESET%^");

    set_property("enchantment",2);

    set_item_bonus("charisma", 1);

    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"special":));
}

int wield_me()
{
    tell_object(ETO, "%^BOLD%^%^YELLOW%^You feel "+
    "your own vanity increase as you "+
    "take hold of the scimitar!%^RESET%^");
    return 1;
}

int unwield_me()
{
    tell_object(ETO, "%^BOLD%^%^YELLOW%^Suprisingly "+	
    "you feel less vain as you release your grip "+
    "on the scimitar!%^RESET%^");
    return 1;
}

int special(object targ) 
{
    string tlim, amt;
    int dam, bolts;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(100) < 75) return 0;
    tlim = targ->return_target_limb();
    switch(random(16)) 
    {
        case 0..4:
            bolts = 1;
            break;		
        case 5..8:
            bolts = 2;
            amt = "Two";
            break;
        case 9:
            bolts = 3;
            amt = "Three";
            break;	
        case 10..15:

            tell_object(ETO, "%^RESET%^%^ORANGE%^You find the "+
            "opportune moment and stab the %^BOLD%^%^RED%^"+
            "bone fragment%^RESET%^%^ORANGE%^ protruding "+
            "from the end of your scimitar handle "+
            "into "+targ->QCN+"%^RESET%^%^ORANGE%^'s "+
            tlim+"!%^RESET%^");
	
            tell_object(targ, ETOQCN+"%^RESET%^%^ORANGE%^ "+
            "flips "+ETO->QP+" scimitar around and "+
            "stabs you in the "+tlim+" with the %^BOLD%^"+
            "%^RED%^bone fragment%^RESET%^%^ORANGE%^ "+
            "that protrudes from the end of its handle!%^RESET%^");

            tell_room(EETO, ETOQCN+"%^RESET%^%^ORANGE%^ "+
            "flips "+ETO->QP+" scimitar around and "+
            "stabs "+targ->QCN+"%^RESET%^%^ORANGE%^ "+
            "in the "+tlim+" with the %^BOLD%^%^RED%^bone "+
            "fragment%^RESET%^%^ORANGE%^ that protrudes from "+
            "the end of its handle!%^RESET%^", ({ETO, targ}));

            targ->cause_typed_damage(targ,tlim,roll_dice(3,4),"piercing");
            return 1;
            break;
    }

    dam = roll_dice((bolts+1), 4);
		
    switch(bolts)
    {
        case 1:

            tell_object(ETO, "%^BOLD%^%^YELLOW%^A brilliant "+
            "bolt of %^BOLD%^%^WHITE%^LIGHT%^BOLD%^%^YELLOW%^"+
            " zaps from the blade of your scimitar and strikes "+
            targ->QCN+"%^BOLD%^%^YELLOW%^'s "+tlim+"!%^RESET%^");
		
            tell_object(targ, "%^BOLD%^%^YELLOW%^A brilliant "+
            "bolt of %^BOLD%^%^WHITE%^LIGHT%^BOLD%^%^YELLOW%^"+
            " zaps from the blade of "+ETOQCN+"%^BOLD%^%^YELLOW%^'s "+
            "scimitar and strikes your "+tlim+"!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^YELLOW%^A brilliant "+
            "bolt of %^BOLD%^%^WHITE%^LIGHT%^BOLD%^%^YELLOW%^"+
            " zaps from the blade of "+ETOQCN+"%^BOLD%^%^YELLOW%^'s "+
            "scimitar and strikes "+targ->QCN+"%^BOLD%^%^YELLOW%^'s "+
            tlim+"!%^RESET%^", ({targ, ETO}));
            break;
			
        case 2..3:
			
            tell_object(ETO, "%^BOLD%^%^YELLOW%^"+amt+" brilliant "+
            "bolts of %^BOLD%^%^WHITE%^LIGHT%^BOLD%^%^YELLOW%^"+
            " zap from the blade of your scimitar and strike "+
            targ->QCN+"%^BOLD%^%^YELLOW%^'s "+tlim+"!%^RESET%^");
	
            tell_object(targ, "%^BOLD%^%^YELLOW%^"+amt+" brilliant "+
            "bolts of %^BOLD%^%^WHITE%^LIGHT%^BOLD%^%^YELLOW%^"+
            " zap from the blade of "+ETOQCN+"%^BOLD%^%^YELLOW%^'s "+
            "scimitar and strike your "+tlim+"!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^YELLOW%^"+amt+" brilliant "+
            "bolts of %^BOLD%^%^WHITE%^LIGHT%^BOLD%^%^YELLOW%^"+
            " zap from the blade of "+ETOQCN+"%^BOLD%^%^YELLOW%^'s "+
            "scimitar and strike "+targ->QCN+"%^BOLD%^%^YELLOW%^'s "+
            tlim+"!%^RESET%^", ({targ, ETO}));
            break;
    }			
	
    targ->cause_typed_damage(targ,tlim,dam,"positive energy");
    return 1;
}
