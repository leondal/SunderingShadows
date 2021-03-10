#include <std.h>
inherit "/d/common/obj/armour/studded.c";

void create() {
    ::create();
    set_id(({"studded","armor","studded armor","leather","studded leather","dark studded","dark leather"}));
    set_short("%^BOLD%^%^BLACK%^dark studded leather armor%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This suit of armor resembles that of a "
"standard set of studded leather, except that it is entirely black.  It "
"consists of hardened leather that has been darkened to a dull shade of "
"gray, and is reinforced with close-set metal rivets.  The rivets are "
"made of a metal that has been treated to reflect no light.%^RESET%^\n");
    set_value(40);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  They prize such "
"armor for its light weight, and its stealthy nature in the darkness of "
"the caverns they dwell in.");
    set_property("lore difficulty",3);
}
