#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();    
    set_exits((["west" : CRROOMS+"lower13", "southeast" : CRROOMS+"lower7"]));		    
}
