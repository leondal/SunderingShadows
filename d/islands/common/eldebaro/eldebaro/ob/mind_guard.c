#include <std.h>
inherit "/d/common/obj/weapon/shortsword";

void create()
{
    ::create();
    set_name("curved short sword");
    set_id(({"curved sword", "sword", "curving short sword", "curving sword", 
    "dark bladed short sword", "mind guard", "dark bladed sword", "mindguard"}));

    set_obvious_short("%^BOLD%^%^CYAN%^curved %^RESET%^%^CYAN%^dark%^BOLD%^ "+
    "bladed short sword%^RESET%^");

    set_short("%^BOLD%^%^CYAN%^M%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^ndg%^RESET%^%^CYAN%^ua"+
    "%^BOLD%^%^CYAN%^rd%^RESET%^");
	
    set_long("%^BOLD%^%^CYAN%^This short sword is forged from a %^RESET%^%^CYAN%^dark blue"+
    "%^BOLD%^%^CYAN%^ metal that seems to emit a low frequency hum constantly. The blade "+
    "of it extends approximately two feet in length and is curved, almost like a scimitar. "+
    "There are %^RESET%^%^CYAN%^strange symbols%^BOLD%^%^CYAN%^ engraved into the length of it "+
    "that seem to flash occasionally but only for a brief moment before they go dull again. One edge "+
    "of the blade is %^BOLD%^%^RED%^r%^BOLD%^%^BLACK%^a%^BOLD%^%^RED%^zor%^BOLD%^%^CYAN%^ sharp. A "+
    "crossguard, made from a brighter azure material rests beneath the blade and attachs "+
    "it to the hilt of the sword. The hilt is engraved with more %^RESET%^%^CYAN%^strange symbols"+
    "%^BOLD%^%^CYAN%^ which seem permenantly dull. A pommel made from %^BOLD%^%^GREEN%^em%^RESET%^"+
    "%^GREEN%^e%^BOLD%^rald%^BOLD%^%^CYAN%^ balloons out from the bottom of the hilt.%^RESET%^");

    set_lore("%^BOLD%^%^CYAN%^These short swords, known invidivually as 'mindguard' where "+
    "forged by some forgotten blacksmith for a creature known as the collector. It is said "+
    "that the collector has always had a host of servants working for him, 'collecting things' and "+
    "that he sometimes grants them one of these weapons to help make sure that they can maintain "+
    "their will power in the face of adversity. Never before has one of them surfaced and "+
    "mostly they were considered nothing more than an old and slightly odd rumor, just like the "+
    "collector himself. Supposedly these weapons were imbued with the ability to guard the "+
    "wielder against mental attacks.%^RESET%^");

    set_property("lore difficulty", 22);
    set_value(3000);
    set_property("enchantment",5);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_item_bonus("will", 4);
    set_item_bonus("mental resistance", 20);
}

int wield_func()
{
    if((int)ETO->query_highest_level() < 35)
    {
        tell_object(ETO, "%^BOLD%^%^CYAN%^The sword will never be wielded "+
        "by someone as %^BOLD%^%^RED%^weak%^BOLD%^%^CYAN%^ as you!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel your will power increase and "+
    "the essence of something blends with your own!%^RESET%^");
    return 1;
}


int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel the added will power and the essence "+
    "fade away!%^RESET%^");
    return 1;
}

int hit_func(object targ)
{
    string tlimb;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(1000) < 325)
    {
        tlimb = targ->return_target_limb();
        tell_object(ETO, "%^BOLD%^%^CYAN%^You stab into "+targ->QCN+"%^BOLD%^%^CYAN%^'s "+
        tlimb+"!%^RESET%^");
				
        tell_object(targ, ETOQCN +"%^BOLD%^%^CYAN%^ stabs "+ETO->QP+" short sword into "+
        "your "+tlimb+"!%^RESET%^");
				
        tell_room(EETO, ETOQCN +"%^BOLD%^%^CYAN%^ stabs "+ETO->QP+" short sword into "+
        targ->QCN+"%^BOLD%^%^CYAN%^'s "+tlimb+"!%^RESET%^", ({ETO, targ}));
                
        if(!random(10)) 
        {
            tell_object(ETO, "%^RESET%^%^CYAN%^You use "+targ->QCN+"%^RESET%^%^CYAN%^'s "+
            "surprise to launch another attack!%^RESET%^");
                    
            tell_object(targ, ETOQCN+"%^RESET%^%^CYAN%^ uses your surprise to launch "+
            "another attack!%^RESET%^");
                    
            tell_room(EETO, ETOQCN+"%^RESET%^%^CYAN%^ uses "+targ->QCN+"%^RESET%^%^CYAN%^'s "+
            "surprise to launch another attack!%^RESET%^", ({ETO, targ}));
                    
            ETO->execute_attack();
        }            
        return roll_dice(2,6);
    }
    return 0;
}

