#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    ::create();
    set_exits((["north" : FFROOMS+"iw9", "south" : FFROOMS+"iw7"]));		
}
