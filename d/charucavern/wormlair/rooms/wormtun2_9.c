#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["north" : WROOMS + "wormtun2_10", "southwest" : WROOMS + "wormtun2_8"]));	    
}
