#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["north" : CRROOMS+"mid2_6", "south" : CRROOMS +"mid2_4"]));		
}
