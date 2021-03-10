#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ A path continues northwest and south "+
    "along the edge of the crater.%^RESET%^");
    set_exits((["northwest" : CRROOMS+"out7", "south" : CRROOMS+"out9"]));		

}
