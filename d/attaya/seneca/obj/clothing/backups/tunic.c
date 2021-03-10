#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("tunic");
    set_id(({"tunic","shirt","Fine brown tunic"}));
    set_short("Fine brown tunic");
    set_long("This is a finely made tunic, with a belt and bronze belt buckle.");
    set_type("clothing");
    set_limbs(({"torso"}));
    set_weight(1);
    set_value(20);
}
