#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["southeast" : CRROOMS+"mid8", "north" : CRROOMS +"mid6"]));		
}
