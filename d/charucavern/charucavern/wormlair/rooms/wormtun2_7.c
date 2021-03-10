#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    set_exits((["north" : WROOMS + "wormtun2_6", "southeast" : WROOMS + "wormtun2_8", "southwest" : WROOMS + "wormtun2_11"]));	    
}
