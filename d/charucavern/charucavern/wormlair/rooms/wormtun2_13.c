#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMLAIR;

void create() 
{
    ::create();
    set_exits((["northwest" : WROOMS + "wormtun2_14", "northeast" : WROOMS + "wormtun2_12"]));	    
}
