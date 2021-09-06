#include <std.h>
inherit "/d/common/obj/jewelry/circlet.c";

void create()
{
    ::create();
    set_name("headband of mental prowess");
    set_id(({ "circlet", "headband", "silver circlet", "mental headband", "mental circlet", "headband of mental prowess" }));
    set_short("%^BOLD%^%^WHITE%^Headband of %^CYAN%^M%^BLUE%^e%^CYAN%^nt%^BLUE%^a%^CYAN%^l Pr%^BLUE%^o%^CYAN%^w%^BLUE%^e%^CYAN%^ss%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r headband adorned with a %^BOLD%^%^BLUE%^bl%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e g%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^m%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This simple s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r headband has a small %^BOLD%^%^BLUE%^bl%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e g%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^m %^WHITE%^set so that when it rests upon the forehead of the wearer, the yellow gem sits perched on the wearer's brow as if it were a third eye in the middle of his forehead.  Despite its simplicty, the circlet has obviously been wrought by the hand of a master jeweller.%^RESET%^");
    set_lore("%^BOLD%^%^WHITE%^The Headbands Mental Prowess were once a common sight upon the brows of the realm's spellcasters, but those crafted lately are merely pale imitations of ones like this example.  It is rumored that an even more powerful version, known as the Headband of Mental Superiority, once existed.  However, no examples of it have been seen in over three thousand years.%^RESET%^");
    set_value(400000);
    set_property("lore difficulty", 0);
    set_size(-1);
    set_property("enchantment", 7);
    set_wear((: TO, "wear_func" :));
    set_remove((: TO, "remove_func" :));
    set_item_bonus("intelligence", 6);
    set_item_bonus("wisdom", 6);
    set_item_bonus("will", 6);
	set_property("quest required", "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
	set_property("level required", 35);
}

int wear_func()
{
    tell_object(ETO, "The %^BOLD%^%^BLUE%^gem %^WHITE%^on the " + query_obvious_short() + " %^BOLD%^%^WHITE%^begins to softly %^CYAN%^glow %^WHITE%^as you place it upon your brow.%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^WHITE%^The %^BOLD%^%^BLUE%^gem %^WHITE%^on " + ETO->QCN + "'s " + query_obvious_short() + " %^BOLD%^%^WHITE%^begins to %^BOLD%^%^CYAN%^glow %^WHITE%^as " + ETO->QS + " places it upon " + ETO->QP + " brow.%^RESET%^", ETO);
    return 1;
}

int remove_func()
{
    tell_object(ETO, "The %^BOLD%^%^BLUE%^gem %^WHITE%^on the " + query_obvious_short() + " %^BOLD%^%^WHITE%^stops %^CYAN%^glowing %^WHITE%^as you remove it from your brow.%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^WHITE%^The %^BOLD%^%^BLUE%^gem %^WHITE%^on " + ETO->QCN + "'s " + query_obvious_short() + " %^BOLD%^%^WHITE%^stops %^BOLD%^%^CYAN%^glowing %^WHITE%^as " + ETO->QS + " removes it from " + ETO->QP + " brow.%^RESET%^", ETO);
    return 1;
}
