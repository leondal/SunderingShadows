#include <std.h>
inherit "/d/common/obj/weapon/polearm_slashing.c";

void create()
{
    ::create();
    set_id(({ "heavy halberd", "pole axe", "halberd", "pole arm", "polearm" }));
    set_name("halberd");
    set_short("A heavy halberd");
    set_long("This eight foot long pole axe looks very menacing and effective.  Its convex axe blade is set at the perfect angle for cutting into someone before they could get to close.  It's topped by a long spearhead and backed with a curved spike.");
}
