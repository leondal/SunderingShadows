#include <std.h>
inherit "/d/common/obj/weapon/polearm_slashing.c";

void create()
{
    ::create();
    set_id(({ "voulge", "pole arm", "polearm" }));
    set_name("voulge");
    set_short("A stout voulge");
    set_long("This looks like some deranged cook affixed a massive cleaver to a long, thick pole to make a weapon capable of cleaving through armor.");
}
