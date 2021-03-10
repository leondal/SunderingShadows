//changed to type "ring" to be worn with pants/skirts ~Circe~ 5/31/07
#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("hose leggings");
    set_id(({"hose","hose leggings","leggings","fine hosery"}));
    set_short("fine hosery");
    set_long("These are finly made hose, in a dark green color.");
    set_type("ring");
    set_limbs(({"right leg","left leg"}));
    set_weight(1);
    set_value(3);
}
