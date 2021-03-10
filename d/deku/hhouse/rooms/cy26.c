#include <std.h>
#include "../inherits/area_stuff.h"
inherit CY;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ The path around the "+
    "house continues to the south and the east.%^RESET%^");

    set_exits((["south" : HHROOMS+"cy27", "east" : HHROOMS+"cy25" ]));		

}
