#include <std.h>
inherit "/d/common/obj/armour/helm.c";

void create() {
    ::create();
    set_id(({"helm","blackened helm"}));
    set_short("%^BOLD%^%^BLACK%^blackened helm%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This helm is rather ornate in its "
"appearance, with a long and narrow design.  From its peak it leads down "
"to cover the back and sides of the head, leaving the face partially "
"open.  A protective strip runs down to the nose of the wearer, offering "
"a small amount of defense from blows to the face.  It has been blackened "
"with some unknown substance, giving it a dark and glossy sheen.\n%^RESET%^");
    set_value(50);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  Their own armor "
"is of impressive craftsmanship, often lighter than its mundane "
"counterparts, and far more finely wrought.");
    set_property("lore difficulty",3);
}
