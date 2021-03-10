#include <std.h>
inherit "/d/common/obj/armour/chain.c";

void create() {
    ::create();
    set_name("mesh armor");
    set_id(({"mesh","armor","supple mesh","mesh armor"}));
    set_short("%^BOLD%^%^BLACK%^supple mesh armor%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This unique suit of armor is formed of "
"countless strands of metal, interwoven in an elaborate design to form "
"a supple coat of mesh.  The entirety of the metal is dull and black, "
"treated so as not to reflect any light cast upon it.%^RESET%^\n");
    set_value(100);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  They prize such "
"armor for its light weight, and its stealthy nature in the darkness of "
"the caverns they dwell in.");
    set_property("lore difficulty",3);
}
