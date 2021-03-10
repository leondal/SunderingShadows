#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMLAIR;

void create() 
{
    ::create();
    
    set_exits((["northwest" : WROOMS +"wormtun1_3", "southeast" : WROOMS +"wormtun1_5"]));	
    
}
