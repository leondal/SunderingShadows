#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    
    set_exits((["southwest" : WROOMS +"wormtun1_5", "northeast" : WROOMS +"wormtun1_7"]));	
    
}
