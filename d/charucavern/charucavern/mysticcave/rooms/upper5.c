#include <std.h>
#include "../inherits/area_stuff.h"
inherit UPPER;

void create() 
{
    ::create();

    set_exits((["north" : CRROOMS+"upper6", "northeast" : CRROOMS +"upper4"]));		
}
