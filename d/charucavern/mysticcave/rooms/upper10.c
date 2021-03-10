#include <std.h>
#include "../inherits/area_stuff.h"
inherit UPPER;

void create() 
{
    ::create();

    set_exits((["north" : CRROOMS+"upper9", "east" : CRROOMS +"upper11"]));		
}
