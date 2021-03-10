#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    
    set_exits((["northwest" : WROOMS +"wormtun1_4", "northeast" : WROOMS +"wormtun1_6"]));	
    
}
