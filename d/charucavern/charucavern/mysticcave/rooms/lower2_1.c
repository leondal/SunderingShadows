#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();     
    set_exits((["east" : CRROOMS +"lower2_2", "west" : CRROOMS+"lower2_enter"]));		    
}
