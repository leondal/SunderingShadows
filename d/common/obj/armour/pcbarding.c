// barding for player use (wemic & centaur), not for IG mounts. N, 2/14.
#include <std.h>
inherit ARMOUR;

void create() {
     ::create();
     set_name("metal half-barding");
     set_id(({ "barding", "metal barding", "half-barding" }));
     set_short("metal half-barding");
     set_long("This set of half-barding is crafted from steel.  It would "
"serve to cover most of the rump and flanks, as well as the lower chest, "
"and is probably designed for a horse or similarly sized quadruped animal.  "
"It has a rough and unfinished look about it, as if it were crafted in haste.");
    set_weight(10);
    set_value(15);
    set_ac(1);
    set_size(3);
    set_type("armor");
    set_armor_prof("medium");
    set_limbs(({ "lower torso" }));
}

int is_metal() { return 1; }
