#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("cloak");
    set_id(({"cloak","cloak of good cloth","waterproof cloak"}));
    set_short("A waterproof cloak");
    set_long("This cloak is well-made of a strong, waterproof cloth.  "+
       "It is a dark blue in color, and has a silver clasp.  The hood "+
       "can be worn to protect you from the elements.");
    set_weight(1);
    set_type("clothing");
    set_limbs(({"neck"}));
    set_value(5);
}
