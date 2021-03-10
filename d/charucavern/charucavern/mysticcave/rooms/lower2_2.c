#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();     
    set_exits((["south" : CRROOMS +"lower2_3", "west" : CRROOMS+"lower2_1"]));		    
}
