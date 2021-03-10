#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    
    set_exits((["northeast" : WROOMS +"wormtun1_1", "southwest" : WROOMS +"wormtun1_3"]));	
    
}
