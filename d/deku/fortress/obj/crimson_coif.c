#include <std.h>
inherit "/d/common/obj/armour/coif.c";

void create()
{
    ::create();
    set_name("crimson coif");
    set_id(({ "coif", "crimson coif", "blood coif",
    "blackthorn's coif","blackthorn coif" }));
    set_short("%^BOLD%^%^BLACK%^Blackthorn's %^RED%^blood "+
    "coif%^RESET%^");
    
    set_obvious_short("A blood red coif");
	
    set_long("%^BOLD%^%^RED%^This coif is made from a large, "+
    "rough piece of leather that has been dyed a deep "+
    "cri%^YELLOW%^m%^RED%^son.  The leather has streaks and spots "+
    "of darker crimson that suggest the process of dying it "+
    "was not a perfect one.  At first glance you would almost "+
    "assume it was dyed in blood.  It is large enough that "+
    "when worn it would cover the entire head of the wearer with "+
    "the ends reaching to slightly below the neck.%^RESET%^");
    	
    set_weight(6);
    set_value(1000);

    set_lore("%^RED%^Legend has it that this item was created for "+
    "a powerful warrior named Blackthorn.  The leather was "+
    "magically bound together for him and then dyed with the "+
    "blood of his fallen enemy, Ragnarann, a priest of tyr.  "+
    "The process was completed by a man named Narameon who had "+
    "became one of his closet friends and an important ally.");
    
    set_type("leather");
    set_size(3);
    set_property("enchantment",3);
    set_item_bonus("strength", 2);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"strike_func":));
}

void init() 
{
    ::init();
    if(interactive(ETO)) 
    {
        if(TO->add_item_owner(ETOQN)) 
        {
            tell_object(ETO, "%^BOLD%^%^RED%^You sense the coif bind to your soul!%^RESET%^");
            TO->set_size(ETO->query_size());
        }
    }
}

int wear_func()
{
    tell_room(EETO,ETO->QCN+"%^RED%^ wears the "+
    "coif with a slight grimace.%^RESET%^",ETO);
    tell_object(ETO,"%^RED%^You slip on the coif "+
    "with a slight grimace.%^RESET%^");
    return 1;
}

int remove_func()
{
    tell_room(EETO,ETO->QCN+"%^RED%^ removes the coif "+
    "and looks relieved.%^RESET%^",ETO);
    tell_object(ETO,"%^RED%^You finally remove the coif "+
    "and feel relieved.%^RESET%^");	
    return 1;
}

int strike_func(int damage, object what, object who)
{
    if(random(1000) < 100)
    {
	
        tell_room(EETO,"%^RED%^The surface of the coif "+
        "worn by "+ETO->QCN+"%^RED%^ seems to shift as "+
        who->QCN+"%^RED%^ strikes it!%^RESET%^",({ETO,who}));
	
        tell_object(ETO,"%^RED%^The surface of your coif shifts, "+
        "absorbing most of the blow, as "+who->QCN+"%^RED%^ "+
        "strikes it!%^RESET%^");
	
        tell_object(who,"%^RED%^The surface of the coif worn by "+
        ETO->QCN+"%^RED%^ seems to shift as you strike it, "+
        "weakening your blow!%^RESET%^");
	
        return (damage*25)/100;
    }
}

int is_metal() { return 0; }