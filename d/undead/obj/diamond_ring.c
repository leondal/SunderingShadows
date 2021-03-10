#include <std.h>
#include "../undead.h"

inherit "/std/armour";

create() 
{
    ::create();
    set_name("Diamond ring");
    set_id(({"ring", "diamond ring", "Sring"}));
    set_short("Diamond Ring");
    set_long("This ring has a golden setting with a small diamond jutting "
        "out of it. The diamond seems to have several grooves carved into "
        "it for some reason.");
    set_type("ring");
    set_ac(0);
    set_weight(0);
    set("value", 500);
    set_limbs(({"right hand","left hand"}));

}
