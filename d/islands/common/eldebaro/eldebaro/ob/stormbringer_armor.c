#include <std.h>
inherit "/d/common/obj/armour/hide.c";

void create()
{
	::create();
	set_name("armor of the stormbringer");
	set_id(({"armor", "woven armor", "armor of the stormbringer", 
    "stormbringer armor", "dark woven armor", "dark armor"}));
    set_obvious_short("dark woven armor");
	set_short("%^BOLD%^%^BLACK%^Armor of the %^BOLD%^%^YELLOW%^"+
    "S%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^o%^BOLD%^%^MAGENTA%^r"+
    "%^BOLD%^%^YELLOW%^m%^BOLD%^%^WHITE%^b%^BOLD%^%^BLACK%^r"+
    "%^BOLD%^%^MAGENTA%^i%^BOLD%^%^YELLOW%^n%^BOLD%^%^WHITE%^g"+
    "%^BOLD%^%^BLACK%^e%^BOLD%^%^MAGENTA%^r%^RESET%^");
    
	set_long("%^BOLD%^%^WHITE%^This thick woven armor is composed of "+
    "several layers of leather. Each layer that you can identify looks as "+
    "it were from another creature. It is impossible at this point "+
    "to identify what any of them may have been. The outter layer, however, "+
    "has several %^BOLD%^%^GREEN%^green scales%^BOLD%^%^WHITE%^ visible. "+
    "Each of the scales is covered by a series of %^BOLD%^%^RED%^markings"+
    "%^BOLD%^%^WHITE%^. Each series depicts harmonious clouds which "+
    "morph into %^BOLD%^%^BLACK%^rag%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^ng "+
    "%^BOLD%^%^WHITE%^storms rapidly and without warning. The rest of the armor appears quite "+
    "mundane and seems to have been designed to fit whoever might wear it rather "+
    "snugly.%^RESET%^");
    
         
    set_lore("%^BOLD%^%^WHITE%^The exact history of this armor has been lost "+
    "to the passage of time. However, the legends around it suggest that it was "+
    "once worn by the Storm Giants of Castle Freeholm. A sect of powerful "+
    "giants who were once thought nothing more than a legend. It was "+
    "said that they were allied behind a powerful King and Queen and were, once "+
    "at least, bent on ruling the primordial plane. These suits of armor were "+
    "quite common in that time and were awarded to any who showed promise and "+
    "determination. Some rumors suggest that it was not only giants who wore "+
    "them.%^RESET%^");         
    
	set_property("enchantment",5);
    set_property("lore difficulty", 20);
    //set_remove((:TO,"removeme":));
    set_struck((:TO, "strike_func":));
    set_item_bonus("electricity resistance", 30);  
    set_size(4);
}

int wearme()
{
    if((int)ETO->query_highest_level() < 35) 
	{
        tell_object(ETO, "%^BOLD%^%^RED%^You lack the required "+
        "power to wear the armor!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel a surge of electricity "+
    "course through your body, but remarkably no pain, as you wear the armor!%^RESET%^");
	return 1;
}
	
int strike_func(int damage, object what, object who)
{
    object mon;
    if(!objectp(who)) return damage;
    if(!objectp(ETO)) return damage;
   
    if(!random(5)) return damage;
    switch(random(100))
    {
        case 0..97:
            tell_object(ETO, "%^BOLD%^%^YELLOW%^A bolt of lightning zaps out at "+who->QCN+
            "%^BOLD%^%^YELLOW%^ and slams into "+who->QO+"!%^RESET%^");
            
            tell_object(who,"%^BOLD%^%^YELLOW%^A bolt of lightning zap out at you, from "+
            ETOQCN+"%^BOLD%^%^YELLOW%^'s armor and slams into you!%^RESET%^");
            
            tell_room(EETO, "%^BOLD%^%^YELLOW%^A bolt of lightning zaps out at "+who->QCN+
            "%^BOLD%^%^YELLOW%^ from "+ETOQCN+"%^BOLD%^%^YELLOW%^'s armor and slams into "+who->QCN+
            "%^BOLD%^%^YELLOW%^!%^RESET%^", ({who, ETO}));
            who->cause_typed_damage(who, who->return_target_limb(), roll_dice(6,6), "electricity");
            return (damage);
            break;
        case 98..99:
            tell_object(ETO, "%^BOLD%^%^WHITE%^A brilliant flash out light EXPLODES from your "+
            "armor as "+who->QCN+"%^BOLD%^%^WHITE%^ strikes it and you feel yourself empowered by "+
            "strange magical words!%^RESET%^");
    
            tell_object(who, "%^BOLD%^%^WHITE%^A brilliant flash of light EXPLODES from "+ETOQCN+
            "%^BOLD%^%^WHITE%^'s armor as you strike it!%^RESET%^");
            
            tell_room(EETO, "%^BOLD%^%^WHITE%^A brilliant flash of light EXPLODES from "+ETOQCN+
            "%^BOLD%^%^WHITE%^'s armor as "+who->QCN+"%^BOLD%^%^WHITE%^ strikes it!%^RESET%^", ({ETO, who}));            
            damage = 0;            
            new("/cmds/spells/s/_storm_of_vengeance")->use_spell(ETO, ETO, 35, 35, "druid");
            return damage;    
    }
    return damage;
}
