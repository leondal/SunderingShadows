#include <std.h>
inherit "/d/common/obj/weapon/polearm_slashing.c";

void create()
{
    ::create();
    set_id(({ "sharp glaive", "a sharp glaive", "pole arm", "polearm", "glaive" }));
    set_name("glaive");
    set_short("A sharp glaive");
    set_long("This weapon consists of a huge, single edged knifeblade on a long pole.  Looks like you could certainly get a bit of leverage into any cutting blow.");
}
