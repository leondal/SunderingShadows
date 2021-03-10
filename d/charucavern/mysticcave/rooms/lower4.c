#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();    
    set_exits((["east" : CRROOMS +"lower5", "west" : CRROOMS+"lower3"]));		    
}
