#include <std.h>
#include "../inherits/area_stuff.h"
inherit UPPER;

void create() 
{
    ::create();

    set_exits((["west" : CRROOMS+"upper11", "north" : CRROOMS +"upper13"]));		
}
