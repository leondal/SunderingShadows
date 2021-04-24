//Added Psion and cleaned up code a bit - Cythera 5/06
//Runs from inherit properly now. Nienne, 08/07
#include <std.h>

inherit "/d/common/obj/armour/bracers.c";


void create()
{
    ::create();
    set_name("bracers");
    
    set_id(({ "flame guards", "guards", "bracers" }));
    
    set_short("%^RESET%^%^RED%^F%^BOLD%^l%^YELLOW%^a%^RESET%^%^ORANGE%^"+
        "m%^RED%^e %^BOLD%^G%^YELLOW%^u%^RESET%^%^ORANGE%^a%^RED%^r"+
        "%^BOLD%^d%^YELLOW%^s%^RESET%^");
        
    set_obvious_short("%^RESET%^%^RED%^A pair of %^BOLD%^reddish%^RESET%^%^RED%^ bracers%^RESET%^");
    
    set_long("%^RESET%^%^ORANGE%^These bracers are made of an odd metal"+
        " with a faint %^BOLD%^%^RED%^reddish%^RESET%^%^ORANGE%^ tint."+
        " The hue changes with the light seemingly like the "+
        "dancing of a flickering %^RED%^f%^BOLD%^l%^RESET%^%^ORANGE%^"+
        "a%^YELLOW%^m%^RESET%^%^RED%^e%^ORANGE%^."+" Small %^BOLD%^"+
        "%^RED%^f%^YELLOW%^i%^RED%^re op%^YELLOW%^a%^RED%^ls%^RESET%^"+
        "%^ORANGE%^ and %^RED%^f%^BOLD%^i%^RESET%^%^RED%^r%^BOLD%^e "+
        "agates%^RESET%^%^ORANGE%^ line the front ends of the bracers "+
        "and they sparkle softly with a faint %^RED%^red%^ORANGE%^ glow."+
        " On top of each bracer there is a twisting tendrils of %^BOLD%^"+
        "%^RED%^fire%^RESET%^%^ORANGE%^ motif.%^RESET%^");
        
    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("damage bonus",7);
    set_item_bonus("endurance",6);
    
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"strike_func":));
    
    set_lore("This set of bracers was made by the mage only known as Tornado,"+
        " a follower of Akadi. Facinated with the power and grace of the elements"+
        " for everday and combat use, he thought he would honor them with bracers."+
        " He made a set of each element he thought worthy, it is no accident no "+
        "guards of the earth were never made.");
           
    set_value(300000);
    
    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wear_func()
{
    ::check();

    tell_room(EETO,"%^RED%^%^BOLD%^Waves of heat rise up off "+ETO->QCN+" bracers"+
        " as "+ETO->QS+" secures them in place.%^RESET%^",ETO);
    tell_object(ETO,"%^RED%^%^BOLD%^You feel a comforting heat as you "+
        "secure the bracers on.%^RESET%^");
    return 1;
}


int remove_func()
{
    tell_room(EETO,"%^RED%^%^BOLD%^"+ETO->QCN+"%^RED%^%^BOLD%^ reluctantly "+
        "removes "+ETO->QP+" bracers.%^RESET%^",ETO);
    tell_object(ETO,"%^RED%^%^BOLD%^You reluctantly remove the bracers and feel"+
        " a bond lessen.%^RESET%^");
    return 1;
}


int strike_func(int damage, object what, object who)
{
    if(!random(2))
    {
        tell_room(environment(query_worn()),"%^RED%^%^BOLD%^"+ETO->QCN+" moves "+
            "with the speed of an inferno to parry "+who->QCN+"'s attack.%^RESET%^",({ETO,who}));
        tell_object(ETO,"%^RED%^%^BOLD%^You feel a swift heat burn in you as you "+
            "parry "+who->QCN+"'s attack.%^RESET%^");
        tell_object(who,"%^RED%^%^BOLD%^"+ETOQCN+" moves with the speed of an inferno"+
            " to parry your attack with "+ETO->QP+" bracers.%^RESET%^");
        return 0;
    }
    return damage;
}
