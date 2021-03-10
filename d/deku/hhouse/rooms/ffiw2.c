#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    ::create();
    set_exits((["east" : FFROOMS+"iw3", "west" : FFROOMS+"iw1"]));		
}
