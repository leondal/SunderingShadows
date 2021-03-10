#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/clothing/gloves";
int can_see;
int charges;

int set_charges(int x) 
{
    return charges = x;
}

int adj_charges(int x) 
{
    return charges += x;
}

int query_charges() {   return charges; }

void create()
{
    string tmp;
    ::create();
    set_name("black leather gloves");
    set_id(({ "glove", "gloves", "black leather glove", "black leather gloves", "leather glove", "leather gloves" }));
	
    set_short("%^BOLD%^%^WHITE%^Ish%^RED%^n%^BOLD%^%^WHITE%^or's "+
    "gloves of %^YELLOW%^li%^BOLD%^%^WHITE%^gh%^YELLOW%^t%^RESET%^");
    set_obvious_short("black leather gloves");

    set_lore("These gloves were crafted by a master tailor and "+
    "then imbued with magic by the wizard ishnor, the magic is "+
    "said to grant the wearer an ability to see in dark places "+
    "and some have been rumored to grant the wearer the "+
    "ability to return the light to their eyes.");
    set_value(1000);
    set_size(-1);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_me":));
    can_see = random(2);

    tmp = "%^BOLD%^%^BLACK%^These skin tight gloves "+
    "are made from a thick leather that has been dyed a "+
    "midnight black.  They extend up the forearms of the "+
    "wearer and are embroidered with several %^BOLD%^%^YELLOW%^"+
    "gold%^BOLD%^%^BLACK%^ and %^BOLD%^%^WHITE%^silver%^BOLD%^"+
    "%^BLACK%^ circular patterns that intertwine harmoniously "+
    "with one another.  The thread used to sew the patterns "+
    "is thin and gives off a slightly eerie and %^CYAN%^iridescent "+
    "glow%^BOLD%^%^BLACK%^.  The fingers of the gloves are "+
    "open and the ends have been melted in an attempt to make "+
    "unraveling the fabric difficult.  Another, slightly tinged "+
    "%^BOLD%^%^YELLOW%^gold%^BOLD%^%^BLACK%^ pattern, this one "+
    "in the shape of a %^CYAN%^st%^YELLOW%^a%^CYAN%^rb%^YELLOW%^u"+
    "%^CYAN%^rst%^BOLD%^%^BLACK%^, has "+
    "been embroidered into the palm of each glove.%^RESET%^";

    if(!can_see) 	
    {
        set_read("%^YELLOW%^In desperate times, when all light "+
        "has failed, let the eyes %^RED%^see%^YELLOW%^.%^RESET%^");
        set_language("elven");
        tmp += "  %^BOLD%^%^BLACK%^An %^BLUE%^inscription%^BOLD%^"+
        "%^BLACK%^ has been sewn beneath the patterns on "+
        "the palms.%^RESET%^";
        set_heart_beat(1);
    }
    set_long(tmp);
    charges = 2 + random(2);
    set_item_bonus("sight bonus", 1);
}

void init() 
{
    ::init();
    if(!can_see) 
    {
        add_action("restore_sight","see");
    }
    if(interactive(ETO)) 
    {
        TO->add_item_owner(ETOQN);
    }
}

int restore_sight() 
{
    if(can_see)
    {
        return 0;
    }
    if(!TO->query_worn()) 
    {
        tell_object(TP,"You must first wear the gloves!");
        return 1;
    }
    if(/*ETO->query_temporary_blinded() || */ETO->query_blind() && charges > 0) 
    {
        tell_object(ETO,"%^CYAN%^You place your gloves over your "+
        "eyes and feel their magic instantly restore light to your "+
        "eyes!%^RESET%^");
        
        tell_room(EETO,ETOQCN+"%^CYAN%^ places "+ETO->QP+" gloves "+
        "over "+ETO->QP+" eyes and you watch in amazement as "+
        "the light is instantly restored to them!%^RESET%^",ETO);
        charges--;
        //ETO->set_temporary_blinded(0);
        ETO->set_blind(0);
        return 1;
    }
    tell_object(ETO,"You place your gloves over your "+
    "eyes.");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETOQCN+" places "+ETO->QP+" gloves "+
        "over "+ETO->QP+" eyes.",ETO);
    }
    return 1;
}


int wear_func()
{
    
    if(ETO->query_highest_level() < 20) 
    {
        tell_object(ETO,"%^RED%^The magic of the gloves is too "+
        "powerful for you to control!%^RESET%^");
        return 0;
    }

    if(!TO->query_owns_item(ETOQN)) 
    {
        tell_object(ETO,"%^RED%^The magic in the gloves "+
        "resists you!%^RESET%^");
        return 0;
    }

    tell_room(EETO,ETO->QCN+"%^BLUE%^ slips "+ETO->QP+" hands into "+
    "the black gloves and the patterns on them flash with a brilliant "+
    "burst of %^BOLD%^%^WHITE%^light%^RESET%^%^BLUE%^!%^RESET%^",ETO);
	
    tell_object(ETO,"%^BLUE%^As you slip your hands into the "+
    "black gloves the patterns on them flash with a brillant burst of "+
    "%^BOLD%^%^WHITE%^light%^RESET%^%^BLUE%^!%^RESET%^");
    return 1;
}

int remove_me() 
{
    tell_room(EETO,ETO->QCN+"%^RED%^ removes "+ETO->QP+" gloves "+
    "and the patterns on them dim.%^RESET%^",ETO);
    tell_object(ETO,"%^RED%^As you remove your gloves the patterns "+
    "on them dim.%^RESET%^");
    return 1;
}

void heart_beat() 
{
    if(!objectp(TO) || !objectp(ETO)) return;
    if(charges >= 3)
    {
        return;
    }
    if((string)EVENTS_D->query_time_of_day() == "dawn" 
    && TO->query_worn()) 
    {
        if(!random(1000) && charges < 3) 
        {
            tell_object(ETO,"%^CYAN%^You feel a sudden pulse surge "+
            "through your gloves!%^RESET%^");
            charges++;
        }
    }
    return;
}