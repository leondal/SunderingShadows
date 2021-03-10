#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ A path continues north and southwest "+
    "along the edge of the crater.%^RESET%^");
    set_exits((["southwest" : CRROOMS+"out10", "north" : CRROOMS+"out8"]));		

}
