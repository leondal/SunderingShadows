#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("embroidered robe");
    set_id(({"embroidered robe","robe","elegant robe"}));
    set_short("elegant robe");
    set_long("This robe is finely crafted by the best artisans of Seneca.  "+
       "Its fine wool will keep you warm on the coldest nights, but it is "+
       "comfortable in warmer weather.  The embroidery is like none you "+
       "have ever seen, the patterns seem to move as you walk.");
    set_weight(1);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_value(20);
}
