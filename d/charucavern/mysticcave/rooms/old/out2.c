#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ A path continues southeast and northwest "+
    "along the edge of the crater.%^RESET%^");
    set_exits((["southeast" : CRROOMS+"out1", "northwest" : CRROOMS+"out3" ]));		

}
