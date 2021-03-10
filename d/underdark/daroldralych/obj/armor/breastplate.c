#include <std.h>
inherit "/d/common/obj/armour/breastplate.c";

void create() {
    ::create();
    set_id(({"breastplate","breast plate","dark breastplate","dark breast plate"}));
    set_short("%^BOLD%^%^BLACK%^a dark breastplate%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This suit of metal armor has been "
"carefully put together by expert craftsmanship, superior to that of most "
"similar armor you've seen.  It covers the torso, leaving the arms free "
"to attack, but also allowing more flexibility of movement than other "
"similar armors.  Its surface is flawless, without marks or damage to "
"detract from its elegant finish.\n%^RESET%^");
    set_value(1500);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  Their own armor "
"is of impressive craftsmanship, often lighter than its mundane "
"counterparts, and far more finely wrought.");
    set_property("lore difficulty",3);
}
