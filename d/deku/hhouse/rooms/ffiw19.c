#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{	
    sexit = "east";
    dest = FFROOMS+"iw20";
    ::create();
    set_exits((["north" : FFROOMS+"iw18"]));		
}
