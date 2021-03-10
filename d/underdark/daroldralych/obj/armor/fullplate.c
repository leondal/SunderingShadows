#include <std.h>
inherit "/d/common/obj/armour/fullplate.c";

void create() {
    ::create();
    set_id(({"armor","full plate","full plate","plate","dark full plate","dark fullplate"}));
    set_short("%^BOLD%^%^BLACK%^blackened fullplate%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This full suit of armor is ornate and "
"beautifully crafted, and forged to fit its owner perfectly.  All the "
"plates are interlocking and carefully angled to deflect blows.  The metal "
"plates are backed by padding and chainmail, distributing its otherwise "
"heavy weight with ease.  The entire suit has been blackened with some "
"unknown substance, giving it a dark glossy coat that adds to its already "
"impressive appearance.\n%^RESET%^");
    set_value(11000);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  Their own armor "
"is of impressive craftsmanship, often lighter than its mundane "
"counterparts, and far more finely wrought.");
    set_property("lore difficulty",3);
}
