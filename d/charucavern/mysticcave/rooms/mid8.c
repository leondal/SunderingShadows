#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["northeast" : CRROOMS+"mid9", "northwest" : CRROOMS +"mid7"]));		
}
