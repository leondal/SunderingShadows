#include <std.h>
#include "../undead.h"

inherit ARMOUR;

void create() 
{
    ::create();
    set_id(({"horn"}));
    set_name("minotaur's horn");
    set_short("%^BOLD%^A Minotaur's Horn%^RESET%^");
    set_weight(0);
    set_long("This is one of the minotaur's horns which appears to have fallen out after his death.");
    set_value(1000);
    set_type("clothing");
    set_limbs(({"head"}));
}

