#include <std.h>

inherit ARMOUR;

void create() 
{
    ::create();
    set_property("no animate",1);
    set_id(({"necklace","cruciform","cross"}));
    set_name("cruciform");
    set_short("%^BLUE%^A Holy Cross%^RESET%^");
    set_weight(0);
    set_long("This is a holy cross hung from a necklace of stone beads.");
    set_value(1000);
    set_type("clothing");
    set_limbs(({"neck"}));
}

