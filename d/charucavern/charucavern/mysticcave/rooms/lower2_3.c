#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();     
    set_exits((["north" : CRROOMS +"lower2_2", "east" : CRROOMS+"lower2_4"]));		    
}
