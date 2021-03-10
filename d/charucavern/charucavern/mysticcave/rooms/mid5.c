#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["west" : CRROOMS+"mid6", "east" : CRROOMS +"mid4"]));		
}
