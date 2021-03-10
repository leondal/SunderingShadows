#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/armour/bracers";

void create()
{
    ::create();
    set_name("blue metal gauntlet");
    set_id(({ "gauntlet", "metal gauntlet","blue metal gauntlet",
    "narameons gauntlet","narameons blue metal gauntlet","hand",
    "blue hand","narameons hand","narameons blue hand", "gauntlets",
    "hands", "blue hands", "narameons hands"}));

    set_short("%^RED%^Naram%^BOLD%^%^WHITE%^eo%^RESET%^%^RED%^"+
    "n's %^BOLD%^%^BLUE%^bl%^BOLD%^%^BLACK%^u%^BLUE%^"+
    "e h%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^nds%^RESET%^");

    set_obvious_short("%^RESET%^%^RED%^A pair of %^BOLD%^%^BLACK%^blue %^BLACK%^meta%^BLUE%^l%^RESET%^%^RED%^ gauntlets%^RESET%^");

    set_long("%^BLUE%^These gauntlets has been designed to fit "+
    "tightly over the left hand. They are made from a deep blue "+
    "substance that is easily recognized as a metal. The fingers "+
    "of the gauntlets are made from a %^BOLD%^%^BLACK%^m%^RESET%^"+
    "%^BLUE%^e%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^h of the metal and "+
    "a slightly lighter colored steel. "+
    "The palm of the gauntlets are a much %^BOLD%^%^BLACK%^darker "+
    "%^RESET%^%^BLUE%^hue that borderlines on the edge of "+
    "%^BOLD%^%^BLACK%^total blackness%^RESET%^%^BLUE%^. "+
    "The upperside of the gauntlets are %^RED%^emblazed%^RESET%^"+
    "%^BLUE%^ with an intense and out of control "+
    "%^RESET%^blue flame%^BLUE%^. The emblems seem almost "+
    "real and even just hastingly glancing at them "+
    "causes your eyes to burn from the invisible heat that seems to "+
    "be given off from them.%^RESET%^");

    set_lore("These gauntlets were crafted for the warrior Narameon. It "+
    "has been ages since they were last seen, they have been thought lost, along "+
    "with their owner, Narameon. He was "+
    "said to frequently use a shield and some "+
    "suggest that they granted him the knowledge of how "+
    "to use his shield to reflect spells back at those who "+
    "dared cast a harmful one his way.");

    set_weight(3);
    set_value(2000);
    //set_item_bonus("temporary feats", "reflection");
    //set_type("chain");
    //set_property("enchantment", 4);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_me":));
}

void init()
{
    ::init();
    if(interactive(ETO))
    {
        if(TO->add_item_owner(ETOQN))
        {
            set_size(ETO->query_size());
        }
    }
}

int wear_func(){

    if(ETO->query_lowest_level() < 25 || !TO->query_owns_item(ETOQN))
    {
        tell_object(ETO,"%^BOLD%^%^BLUE%^The gauntlet fails to fit "+
        "you!%^RESET%^");
        return 0;
    }

    if(!ETO->query_invis())
    {
        tell_room(EETO,ETOQCN+"%^BLUE%^ struggles with the ill-fitted "+
        "metal gauntlet and finally pulls it into place.%^RESET%^",ETO);
    }

    tell_object(ETO,"%^BLUE%^You struggle with the ill-fitted "+
    "blue metal gauntlet and finally manage to pull it into place. "+
    "%^RESET%^");
    ETO->add_temporary_feat("reflection");
    return 1;
}

int remove_me()
{
    if(!ETO->query_invis())
    {
        tell_room(EETO,ETOQCN+"%^BLUE%^ struggles with "+ETO->QP+
        " ill-fitted metal gauntlet and manages to pull it from "+
        ETO->QP+" hand!%^RESET%^",ETO);
    }
    tell_object(ETO,"%^BLUE%^You struggle with the ill-fitted "+
    "blue metal gauntlet and finally manage to pull it from your "+
    "hand!%^RESET%^");
    ETO->remove_temporary_feat("reflection");
    return 1;
}

int isMagic(){
    int y;
    y = ::isMagic();
    y = y + 1;
    return y;
}

int is_metal() { return 1; }
