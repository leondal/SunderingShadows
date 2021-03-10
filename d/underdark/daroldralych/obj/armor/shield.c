#include <std.h>
inherit "/d/common/obj/armour/mshield.c";

void create() {
    ::create();
    set_id(({"shield","medium shield","blackened shield","blackened medium shield"}));
    set_short("%^BOLD%^%^BLACK%^blackened medium shield%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This fine shield is crafted to be "
"defensive without being cumbersome in combat.  Flat across the top, it "
"comes down on both sides in a curved shape to meet at a point below.  It "
"has been blackened with some unknown substance, giving it a dark and "
"glossy sheen.\n%^RESET%^");
    set_value(10);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  Their own armor "
"is of impressive craftsmanship, often lighter than its mundane "
"counterparts, and far more finely wrought.");
    set_property("lore difficulty",3);
}
