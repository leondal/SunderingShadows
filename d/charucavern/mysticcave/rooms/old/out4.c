#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ A path continues northeast and south "+
    "along the edge of the crater.%^RESET%^");
    set_exits((["south" : CRROOMS+"out3", "northeast" : CRROOMS+"out5" ]));		

}
