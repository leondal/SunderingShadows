#include <std.h>
inherit "/d/common/obj/armour/greaves";
object myOwner;

void create()
{
    ::create();
    set_name("shiny steel greaves");
    set_id(({ "greaves", "greaves of power", 
    "steel greaves", "greave", "pants", "shiny steal greaves"}));
    
    set_short("%^BOLD%^%^WHITE%^Greaves of P%^BOLD%^%^BLACK%^o"+
    "%^WHITE%^w%^BLACK%^e%^WHITE%^r%^RESET%^");
    
    set_obvious_short("%^BOLD%^%^WHITE%^shiny steel greaves%^RESET%^");
    
    set_long("%^BOLD%^%^WHITE%^These greaves are made from a very thick "+
    "shiny steel. They literally gl%^CYAN%^ea%^WHITE%^m when even the "+
    "smallest light touches their surface. They are made so that they fit "+
    "snugly against the legs of the wearer. There are small %^CYAN%^indiscernable "+
    "symbols%^WHITE%^ engraved into their surface, the symbols seem to "+
    "refract any light that comes into contact with them. You believe that "+
    "whatever power that the greaves have is because of these "+
    "strange symbols. The greaves are padded on the inside with a "+
    "%^BOLD%^%^BLACK%^dark fabric%^BOLD%^%^WHITE%^ in order to prevent "+
    "chaffing when worn.%^RESET%^");

    set_value(3500);
    
    set_lore("%^BOLD%^%^WHITE%^These are greaves of power. Some rumors "+
    "suggest that there have been several different versions of them "+
    "throughout history, with various methods of creation. These particular "+
    "pair were rumored to have been imbued with magic by Aorus Devar. Some "+
    "believe that he gave them to those who were closest to him, in order to "+
    "empower them and make them more perceptive of the reality around them. "+
    "It is unknown whether or not there is any truth to these rumors.%^RESET%^");
    
    set_property("lore difficulty",25);    
    set_size(1);
    set_property("enchantment",3);
    set_item_bonus("caster level", 1);
    set_item_bonus("perception", 2);
    set_wear((:TO,"wear_me":));
    set_remove("%^BOLD%^%^BLUE%^You remove the greaves and feel "+
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
            "binding with the greaves!%^RESET%^");
            if((int)TO->query_size() != (int)ETO->query_size()) 
            {
                set_size(ETO->query_size());
                tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the greaves "+
                "shifting and transforming to fit you!%^RESET%^");
            }
        }
    }
}

int wear_me() 
{
    if(ETO->query_highest_level() < 20) {
        tell_object(ETO,"%^BOLD%^%^BLACK%^You are not powerful "+
        "enough to wear these greaves!%^RESET%^");
        return 0;
    }
    if(!TO->query_owns_item(ETOQN) && ETO->is_player()) 
    {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The greaves "+
        "have been bound to another!%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLUE%^You wear the greaves and "+
    "feel yourself empowered by them!%^RESET%^");
    return 1;
}