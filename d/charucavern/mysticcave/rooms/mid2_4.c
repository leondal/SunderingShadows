#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["northwest" : CRROOMS+"mid2_3", "north" : CRROOMS +"mid2_5"]));		
}
