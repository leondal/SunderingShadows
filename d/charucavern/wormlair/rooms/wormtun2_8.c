#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["northeast" : WROOMS + "wormtun2_9", "northwest" : WROOMS + "wormtun2_7"]));	    
}
