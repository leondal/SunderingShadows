#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMLAIR;

void create() 
{
    ::create();
    set_exits((["northeast" : WROOMS + "wormtun3_6"]));	    
}
