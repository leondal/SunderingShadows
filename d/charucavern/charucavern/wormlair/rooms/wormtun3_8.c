#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["northwest" : WROOMS + "wormtun3_3", "southwest" : WROOMS + "wormtun3_1"]));	    
}
