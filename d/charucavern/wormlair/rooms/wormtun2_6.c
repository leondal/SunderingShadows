#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["west" : WROOMS + "wormtun2_5", "south" : WROOMS + "wormtun2_7"]));	    
}
