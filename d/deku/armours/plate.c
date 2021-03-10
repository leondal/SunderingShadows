#include <std.h>
inherit "/d/common/obj/armour/plate.c";

void create() 
{
    ::create();
    set_name("dark platemail");
    set_id(({"plate", "armor", "dark plate", "platemail", "mail",
    "dark lord armor", "armor of the dark lord"}));
    set_obvious_short("suit of dark platemail");
    set_short("%^BOLD%^%^BLACK%^Armor of The D%^WHITE%^a%^BLACK%^rk "+
    "L%^WHITE%^o%^BLACK%^rd%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^This armor has been forged from a "+
    "black metal. It seems as if it were designed originally like a suit of "+
    "chain mail, but that as an after thought there were darker "+
    "metal plates attached to it to protect vital areas. The chain portion of "+
    "the armor is somewhat %^BOLD%^%^WHITE%^shiny%^BOLD%^%^BLACK%^ and "+
    "polished. The plates are a dull, deeper metal that seem to %^WHITE%^"+
    "absorb%^BLACK%^ light. The armor is designed in such a way that the "+
    "weight of it is evenly distributed over the entre body of the wearer and "+
    "there are numerous straps and buckles keeping it all together.%^RESET%^");
	
    set_property("lore difficulty", 20);
    set_lore("%^BOLD%^%^BLACK%^The exacty history of this armor has mostly been "+
    "forgotten. One story suggests that it was once worn by someone who either referred "+
    "to himself as the Dark Lord or for whatever reason was called that. Supposedly the "+
    "metal of the armor was slightly magical, protecting against what the Dark Lord "+
    "feared the most, acid. It also rumored to be able to increase his overall chances of "+
    "survival. However, another story suggests that the armor was created by an "+
    "over privileged and quite wealthy member of the royal class who never even "+
    "wore the armor outside of trying it on.%^RESET%^");    
    set_value(4000);
    set_property("enchantment", 3);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO, "strike_func":));
    set_item_bonus("survival", 2);
    set_item_bonus("acid resistance", 10);
}

int wearme()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel yourself become more protected "+
    "as you wear the suit of plate mail.%^RESET%^");
	return 1;
}
	
int removeme()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the protection fade away as "+
    "you remove the suit of plate mail.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who)
{
    object mon;
    if(!objectp(who)) return damage;
    if(!objectp(ETO)) return damage;
   
    if(random(4)) return damage;
    tell_object(ETO, who->QCN+"%^BOLD%^%^BLACK%^'s attack is deflected by one of the dull "+
    "metal plates on your armor!%^RESET%^");
    
    tell_object(who, "%^BOLD%^%^BLACK%^Your attack on "+ETO->QCN+"%^BOLD%^%^BLACK%^ is deflected "+
    "by one of the dull metal plates on "+ETO->QP+" armor!%^RESET%^");
    
    tell_room(EETO, who->QCN+"%^BOLD%^%^BLACK%^'s attack on "+ETO->QCN+"%^BOLD%^%^BLACK%^ "+
    "is deflected by one of the dull metal plates on "+ETO->QCN+"%^BOLD%^%^BLACK%^'s "+
    "armor!%^RESET%^", ({who, ETO}));
    return 0;
}

