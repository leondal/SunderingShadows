#include <std.h>
#include "../inherits/area_stuff.h"
inherit CY;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ The path around the "+
    "house continues to the north and the south.%^RESET%^");

    set_exits((["north" : HHROOMS+"cy31", "south" : HHROOMS+"cy33" ]));		

}
