#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("gloves");
    set_id(({"gloves","gauntlets","glove","gauntlet","leather gloves"}));
    set_short("leather gloves");
    set_long("These gloves are made from heavy leather and are designed "+
       "to protect your hands.  Wonderfully, they also have a fur lining "+
       "and actually keep your hands very warm.");
    set_type("clothing");
    set_limbs(({"right hand","left hand"}));
    set_weight(1);
    set_value(1);
}
