#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMLAIR;

void create() 
{
    ::create();
    set_exits((["northeast" : WROOMS + "wormtun3_9", "southwest" : WROOMS + "wormtun3_2", "southeast" : WROOMS + "wormtun3_8", "northwest" : WROOMS + "wormtun3_4"]));	    
}
