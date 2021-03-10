#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ A path continues north and southeast "+
    "along the edge of the crater.%^RESET%^");
    set_exits((["southeast" : CRROOMS+"out2", "north" : CRROOMS+"out4" ]));		

}
