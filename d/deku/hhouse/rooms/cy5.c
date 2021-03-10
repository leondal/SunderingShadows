#include <std.h>
#include "../inherits/area_stuff.h"
inherit CY;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ The path around the "+
    "house continues to the east and the west.%^RESET%^");

    set_exits((["east" : HHROOMS+"cy6", "west" : HHROOMS+"cy4" ]));		

}
