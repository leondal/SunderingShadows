#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();    
    set_exits((["southeast" : CRROOMS +"lower6", "west" : CRROOMS+"lower4"]));		    
}
