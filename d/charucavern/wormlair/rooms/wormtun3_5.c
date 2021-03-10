#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["south" : WROOMS + "wormtun3_4", "northwest" : WROOMS + "wormtun3_6"]));	    
}
