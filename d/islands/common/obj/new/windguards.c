//Added Psion and cleaned up the code a bit - Cythera 5/06
//Runs from inherit properly now. Nienne, 08/07
//Changed wear/remove to ETO/EETO rather than TP/ETP. Nienne, 08/07
#include <std.h>

inherit "/d/common/obj/armour/bracers.c";

void create()
{
    ::create();
    set_name("bracers");
    set_id(({ "wind guards", "bracers", "guards" }));
    set_short("%^BOLD%^%^WHITE%^W%^RESET%^i%^BOLD%^%^BLACK%^n%^WHITE%^d%^RESET%^ G%^BOLD%^%^BLACK%^u%^WHITE%^a%^RESET%^r%^BOLD%^%^BLACK%^d%^WHITE%^s%^RESET%^");
    
    set_obvious_short("%^BOLD%^%^WHITE%^A pair of white bracers%^RESET%^");
    
    set_long("%^RESET%^%^BOLD%^These bracers are made of an odd metal with a soft %^RESET%^"+
        "white%^BOLD%^%^WHITE%^ tint. The hue changes with the light seemingly like "+
        "%^RESET%^c%^BOLD%^l%^RESET%^o%^BOLD%^u%^RESET%^d%^BOLD%^s that roll past a "+
        "scenery. Small %^BOLD%^%^BLUE%^aventurines%^WHITE%^ and %^CYAN%^turquoises"+
        "%^WHITE%^ line the front ends of the bracers, sparkling softly with a faint"+
        " white glow. On top of each bracer there is an intricate etching of a cloud.%^RESET%^");
    
    set_value(300000);
    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("athletics",6);
    set_item_bonus("attack bonus",7);
    
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"strike_func":));
        
    set_lore("This set of bracers was made by the mage only known as Tornado, a "+
        "follower of Akadi. Facinated with the power and grace of the elements for"+
        " everday and combat use, he thought he would honor them with bracers. He "+
        "made a set of each element he thought worthy, it is no accident no guards "+
        "of the earth were never made.");
        
    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wear_func()
{
    ::check();
    tell_room(EETO,"%^RESET%^%^BOLD%^A slight breeze ruffles "+ETO->QCN+"'s clothing%^RESET%^"+
        "%^BOLD%^ as "+ETO->QS+" slips on a pair of white bracers. %^RESET%^",ETO);
    tell_object(ETO,"%^RESET%^%^BOLD%^You fasten the bracers on and feel a slight breeze ruffle your clothing.%^RESET%^");
    return 1;
}


int remove_func()
{
    tell_room(EETO,"%^RESET%^%^BOLD%^"+ETO->QCN+"%^RESET%^%^BOLD%^ reluctantly removes the"+
        " white bracers.%^RESET%^",ETO);
    tell_object(ETO,"%^RESET%^%^BOLD%^You reluctantly remove the bracers and feel"+
        " a bond to the air lessen.%^RESET%^");
    return 1;
}


int strike_func(int damage, object what, object who)
{
    if(!random(2)) 
    {
        tell_room(environment(query_worn()),"%^RESET%^%^BOLD%^"+ETO->QCN+"%^RESET%^%^BOLD%^ moves like the wind"+
            " to parry "+who->QCN+"%^RESET%^%^BOLD%^'s wild thrust with "+ETO->QP+" bracers.%^RESET%^",({ETO,who}));
        tell_object(ETO,"%^RESET%^%^BOLD%^You feel a burst of speed that aids you to parry "+
            ""+who->QCN+"%^RESET%^%^BOLD%^'s wild thrust with your bracers.%^RESET%^");
        tell_object(who,"%^RESET%^%^BOLD%^Your wild thrust is parried by "+ETO->QCN+"%^RESET%^");
        return 0;
    }
    return damage;
}
