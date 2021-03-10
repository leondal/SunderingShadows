#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();    
    set_exits((["north" : CRROOMS+"lower11", "east" : CRROOMS+"lower9"]));		    
}
