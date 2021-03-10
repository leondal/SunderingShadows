#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{	
    sexit = "east";
    dest = FFROOMS+"r3";
    ::create();
    set_exits((["south" : FFROOMS+"iw8", "north" : FFROOMS+"iw10"]));		
}
