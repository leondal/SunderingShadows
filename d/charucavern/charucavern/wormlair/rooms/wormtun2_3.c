#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["south" : WROOMS + "wormtun2_4", "west" : WROOMS + "wormtun2_2"]));	    
}
