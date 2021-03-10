#include <std.h>
#include "../undead.h"

inherit ARMOUR;

void create() 
{
    ::create();
    set_id(({"eye","eyeball"}));
    set_name("eye");
    set_short("%^RED%^An eyeball%^RESET%^");
    set_weight(0);
    set_long("This appears to be an eyeball from one of the reknowned Sister's of fate.");
    set_value(1000);
    set_type("clothing");
    set_limbs(({"head"}));
}

