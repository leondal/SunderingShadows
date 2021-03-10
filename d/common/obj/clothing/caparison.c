// caparison for player use (wemic & centaur), not for IG mounts. N, 2/14.
#include <std.h>
inherit ARMOUR;

void create() {
     ::create();
     set_name("caparison");
     set_id(({ "caparison", "linen caparison" }));
     set_short("linen caparison");
     set_long("This simple caparison is crafted from linen.  Such a garment "
"usually serves as a decorative drape for a mount, though some sturdier ones "
"can be used as protection from wind and weather as well. It would "
"serve to cover most of the rump and flanks, as well as the lower chest, "
"and is probably designed for a horse or similarly sized quadruped animal.  "
"It has a rough and unfinished look about it, as if it were crafted in haste.");
    set_weight(3);
    set_value(10);
    set_type("clothing");
    set_limbs(({ "lower torso" }));
    set_ac(0);
    set_size(3);
}
