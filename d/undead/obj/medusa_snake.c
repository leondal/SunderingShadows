#include <std.h>
#include "../undead.h"

inherit ARMOUR;

void create() 
{
    ::create();
    set_id(({"snake"}));
    set_name("medusa's snake");
    set_short("%^BOLD%^%^BLACK%^A snake from Medusa's head%^RESET%^");
    set_weight(0);
    set_long("This appears to be a snake from the head of Medusa. It is only just "
        "barely alive now, you're pretty sure it is not dangerous.");
    set_value(0);
    set_type("clothing");
    set_limbs(({"head"}));
}

