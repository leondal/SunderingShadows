#include <std.h>
inherit "/d/common/obj/weapon/polearm_slashing.c";

void create()
{
    ::create();
    set_id(({ "bardiche", "polearm", "pole axe", "axe" }));
    set_name("bardiche");
    set_short("A nasty looking bardiche");
    set_long("The massive blade on this axe makes you shudder, as its only purpose could be war.  Just over two feet of razor sharpened steel are connected to a five foot handle with two steel rings.");
}
