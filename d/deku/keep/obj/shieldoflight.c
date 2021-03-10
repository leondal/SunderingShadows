#include <std.h>
inherit "/d/common/obj/armour/mshield.c";

#define LANGS ({"elven","common"})
int uses, daylight_time;

void init()
{
    ::init();
    if(interactive(ETO)) 
    {
        TO->add_item_owner(ETOQN);
    }
    add_action("make_day","daylight");
}

void create()
{
    ::create();
    set_name("shield");
    set_id(({ "shield", "shield of light", "light shield", "daylight shield", 
    "shield of daylight","crystal shield of light","crystal shield"}));
    set_short("%^BOLD%^%^WHITE%^Shield of %^YELLOW%^D%^BOLD%^%^WHITE%^a%^YELLOW%^y%^BOLD%^"+
    "%^WHITE%^l%^YELLOW%^i%^BOLD%^%^WHITE%^g%^YELLOW%^h%^BOLD%^%^WHITE%^t%^RESET%^");
    set_obvious_short("A green crystal shield");
    set_long("%^BOLD%^%^GREEN%^This shield is made from a completely smooth and rounded piece "+
    "of %^RESET%^%^GREEN%^green%^BOLD%^ crystal.  The edge of the shield is lined with a "+
    "%^BOLD%^%^WHITE%^silvery alloy%^GREEN%^ and an insignia of a %^BOLD%^%^YELLOW%^glowing "+
    "%^CYAN%^orb%^BOLD%^%^GREEN%^ is engraved into the front of it.  A slight %^YELLOW%^aura"+
    "%^BOLD%^%^GREEN%^ of light is constantly given off by it.  An inscription is inscribed "+
    "into the back of it above the %^MAGENTA%^leather straps%^BOLD%^%^GREEN%^ that buckle to "+
    "hold it securely in place.%^RESET%^");
    set_lore("Legends suggest that this shield was crafted by elves during the Crown Wars. They"+
    "were lost to time and no one is quite sure how they ended up on Deku. One theory is that the."+
    "Shadowlord is a corrupted elven magi who used dark magic to create himself an island of horrors"+
    "bringing them with him. Other theories suggest that they were stolen by Lord Blacktongues forces to"+ 
    "ensure he could corrupt them for his mortal minions, long after the Crown Wars.");
    set_language(LANGS[random(sizeof(LANGS))]);
    set_read("When %^YELLOW%^daylight%^RESET%^ is needed, it shall be, if only you command me");
    set_value(1000);
    set_property("enchantment",3);
    set_wear((:TO,"wear_func":));
    set_item_bonus("sight bonus", 2);
    set_item_bonus("negative energy resistance", 10);
    set_remove((:TO,"remove_func":));
    uses = 3 + random(6);
    set_ac(0);
}

int make_day()
{
    if(!objectp(ETO)) return 0;
    if (ETO->query_bound() || ETO->query_unconscious()) 
    {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }
    if(!query_worn()) 
    {
        write("You must wear the shield first.");
        return 1;
    }
    if(uses > 0)
    {
        if(time() - daylight_time > 100)
        {
            tell_object(ETO,"%^BOLD%^%^WHITE%^A bright %^YELLOW%^light%^BOLD%^%^WHITE%^ bursts "+
            "forth from your shield!%^RESET%^");
            tell_room(ETO,"%^BOLD%^%^WHITE%^A bright %^YELLOW%^light%^BOLD%^%^WHITE%^ bursts "+
            "forth from the "+ETO->query_cap_name()+"%^BOLD%^%^WHITE%^'s shield!%^RESET%^",ETO);
            new("/cmds/spells/d/_daylight.c")->use_spell(TP,0,10,8,"cleric");
            daylight_time = time();
            uses--;
            return 1;
        }
        write("The shield fails to respond.");
        return 1;
    }
    write("The shield is out of charges.");
    return 1;
}

int wear_func()
{
    int x;
    if(!TO->query_owns_item(ETOQN) && interactive(ETO)) 
	{
        tell_object(ETO,"The shield refuses you!");
        return 0;
    }
    if(!ETO->query_invis()) 
    {
        tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+"%^MAGENTA%^ buckles the "+
        "leather straps of "+ETO->QP+"%^MAGENTA%^ shield.%^RESET%^",ETO);
    }
    x = TO->query_property("enchantment");
    
    if(ALIGN->is_evil(ETO) && x > 0) 
    {
        TO->remove_property("enchantment");
    }

    if(ALIGN->is_neutral(ETO) && x >= 0) 
    {
        while((int)TO->query_property("enchantment") != 2) 
        {
            TO->remove_property("enchantment");
            TO->set_property("enchantment",2);
        }
    }            
    if(ALIGN->is_good(ETO) && x >= 0) 
    {
        while((int)TO->query_property("enchantment") != 3) {
            TO->remove_property("enchantment");
            TO->set_property("enchantment",3);
        }
    }

    tell_object(ETO,"%^MAGENTA%^You buckle the leather straps of your "+
    "shield, securing it tightly "+
    "in place.%^RESET%^ ");
    return 1;
}

int remove_func()
{
    if(!ETO->query_invis()) 
    {
        tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+"%^MAGENTA%^ unbuckles the "+
        "leather straps of "+ETO->QP+"%^MAGENTA%^ shield.%^RESET%^",ETO);
    }
    tell_object(ETO,"%^MAGENTA%^You unbuckle the leather straps holding your shield in place."+
    "%^RESET%^");
    return 1;
}