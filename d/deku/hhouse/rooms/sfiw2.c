#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    ::create();
    set_exits((["west" : SFROOMS+"iw1", "north" : SFROOMS+"iw3"]));		
}
