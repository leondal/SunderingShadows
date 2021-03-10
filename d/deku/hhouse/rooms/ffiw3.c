#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    ::create();
    set_exits((["north" : FFROOMS+"iw4", "west" : FFROOMS+"iw2"]));		
}
