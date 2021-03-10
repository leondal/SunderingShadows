#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    
    set_exits((["southwest" : WROOMS +"wormtun1_6", "northeast" : WROOMS +"wormtun1_11", "southeast" : WROOMS +"wormtun1_8", 
    "northwest" : WROOMS + "wormtun1_9"]));	
    
}
