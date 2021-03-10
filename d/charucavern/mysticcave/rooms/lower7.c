#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();    
    set_exits((["west" : CRROOMS +"lower15", "northwest" : CRROOMS+"lower14", "northeast" : CRROOMS+"lower6"]));		    
}
