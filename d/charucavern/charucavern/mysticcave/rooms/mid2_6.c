#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["west" : CRROOMS+"mid2_7", "south" : CRROOMS +"mid2_5"]));		
}
