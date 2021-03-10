#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["north" : WROOMS + "wormtun3_5", "southeast" : WROOMS + "wormtun3_3"]));	    
}
