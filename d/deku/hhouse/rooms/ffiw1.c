#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{
    sexit = "west";
    dest = FFROOMS+"36";
    ::create();
    set_exits((["east" : FFROOMS+"iw2"]));		
}
