#include <std.h>
inherit "/d/common/obj/weapon/polearm_piercing.c";

void create()
{
    ::create();
    set_id(({ "pole arm", "polearm", "spetum" }));
    set_name("spetum");
    set_short("A spetum");
    set_long("This is a long polearm with a long, heavy spear point that splits into two forward curving spikes at its base.");
}
