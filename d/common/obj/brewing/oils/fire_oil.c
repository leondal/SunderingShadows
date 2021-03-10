#include <std.h>
inherit "d/common/obj/brewing/oils/weapon_oil_inherit.c";

void create() {
    ::create();
    set_name("fire oil");
    set_id(({"jar","liquid","oil","fire oil"}));
    set_obvious_short("%^RED%^A jar of %^BOLD%^fl%^RESET%^%^RED%^a%^BOLD%^m%^RESET%^%^RED%^i%^BOLD%^ng %^RESET%^%^RED%^liquid%^RESET%^");
    set_short("%^RED%^F%^BOLD%^i%^BLACK%^r%^RESET%^%^RED%^e %^BOLD%^o%^RESET%^%^RED%^i%^BOLD%^l%^RESET%^");
    set_long("%^RESET%^%^BOLD%^This jar is nearly as large as a small human head.  It is a "
        "square shape with a narrow neck that tapers up to a corked top.  "
        "Inside the jar a %^RED%^red liquid%^RESET%^%^BOLD%^ dances %^BLACK%^angrily"
        " %^WHITE%^about as though"
        " it were on %^BOLD%^%^RED%^f%^BLACK%^i%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^BOLD%^."
        "  The %^RED%^liquid%^RESET%^%^BOLD%^ seems to never actually touch the insides"
        " of the fortified glass but is kept apart from it by forces unknown.%^RESET%^");
    set_lore("%^RESET%^%^RED%^It is said that a pyromancer named Jaced Laveckia is the "
        "original creator of the fire oil.  Once applied to a weapon, it will embue "
        "it with its magic and permanently light the weapon on fire, striking terror"
        " into any foe the wielder comes across.");
    reversed = 0; 

}

int apply(string str) 
{
    object target;
    if(!objectp(TO) || !objectp(ETO)) return 0;
    if(!objectp(target = ::apply(str, 1))) return 1;
    
    tell_object(ETO,"%^RED%^You turn the jar up and the fluid seems to leap out "
        "onto your "+target->query_short()+" %^RED%^of it's own accord.");
    tell_room(EETO,"%^RED%^"+ETO->QCN+" pours some fiery liquid out of a "
        "jar and onto "+ETO->QP+" "+target->query_short()+".",ETO);

    if(reversed) 
    {
      tell_object(ETO,"%^RED%^Your "+target->query_short()+" is completely coated "
        "in the glowing goo before it hisses and fizzles away into nothing, leaving "
        "only an unpleasantly acrid smell behind.");
      tell_room(EETO,"%^RED%^The liquid on "+ETO->QCN+"'s "+target->query_short()+" "
        "hisses and fizzles away into nothing, leaving only an unpleasantly acrid "
        "smell behind.", ETO);
    }
    else  {
      tell_object(ETO,"%^RED%^Your "+target->query_short()+" %^RED%^is completely coated "
        "in the fiery liquid before it %^BOLD%^errupts %^RESET%^%^RED%^with %^BOLD%^flame!");
      tell_room(EETO,"%^RED%^The liquid on "+ETO->QCN+"'s "+target->query_short()+" "
        "%^BOLD%^%^RED%^bursts %^RESET%^%^RED%^into %^BOLD%^%^RED%^flame%^RESET%^%^RED%^!", ETO);
      target->set_property("oiled","damage bonus fire 5");
      target->remove_property("added short string");
      target->set_property("added short string",({" %^RESET%^%^RED%^{{%^BOLD%^FLAMING%^RESET%^%^RED%^}}%^RESET%^"}));
      target->set_property("added short",target->query_property("added short string"));

    }
    TO->remove();
    return 1;
}

void set_reversed(int mystatus) { reversed = mystatus; }