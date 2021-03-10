#include <std.h>
inherit "/d/common/obj/weapon/polearm_piercing.c";

create()
{
    ::create();
    set_id(({ "pike", "awlpike" }));
    set_name("awlpike");
    set_short("A awlpike");
    set_long("A spear 12-20 feet long, with a spiked point on the end."
             );
}
