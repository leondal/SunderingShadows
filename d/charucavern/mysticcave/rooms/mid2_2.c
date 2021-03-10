#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["northeast" : CRROOMS+"mid2_1", "southeast" : CRROOMS +"mid2_3"]));		
}
