#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

void create()
{
    ::create();
    set_name("azure robe");
    set_obvious_short("Simple azure robe");
    
    set_short("%^BOLD%^%^CYAN%^R%^BOLD%^%^BLACK%^o%^BOLD%^%^CYAN%^"+
    "b%^BOLD%^%^BLACK%^e%^BOLD%^%^CYAN%^ of P%^BOLD%^%^BLACK%^o"+
    "%^BOLD%^%^CYAN%^w%^BOLD%^%^BLACK%^e%^BOLD%^%^CYAN%^r%^RESET%^");
    
    set_id(({"robe", "azure robe", "robe of power", "simple robe", 
    "power robe"}));
	set_long(
	    "%^BOLD%^%^CYAN%^This robe has been carefully and expertly "+
        "sewn from a soft billowing az%^RESET%^%^BLUE%^u%^BOLD%^%^CYAN%^re "+
        "fabric. The fabric is also quite thick and you can ascertain that it "+
        "would likely be warm in even the coldest climate. It has been "+
        "cut so that it would flow down to nearly the ankles of anyone "+
        "who would wear it. It appears almost mundane and there are no "+
        "visible markings at all, even the seams appear to have been painstakingly "+
        "hidden from view. A brighter colored sash loops through the robe and "+
        "serves the purpose of letting the wearer tie it in place. "+
        "There are several pockets, obviously designed to "+
        "hold %^BOLD%^%^WHITE%^components%^BOLD%^%^CYAN%^ apparent on the inside "+
        "of it.%^RESET%^");
        
    set_lore("%^BOLD%^%^CYAN%^This robe is known as a robe of power. "+
    "There are several legends surrounding it, all of questionable origin. "+
    "One legends says that the robe imbues the wearer with a protection from "+
    "magical attacks and somehow augments the essence of the wearer. Another "+
    "legend suggest that the robe itself is quite fickle and never "+
    "satisified with being owned by one particular being for very long. In "+
    "fact it is known to change itself depending on who or what carries it at "+
    "any given moment. Yet another legend suggests that should the robe "+
    "desire to do so, that it is capable of unleashing powerful magic of its "+
    "own during battle.%^RESET%^");
    
    set_type("clothing");
    set_property("no curse", 1);
    set_property("enchantment",5);
    set_item_bonus("spell damage resistance", 15);
    set_max_internal_encumbrance(21);
    set_value(35000);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO,"strike_func":));
    
}

int wearme()
{   
    if((int)ETO->query_highest_level() < 35) 
	{
        tell_object(ETO, "%^BOLD%^%^RED%^The robe simply "+
        "falls off of you!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^CYAN%^You tie the simple sash of the "+
    "robe around your waist and feel a strange sensation as "+
    "your own power is suddenly augmented!%^RESET%^");
    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^ ties the simple sash of "+
        ETO->QP+" robe to hold it in place.%^RESET%^", ETO);
    }
    if(ETO->is_class("mage") || ETO->is_class("psion") || ETO->is_class("psywarrior")) 
    {
        TO->set_item_bonus("intelligence",6);
        TO->set_item_bonus("charisma",0);
        TO->set_item_bonus("wisdom", 0);
    }
    else if(ETO->is_class("cleric") || ETO->is_class("monk"))
    {
        TO->set_item_bonus("intelligence", 0);
        TO->set_item_bonus("charisma", 0);
        TO->set_item_bonus("wisdom", 6);
    }
    else
    {
        TO->set_item_bonus("intelligence",0);
        TO->set_item_bonus("wisdom", 0);
        TO->set_item_bonus("charisma",6);
    }
    return 1;
}

int removeme()
{
    tell_object(ETO, "%^BOLD%^%^CYAN%^You untie the simple sash and carefully "+
    "remove the robe... and suddenly the augmented power fades away!%^RESET%^");
    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^ unties the simple sash of "+
        ETO->QP+" robe.%^RESET%^", ETO);
    }
    return 1;
}

void init()
{
    int x, y;
	::init();
	add_action("check_put","put");
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    x = (int)ETO->query_size();
    y = (int)TO->query_size();
    if(x != y)
    {
        if(x > y)
        {
            tell_object(ETO, "%^BOLD%^%^CYAN%^You feel the robe "+
            "changing... and elongating to fit you!%^RESET%^");
            if(objectp(EETO) && !ETO->query_invis())
            {
                tell_room(EETO, "%^BOLD%^%^CYAN%^The robe carried by "+
                ETOQCN+"%^BOLD%^%^CYAN%^ suddenly changes.... elongating to "+
                "fit "+ETO->QO+"!%^RESET%^", ETO);
            }
        }
        else if(x < y)
        {
            tell_object(ETO, "%^BOLD%^%^CYAN%^You feel the robe "+
            "changing... and shrinking to fit you!%^RESET%^");
            if(objectp(EETO) && !ETO->query_invis())
            {
                tell_room(EETO, "%^BOLD%^%^CYAN%^The robe carried by "+
                ETOQCN+"%^BOLD%^%^CYAN%^ suddenly changes.... shrinking to "+
                "fit "+ETO->QO+"!%^RESET%^", ETO);
            }
        }
        TO->set_size(x);
        return;
    }        
}

int check_put(string str)
{
	if(!query_worn()) 
    {
	    notify_fail("You must be wearing the robes to place something in their"+
		    " pockets.\n");
		return 0;
	}

	if(query_worn()) return ::put_into();
}

int strike_func(int damage, object what, object who)
{
    object mob;
    if(!objectp(ETO)) return 0;
    if(!objectp(who)) return 0;
    if(!random(5))
    {
        switch(random(10))
        {
            case 0..7:
                
                tell_object(ETO, "%^BOLD%^%^WHITE%^As "+who->QCN+"%^BOLD%^%^WHITE%^ strikes "+
                "at you... you find yourself suddenly in a different spot!%^RESET%^");
                
                tell_object(who, "%^BOLD%^%^WHITE%^As you strike at "+ETOQCN+"%^BOLD%^%^WHITE%^... "+
                ETO->QS+" is suddenly in a different spot!%^RESET%^");
                
                tell_room(EETO, "%^BOLD%^%^WHITE%^As "+who->QCN+"%^BOLD%^%^WHITE%^ strikes at "+
                ETO->QCN+"%^BOLD%^%^WHITE%^... "+ETO->QS+" is suddenly in a different "+
                "spot!%^RESET%^", ({ETO, who}));
                
                return 0;
                break;
            case 8..9:
                
                tell_object(ETO, "%^BOLD%^%^WHITE%^A brilliant flash out light clouds your vision "+
                "for a moment as "+who->QCN+"%^BOLD%^%^WHITE%^ strikes you.... you feel something "+
                "unseen stand between you and "+who->QO+", absorbing the force of the blow!%^RESET%^");
                
                tell_object(who, "%^BOLD%^%^WHITE%^As you strike "+who->QCN+"%^BOLD%^%^WHITE%^ a flash of "+
                "your own death goes through your mind......\n\nSuddenly you see a winged being "+
                "reaching into you and squeezing your insides and you %^BOLD%^%^RED%^SCREAM"+
                "%^BOLD%^%^WHITE%^ in agony!%^RESET%^");                
                
                tell_room(EETO, "%^BOLD%^%^WHITE%^As "+who->QCN+"%^BOLD%^%^WHITE%^ strikes "+
                ETO->QCN+"%^BOLD%^%^WHITE%^ a brilliant flash of light clouds your vision for "+
                "a brief moment and "+ETO->QCN+"%^BOLD%^%^WHITE%^ seems unharmed as "+
                who->QCN+"%^BOLD%^%^WHITE%^ suddenly %^BOLD%^%^RED%^SCREAMS%^BOLD%^%^WHITE%^ "+
                "in agony!%^RESET%^", ({who, ETO}));                
                who->cause_typed_damage(who, who->return_target_limb(), (damage*(1+roll_dice(1,6))), "divine");
                return 0;
                break;
        }
        
    }    
    return damage;
}
