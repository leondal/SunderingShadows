#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ A path continues northeast and northwest "+
    "along the edge of the crater. The city of verbobone lies directly to the south.%^RESET%^");
    set_exits((["northeast" : CRROOMS+"out10", "northwest" : CRROOMS+"out2", 
    "south" : OE ]));		

}
