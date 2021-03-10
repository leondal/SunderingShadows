#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["southeast" : WROOMS + "wormtun3_5", "southwest" : WROOMS + "wormtun3_7"]));	    
}
