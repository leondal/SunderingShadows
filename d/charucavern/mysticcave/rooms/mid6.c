#include <std.h>
#include "../inherits/area_stuff.h"
inherit MID;

void create() 
{
    ::create();
    set_exits((["south" : CRROOMS+"mid7", "east" : CRROOMS +"mid5"]));		
}
