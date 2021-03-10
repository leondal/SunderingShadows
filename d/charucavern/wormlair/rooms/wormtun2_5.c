#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMLAIR;

void create() 
{
    ::create();
    set_exits((["west" : WROOMS + "wormtun2_4", "east" : WROOMS + "wormtun2_6"]));	    
}
