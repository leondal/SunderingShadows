#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["northeast" : WROOMS + "wormtun3_3", "southeast" : WROOMS + "wormtun3_1"]));	    
}
