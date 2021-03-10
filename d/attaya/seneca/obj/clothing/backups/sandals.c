#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("sandals");
    set_id(({"sandals","fine leather sandals"}));
    set_short("fine leather sandals");
    set_long("These sandals have hard leather with a soft cloth "+
       "over it as a sole and soft leather strips to hold it to "+
       "your foot.  They are good for walking around town.");
    set_type("clothing");
    set_limbs(({"right foot","left foot"}));
    set_weight(1);
    set_value(5);
    set_cointype("silver");
}
