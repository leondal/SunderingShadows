#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("sandals");
    set_id(({"sandals","fine leather sandals"}));
    set_short("%^RESET%^%^ORANGE%^fine leather sandals%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^These well-made sandals are simple "+
       "in design.  They feature a thick leather sole lined with "+
       "light padding to aid in comfort. The upper is made of "+
       "tanned leather that buckles across the top of the foot "+
       "and a matching strap that encircles the heel.  These "+
       "sandals would be great for walking around town, but "+
       "would not offer much support on long journeys.%^RESET%^");
    set_type("clothing");
    set_limbs(({"right foot","left foot"}));
    set_weight(1);
    set_value(5);
}
