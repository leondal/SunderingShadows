#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    ::create();
    set_exits((["north" : FFROOMS+"iw8", "south" : FFROOMS+"iw6", "west" : FFROOMS+"iw11"]));		
}
