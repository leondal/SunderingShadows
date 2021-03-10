#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["northwest" : CRROOMS+"mid2_2", "southeast" : CRROOMS +"mid2_4"]));		
}
