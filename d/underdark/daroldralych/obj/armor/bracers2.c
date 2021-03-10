#include <std.h>
inherit "/d/common/obj/armour/bracers.c";

void create() {
    ::create();
    set_id(({"bracers","dark bracers","leather bracers","dark leather bracers"}));
    set_short("%^BOLD%^%^BLACK%^dark leather bracers of defense%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^dark leather bracers%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These simple bracers are formed of "
"thick leather, hardened to form an effective protection.  Each band of "
"dusky leather forms a sheath for the forarms of the wearer, tied closed "
"with laces that run up the length of the underside of each bracer.  They "
"would form a good defense against blows, without restricting the "
"wearer's movements.\n%^RESET%^");
    set_value(450);
    set_lore("Such armor as this is said to be made by the drow - the "
"evil race of dark elves that live within the underdark.  They prize such "
"armor for its light weight, and its stealthy nature in the darkness of "
"the caverns they dwell in.");
    set_property("lore difficulty",3);
}
