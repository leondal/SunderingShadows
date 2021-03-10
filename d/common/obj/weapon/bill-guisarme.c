#include <std.h>
inherit "/d/common/obj/weapon/polearm_piercing.c";

create()
{
    ::create();
    set_id(({ "bill-guisarme" }));
    set_name("bill-guisarme");
    set_short("A bill-guisarme");
    set_long("This is a combination pole arm. It has a spike and axe on one end, and a hook on the other end."
             );
}
