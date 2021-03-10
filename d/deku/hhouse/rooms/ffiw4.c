#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    ::create();
    set_exits((["north" : FFROOMS+"iw6", "south" : FFROOMS+"iw3", "east" : FFROOMS+"iw5"]));		
}
