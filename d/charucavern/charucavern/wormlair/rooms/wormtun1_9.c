#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    
    set_exits((["northeast" : WROOMS + "wormtun1_10", "northwest" : WROOMS + "wormtun1_1", "southeast" : WROOMS + "wormtun1_7"]));	
    
}
