#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();     
    set_exits((["west" : CRROOMS +"lower2_7", "south" : CRROOMS+"lower2_5"]));		    
}
