#include <std.h>

inherit "/d/common/obj/armour/hide.c";


void create()
{
    ::create();

    set_name("chainshirt");

    set_id(({ "chain", "chainshirt", "chain shirt", "shirt", "elven chain", "elven mail", "elven chainmail", "elven chain mail" }));

    set_short("%^RESET%^%^GREEN%^E%^BOLD%^%^WHITE%^l%^RESET%^%^GREEN%^ven Ch%^BOLD%^%^WHITE%^ai%^RESET%^%^GREEN%^nmail%^RESET%^");

    set_obvious_short("%^BOLD%^%^WHITE%^ornate s%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^lver cha%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^nsh%^RESET%^%^GREEN%^i%^BOLD%^%^WHITE%^rt%^RESET%^");

    set_long("%^RESET%^%^GREEN%^This shirt of armor is made of interlocking "+
        "%^BOLD%^%^WHITE%^silver rings%^RESET%^%^GREEN%^. Underneath the thin silver is a thin layer of "+
        "quilted silk, "+
        "to prevent chafing and cushion the impact of blows. Several layers of the"+
        " silvered mail are hung over the vital "+
        "areas. The links yield easily to blows, absorbing some the shock. Most of "+
        "the weight is carried on the shoulders. The mail shifts to meet the body "+
        "of the wearer.  Mid chest there is a %^BOLD%^%^GREEN%^flawless emerald%^RESET%^%^GREEN%^"+
        " set into the armor and very %^BOLD%^%^GREEN%^small emeralds%^RESET%^%^GREEN%^"+
        " are symmetrically decorated on various parts of the mail.");

    set_value(200000);

    set_lore(
        " The Mail of the Elves is the pride among their race.  For they alone have"+
        " gained the ability to weave pure threads of silver, silk, and nature itself"+
        " into each suit of armor.  Many would kill for a suit of this rare armor,"+
        " something the elves adamantly protect.");

    set_property("no curse",1);
    set_property("enchantment",7);

    set_size(-1);

    set_item_bonus("dexterity",6);
    set_item_bonus("magic resistance",4);

    set_remove((:TO,"remove_func":));
    set_struck((:TO,"strike_func":));
    set_wear((:TO,"wear_func":));

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wear_func()
{
    tell_room(EETO,"%^RESET%^%^GREEN%^"+ETOQCN+" slips on a gleaming %^BOLD%^%^WHITE%^silver chainshirt%^RESET%^%^GREEN%^ encrusted with %^BOLD%^%^GREEN%^emeralds%^RESET%^%^GREEN%^.",ETO);
    tell_object(ETO,"%^RESET%^%^GREEN%^You slip on the light suit of %^BOLD%^%^WHITE%^chainshirt%^RESET%^%^GREEN%^ and marvel how the %^BOLD%^%^GREEN%^emeralds sparkle%^RESET%^%^GREEN%^.");
    if((string)ETO->query_race() == "elf")
    {
        set_item_bonus("sight bonus",5);
    }
    else
    {
        if((string)ETO->query_race() == "half-elf")
        {
            set_item_bonus("sight bonus",1);
        }
        else
        {
            set_item_bonus("sight bonus",0);
        }
    }
    return 1;
}


int remove_func()
{
    tell_room(EETO,"%^RESET%^%^GREEN%^"+ETOQCN+" slips off the gleaming suit of %^BOLD%^%^WHITE%^chainshirt%^RESET%^.",ETO);
    tell_object(ETO,"%^RESET%^%^GREEN%^You slip off the %^BOLD%^%^WHITE%^chainshirt%^RESET%^%^GREEN%^, feeling the pride of the elven nation fade away.");
    return 1;
}


int strike_func(int damage, object what, object who)
{
    if(!random(2))
    {
        tell_room(EETO,"%^RESET%^GREEN%^Ethereal vines burst "+
            "out of the %^BOLD%^%^GREEN%^emeralds %^RESET%^%^GREEN%^on "+ETOQCN+" mail, wrapping around "+
            ""+ETO->QP+" body to shield "+ETO->QO+" from "+who->QCN+"'s "+
            "blow.",({ETO,who}));
        tell_object(ETO,"%^RESET%^%^GREEN%^Ethereal vines wrap around you, for a"+
            " brief moment you feel your mind pulled into a deeper "+
            "connection with nature and the Weave.");
        tell_object(who,"%^RESET%^%^GREEN%^Ethereal vines burst out of"+
            " the emeralds on "+ETOQCN+"'s mail, wrapping around "+
            ""+ETO->QP+" body, shielding "+ETO->QO+" from your blow.");
        return 0;
    }
    return damage;
}


int is_metal() { return 1; }
