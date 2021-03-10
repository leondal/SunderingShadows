#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();     
    set_exits((["north" : CRROOMS +"lower2_6", "south" : CRROOMS+"lower2_4"]));		    
}
