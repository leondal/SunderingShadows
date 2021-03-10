#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    sexit = "north";
    dest = SFROOMS+"h15";
    ::create();
    set_exits((["west" : SFROOMS+"iw4"]));
}
