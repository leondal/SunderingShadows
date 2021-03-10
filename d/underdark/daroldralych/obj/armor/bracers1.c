#include <std.h>
inherit "/d/common/obj/armour/bracers.c";

void create() {
    ::create();
    set_id(({"bracers","blackened bracers"}));
    set_short("%^BOLD%^%^BLACK%^blackened bracers of defense%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^blackened bracers%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These bracers are rather plain, but "
"carefully designed to be an effective protection.  Two bands of metal, "
"blackened by some unknown substance, form sheathes for the forearms of "
"the wearer, keeping them safe from blows.  Small clasps on the underside "
"hold them closed around the arms.\n%^RESET%^");
    set_value(650);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  Their own armor "
"is of impressive craftsmanship, often lighter than its mundane "
"counterparts, and far more finely wrought.");
    set_property("lore difficulty",3);
}
