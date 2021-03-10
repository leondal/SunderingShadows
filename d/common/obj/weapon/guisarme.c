#include <std.h>
inherit "/d/common/obj/weapon/polearm_piercing.c";

void create()
{
    ::create();
    set_id(({ "guisarme", "pole arm", "polearm" }));
    set_name("guisarme");
    set_short("A gruesome looking guisarme");
    set_long("This weapon looks like a pruning hook that's been pressed into service as a moderately effective polearm.  It doesn't have a spear point however, just the inside of the sharpened curved hook to inflict damage.");
}
