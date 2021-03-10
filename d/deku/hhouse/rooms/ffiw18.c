#include <std.h>
#include "../inherits/area_stuff.h"
inherit INWALL;

void create() 
{	
    sexit = "west";
    dest = FFROOMS+"r6";
    ::create();
    set_exits((["south" : FFROOMS+"iw19", "north" : FFROOMS+"iw17"]));		
}
