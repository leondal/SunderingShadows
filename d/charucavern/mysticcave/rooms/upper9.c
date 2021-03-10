#include <std.h>
#include "../inherits/area_stuff.h"
inherit UPPER;

void create() 
{
    ::create();

    set_exits((["south" : CRROOMS+"upper10", "west" : CRROOMS +"upper8"]));		
}
