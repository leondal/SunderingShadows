#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("mink coat");
    set_id(({"mink coat","coat","Mink Coat"}));
    set_short("Mink Coat");
    set_long("This coat is made from the finest furs of trapped mink.  "+
       "The inside is made of the finest material, and the minks used "+
       "were only of the highest quality.  The fur is soft and smooth to the touch.");
    set_weight(2);
    set_type("clothing");
    set_limbs(({"neck"}));
    set_value(300);
}
