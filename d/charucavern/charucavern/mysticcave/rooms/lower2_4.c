#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();     
    set_exits((["north" : CRROOMS +"lower2_5", "west" : CRROOMS+"lower2_3"]));		    
}
