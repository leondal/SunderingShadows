#include <std.h>
#include "../undead.h"

inherit ARMOUR;

void create() 
{
    ::create();
    set_id(({"necklace","eyes","necklace of eyes"}));
    set_name("necklace of eyes");
    set_short("%^MAGENTA%^A Necklace of Eyes%^RESET%^");
    set_weight(0);
    set_long("This necklace appears to be a golden chain with a pair of eyes "
        "strung along it.");
    set_value(1000);
    set_type("ring");
    set_limbs(({"neck"}));
}

