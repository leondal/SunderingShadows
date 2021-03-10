#include <std.h>
inherit "/d/common/obj/weapon/polearm_piercing.c";

void create()
{
    ::create();
    set_id(({ "hammer", "lucern hammer", "pole arm", "polearm", }));
    set_name("lucern hammer");
    set_short("A lucern hammer");
    set_long("This pole arm has a longe spear tip with a three-pronged, sharpened hammer jutting from one side, and a spike counterbalance on the other.  It looks like a good weapon for smashing through armor.");
}
