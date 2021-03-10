#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create() 
{
    ::create();
    set_id(({ "dagger","silver dagger" }));
    set_obvious_short("silver dagger");
    set_short("%^WHITE%^%^BOLD%^S%^RESET%^%^WHITE%^i%^BOLD%^lv%^RESET%^%^WHITE%^"+
    "e%^BOLD%^r's %^RESET%^%^WHITE%^E%^BOLD%^dg%^RESET%^%^WHITE%^e%^RESET%^");
    
    set_long("%^WHITE%^%^BOLD%^This slender dagger is composed entirely of s%^RESET%^%^WHITE%^"+
    "i%^BOLD%^lv%^RESET%^%^WHITE%^e%^BOLD%^r. It almost seems as if someone just took a "+
    "chunk of silver and then molded it, forming a pommel, a hilt, a guard, and even a blade "+
    "from the one solid piece. The blade of it has been honed to a %^RED%^razor-sharp%^BOLD%^"+
    "%^WHITE%^ edge on both sides. The guard is simply a piece of silver that juts out from "+
    "either side and curves smoothly downward. The handle has been molded to have a grip, "+
    "obviously an attempt to make sure whoever is wielding it would not lose control of the weapon. "+
    "The pommel is slightly larger than the rest of the weapon and has several ridges "+
    "which protrude downward. It is apparent that something has been added to the "+
    "silver in order to make the weapon much more solid, but you are unsure of what it is. There "+
    "are no other markings visible on the weapon.%^RESET%^");
    
    set_property("lore difficulty", 20);
    
    set_lore("%^BOLD%^%^WHITE%^These daggers were once quite common by a group of "+
    "rogues who were said to report directly to the ShadowLord. However, history says "+
    "little about what happened to them. These weapons were said to be able to "+
    "sap life from their targets and even blind them temporarily. The rumors suggest that "+
    "maybe this was a side effect of the magic used to create these daggers. They "+
    "were known in that time as Silver's Edge.%^RESET%^");
    
    set_value(4500);
    set_property("enchantment",3 + random(2));
    set_wield((:TO,"wield_me":));
    set_unwield("%^WHITE%^You carefully release your grip on the dagger.%^RESET%^");
	set_hit((:TO,"weapon_hit":));
}

int wield_me() 
{
    if(ETO->query_highest_level() < 20) 
    {
        tell_object(ETO,"%^RED%^The magic of this weapon is beyond "+
        "you!%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^BOLD%^%^WHITE%^You grip the dagger and marvel at the "+
    "viciously sharp edges of its blade.%^RESET%^");
    return 1;
}   

int weapon_hit(object targ) 
{
    int dam;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(5)) return 0;
    switch(random(10))
    {
        case 0..4: case 7..9:
            tell_object(ETO, "%^BOLD%^%^WHITE%^You strike "+targ->QCN+"%^BOLD%^%^WHITE%^ "+
            "with the %^RED%^razor-sharp%^BOLD%^%^WHITE%^ dagger and feel it "+
            "%^BOLD%^%^BLACK%^sapping%^BOLD%^%^WHITE%^ "+targ->QP+" lifeforce!%^RESET%^");
            
            tell_object(targ, ETOQCN+"%^BOLD%^%^WHITE%^ strikes you with "+ETO->QP+
            " %^RED%^razor-sharp%^BOLD%^%^WHITE%^ dagger and you feel it %^BOLD%^%^BLACK%^"+
            "sapping%^BOLD%^%^WHITE%^ your lifeforce!%^RESET%^");
            
            tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^'s strikes "+targ->QCN+"%^BOLD%^%^WHITE%^ "+
            "with "+ETO->QP+" %^RED%^razor-sharp%^BOLD%^%^WHITE%^ dagger!%^RESET%^", ({ETO, targ}));
            
            dam = roll_dice(2,4);
            ETO->add_hp(dam);
            return dam;
            break;
        case 5..6:
            tell_object(ETO, "%^BOLD%^%^WHITE%^As you strike "+targ->QCN+"%^BOLD%^%^WHITE%^"+
            "with the %^RED%^razor-sharp%^BOLD%^%^WHITE%^ dagger a brilliant flash of "+
            "light blinds "+targ->QO+"!%^RESET%^");
            
            tell_object(targ, "%^BOLD%^%^WHITE%^As "+ETOQCN+"%^BOLD%^%^WHITE%^ strikes you "+
            "with "+ETO->QP+"%^RED%^ razor-sharp%^BOLD%^%^WHITE%^ dagger you are blinded "+
            "by a brilliant flash of light!%^RESET%^");
            
            tell_room(EETO, "%^BOLD%^%^WHITE%^As "+ETOQCN+"%^BOLD%^%^WHITE%^ strikes "+targ->QCN+
            " with "+ETO->QP+"%^RED%^ razor-sharp%^BOLD%^%^WHITE%^ dagger a brilliant flash of "+
            "light blinds "+targ->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^", ({ETO, targ}));
            
            targ->set_temporary_blinded(2, "%^BOLD%^%^WHITE%^You have been blinded by a brilliant "+
            "flash of light!%^RESET%^");
            return roll_dice(1,6);
            break;            
    }
    return 0;
}
