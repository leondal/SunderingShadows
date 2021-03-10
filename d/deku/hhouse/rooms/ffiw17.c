#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{	
    ::create();
    set_exits((["south" : FFROOMS+"iw18", "north" : FFROOMS+"iw16"]));		
}
