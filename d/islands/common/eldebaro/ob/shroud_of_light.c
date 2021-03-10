#include <std.h>
inherit "/d/common/obj/clothing/magerobe";
int charges;

void create()
{
    ::create();
    set_name("brilliant flowing garment");
    set_id(({ "robe", "garment", "flowing garment",
    "brilliant shroud", "shroud of light", "shroud", "light shroud"}));
	
    set_short("%^BOLD%^%^WHITE%^Shr%^BOLD%^%^YELLOW%^ou%^BOLD%^%^WHITE%^"+
    "d %^BOLD%^%^YELLOW%^o%^BOLD%^%^WHITE%^f L%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^"+
    "ght%^RESET%^");
	
    set_obvious_short("%^BOLD%^%^WHITE%^A brilliant flowing garment%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This garment looks like the work "+
    "of a master tailor. It has been exquisitely woven from a very br%^BOLD%^%^YELLOW%^i"+
    "%^BOLD%^%^WHITE%^ght fabric. It appears %^BOLD%^%^YELLOW%^seamless%^BOLD%^%^WHITE%^"+
    " as if the tailor spent an inordinate amount of time on hiding the stitches from "+
    "any untrained observer. It is entirely smooth, %^BOLD%^%^YELLOW%^flawless%^BOLD%^%^WHITE%^ "+
    "in fact, and flows softly down the body of the one who wears it. It looks as if it "+
    "would fall to slightly below the knees of whoever that might be. The edges of the "+
    "garment are ever so slightly a %^BOLD%^%^BLACK%^darker%^BOLD%^%^WHITE%^ hue as if "+
    "they were attached at the very end of its creation. However, you are unable to "+
    "find any stitches attaching them to the main body of the garment. At first glance you "+
    "think that the entire garment is glowing brilliantly, but it seems to just be an illusion "+
    "provided by the strange fabric.%^RESET%^");
    
    set_value(4000);

    set_lore("%^BOLD%^%^WHITE%^The rumours surrounding this garment are few and far "+
    "between. There are two primary ones. The first one talks about a tailor who had found a "+
    "way of preserving fabric so that it would never falter with the passage of time. "+
    "It was said that everything he tailored after the discovery he hoarded with a ferocity "+
    "that alarmed those who had knew him previously. Some said that he was possessed, others "+
    "believed that he had simply gone mad.\n\n"+
    "The other rumor involves a mysterious tailor who had gone to great lengths to make sure "+
    "any of the items commissioned by Kayan Freeholm were tainted. The giant, who was known for his "+
    "ruthlessness had supposedly become obsessed with darkness. The mystery tailor had worked tirelessly "+
    "to 'fix' some of those garments by imbuing them with the very essence of light. This particular "+
    "garment is said to allow someone to %^BOLD%^%^YELLOW%^brighten someone%^BOLD%^%^WHITE%^ or "+
    "%^BOLD%^%^YELLOW%^brighten something%^BOLD%^%^WHITE%^ at will, in direct reversal of Kayan's order that "+
    "all garments be able to darken. Whoever the mystery tailor was, he was able to find a process that "+
    "allowed fabric to withstand the test of time. He had also, like the tailors working for Kayan, "+
    "found a way to allow the garment's magic to recharge simply by using the energy of the fray during "+
    "combat.\n\n"+
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
            tell_object(ETO, "%^BOLD%^%^WHITE%^You feel an invisible "+
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
    add_action("brighten_them", "brighten");
}

int brighten_them(string str)
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
        tell_object(ETO, "%^BOLD%^%^WHITE%^The garment fails to respond!%^RESET%^");
        return 1;
    }
    tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ seems strangely fixated on "+targ->QCN+
    "%^BOLD%^%^WHITE%^!%^RESET%^", ({ETO, targ}));
    if(living(targ))
    {        
        tell_object(ETO, "%^BOLD%^%^WHITE%^You focus on "+targ->QCN+"%^BOLD%^%^WHITE%^ "+
        "and draw on the power of the garment to envelope "+targ->QO+" with a "+
        "globe of light!%^RESET%^");
        
        tell_object(targ, ETOQCN+"%^BOLD%^%^WHITE%^ seems strangely fixated on you!");       
    }
    else
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You focus on "+targ->QCN+"%^BOLD%^%^WHITe%^ "+
        "and draw on the power of the garment to envelope it with a "+
        "globe of light!%^RESET%^");
    }
    charges--;
    new("/cmds/spells/l/_light.c")->use_spell(ETO, targ, 40, 100, "mage");
    return 1;    
}

int wear_func()
{
    
    if(ETO->query_highest_level() < 35 && interactive(ETO)) 
    {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The magic in the garment "+
        "will not submit to someone as %^BOLD%^%^RED%^weak%^BOLD%^"+
        "%^WHITE%^ as you!%^RESET%^");
        return 0;
    }

    if(!TO->query_owns_item(ETOQN) && ETO->is_player()) 
    {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The garment has been "+
        "bound to the soul of another!%^RESET%^");
        return 0;
    }

    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel an aura of energy encompass "+
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
        tell_room(EETO, "%^BOLD%^%^WHITE%^As "+who->QCN+"%^BOLD%^%^WHITE%^ strikes "+ETOQCN+
        "%^BOLD%^%^WHITE%^ "+who->QS+" is blasted with a %^BOLD%^%^MAGENTA%^r"+
        "%^BOLD%^%^WHITE%^a%^BOLD%^%^MAGENTA%^y%^BOLD%^%^WHITE%^ of %^BOLD%^%^YELLOW%^l"+
        "%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^g%^BOLD%^%^WHITE%^h%^BOLD%^%^YELLOW%^t"+
        "%^BOLD%^%^WHITE%^!%^RESET%^", ({ETO, who}));
        
        tell_object(ETO, "%^BOLD%^%^WHITE%^A %^BOLD%^%^MAGENTA%^r"+
        "%^BOLD%^%^WHITE%^a%^BOLD%^%^MAGENTA%^y%^BOLD%^%^WHITE%^ of %^BOLD%^%^YELLOW%^l"+
        "%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^g%^BOLD%^%^WHITE%^h%^BOLD%^%^YELLOW%^t"+
        "%^BOLD%^%^WHITE%^ strikes "+who->QCN+"%^BOLD%^%^WHITE%^ as "+who->QS+
        " strikes you!%^RESET%^");
				
        tell_object(who, "%^BOLD%^%^WHITE%^A %^BOLD%^%^MAGENTA%^r"+
        "%^BOLD%^%^WHITE%^a%^BOLD%^%^MAGENTA%^y%^BOLD%^%^WHITE%^ of %^BOLD%^%^YELLOW%^l"+
        "%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^g%^BOLD%^%^WHITE%^h%^BOLD%^%^YELLOW%^t"+
        "%^BOLD%^%^WHITE%^ from "+ETOQCN+"%^BOLD%^%^WHITE%^'s garment strikes "+
        "you!%^RESET%^");
        
        if(!random(3)) charges++;
        who->set_temporary_blinded(2, "%^BOLD%^%^WHITE%^You are blinded by the ray of light!%^RESET%^");
        return (damage/2);        
    }    
    return damage;
}

