#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    sexit = "west";
    dest = SFROOMS+"h26";
    ::create();
    set_exits((["east" : SFROOMS+"iw2"]));		
}
