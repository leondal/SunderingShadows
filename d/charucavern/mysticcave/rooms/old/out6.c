#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^ A path continues southeast and southwest "+
    "along the edge of the crater. A rickety wooden ladder descends down into the darkness of "+
    "the crater.%^RESET%^");
    set_exits((["southwest" : CRROOMS+"out5", "southeast" : CRROOMS+"out7", "ladder" : CRROOMS+"out11"]));		

}
