#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["northwest" : WROOMS + "wormtun2_15", "southeast" : WROOMS + "wormtun2_13"]));	    
}
