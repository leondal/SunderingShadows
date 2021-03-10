#include <std.h>
inherit "/d/common/obj/armour/cloak_hooded";
int charges;
int flag = 0;

void create() 
{
    ::create();
    set_name("short charcoal cloak");
    set_id(({"cloak", "charcoal cloak", "short cloak", 
    "short charcoal cloak", "cloak of invisibility"}));
    
    set_short("%^BOLD%^%^BLACK%^Cl%^BOLD%^%^WHITE%^oa%^BOLD%^%^BLACK%^k "+
    "of %^BOLD%^%^CYAN%^inv%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^s%^BOLD%^%^WHITE%^i"+
    "%^BOLD%^%^CYAN%^b%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^i%^BOLD%^"+
    "%^CYAN%^ty%^RESET%^");
    
    set_obvious_short("short charcoal cloak");
    
    set_weight(3);
    
	set_long("%^BOLD%^%^BLACK%^This cloak is made from a charcoal gr%^BOLD%^%^WHITE%^a"+
    "%^BOLD%^%^BLACK%^y fabric that is exceptionally light and thin. In fact, it is "+
    "almost see through. It seems to %^BOLD%^%^CYAN%^g%^BOLD%^%^WHITE%^l%^BOLD%^%^CYAN%^"+
    "i%^BOLD%^%^MAGENTA%^t%^BOLD%^%^YELLOW%^t%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^CYAN%^"+
    "%^BOLD%^%^BLACK%^ when even the faintest amount of light touches it. It has been "+
    "cut short for a cloak, coming down only to the upper back of the wearer. There appears "+
    "to be no thread holding it together either, as if it is a solid piece of fabric "+
    "perfectly shaped into the form of a cloak. It seems quite mundane.%^RESET%^");

	set_property("lore difficulty", 30);

	set_lore("%^BOLD%^%^BLACK%^This is a cloak of invisibility. There have been "+
    "many of them throughout history but these particular cloaks was made for some segment "+
    "of the temple of Lysara. It is thought that they were used at one point to allow certain "+
    "members of the segment to do reconnaissance work against some being who was raising a "+
    "vast army of undead. The most likely stories suggest that this cloak was also imbued with "+
    "some ability to protect its wearer from all types of damage, supposedly so that if they "+
    "were ever discovered they would be more capable of fighting back against the hordes. "+
    "To use this cloak all one has to do is will it to <%^BOLD%^%^CYAN%^fade%^BOLD%^%^BLACK%^> "+
    "or will it to <%^BOLD%^%^CYAN%^emerge%^BOLD%^%^BLACK%^>.%^RESET%^");

    set_value(15000);
    set_property("enchantment",5);
    set_wear((:TO,"wear_me":));
    set_remove((:TO,"remove_me":));
    set_size(-1);
    charges = random(10) + 12;//slightly more charges than a jade ring - Saide	
    set_item_bonus("damage resistance", 8);
    set_item_bonus("spell damage resistance", 16);
}

void init()
{
    ::init();
    add_action("fade", "fade");
    add_action("emerge", "emerge");
}

int wear_me() 
{
	if((int)ETO->query_highest_level() < 35) 
	{
        tell_object(ETO, "%^BOLD%^%^RED%^The cloak refuses to be "+
        "worn by one as weak as you!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^BLACK%^You feel a powerful %^BOLD%^%^CYAN%^"+
    "aura%^BOLD%^%^BLACK%^ flow outward from the cloak as you slip it on.%^RESET%^");
    return 1;
}

int remove_me() 
{
    tell_object(ETO, "%^BOLD%^%^BLACK%^You remove the cloak and "+
    "feel the %^BOLD%^%^CYAN%^energy%^BOLD%^%^BLACK%^ leave you.%^RESET%^");
    if(flag == 1) 
    {
        flag = 0;
        if(ETO->query_magic_hidden()) ETO->set_magic_hidden(0);		
    }
    return 1;
}

int fade() 
{
    if(query_worn()) 
    {
        if(ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) 
        {
            ETO->send_paralyzed_message("info",TP);
            return 1;
        }
        if((int)TP->query_magic_hidden()) 
        {
            tell_object(ETO, "%^BOLD%^%^CYAN%^You are already faded from view!%^RESET%^");
            return 1;
        }
        if(charges > 0) 
        {
            flag = 1;
            tell_object(ETO,"%^BOLD%^%^BLACK%^You will the %^BOLD%^%^CYAN%^"+
            "cloak%^BOLD%^%^BLACK%^ to let you fade from sight!%^RESET%^");
            tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ fades away from vision.%^RESET%^", ETO);		
            ETO->set_magic_hidden(1);
            charges = charges - 1;
            return 1;
		}
        if(charges <= 0) 
        {
            tell_object(ETO, "%^BOLD%^%^RED%^The cloak has spent all of its "+
            "energy!%^RESET%^");
            return 1;
        }	
    }
    else 
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You must be wearing the cloak in order to "+
        "will it to allow you to fade!%^RESET%^.%^RESET%^");	
        return 1;
    }			
}

int emerge() 
{
    if(query_worn()) 
    {
        if(!flag)
        {
            tell_object(ETO, "%^BOLD%^%^RED%^You are not currently using the "+
			"cloak.%^RESET%^");
            return 1;
        }
        if(flag == 1) 
        {
            tell_object(ETO,"%^BOLD%^%^WHITE%^You emerge, allowing normal sight to see you once again.%^RESET%^");
            flag = 0;
            if(ETO->query_magic_hidden()) ETO->set_magic_hidden(0);
            tell_room(EETO, ETOQCN + "%^BOLD%^%^WHITE%^ emerges from nowhere!%^RESET%^",ETO);
            return 1;
        }
    }
    else 
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You must be wearing the cloak to will it to "+
        "let you emerge!%^RESET%^");	
        return 1;
    }	
}