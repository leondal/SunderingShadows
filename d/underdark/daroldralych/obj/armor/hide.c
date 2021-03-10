#include <std.h>
inherit "/d/common/obj/armour/hide.c";

void create() {
    ::create();
    set_id(({"hide","armor","mottled hide","hide armor"}));
    set_short("%^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^%^BLACK%^tled hide armor%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This dusky armor has been prepared from "
"the thick hide of some creature and has been layered for protection.  "
"The hide has been boiled to toughen it, which makes it somewhat more "
"stiff than a simple suit of leather.  It has been carefully treated, "
"however, allowing for a greater degree of movement than is usually seen "
"in armors of this kind.\n%^RESET%^");
    set_value(30);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  They prize such "
"armor for its light weight, and its stealthy nature in the darkness of "
"the caverns they dwell in.");
    set_property("lore difficulty",3);
}
