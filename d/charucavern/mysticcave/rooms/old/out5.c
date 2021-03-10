#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ A path continues northeast and southwest "+
    "along the edge of the crater.%^RESET%^");
    set_exits((["southwest" : CRROOMS+"out4", "northeast" : CRROOMS+"out6"]));		

}
