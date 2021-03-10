#include <std.h>
#include "../inherits/area_stuff.h"
inherit UPPER;

void create() 
{
    ::create();

    set_exits((["southwest" : CRROOMS+"upper4", "west" : CRROOMS +"upper2"]));		
}
