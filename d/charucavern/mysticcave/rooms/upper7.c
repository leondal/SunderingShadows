#include <std.h>
#include "../inherits/area_stuff.h"
inherit UPPER;

void create() 
{
    ::create();

    set_exits((["southwest" : CRROOMS+"upper8", "east" : CRROOMS +"upper6"]));		
}
