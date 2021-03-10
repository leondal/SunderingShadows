// this one is a trade for the bloodstone amulet from the watcher
//hades 7-12-20
#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create()
{
    ::create();
    set_name("Moonstone Amulet");
    set_id(({ "amulet", "moonstone amulet", "amulet of the moon" }));
    set_short("%^RESET%^%^CYAN%^Amu%^BLUE%^l%^CYAN%^et of the M%^BLUE%^o%^CYAN%^on%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^mo%^BLUE%^o%^CYAN%^nstone a%^BLUE%^m%^CYAN%^ulet%^RESET%^");
    set_lore("The elves in their fight against the fey'ri crafted "+
    "these amulets to protect them from the hellish power of the "+
    "fey'ri.  They are created by purifying the bloodstones that "+
    "the fey'ri create with infernal magic.");
    set_property("lore difficulty", 30);
    set_long("%^CYAN%^This is an amulet on a braided hemp cord.   A half-moon"+
    " shaped moonstone hangs from the cord which can be tied around "+
    "the neck.   It glows with %^BOLD%^fey magic.");

    set_size(-1);
    set_value(5000);
    set_wear((: TO, "wear_me" :));
    set_property("enchantment", 4 + random(2));
    set_item_bonus("fire resistance", 10);
    set_item_bonus("cold iron resistance", -10); 
    set_item_bonus("positive energy resistance", -5); 
}
int wear_me()
{
    tell_object(ETO, "%^CYAN%^You secure the amulet around your neck and fey power fills you");
    return 1;
}
