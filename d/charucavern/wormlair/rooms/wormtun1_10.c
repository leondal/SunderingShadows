#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMLAIR;

void create() 
{
    ::create();
    
    set_exits((["southwest" : WROOMS + "wormtun1_9", "southeast" : WROOMS + "wormtun1_11"]));	
    
}
