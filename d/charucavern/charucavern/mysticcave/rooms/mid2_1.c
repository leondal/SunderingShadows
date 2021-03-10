#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["east" : CRROOMS+"mid2_enter", "southwest" : CRROOMS +"mid2_2"]));		
}
