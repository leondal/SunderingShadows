#include <std.h>
inherit "/d/common/obj/weapon/polearm_slashing.c";

create()
{
    ::create();
    set_id(({ "fauchard" }));
    set_name("fauchard");
    set_short("A fauchard");
    set_long("This eight foot wooden shaft holds a massive, curved blade at its end.  The blade is reminiscent of a that of a scythe with its curve and backward edge, but it has been mounted straight rather than from the side of the pole.");
}
