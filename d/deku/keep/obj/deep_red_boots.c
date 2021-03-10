#include <std.h>
inherit "/d/common/obj/clothing/shoes";

int charges, flag;

int set_charges(int x) 
{
    charges = x;
    return charges;
}

int adj_charges(int x) 
{
    charges += x;
    return charges;
}

void query_charges() 
{
    return charges;
}

void create()
{
    ::create();
    set_name("A pair of red boots");
    set_id(({ "boots","deep red boots","red boots","deep boots"}));
    set_short("%^BOLD%^%^RED%^A%^BOLD%^%^BLUE%^l%^BOLD%^%^RED%^"+
    "u%^BOLD%^%^BLUE%^s%^BOLD%^%^RED%^t%^BOLD%^%^BLUE%^i"+
    "%^BOLD%^%^RED%^a%^BOLD%^%^BLUE%^n%^BOLD%^%^RED%^'s red "+
    "boots of b%^RESET%^%^GREEN%^l%^BOLD%^%^RED%^e%^RESET%^"+
    "%^GREEN%^n%^BOLD%^%^RED%^d%^RESET%^%^GREEN%^i%^BOLD%^%^RED%^"+
    "n%^RESET%^%^GREEN%^g%^RESET%^");
    set_obvious_short("A pair of red boots");
    set_long("%^RED%^These soft boots are made from a thick, red, "+
    "%^YELLOW%^fabric%^RED%^.  They are seamless and of an "+
    "unaturally excellent quality, you believe that a magic has "+
    "somehow been involved in their creation.  They offer comfort "+
    "and warmth to the wearer, extending up the legs to right "+
    "below the %^BLUE%^knees%^RED%^.  A %^BLUE%^phrase%^RED%^ "+
    "has been written on the outter side of each boot.  There "+
    "are several thick and fluffy layers of cotton that, dyed a "+
    "%^CYAN%^sky blue%^RED%^, lining the outside edges of "+
    "the top of the boots.  The soles of the boots are thick "+
    "and hard, to provide protection to the wearer even in the "+
    "most rugged terrain.%^RESET%^"); 
    set_language("elven");
    set_read("My fellow rangers may you always %^GREEN%^"+
    "blend%^RESET%^ into nature.%^RESET%^");

    set_lore("%^GREEN%^These boots were said to have "+
    "been created originally for the elven "+
    "ranger Alustian.  The legend says that they were a "+
    "gift of the forest father, %^BOLD%^"+
    "%^GREEN%^Silvanus%^RESET%^%^GREEN%^, because of "+
    "Alustians aid to some of his clergy in "+
    "defending a forest from an attempted invasion.  "+
    "Alustian was a devout follower of %^BOLD%^%^GREEN%^"+
    "Mielikki%^RESET%^%^GREEN%^ and gladly received the boots "+
    "and eventually allowed some "+
    "magi to recreate them.  This pair is one of those "+
    "created versions, they still function, "+
    "but are not as powerful as their ancestors.%^RESET%^");

    set_weight(1);
    set_value(1000);
    set_size(-1);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_property("enchantment",3);
    set_item_bonus("stealth", 2);
    set_charges(15 + random(3));
}

void init() 
{
    ::init();
    if(!objectp(ETO)) return;
    if(ETO->is_class("ranger")) 
    {
        add_action("blend_func","blend");
    }
    if(interactive(ETO)) 
    {
        TO->add_item_owner(ETOQN);
    }
}

int do_fail() 
{
    tell_object(ETO,"%^GREEN%^The boots do not "+
    "respond to your command.%^RESET%^");
}

int blend_func() 
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(ETO->query_bound() || ETO->query_unconscious()) 
    {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }

    if(!ETO->is_class("ranger") || 
    TO->query_charges() <= 0 || ETO->query_invis() ||
    EETO->query_property("indoors") ||
    !TO->query_worn()) 
    {
        do_fail();
        return 1;
    }

    adj_charges(-1);
    new("/cmds/spells/m/_meld_into_nature")->use_spell(ETO,ETO,30,100,"cleric");
    flag = 1;
    return 1;
}

int wear_func() 
{
    if(!TO->query_owns_item(ETOQN) && interactive(ETO)) 
	{
        tell_object(ETO,"%^RED%^The boots don't fit you!%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^BLUE%^You slip your feet into "+
    "the warm and comfortable boots.%^RESET%^");
    return 1;
}

int remove_func()
{
    object ob;
    tell_object(ETO,"%^RED%^You let out a sigh as you "+
    "pull your feet from the boots.%^RESET%^");
    tell_room(environment(ETO),ETO->query_cap_name() + 
    " sighs softly%^RESET%^",ETO);
    if(flag == 1 && ETO->query_invis() && ob = present("invisobx999",ETO)) 
    {
        ob->show_up();
        flag = 0;
    }
    return 1;
}

int isMagic()
{
    int y;
    y = ::isMagic();
    y = y + 1;
    return y;
}