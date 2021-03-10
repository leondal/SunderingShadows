#include <std.h>
inherit "/d/common/obj/armour/leather.c";

void create() {
    ::create();
    set_id(({"leather","leather armor","armor","armour","dark leather","dark leather armor","dark armor","dleather"}));
    set_short("%^BOLD%^%^BLACK%^dark leather armor%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This suit of armor somewhat resembles "
"that of standard surface leather, except that it is entirely black.  It "
"consists of hardened leather that has been darkened to a dull shade of "
"gray, but is surprisingly light for its appearance.%^RESET%^\n");
    set_value(20);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  They prize such "
"armor for its light weight, and its stealthy nature in the darkness of "
"the caverns they dwell in.");
    set_property("lore difficulty",3);
}
