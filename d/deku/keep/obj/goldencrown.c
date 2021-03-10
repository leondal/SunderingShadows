#include <std.h>
inherit "/d/common/obj/jewelry/circlet.c";

void create()
{
    ::create();
    set_name("gold crown");
    set_id(({ "crown", "gold crown", "blacktongue crown"}));
    set_short("%^YELLOW%^%^RED%^g%^BOLD%^%^GREEN%^e%^BLUE%^m%^YELLOW%^ "+
    "encrusted gold crown%^RESET%^");
    set_long("%^YELLOW%^This large crown is made from solid, "+
    "polished gold.  Varying patterns "+
    "of %^BOLD%^%^WHITE%^d%^CYAN%^iam%^BOLD%^%^WHITE%^on%^CYAN%^"+
    "ds%^YELLOW%^, %^BOLD%^%^GREEN%^"+
    "eme%^RESET%^%^GREEN%^ra%^BOLD%^%^GREEN%^lds%^YELLOW%^, and %^RESET%^%^RED%^rub"+
    "%^BOLD%^%^YELLOW%^i%^RESET%^%^RED%^es%^YELLOW%^ line "+
    "the outside of the top it.  A single "+
    "large %^BOLD%^%^WHITE%^cr%^BLUE%^ys%^BOLD%^%^WHITE%^tal%^YELLOW%^ "+
    "is inset in the center "+
    "of the front of it.  Two words are etched into the gold "+
    "beneath the %^BOLD%^%^WHITE%^cr"+
    "%^BLUE%^ys%^BOLD%^%^WHITE%^tal%^YELLOW%^.%^RESET%^");
    set_read("Lord BlackTongue");
    set_language("common");
    set_weight(2);
    set_value(1000);
    set_size(3);
    set_wear("%^YELLOW%^You feel a sense of nobility as "+
    "you wear the gem encrusted crown.%^RESET%^");
    set_remove("%^RED%^As you take the crown from atop your head "+
    "you feel like your same old "+
    "self again.%^RESET%^");
}


