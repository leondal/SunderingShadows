#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["west" : CRROOMS+"mid5", "east" : CRROOMS +"mid3"]));		
}
