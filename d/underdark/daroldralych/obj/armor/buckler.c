#include <std.h>
inherit "/d/common/obj/armour/buckler.c";

void create() {
    ::create();
    set_id(({"buckler","leather buckler","dark buckler","dark leather buckler"}));
    set_short("%^BOLD%^%^BLACK%^dark leather buckler%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This small shield is made of dark leather, "
"and is designed to be worn on the forearm.  It has been hardened and "
"shaped into an oval shield that is light enough not to impede "
"movement.\n%^RESET%^");
    set_value(3);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  They prize such "
"armor for its light weight, and its stealthy nature in the darkness of "
"the caverns they dwell in.");
    set_property("lore difficulty",3);
}
