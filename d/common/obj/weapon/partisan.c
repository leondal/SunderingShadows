#include <std.h>
inherit "/d/common/obj/weapon/polearm_piercing.c";

void create()
{
    ::create();
    set_id(({ "partisan", "pole arm", "polearm", "spear" }));
    set_name("partisan");
    set_short("A partisan");
    set_long("This form of pole arm consists of a long ox-tongue spear blade, with two small axe blades added to the base of the spearhead.");
}
