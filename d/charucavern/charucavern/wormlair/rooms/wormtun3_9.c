#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["southwest" : WROOMS + "wormtun3_3", "east" : WROOMS + "wormtun3_10"]));	    
}
