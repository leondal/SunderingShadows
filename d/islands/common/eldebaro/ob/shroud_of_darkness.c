#include <std.h>
inherit "/d/common/obj/clothing/magerobe";
int charges;

void create()
{
    ::create();
    set_name("flowing dark garment");
    set_id(({ "robe", "garment", "flowing dark garment",
    "dark shroud", "shroud of darkness", "shroud"}));
	
    set_short("%^BOLD%^%^BLACK%^Shr%^BOLD%^%^WHITE%^ou"+
    "%^BOLD%^%^BLACK%^d %^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^f "+
    "D%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^rkn%^BOLD%^%^WHITE%^e"+
    "%^BOLD%^%^BLACK%^ss%^RESET%^");
	
    set_obvious_short("%^BOLD%^%^BLACK%^A flowing dark garment%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This garment looks like the work "+
    "of a master tailor. It has been exquisitely woven from a very d%^BOLD%^%^WHITE%^a"+
    "%^BOLD%^%^BLACK%^rk fabric. It appears %^BOLD%^%^WHITE%^seamless%^BOLD%^%^BLACK%^"+
    " as if the tailor spent an inordinate amount of time on hiding the stitches from "+
    "any untrained observer. It is entirely smooth, %^BOLD%^%^WHITE%^flawless%^BOLD%^%^BLACK%^ "+
    "in fact, and flows softly down the body of the one who wears it. It looks as if it "+
    "would fall to slightly below the knees of whoever that might be. The edges of the "+
    "garment are ever so slightly a %^BOLD%^%^WHITE%^lighter%^BOLD%^%^BLACK%^ hue as if "+
    "they were attached at the very end of its creation. However, you are unable to "+
    "find any stitches attaching them to the main body of the garment.%^RESET%^");
    
    set_value(4000);

    set_lore("%^BOLD%^%^WHITE%^The rumours surrounding this garment are few and far "+
    "between. There are two primary ones. The first one talks about a tailor who had found a "+
    "way of preserving fabric so that it would never falter with the passage of time. "+
    "It was said that everything he tailored after the discovery he hoarded with a ferocity "+
    "that alarmed those who had knew him previously. Some said that he was possessed, others "+
    "believed that he had simply gone mad.\n\n"+
    "The other rumor involves a tailor who was forced to work for Kayan Freeholm, many years ago now. "+
    "The giant was planning on conquering the world but wanted a remarkable gown fashioned for his beloved, "+
    "Asantra, beforehand. The tailor was forced to create until his hands bled, then he was allowed a day of rest, "+
    "this continued for some unknown length of time before he discovered a fabric that would mend "+
    "itself. Kayan had become obsessed with darkness, for, supposedly anyway, some unknown reason and "+
    "wanted each garment the tailor crafted imbued with the ability to %^BOLD%^%^BLACK%^darken someone"+
    "%^BOLD%^%^WHITE%^ or %^BOLD%^%^BLACK%^darken something%^BOLD%^%^WHITE%^ at will. It is said that "+
    "during combat this garment actually replenishes itself from the energy of the fray.\n\n"+
    "It is likely that neither story is exactly true or perhaps they are simply different perspectives of the "+
    "same one.%^RESET%^");

    set_property("lore difficulty",25);
    set_property("enchantment",5);

    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_me":));
    set_struck((:TO,"strike_func":));
    if(!random(2)) set_item_bonus("intelligence", 2);
    else if(!random(2)) set_item_bonus("charisma", 2);
    else if(!random(2)) set_item_bonus("wisdom", 2); 
    charges = 4 + random(7);
}

void init() 
{
    ::init();
    if(interactive(ETO)) 
    {
        if(TO->add_item_owner(ETOQN))
        {
            tell_object(ETO, "%^BOLD%^%^BLACK%^You feel an invisible "+
            "force encompass you for a moment as the "+
            "garment binds to your soul!%^RESET%^");
            if((int)TO->query_size() != (int)ETO->query_size()) 
            {
                set_size(ETO->query_size());
                tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the garment "+
                "shifting and transforming, as it changes itself "+
                "to fit your body!%^RESET%^");
            }
        }
    }
    add_action("darken_them", "darken");
}

int darken_them(string str)
{
    object targ;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!living(ETO)) return 0;
    if(!stringp(str)) return 0;
    if(!query_worn()) return 0;
    if (ETO->query_bound() || ETO->query_unconscious() || ETO->query_paralyzed()) 
    {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }
    if(!objectp(targ = present(str, EETO))) 
    {
        tell_object(ETO, "You don't see that here!");
        return 1;
    }
    if(!charges)
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^The garment fails to respond!%^RESET%^");
        return 1;
    }
    tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ seems strangely fixated on "+targ->QCN+
    "%^BOLD%^%^BLACK%^!%^RESET%^", ({ETO, targ}));
    if(living(targ))
    {        
        tell_object(ETO, "%^BOLD%^%^BLACK%^You focus on "+targ->QCN+"%^BOLD%^%^BLACK%^ "+
        "and draw on the power of the garment to envelope "+targ->QO+" with a "+
        "globe of darkness!%^RESET%^");
        
        tell_object(targ, ETOQCN+"%^BOLD%^%^BLACK%^ seems strangely fixated on you!");       
    }
    else
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^You focus on "+targ->QCN+"%^BOLD%^%^BLACK%^ "+
        "and draw on the power of the garment to envelope it with a "+
        "globe of darkness!%^RESET%^");
    }
    charges--;
    new("/cmds/spells/d/_darkness.c")->use_spell(ETO, targ, 40, 100, "mage");
    return 1;    
}

int wear_func()
{
    
    if(ETO->query_highest_level() < 35 && interactive(ETO)) 
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^The magic in the garment "+
        "will not submit to someone as %^BOLD%^%^RED%^weak%^BOLD%^"+
        "%^BLACK%^ as you!%^RESET%^");
        return 0;
    }

    if(!TO->query_owns_item(ETOQN) && ETO->is_player()) 
    {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The garment has been "+
        "bound to the soul of another!%^RESET%^");
        return 0;
    }

    tell_object(ETO, "%^BOLD%^%^BLACK%^You feel an aura of energy encompass "+
    "you as the garment seems to mend itself!%^RESET%^");
    TO->set_overallStatus(100);
    return 1;
}

int remove_me() 
{
    tell_object(ETO, "%^BOLD%^%^BLACK%^You feel the aura of energy "+
    "fade away!%^RESET%^");
    return 1;
}

int strike_func(int damage, object what, object who)
{
    object mob;
    if(!objectp(ETO)) return 0;
    if(!objectp(who)) return 0;
    if(!random(2))
    {
        tell_room(EETO, "%^BOLD%^%^BLACK%^As "+who->QCN+"%^BOLD%^%^BLACK%^ strikes "+ETOQCN+
        "%^BOLD%^%^BLACK%^ "+who->QS+" is enveloped with a globe of "+
        "%^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^"+
        "tt%^BOLD%^%^WHITE%^er d%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^rkn%^BOLD%^%^WHITE%^e"+
        "%^BOLD%^%^BLACK%^ss!%^RESET%^", ({ETO, who}));
        
        tell_object(ETO, "%^BOLD%^%^BLACK%^A globe of %^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^"+
        "tt%^BOLD%^%^WHITE%^er d%^BOLD%^%^WHITE%^"+
        "a%^BOLD%^%^BLACK%^rkn%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^ss envelopes "+
        who->QCN+"%^BOLD%^%^BLACK%^ as "+who->QS+" strikes you!%^RESET%^");
				
        tell_object(who, "%^BOLD%^%^BLACK%^A globe of %^BOLD%^%^WHITE%^u%^BOLD%^%^BLACK%^"+
        "tt%^BOLD%^%^WHITE%^er d%^BOLD%^%^WHITE%^"+
        "a%^BOLD%^%^BLACK%^rkn%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^ss envelopes "+
        "you%^BOLD%^%^BLACK%^ as you strike "+ETOQCN+"%^BOLD%^%^BLACK%^!%^RESET%^");
        if(!random(3)) charges++;
        who->set_temporary_blinded(2, "%^BOLD%^%^BLACK%^You are blinded by the globe of darkness!%^RESET%^");
        return (damage/2);        
    }    
    return damage;
}

