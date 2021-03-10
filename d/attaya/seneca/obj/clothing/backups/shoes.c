#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("shoes");
    set_id(({"shoes","fine shoes"}));
    set_short("fine shoes");
    set_long("These are sturdy shoes, made by the fine shoemakers "+
       "of Seneca.  They provide your feet with protection while "+
       "walking but are not good against the elements.");
    set_type("clothing");
    set_limbs(({"right foot","left foot"}));
    set_weight(1);
    set_value(1);
}
