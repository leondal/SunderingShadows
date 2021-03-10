#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ A path continues northwest and southeast "+
    "along the edge of the crater.%^RESET%^");
    set_exits((["northwest" : CRROOMS+"out6", "southeast" : CRROOMS+"out8"]));		

}
