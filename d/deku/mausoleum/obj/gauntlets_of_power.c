#include <std.h>
inherit "/d/common/obj/armour/gauntlets";
object myOwner;

void create()
{
    ::create();
    set_name("steel gauntlets");
    set_id(({ "gauntlets", "gauntlets of power", 
    "steel gauntlets", "gauntlet", "gloves"}));
    
    set_short("%^BOLD%^%^WHITE%^Gauntlets of P%^BOLD%^%^BLACK%^o"+
    "%^WHITE%^w%^BLACK%^e%^WHITE%^r%^RESET%^");
    
    set_obvious_short("%^BOLD%^%^WHITE%^steel gauntlets%^RESET%^");
    
    set_long("%^BOLD%^%^WHITE%^These gauntlets are made of a thick "+
    "and heavy steel m%^CYAN%^e%^WHITE%^sh. They are longer than normal, extending up to "+
    "close to the elbow of the wearer. Portions of the steel shine "+
    "br%^CYAN%^i%^WHITE%^ll%^CYAN%^ia%^WHITE%^ntly and there are "+
    "other %^BOLD%^%^BLACK%^darker sections%^BOLD%^%^WHITE%^ that "+
    "form what almost seems like an intentional striped p%^BLACK%^a%^WHITE%^"+
    "tt%^BLACK%^e%^WHITE%^rn. There are %^CYAN%^indiscernable%^WHITE%^ "+
    "symbols covering the %^BOLD%^%^BLACK%^darker sections%^WHITE%^ and "+
    "you believe the symbols are what give the gauntlets power. "+
    "The inside of the gauntlets are "+
    "padded with a %^RESET%^%^RED%^thick red%^BOLD%^%^WHITE%^ "+
    "fabric in order to prevent chaffing.%^RESET%^");

    set_value(3500);
    
    set_lore("%^BOLD%^%^WHITE%^These gauntlets are known as "+
    "gauntlets of power. It is believed that there were many "+
    "different forms of them and that each was created using a "+
    "different method throughout history. This particular set was "+
    "rumored to have been imbued with magic by Aorus Devar, "+
    "and given to some warriors who were closet to him. Time has "+
    "forgotten most of those warriors and most of these gauntlets "+
    "as well.%^RESET%^");
    
    set_property("lore difficulty",25);    
    set_size(1);
    set_property("enchantment",3);
    set_item_bonus("strength", 2);
    set_item_bonus("endurance", 1);
    set_wear((:TO,"wear_me":));
    set_remove("%^BOLD%^%^BLUE%^You remove the gauntlets and feel "+
    "the power ebb away.%^RESET%^");
}

void init() 
{
    ::init();
    if(interactive(ETO)) 
    {
        if(TO->add_item_owner(ETOQN))
        {
            tell_object(ETO, "%^BOLD%^%^WHITE%^You feel yourself "+
            "binding with the gauntlets!%^RESET%^");
            if((int)TO->query_size() != (int)ETO->query_size()) 
            {
                set_size(ETO->query_size());
                tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the gauntlets "+
                "shifting and transforming to fit you!%^RESET%^");
            }
        }
    }
}

int wear_me() 
{
    if(ETO->query_highest_level() < 20) {
        tell_object(ETO,"%^BOLD%^%^BLACK%^You are not powerful "+
        "enough to wear these gauntlets!%^RESET%^");
        return 0;
    }
    if(!TO->query_owns_item(ETOQN) && ETO->is_player()) 
    {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The gauntlets "+
        "have been bound to another!%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLUE%^You slip your hands "+
    "into the gauntlets and feel the power from them "+
    "strengthen you!%^RESET%^");
    return 1;
}